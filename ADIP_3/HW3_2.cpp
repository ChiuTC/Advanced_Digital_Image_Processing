#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>

using namespace std;

class HW3_2 {
private:
public:
	unsigned char* powerLow(unsigned char* src, unsigned char* dst, float gamma) {
		float constant = 1;
		int val = 0;
		for (int r = 0; r < 600; r++) {
			for (int c = 0; c < 800; c++) {
				val = constant * pow(*(src + r * 800 + c), gamma);
				if (val > 255) {
					val = 255;
				}
				else if (val < 0) {
					val = 0;
				}
				*(dst + r * 800 + c) = val;
				
			}
		}
		return dst;
	}
	unsigned char* powerLowNormalize(unsigned char* src, unsigned char* dst, float gamma) {
		float constant = 1;
		float val = 0;
		for (int r = 0; r < 600; r++) {
			for (int c = 0; c < 800; c++) {
				val = constant * pow(*(src + r * 800 + c)/255.0f, gamma);
				val *= 255;
				if (val > 255) {
					val = 255;
				}
				else if (val < 0) {
					val = 0;
				}
				*(dst + r * 800 + c) = int(val);
			}
		}
		return dst;
	}
	unsigned char* piecewiseLinearD(unsigned char* src, unsigned char* dst) {
		int val = 0;
		float x1 = 100;
		float y1 = 220;
		float b1 = 0;
		float x2 = 255;
		float y2 = 255;
		float b2 = 197.41;
		float m1 = (y1 - 0) / (x1 - 0);
		float m2 = (y2 - y1) / (x2 - x1);
		for (int r = 0; r < 600; r++) {
			for (int c = 0; c < 800; c++) {
				if (*(src + r * 800 + c) <= 100) {
					val = m1 * (*(src + r * 800 + c)) + b1;
					if (val > 255) {
						val = 255;
					}
					else if (val < 0) {
						val = 0;
					}
					*(dst + r * 800 + c) = val;
				}
				else {
					val = m2 * (*(src + r * 800 + c)) + b2;
					if (val > 255) {
						val = 255;
					}
					else if (val < 0) {
						val = 0;
					}
					*(dst + r * 800 + c) = val;
				}
			}
		}
		return dst;
	}
	unsigned char* piecewiseLinearB(unsigned char* src, unsigned char* dst) {
		int val = 0;
		float x1 = 160;
		float y1 = 100;
		float b1 = 0;
		float x2 = 255;
		float y2 = 255;
		float b2 = -161;
		float m1 = (y1 - 0) / (x1 - 0);
		float m2 = (y2 - y1) / (x2 - x1);
		for (int r = 0; r < 600; r++) {
			for (int c = 0; c < 800; c++) {
				if (*(src + r * 800 + c) <= 160) {
					val = m1 * (*(src + r * 800 + c)) + b1;
					if (val > 255) {
						val = 255;
					}
					else if (val < 0) {
						val = 0;
					}
					*(dst + r * 800 + c) = val;
				}
				else {
					val = m2 * (*(src + r * 800 + c)) + b2;
					if (val > 255) {
						val = 255;
					}
					else if (val < 0) {
						val = 0;
					}
					*(dst + r * 800 + c) = val;
				}
			}
		}
		return dst;
	}
	unsigned char* piecewiseLinearH(unsigned char* src, unsigned char* dst) {
		int val = 0;
		float x1 = 160;
		float y1 = 130;
		float b1 = 0;
		float x2 = 255;
		float y2 = 255;
		float b2 = -80.52;
		float m1 = (y1 - 0) / (x1 - 0);
		float m2 = (y2 - y1) / (x2 - x1);
		for (int r = 0; r < 600; r++) {
			for (int c = 0; c < 800; c++) {
				if (*(src + r * 800 + c) <= 160) {
					val = m1 * (*(src + r * 800 + c)) + b1;
					if (val > 255) {
						val = 255;
					}
					else if (val < 0) {
						val = 0;
					}
					*(dst + r * 800 + c) = val;
				}
				else {
					val = m2 * (*(src + r * 800 + c)) + b2;
					if (val > 255) {
						val = 255;
					}
					else if (val < 0) {
						val = 0;
					}
					*(dst + r * 800 + c) = val;
				}
			}
		}
		return dst;
	}
};