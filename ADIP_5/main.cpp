#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "AssMethod.h"
#include "ImageIO.cpp"
#include "HW5_1.cpp"
#include "HW5_2.cpp"
#include "HW5_3.cpp"
#include "HW5_4.cpp"
#include <time.h>
using namespace std;
using namespace cv;
ImageIO imageIo;
HW5_1 hw5_1;
HW5_2 hw5_2;
HW5_3 hw5_3;
HW5_4 hw5_4;
AssMethod assMethod;
int main() {
	cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_SILENT);
	double START, END;
	FILE* input_img{};
	FILE* output_img{};
	unsigned char* rhombus_256 = new unsigned char[256 * 256 * sizeof(unsigned char)];
	unsigned char* rhombus_256_dft = new unsigned char[256 * 256 * sizeof(unsigned char)];
	unsigned char* rhombus_256_idft = new unsigned char[256 * 256 * sizeof(unsigned char)];
	unsigned char* rhombus_256_dct = new unsigned char[256 * 256 * sizeof(unsigned char)];

	unsigned char* sine_128 = new unsigned char[128 * 128 * sizeof(unsigned char)];
	unsigned char* sine_128_dft = new unsigned char[128 * 128 * sizeof(unsigned char)];
	unsigned char* sine_128_idft = new unsigned char[128 * 128 * sizeof(unsigned char)];
	unsigned char* sine_128_dct = new unsigned char[128 * 128 * sizeof(unsigned char)];

	unsigned char* lena_256 = new unsigned char[256 * 256 * sizeof(unsigned char)];
	unsigned char* lena_256_dft = new unsigned char[256 * 256 * sizeof(unsigned char)];
	unsigned char* lena_256_idft = new unsigned char[256 * 256 * sizeof(unsigned char)];
	unsigned char* lena_256_dct = new unsigned char[256 * 256 * sizeof(unsigned char)];

	unsigned char* raccoon_512 = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* raccoon_512_dft = new unsigned char[512 * 512 * sizeof(unsigned char)];

	unsigned char* owl_blur_512 = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* owl_blur_512_dft = new unsigned char[512 * 512 * sizeof(unsigned char)];

	unsigned char* mark_512 = new unsigned char[512 * 512 * sizeof(unsigned char)];

	unsigned char* house_512 = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* house_512_histEqu = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* house_512_localHistEqu = new unsigned char[512 * 512 * sizeof(unsigned char)];

	rhombus_256 = imageIo.input("./HW5_images_file/rhombus_256.raw", 256 * 256, 256 * 256 * sizeof(unsigned char), input_img);
	sine_128 = imageIo.input("./HW5_images_file/sine_128.raw", 128 * 128, 128 * 128 * sizeof(unsigned char), input_img);
	lena_256 = imageIo.input("./HW5_images_file/lena_256.raw", 256 * 256, 256 * 256 * sizeof(unsigned char), input_img);
	raccoon_512 = imageIo.input("./HW5_images_file/raccoon_512.raw", 512 * 512, 512 * 512 * sizeof(unsigned char), input_img);
	owl_blur_512 = imageIo.input("./HW5_images_file/owl_blur_512.raw", 512 * 512, 512 * 512 * sizeof(unsigned char), input_img);
	mark_512 = imageIo.input("./HW5_images_file/mark_512.raw", 512 * 512, 512 * 512 * sizeof(unsigned char), input_img);
	house_512 = imageIo.input("./HW5_images_file/house512.raw", 512 * 512, 512 * 512 * sizeof(unsigned char), input_img);

	Mat rhombus_256_mat = Mat::zeros(256, 256, CV_8UC1);
	Mat sine_128_mat = Mat::zeros(128, 128, CV_8UC1);
	Mat lena_256_mat = Mat::zeros(256, 256, CV_8UC1);
	Mat raccoon_512_mat = Mat::zeros(512, 512, CV_8UC1);
	Mat owl_blur_512_mat = Mat::zeros(512, 512, CV_8UC1);
	Mat mark_512_mat = Mat::zeros(512, 512, CV_8UC1);
	Mat house_512_mat = Mat::zeros(512, 512, CV_8UC1);

	vector<complex_t> sine_128_complexI;
	vector<complex_t> lena_256_complexI;
	vector<complex_t> rhombus_256_complexI;
	dftData rhombus_256_mat_dft;
	dftData sine_128_mat_dft;
	dftData lena_256_mat_dft;
	Mat rhombus_256_mat_idft;
	Mat sine_128_mat_idft;
	Mat lena_256_mat_idft;
	vec2 src_size(512, 512);
	vec2 ker_size(101, 101);
	double mse = 0;
	printf("1: 5_1_1 answer\n2: 5_1_2 answer\n3: 5_1_3 answer\n4: 5_1_4 answer\n5: 5_1_5 answer\n6: 5_2_1 answer\n7: 5_2_2 answer\n8: 5_3_1 answer\n9: 5_3_2 answer\n10: 5_4 answer\n");
	printf("Enter the question number to select output result or press -1 to exit\n");
	int input = 0;
	while (input != -1) {

		scanf("%d", &input);

		switch (input) {
		case -1:

			break;
		case 1:

			//hw5_1_1
			sine_128_complexI = hw5_1.doMyDFT(sine_128, sine_128_dft, 128, 128);
			imageIo.output("sine_128_mydft.raw", 128 * 128, output_img, sine_128_dft);

			lena_256_complexI = hw5_1.doMyDFT(lena_256, lena_256_dft, 256, 256);
			imageIo.output("lena_256_mydft.raw", 256 * 256, output_img, lena_256_dft);

			rhombus_256_complexI = hw5_1.doMyDFT(rhombus_256, rhombus_256_dft, 256, 256);
			imageIo.output("rhombus_256_mydft.raw", 256 * 256, output_img, rhombus_256_dft);
			printf("5_1_1 answer\n");
			break;
		case 2:
			//hw5_1_2
			//opencv
			START = clock();
			rhombus_256_mat_dft = hw5_1.doDFT(rhombus_256_mat, rhombus_256, 256, 256, 0, "rhombus_256_mat_dft.png");
			END = clock();
			printf("rhombus_256_mat_dft 執行所花費時間:%f\n", double(clock() / CLOCKS_PER_SEC));
			printf("rhombus_256_mat_dft 進行運算所花費時間:%f\n\n", (END - START) / CLOCKS_PER_SEC);

			START = clock();
			sine_128_mat_dft = hw5_1.doDFT(sine_128_mat, sine_128, 128, 128, 0, "sine_128_mat_dft.png");
			END = clock();
			printf("sine_128_mat_dft 執行所花費時間:%f\n", double(clock() / CLOCKS_PER_SEC));
			printf("sine_128_mat_dft 進行運算所花費時間:%f\n\n", (END - START) / CLOCKS_PER_SEC);

			START = clock();
			lena_256_mat_dft = hw5_1.doDFT(lena_256_mat, lena_256, 256, 256, 0, "lena_256_mat_dft.png");
			END = clock();
			printf("lena_256_mat_dft 執行所花費時間:%f\n", double(clock() / CLOCKS_PER_SEC));
			printf("lena_256_mat_dft 進行運算所花費時間:%f\n\n", (END - START) / CLOCKS_PER_SEC);
			//my method
			START = clock();
			rhombus_256_complexI = hw5_1.doMyDFT(rhombus_256, rhombus_256_dft, 256, 256);
			END = clock();
			printf("rhombus_256_dft 執行所花費時間:%f\n", double(clock() / CLOCKS_PER_SEC));
			printf("rhombus_256_dft 進行運算所花費時間:%f\n\n", (END - START) / CLOCKS_PER_SEC);
			imageIo.output("rhombus_256_mydft.raw", 256 * 256, output_img, rhombus_256_dft);

			START = clock();
			sine_128_complexI = hw5_1.doMyDFT(sine_128, sine_128_dft, 128, 128);
			END = clock();
			printf("sine_128_dft 執行所花費時間:%f\n", double(clock() / CLOCKS_PER_SEC));
			printf("sine_128_dft 進行運算所花費時間:%f\n\n", (END - START) / CLOCKS_PER_SEC);
			imageIo.output("sine_128_mydft.raw", 128 * 128, output_img, sine_128_dft);

			START = clock();
			lena_256_complexI = hw5_1.doMyDFT(lena_256, lena_256_dft, 256, 256);
			END = clock();
			printf("lena_256_dft 執行所花費時間:%f\n", double(clock() / CLOCKS_PER_SEC));
			printf("lena_256_dft 進行運算所花費時間:%f\n\n", (END - START) / CLOCKS_PER_SEC);
			imageIo.output("lena_256_mydft.raw", 256 * 256, output_img, lena_256_dft);

			//dftData raccoon_512_mat_dft_mag = hw5_1.doDFT(raccoon_512_mat, raccoon_512, 512, 512, 0, "raccoon_512_mat_dft.png");
			printf("5_1_2 answer\n");
			break;
		case 3:
			//hw5_1_3
			sine_128_complexI = hw5_1.doMyDFT(sine_128, sine_128_dft, 128, 128);
			hw5_1.doMyIDFT(sine_128_complexI, sine_128_idft, 128, 128);
			imageIo.output("sine_128_myidft.raw", 128 * 128, output_img, sine_128_idft);
			mse = assMethod.MSE(128, 128, sine_128, sine_128_idft);
			printf("mse of sine_128:%f\n", mse);

			lena_256_complexI = hw5_1.doMyDFT(lena_256, lena_256_dft, 256, 256);
			hw5_1.doMyIDFT(lena_256_complexI, lena_256_idft, 256, 256);
			imageIo.output("lena_256_myidft.raw", 256 * 256, output_img, lena_256_idft);
			mse = assMethod.MSE(256, 256, lena_256, lena_256_idft);
			printf("mse of lena_256:%f\n", mse);

			rhombus_256_complexI = hw5_1.doMyDFT(rhombus_256, rhombus_256_dft, 256, 256);
			hw5_1.doMyIDFT(rhombus_256_complexI, rhombus_256_idft, 256, 256);
			imageIo.output("rhombus_256_myidft.raw", 256 * 256, output_img, rhombus_256_idft);
			mse = assMethod.MSE(256, 256, rhombus_256, rhombus_256_idft);
			printf("mse of rhombus_256:%f\n", mse);
			printf("5_1_3 answer\n");
			break;
		case 4:
			//hw5_1_4
			rhombus_256_mat_dft = hw5_1.doDFT(rhombus_256_mat, rhombus_256, 256, 256, 0, "rhombus_256_mat_dft.png");
			sine_128_mat_dft = hw5_1.doDFT(sine_128_mat, sine_128, 128, 128, 0, "sine_128_mat_dft.png");
			lena_256_mat_dft = hw5_1.doDFT(lena_256_mat, lena_256, 256, 256, 0, "lena_256_mat_dft.png");

			START = clock();
			rhombus_256_mat_idft = hw5_1.doIDFT(rhombus_256_mat_dft.complexI, rhombus_256, 256, 256, "rhombus_256_mat_idft.png");
			END = clock();
			printf("rhombus_256_mat_idft 執行所花費時間:%f\n", double(clock() / CLOCKS_PER_SEC));
			printf("rhombus_256_mat_idft 進行運算所花費時間:%f\n\n", (END - START) / CLOCKS_PER_SEC);

			START = clock();
			sine_128_mat_idft = hw5_1.doIDFT(sine_128_mat_dft.complexI, sine_128, 128, 128, "sine_128_mat_idft.png");
			END = clock();
			printf("sine_128_mat_idft 執行所花費時間:%f\n", double(clock() / CLOCKS_PER_SEC));
			printf("sine_128_mat_idft 進行運算所花費時間:%f\n\n", (END - START) / CLOCKS_PER_SEC);

			START = clock();
			lena_256_mat_idft = hw5_1.doIDFT(lena_256_mat_dft.complexI, lena_256, 256, 256, "lena_256_mat_idft.png");
			END = clock();
			printf("lena_256_mat_idft 執行所花費時間:%f\n", double(clock() / CLOCKS_PER_SEC));
			printf("lena_256_mat_idft 進行運算所花費時間:%f\n\n", (END - START) / CLOCKS_PER_SEC);

			rhombus_256_complexI = hw5_1.doMyDFT(rhombus_256, rhombus_256_dft, 256, 256);
			imageIo.output("rhombus_256_mydft.raw", 256 * 256, output_img, rhombus_256_dft);
			START = clock();
			hw5_1.doMyIDFT(rhombus_256_complexI, rhombus_256_idft, 256, 256);
			END = clock();
			printf("rhombus_256_idft 執行所花費時間:%f\n", double(clock() / CLOCKS_PER_SEC));
			printf("rhombus_256_idft 進行運算所花費時間:%f\n\n", (END - START) / CLOCKS_PER_SEC);
			imageIo.output("rhombus_256_myidft.raw", 256 * 256, output_img, rhombus_256_idft);

			sine_128_complexI = hw5_1.doMyDFT(sine_128, sine_128_dft, 128, 128);
			imageIo.output("sine_128_mydft.raw", 128 * 128, output_img, sine_128_dft);
			START = clock();
			hw5_1.doMyIDFT(sine_128_complexI, sine_128_idft, 128, 128);
			END = clock();
			printf("sine_128_idft 執行所花費時間:%f\n", double(clock() / CLOCKS_PER_SEC));
			printf("sine_128_idft 進行運算所花費時間:%f\n\n", (END - START) / CLOCKS_PER_SEC);
			imageIo.output("sine_128_myidft.raw", 128 * 128, output_img, sine_128_idft);

			lena_256_complexI = hw5_1.doMyDFT(lena_256, lena_256_dft, 256, 256);
			imageIo.output("lena_256_mydft.raw", 256 * 256, output_img, lena_256_dft);
			START = clock();
			hw5_1.doMyIDFT(lena_256_complexI, lena_256_idft, 256, 256);
			END = clock();
			printf("lena_256_idft 執行所花費時間:%f\n", double(clock() / CLOCKS_PER_SEC));
			printf("lena_256_idft 進行運算所花費時間:%f\n\n", (END - START) / CLOCKS_PER_SEC);
			imageIo.output("lena_256_myidft.raw", 256 * 256, output_img, lena_256_idft);

			printf("5_1_4 answer\n");
			break;
		case 5:
			//hw5_1_5
			hw5_1.doMyDCT(sine_128, sine_128_dct, 128, 128);
			imageIo.output("sine_128_mydct.raw", 128 * 128, output_img, sine_128_dct);

			hw5_1.doMyDCT(lena_256, lena_256_dct, 256, 256);
			imageIo.output("lena_256_mydct.raw", 256 * 256, output_img, lena_256_dct);

			hw5_1.doMyDCT(rhombus_256, rhombus_256_dct, 256, 256);
			imageIo.output("rhombus_256_mydct.raw", 256 * 256, output_img, rhombus_256_dct);

			printf("5_1_5 answer\n");
			break;
		case 6:
			//hw5_2_1
			hw5_2.ButterworthLPF(raccoon_512_mat, raccoon_512, 5, 1, 512.0f, 512.0f, "raccoon_512_LPF_5_1.png", "raccoon_512_LPF_mag_5_1.png");
			hw5_2.ButterworthLPF(raccoon_512_mat, raccoon_512, 5, 2, 512.0f, 512.0f, "raccoon_512_LPF_5_2.png", "raccoon_512_LPF_mag_5_2.png");
			hw5_2.ButterworthLPF(raccoon_512_mat, raccoon_512, 5, 3, 512, 512, "raccoon_512_LPF_5_3.png", "raccoon_512_LPF_mag_5_3.png");
			hw5_2.ButterworthLPF(raccoon_512_mat, raccoon_512, 20, 1, 512, 512, "raccoon_512_LPF_20_1.png", "raccoon_512_LPF_mag_20_1.png");
			hw5_2.ButterworthLPF(raccoon_512_mat, raccoon_512, 20, 2, 512, 512, "raccoon_512_LPF_20_2.png", "raccoon_512_LPF_mag_20_2.png");
			hw5_2.ButterworthLPF(raccoon_512_mat, raccoon_512, 20, 3, 512, 512, "raccoon_512_LPF_20_3.png", "raccoon_512_LPF_mag_20_3.png");
			hw5_2.ButterworthLPF(raccoon_512_mat, raccoon_512, 50, 1, 512, 512, "raccoon_512_LPF_50_1.png", "raccoon_512_LPF_mag_50_1.png");
			hw5_2.ButterworthLPF(raccoon_512_mat, raccoon_512, 50, 2, 512, 512, "raccoon_512_LPF_50_2.png", "raccoon_512_LPF_mag_50_2.png");
			hw5_2.ButterworthLPF(raccoon_512_mat, raccoon_512, 50, 3, 512, 512, "raccoon_512_LPF_50_3.png", "raccoon_512_LPF_mag_50_3.png");

			hw5_2.ButterworthHPF(raccoon_512_mat, raccoon_512, 5, 1, 512, 512, "raccoon_512_HPF_5_1.png", "raccoon_512_HPF_mag_5_1.png");
			hw5_2.ButterworthHPF(raccoon_512_mat, raccoon_512, 5, 2, 512, 512, "raccoon_512_HPF_5_2.png", "raccoon_512_HPF_mag_5_2.png");
			hw5_2.ButterworthHPF(raccoon_512_mat, raccoon_512, 5, 3, 512, 512, "raccoon_512_HPF_5_3.png", "raccoon_512_HPF_mag_5_3.png");
			hw5_2.ButterworthHPF(raccoon_512_mat, raccoon_512, 20, 1, 512, 512, "raccoon_512_HPF_20_1.png", "raccoon_512_HPF_mag_20_1.png");
			hw5_2.ButterworthHPF(raccoon_512_mat, raccoon_512, 20, 2, 512, 512, "raccoon_512_HPF_20_2.png", "raccoon_512_HPF_mag_20_2.png");
			hw5_2.ButterworthHPF(raccoon_512_mat, raccoon_512, 20, 3, 512, 512, "raccoon_512_HPF_20_3.png", "raccoon_512_HPF_mag_20_3.png");
			hw5_2.ButterworthHPF(raccoon_512_mat, raccoon_512, 50, 1, 512, 512, "raccoon_512_HPF_50_1.png", "raccoon_512_HPF_mag_50_1.png");
			hw5_2.ButterworthHPF(raccoon_512_mat, raccoon_512, 50, 2, 512, 512, "raccoon_512_HPF_50_2.png", "raccoon_512_HPF_mag_50_2.png");
			hw5_2.ButterworthHPF(raccoon_512_mat, raccoon_512, 50, 3, 512, 512, "raccoon_512_HPF_50_3.png", "raccoon_512_HPF_mag_50_3.png");

			printf("5_2_1 answer\n");
			break;
		case 7:
			//hw5_2_2
			hw5_2.HFEmphasisFilter(owl_blur_512_mat, owl_blur_512, 50, 3, 512, 512, "owl_blur_512_HFEmphasis.png");
			printf("5_2_2 answer\n");
			break;
		case 8:
			//hw5_3_1
			hw5_3.methodI(raccoon_512_mat, raccoon_512, mark_512_mat, mark_512, 512, 512, "methodI_image.png");
			printf("5_3_1 answer\n");
			break;
		case 9:
			//hw5_3_2
			hw5_3.methodII(raccoon_512_mat, raccoon_512, mark_512_mat, mark_512, 512, 512, "methodII_image.png");
			printf("5_3_2 answer\n");
			break;
		case 10:
			//hw5_4
			//D0 c rH rL
			hw5_4.HomomorphicFilter(house_512_mat, house_512, 50, 100, 1.6, 0.8, 512, 512, "house_HomomorphicFilter.png");
			hw5_4.HistgramEqu(house_512, house_512_histEqu, 512, 512);
			imageIo.output("house_512_HistgramEqu.raw", 512 * 512, output_img, house_512_histEqu);
			hw5_4.LocalHistEqu(house_512, house_512_localHistEqu, src_size, ker_size);
			imageIo.output("house_512_LocalHistgramEqu.raw", 512 * 512, output_img, house_512_localHistEqu);
			printf("5_4 answer\n");
			break;
		}
	}
}