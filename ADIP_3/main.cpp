#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "ImageIO.cpp"
#include <cstdlib>
#include <stdio.h>
#include "Resize.cpp"
#include "HW3_1.cpp"
#include "HW3_2.cpp"
#include "HW3_3.cpp"
#include "type.h"
#include <opencv2/core/utils/logger.hpp>
using namespace std;
ImageIO imageIo;
Resize resize;
HW3_1 hw3_1;
HW3_2 hw3_2;
HW3_3 hw3_3;

int main() {
	cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_SILENT);
	FILE* file{};
	
	unsigned char* cat_512 = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* cat_512_equal = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* cat_512_match_catch_cat = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* cat_512_match_traffic = new unsigned char[512 * 512 * sizeof(unsigned char)];

	unsigned char* JackieChen = new unsigned char[621 * 466 * sizeof(unsigned char)];

	unsigned char* cat_512_7 = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* cat_512_6 = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* cat_512_5 = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* cat_512_4 = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* cat_512_3 = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* cat_512_2 = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* cat_512_1 = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* cat_512_0 = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* JackieChen_512 = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* JackieChen_512_binary = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* cat_512_synthesize = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* cat_512_synthesize_0 = new unsigned char[512 * 512 * sizeof(unsigned char)];

	unsigned char* meerkat_dark = new unsigned char[800 * 600 * sizeof(unsigned char)];
	unsigned char* meerkat_dark_1_17 = new unsigned char[800 * 600 * sizeof(unsigned char)];
	unsigned char* meerkat_dark_1_25 = new unsigned char[800 * 600 * sizeof(unsigned char)];
	unsigned char* meerkat_dark_piecewise_linear = new unsigned char[800 * 600 * sizeof(unsigned char)];
	unsigned char* meerkat_dark_equal = new unsigned char[800 * 600 * sizeof(unsigned char)];

	unsigned char* meerkat_bright = new unsigned char[800 * 600 * sizeof(unsigned char)];
	unsigned char* meerkat_bright_2_5 = new unsigned char[800 * 600 * sizeof(unsigned char)];
	unsigned char* meerkat_bright_3_5 = new unsigned char[800 * 600 * sizeof(unsigned char)];
	unsigned char* meerkat_bright_piecewise_linear = new unsigned char[800 * 600 * sizeof(unsigned char)];
	unsigned char* meerkat_bright_equal = new unsigned char[800 * 600 * sizeof(unsigned char)];

	unsigned char* meerkat_high_contrast = new unsigned char[800 * 600 * sizeof(unsigned char)];
	unsigned char* meerkat_high_contrast_1_04 = new unsigned char[800 * 600 * sizeof(unsigned char)];
	unsigned char* meerkat_high_contrast_0_97 = new unsigned char[800 * 600 * sizeof(unsigned char)];
	unsigned char* meerkat_high_contrast_piecewise_linear = new unsigned char[800 * 600 * sizeof(unsigned char)];
	unsigned char* meerkat_high_contrast_equal = new unsigned char[800 * 600 * sizeof(unsigned char)];
	unsigned char* catch_300x168 = new unsigned char[300 * 168 * sizeof(unsigned char)];
	unsigned char* catch_300x168_equal = new unsigned char[300 * 168 * sizeof(unsigned char)];

	unsigned char* traffic_970x646 = new unsigned char[970 * 646 * sizeof(unsigned char)];
	unsigned char* traffic_970x646_equal = new unsigned char[970 * 646 * sizeof(unsigned char)];

	cat_512 = imageIo.input("./HW3_images_file/cat_512.raw", 512 * 512, 512 * 512 * sizeof(unsigned char), file);
	JackieChen = imageIo.input("./HW3_images_file/JackieChen.raw", 800 * 600, 800 * 600 * sizeof(unsigned char), file);
	meerkat_dark = imageIo.input("./HW3_images_file/meerkat_dark_800x600.raw", 800 * 600, 800 * 600 * sizeof(unsigned char), file);
	meerkat_bright = imageIo.input("./HW3_images_file/meerkat_bright_800x600.raw", 800 * 600, 800 * 600 * sizeof(unsigned char), file);
	meerkat_high_contrast = imageIo.input("./HW3_images_file/meerkat_high_contrast_800x600.raw", 800 * 600, 800 * 600 * sizeof(unsigned char), file);
	catch_300x168 = imageIo.input("./HW3_images_file/catch_300x168.raw", 300 * 168, 300 * 168 * sizeof(unsigned char), file);
	traffic_970x646 = imageIo.input("./HW3_images_file/traffic_970x646.raw", 970 * 646, 970 * 646 * sizeof(unsigned char), file);
	printf("1: 3_1 answer\n2: 3_2_1 answer\n3: 3_2_2 answer\n4: 3_3_1 answer\n5: 3_3_2 answer\n6: 3_3_3 answer\n");
	printf("Enter the question number to select output result or press -1 to exit\n");
	int input = 0;
	while (input != -1) {

		scanf("%d", &input);

		switch (input) {
		case -1:
			break;
		case 1:
			printf("3_1 answer\n");
			//HW3_1
			hw3_1.bitPlaneSlicing(cat_512, cat_512_7, 128);
			hw3_1.bitPlaneSlicing(cat_512, cat_512_6, 64);
			hw3_1.bitPlaneSlicing(cat_512, cat_512_5, 32);
			hw3_1.bitPlaneSlicing(cat_512, cat_512_4, 16);
			hw3_1.bitPlaneSlicing(cat_512, cat_512_3, 8);
			hw3_1.bitPlaneSlicing(cat_512, cat_512_2, 4);
			hw3_1.bitPlaneSlicing(cat_512, cat_512_1, 2);
			hw3_1.bitPlaneSlicing(cat_512, cat_512_0, 1);
			imageIo.output("cat_512_7.raw", 512 * 512, file, cat_512_7);
			imageIo.output("cat_512_6.raw", 512 * 512, file, cat_512_6);
			imageIo.output("cat_512_5.raw", 512 * 512, file, cat_512_5);
			imageIo.output("cat_512_4.raw", 512 * 512, file, cat_512_4);
			imageIo.output("cat_512_3.raw", 512 * 512, file, cat_512_3);
			imageIo.output("cat_512_2.raw", 512 * 512, file, cat_512_2);
			imageIo.output("cat_512_1.raw", 512 * 512, file, cat_512_1);
			imageIo.output("cat_512_0.raw", 512 * 512, file, cat_512_0);
			JackieChen_512 = resize.bilinear(621 * 466, 512 * 512, JackieChen);
			hw3_1.binary(JackieChen_512, JackieChen_512_binary);
			hw3_1.bitPlaneSynthesize(cat_512_0, cat_512_1, cat_512_2, cat_512_3, cat_512_4, cat_512_5, cat_512_6, cat_512_7, cat_512_synthesize);
			imageIo.output("cat_512_synthesize.raw", 512 * 512, file, cat_512_synthesize);

			hw3_1.bitPlaneSynthesize(JackieChen_512_binary, cat_512_1, cat_512_2, cat_512_3, cat_512_4, cat_512_5, cat_512_6, cat_512_7, cat_512_synthesize);
			hw3_1.bitPlaneSlicing(cat_512_synthesize, cat_512_synthesize_0, 1);

			imageIo.output("JackieChen_512.raw", 512 * 512, file, JackieChen_512);
			imageIo.output("JackieChen_512_binary.raw", 512 * 512, file, JackieChen_512_binary);
			imageIo.output("cat_512_synthesize_with_JackieChen.raw", 512 * 512, file, cat_512_synthesize);
			imageIo.output("LSB_bit_plane.raw", 512 * 512, file, cat_512_synthesize_0);
			delete[] cat_512_7;
			delete[] cat_512_6;
			delete[] cat_512_5;
			delete[] cat_512_4;
			delete[] cat_512_3;
			delete[] cat_512_2;
			delete[] cat_512_1;
			delete[] cat_512_0;
			delete[] JackieChen_512;
			delete[] JackieChen_512_binary;
			delete[] cat_512_synthesize;
			delete[] cat_512_synthesize_0;
			break;
		case 2:
			printf("3_2_1 answer\n");
			////HW3_2_1
			hw3_2.powerLow(meerkat_dark, meerkat_dark_1_17, 1.17);
			hw3_2.powerLow(meerkat_dark, meerkat_dark_1_25, 1.25);
			imageIo.output("meerkat_dark_1_17.raw", 800 * 600, file, meerkat_dark_1_17);
			imageIo.output("meerkat_dark_1_25.raw", 800 * 600, file, meerkat_dark_1_25);
			hw3_2.powerLowNormalize(meerkat_bright, meerkat_bright_2_5, 2.5);
			hw3_2.powerLowNormalize(meerkat_bright, meerkat_bright_3_5, 3.5);
			imageIo.output("meerkat_bright_2_5.raw", 800 * 600, file, meerkat_bright_2_5);
			imageIo.output("meerkat_bright_3_5.raw", 800 * 600, file, meerkat_bright_3_5);
			hw3_2.powerLow(meerkat_high_contrast, meerkat_high_contrast_1_04, 1.04);
			hw3_2.powerLow(meerkat_high_contrast, meerkat_high_contrast_0_97, 0.97);
			imageIo.output("meerkat_high_contrast_1_04.raw", 800 * 600, file, meerkat_high_contrast_1_04);
			imageIo.output("meerkat_high_contrast_0_97.raw", 800 * 600, file, meerkat_high_contrast_0_97);
			delete[] meerkat_dark_1_17;
			delete[] meerkat_dark_1_25;
			delete[] meerkat_bright_2_5;
			delete[] meerkat_bright_3_5;
			delete[] meerkat_high_contrast_1_04;
			delete[] meerkat_high_contrast_0_97;
			break;
		case 3:
			printf("3_2_2 answer\n");
			//HW3_2_2
			hw3_2.piecewiseLinearD(meerkat_dark, meerkat_dark_piecewise_linear);
			imageIo.output("meerkat_dark_piecewise_linear.raw", 800 * 600, file, meerkat_dark_piecewise_linear);
			hw3_2.piecewiseLinearB(meerkat_bright, meerkat_bright_piecewise_linear);
			imageIo.output("meerkat_bright_piecewise_linear.raw", 800 * 600, file, meerkat_bright_piecewise_linear);
			hw3_2.piecewiseLinearH(meerkat_high_contrast, meerkat_high_contrast_piecewise_linear);
			imageIo.output("meerkat_high_contrast_piecewise_linear.raw", 800 * 600, file, meerkat_high_contrast_piecewise_linear);
			delete[] meerkat_dark_piecewise_linear;
			delete[] meerkat_bright_piecewise_linear;
			delete[] meerkat_high_contrast_piecewise_linear;
			break;
		case 4:
			printf("3_3_1 answer\n");
			//HW3_3_1
			histSize* histNum_D;
			histSize* histNum_B;
			histSize* histNum_H;
			histNum_D = hw3_3.calHist(meerkat_dark, 600, 800);
			histNum_B = hw3_3.calHist(meerkat_bright, 600, 800);
			histNum_H = hw3_3.calHist(meerkat_high_contrast, 600, 800);
		
			hw3_3.plotHist(histNum_D,"histogram_of_meerkat_dark.png");
			hw3_3.plotHist(histNum_B, "histogram_of_meerkat_bright.png");
			hw3_3.plotHist(histNum_H, "histogram_of_meerkat_high_contrast.png");
			delete histNum_D;
			delete histNum_B;
			delete histNum_H;
			break;
		case 5:
			printf("3_3_2 answer\n");
			//HW3_3_2
			histSize* histNum_D_2;
			histSize* histNum_B_2;
			histSize* histNum_H_2;
			histNum_D_2 = hw3_3.calHist(meerkat_dark, 600, 800);
			histNum_B_2 = hw3_3.calHist(meerkat_bright, 600, 800);
			histNum_H_2 = hw3_3.calHist(meerkat_high_contrast, 600, 800);
			hw3_3.calHistEqu(meerkat_dark, meerkat_dark_equal, histNum_D_2, 600, 800);
			imageIo.output("meerkat_dark_hist_equal.raw", 800 * 600, file, meerkat_dark_equal);
			hw3_3.calHistEqu(meerkat_bright, meerkat_bright_equal, histNum_B_2, 600, 800);
			imageIo.output("meerkat_bright_hist_equal.raw", 800 * 600, file, meerkat_bright_equal);
			hw3_3.calHistEqu(meerkat_high_contrast, meerkat_high_contrast_equal, histNum_H_2, 600, 800);
			imageIo.output("meerkat_high_contrast_hist_equal.raw", 800 * 600, file, meerkat_high_contrast_equal);

			histSize* histNum_D_E_2;
			histSize* histNum_B_E_2;
			histSize* histNum_H_E_2;
			histNum_D_E_2 = hw3_3.calHist(meerkat_dark_equal, 600, 800);
			histNum_B_E_2 = hw3_3.calHist(meerkat_bright_equal, 600, 800);
			histNum_H_E_2 = hw3_3.calHist(meerkat_high_contrast_equal, 600, 800);
			hw3_3.plotHist(histNum_D_E_2,"histogram_of meerkat_dark_equal.png");
			hw3_3.plotHist(histNum_B_E_2, "histogram_of meerkat_bright_equal.png");
			hw3_3.plotHist(histNum_H_E_2, "histogram_of meerkat_high_contrast_equal.png");
			break;
		case 6:
			printf("3_3_3 answer\n");
			//HW3_3_3
	//catch_300x168
	//traffic_970x646
			histSize* histNum_cat;
			histSize* histNum_catch_cat;
			histSize* histNum_traffic;
			histSize* histNum_cat_match_catch_cat;
			histSize* histNum_cat_match_traffic;

			histNum_cat = hw3_3.calHist(cat_512, 512, 512);
			hw3_3.calHistEqu(cat_512, cat_512_equal, histNum_cat, 512, 512);


			//imageIo.output("cat_512_equal.raw", 512 * 512, cat_512_file, cat_512_equal);

			histNum_catch_cat = hw3_3.calHist(catch_300x168, 300, 168);
			hw3_3.calHistEqu(catch_300x168, catch_300x168_equal, histNum_catch_cat, 300, 168);
			//imageIo.output("catch_300x168_equal.raw", 300 * 168, catch_300x168_file, catch_300x168_equal);

			histNum_traffic = hw3_3.calHist(traffic_970x646, 970, 646);
			hw3_3.calHistEqu(traffic_970x646, traffic_970x646_equal, histNum_traffic, 970, 646);
			//imageIo.output("traffic_970x646_equal.raw", 970 * 646, traffic_970x646_file, traffic_970x646_equal);

			hw3_3.calHistMatching(cat_512, cat_512_match_catch_cat, histNum_cat, histNum_catch_cat, 512, 512, 168, 300);
			imageIo.output("cat_512_match_catch_cat.raw", 512 * 512, file, cat_512_match_catch_cat);
			histNum_cat_match_catch_cat = hw3_3.calHist(cat_512_match_catch_cat, 512, 512);


			hw3_3.calHistMatching(cat_512, cat_512_match_traffic, histNum_cat, histNum_traffic, 512, 512, 646, 970);
			imageIo.output("cat_512_match_traffic.raw", 512 * 512, file, cat_512_match_traffic);
			histNum_cat_match_traffic = hw3_3.calHist(cat_512_match_traffic, 512, 512);

		
			//
			hw3_3.plotHist(histNum_cat, "histogram_of_cat_512.png");
			hw3_3.plotHist(histNum_traffic, "histogram_of_traffic_970x646.png");
			hw3_3.plotHist(histNum_catch_cat, "histogram_of_catch_300x168.png");
			hw3_3.plotHist(histNum_cat_match_catch_cat, "histogram_of_cat_512_match_catch_cat.png");
			hw3_3.plotHist(histNum_cat_match_traffic, "histogram_of_cat_512_match_traffic.png");
			delete[] traffic_970x646_equal;
			delete[] cat_512_equal;
			delete[] catch_300x168_equal;
			delete histNum_cat;
			delete histNum_catch_cat;
			delete histNum_traffic;
			break;
		default:
			printf("Wrong input number\n");

		}

	}
	delete[] cat_512;
	delete[] JackieChen;
	delete[] meerkat_dark;
	delete[] meerkat_bright;
	delete[] meerkat_high_contrast;
	delete[] catch_300x168;
	delete[] traffic_970x646;
}