#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include <math.h>
#include "AssMethod.h"

//1.(1)

float AssMethod::MSE(int row, int col, unsigned char* ori_img, unsigned char* img) {
	float mse = 0;
	for (int i = 0; i < (row * col); i++) {
		mse += pow(*(ori_img + i) - *(img + i), 2);
	}
	mse /= (row * col);
	return mse;
}
float AssMethod::PSNR(float mse) {
	int max_i = 255;//unsigned char = 8 bit
	float psnr = 10 * log10(pow(max_i, 2) / mse);
	return psnr;
}