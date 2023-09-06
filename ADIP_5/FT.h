#pragma once
#include <complex>
#include <vector>
#include <math.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/utils/logger.hpp>
using namespace std;
using namespace cv;
typedef complex<double> complex_t;
#include "Type.h"
struct dftData {
	Mat complexI;
	Mat D;
};
class FT {
private:
	complex_t calExp(double u, double r, double m, bool forward);
public:
	void center(Mat magI);
	Mat toLogScale(Mat complexI, Mat plane[2]);
	complex_t DFT(unsigned char* src , double row, double col, double u, double v);
	complex_t IDFT(vector<complex_t> src, double row, double col, double r, double c);
	double C(double row, double col, double u, double v);
	double DCT(unsigned char* src, double row, double col, double u, double v);
	double IDCT(unsigned char* src, double row, double col, double u, double v);
	unsigned char doConvolution(unsigned char* src, vec2 src_origin, kernal ker, vec2 src_size);
};