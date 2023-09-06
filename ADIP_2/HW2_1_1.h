#pragma once
class AssessmentMethod {
private:

public:
	//1.(1)
	float MSE(int row, int col, unsigned char* ori_img, unsigned char* img);
	float PSNR(float mse);
};