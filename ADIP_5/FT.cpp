#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "FT.h"
#define PI 3.14159265354
using namespace std;

vec2::vec2() {
	r = 0;
	c = 0;
}
vec2::vec2(int r_, int c_) {
	r = r_;
	c = c_;
}
Mat FT::toLogScale(Mat complexI, Mat planes[2]) {
	// compute the magnitude and switch to logarithmic scale
	// => log(1 + sqrt(Re(DFT(I))^2 + Im(DFT(I))^2))
	split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
	magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
	Mat magI = planes[0];
	magI += Scalar::all(1);                    // switch to logarithmic scale
	log(magI, magI);
	// crop the spectrum, if it has an odd number of rows or columns
	magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));
	return magI;
}

void FT::center(Mat magI) {
	int cx = magI.cols / 2;
	int cy = magI.rows / 2;
	Mat q0(magI, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
	Mat q1(magI, Rect(cx, 0, cx, cy));  // Top-Right
	Mat q2(magI, Rect(0, cy, cx, cy));  // Bottom-Left
	Mat q3(magI, Rect(cx, cy, cx, cy)); // Bottom-Right
	Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);
	q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
	q2.copyTo(q1);
	tmp.copyTo(q2);
}

complex_t FT::calExp(double u, double r, double m, bool forward = true) {
	if (forward) {
		return complex_t(cos(2 * PI * u * r / m), -sin(2 * PI * u * r / m));
	}
	else {
		return complex_t(cos(2 * PI * u * r / m), sin(2 * PI * u * r / m));
	}
}
	
complex_t FT::DFT(unsigned char* src, double row, double col, double u, double v) {

	complex_t val(0, 0);
	double center = 0;

	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			center = (pow(-1, (r + c)));
			val += double(*(src + r * int(col) + c)) * center * calExp(u, r, row) * calExp(v, c, col);
		}
	}
	//val /= (row * col);
	//printf("val1:%f\n", log(1 + sqrt(pow(val1.real(), 2) + pow(val1.imag(), 2))));
	return val;
	//return log(1 + sqrt(pow(val.real(), 2) + pow(val.imag(), 2)));
}
complex_t FT::IDFT(vector<complex_t> src, double row, double col, double r, double c) {

	complex_t val(0, 0);
	double center = 0;

	for (int u = 0; u < row; u++) {
		for (int v = 0; v < col; v++) {
			center = (pow(-1, (u + v)));
			val += src[u * int(col) + v] * calExp(r, u, row, false) * calExp(c, v, col, false);
			//printf("%f", val.real());
		}
	}
	val /= (row * col);
	//printf("val1:%f\n", log(1 + sqrt(pow(val1.real(), 2) + pow(val1.imag(), 2))));
	return val;
	//return log(1 + sqrt(pow(val.real(), 2) + pow(val.imag(), 2)));
}

double FT::C(double row, double col, double u, double v) {
	if (u == 0 && v == 0) {
		return(sqrt(1 / row));
	}
	else {
		return(sqrt(2 / col));
	}
}
double FT::DCT(unsigned char* src, double row, double col, double u, double v) {
	double cos_val1 = 0;
	double cos_val2 = 0;
	double val = 0;
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			cos_val1 = cos(((2 * r + 1) * u * PI) / (2 * row));
			cos_val2 = cos(((2 * c + 1) * v * PI) / (2 * col));
			val += double(*(src + r * int(col) + c)) * cos_val1 * cos_val2;
		}
	}
	//printf("%f\n", C(row, col, u, v) * C(row, col, u, v) * val);
	return C(row, col, u, v) * C(row, col, u, v) * val;
}
double FT::IDCT(unsigned char* src, double row, double col, double r, double c) {
	double cos_val1 = 0;
	double cos_val2 = 0;
	double val = 0;
	for (int u = 0; u < row; u++) {
		for (int v = 0; v < col; v++) {
			cos_val1 = cos(((2 * r + 1) * u * PI) / (2 * row));
			cos_val2 = cos(((2 * c + 1) * v * PI) / (2 * col));
			val += C(row, col, u, v) * C(row, col, u, v) * double(*(src + u * int(col) + v)) * cos_val1 * cos_val2;
		}
	}
	return val;
}


unsigned char FT::doConvolution(unsigned char* src, vec2 src_origin, kernal ker, vec2 src_size) {
	unsigned char index = ker.size.r / 2;// 3/2 = 1
	unsigned char value = 0;
	double temp = 0;
	double src_val = 0;
	double ker_val = 0;
	for (int x = -index; x <= index; x++) {
		for (int y = -index; y <= index; y++) {
			src_val = *(src + (src_origin.r + x) * src_size.c + (src_origin.c + y));
			ker_val = *(ker.element + (x + index) * ker.size.c + (y + index));
			//printf("%d,%d :", x, y);
			//printf("%f,%f\n", src_val, ker_val);
			temp += src_val * ker_val;
		}
	}
	//printf("%f\n", temp);
	if (temp < 0) {
		temp = 0;
	}

	else if (temp > 255) {
		temp = 255;
	}
	value = round(temp);
	return value;

	//printf("%d\n", value);
}