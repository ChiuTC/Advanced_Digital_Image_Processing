#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "HW2_1_1.h"


using namespace std;
class HW2_1_2{
private:
	
public:
	//1.(2)
	AssessmentMethod assMethod;
	void task(int row, int col, unsigned char* lena256, unsigned char* lena256_blur_50, unsigned char* lena256_blur_100) {
		float mse_50 = assMethod.MSE(row, col, lena256, lena256_blur_50);
		float mse_100 = assMethod.MSE(row, col, lena256, lena256_blur_100);
		printf("MSE of lena256 with parameter 50 = %.3f\nMSE of lena256 with parameter 100 = %.3f\n", mse_50, mse_100);
		float psnr_50 = assMethod.PSNR(mse_50);
		float psnr_100 = assMethod.PSNR(mse_100);
		printf("PSNR of lena256 with parameter 50 = % .3f\nPSNR of lena256 with parameter 100 = % .3f\n", psnr_50, psnr_100);
	}
};
