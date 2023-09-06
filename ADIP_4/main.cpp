#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "ImageIO.cpp"
#include "HW4_1.cpp"
#include "HW4_2.cpp"
#include "HW4_3.cpp"
#include <opencv2/core/utils/logger.hpp>
using namespace std;
ImageIO imageIo;
HW4_1 hw4_1;
HW4_2 hw4_2;
HW4_3 hw4_3;

int main() {
	cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_SILENT);
	Hist hist;
	FILE* roof_640x427_File{};
	FILE* roof_640x427_noise_File{};
	FILE* block_white_256_File{};
	FILE* chessboard_256_File{};
	FILE* baboon_256_File{};
	FILE* house_blur_noise_790x720_File{};
	FILE* tsukuba_683x512_File{};

	unsigned char* roof_640x427 = new unsigned char[640 * 427 * sizeof(unsigned char)];
	unsigned char* roof_640x427_Lapalacian_smaller_output = new unsigned char[640 * 427 * sizeof(unsigned char)];
	unsigned char* roof_640x427_Lapalacian_zero_padding = new unsigned char[640 * 427 * sizeof(unsigned char)];
	unsigned char* roof_640x427_Lapalacian_ad_hoc = new unsigned char[640 * 427 * sizeof(unsigned char)];
	unsigned char* roof_640x427_Lapalacian_replication = new unsigned char[640 * 427 * sizeof(unsigned char)];

	unsigned char* roof_640x427_noise = new unsigned char[640 * 427 * sizeof(unsigned char)];
	unsigned char* roof_640x427_noise_Lapalacian_smaller_output = new unsigned char[640 * 427 * sizeof(unsigned char)];
	unsigned char* roof_640x427_noise_Lapalacian_zero_padding = new unsigned char[640 * 427 * sizeof(unsigned char)];
	unsigned char* roof_640x427_noise_Lapalacian_ad_hoc = new unsigned char[640 * 427 * sizeof(unsigned char)];
	unsigned char* roof_640x427_noise_Lapalacian_replication = new unsigned char[640 * 427 * sizeof(unsigned char)];

	unsigned char* roof_640x427_sobel_x_replication = new unsigned char[640 * 427 * sizeof(unsigned char)];
	unsigned char* roof_640x427_sobel_y_replication = new unsigned char[640 * 427 * sizeof(unsigned char)];
	unsigned char* roof_640x427_sobel_combine_replication = new unsigned char[640 * 427 * sizeof(unsigned char)];
	unsigned char* roof_640x427_noise_sobel_x_replication = new unsigned char[640 * 427 * sizeof(unsigned char)];
	unsigned char* roof_640x427_noise_sobel_y_replication = new unsigned char[640 * 427 * sizeof(unsigned char)];
	unsigned char* roof_640x427_noise_sobel_combine_replication = new unsigned char[640 * 427 * sizeof(unsigned char)];

	unsigned char* block_white_256 = new unsigned char[256 * 256 * sizeof(unsigned char)];
	unsigned char* block_white_256_mean = new unsigned char[256 * 256 * sizeof(unsigned char)];

	unsigned char* chessboard_256 = new unsigned char[256 * 256 * sizeof(unsigned char)];
	unsigned char* chessboard_256_mean = new unsigned char[256 * 256 * sizeof(unsigned char)];

	unsigned char* baboon_256 = new unsigned char[256 * 256 * sizeof(unsigned char)];
	unsigned char* baboon_256_0_8 = new unsigned char[256 * 256 * sizeof(unsigned char)];
	unsigned char* baboon_256_1_3 = new unsigned char[256 * 256 * sizeof(unsigned char)];
	unsigned char* baboon_256_2_0 = new unsigned char[256 * 256 * sizeof(unsigned char)];
	
	unsigned char* house_blur_noise_790x720 = new unsigned char[790 * 720 * sizeof(unsigned char)];
	unsigned char* house_blur_noise_790x720_median = new unsigned char[790 * 720 * sizeof(unsigned char)];
	unsigned char* house_blur_noise_790x720_improve = new unsigned char[790 * 720 * sizeof(unsigned char)];
	unsigned char* house_blur_noise_790x720_improve_x = new unsigned char[790 * 720 * sizeof(unsigned char)];
	unsigned char* house_blur_noise_790x720_improve_y = new unsigned char[790 * 720 * sizeof(unsigned char)];
	unsigned char* house_blur_noise_790x720_improve_match = new unsigned char[790 * 720 * sizeof(unsigned char)];

	unsigned char* tsukuba_683x512 = new unsigned char[683 * 512 * sizeof(unsigned char)];
	unsigned char* tsukuba_683x512_3 = new unsigned char[683 * 512 * sizeof(unsigned char)];
	unsigned char* tsukuba_683x512_5 = new unsigned char[683 * 512 * sizeof(unsigned char)];
	unsigned char* tsukuba_683x512_7 = new unsigned char[683 * 512 * sizeof(unsigned char)];

	roof_640x427 = imageIo.input("./HW4_images_file/roof_640x427.raw", 640 * 427, 640 * 427 * sizeof(unsigned char), roof_640x427_File);
	roof_640x427_noise = imageIo.input("./HW4_images_file/roof_640x427_noise.raw", 640 * 427, 640 * 427 * sizeof(unsigned char), roof_640x427_noise_File);
	block_white_256 = imageIo.input("./HW4_images_file/block&white_256.raw", 256 * 256, 256 * 256 * sizeof(unsigned char), block_white_256_File);
	chessboard_256 = imageIo.input("./HW4_images_file/chessboard_256.raw", 256 * 256, 256 * 256 * sizeof(unsigned char), chessboard_256_File);
	baboon_256 = imageIo.input("./HW4_images_file/baboon_256.raw", 256 * 256, 256 * 256 * sizeof(unsigned char), baboon_256_File);
	house_blur_noise_790x720 = imageIo.input("./HW4_images_file/house_blur_noise_790x720.raw", 790 * 720, 790 * 720 * sizeof(unsigned char), house_blur_noise_790x720_File);
	tsukuba_683x512 = imageIo.input("./HW4_images_file/tsukuba_683x512.raw", 683 * 512, 683 * 512 * sizeof(unsigned char), tsukuba_683x512_File);
	
	vec2 roof_size(427, 640);
	vec2 block_white_size(256, 256);
	vec2 ker_size_4_2_1(5, 5);
	vec2 house_size(720, 790);vec2 house_ker_size_3(3, 3), house_ker_size_5(5, 5), house_ker_size_7(7, 7), house_ker_size_9(9, 9);
	vec2 baboon_ker_size3(3, 3), baboon_ker_size5(5, 5);vec2 baboon_size(256, 256);
	vec2 tsukuba_size(512, 683);vec2 tsu_ker_size_3(3, 3), tsu_ker_size_5(5, 5), tsu_ker_size_7(7, 7);
	double Gx = 0;
	double Gy = 0;
	double value = 0;
	histSize* histNum_r;
	histSize* histNum_m;

	printf("1: 4_1_1 answer\n2: 4_1_2 answer\n3: 4_2_1 answer\n4: 4_2_2 answer\n5: 4_2_3 answer\n6: 4_3 answer\n");
	printf("Enter the question number to select output result or press -1 to exit\n");
	int input = 0;
	while (input != -1) {

		scanf("%d", &input);

		switch (input) {
		case -1:
			break;
		case 1:
			//HW4_1_1
			printf("4_1_1 answer\n");
			
			hw4_1.HW4_1_smaller_output(roof_640x427, roof_640x427_Lapalacian_smaller_output, roof_size, 1);
			imageIo.output("roof_640x427_Lapalacian4_smaller_output.raw", 640 * 427, roof_640x427_File, roof_640x427_Lapalacian_smaller_output);
			hw4_1.HW4_1_smaller_output(roof_640x427_noise, roof_640x427_noise_Lapalacian_smaller_output, roof_size, 1);
			imageIo.output("roof_640x427_noise_Lapalacian4_smaller_output.raw", 640 * 427, roof_640x427_File, roof_640x427_noise_Lapalacian_smaller_output);

			hw4_1.HW4_1_zero_padding(roof_640x427, roof_640x427_Lapalacian_zero_padding, roof_size, 1);
			imageIo.output("roof_640x427_Lapalacian4_zero_padding.raw", 640 * 427, roof_640x427_File, roof_640x427_Lapalacian_zero_padding);
			hw4_1.HW4_1_zero_padding(roof_640x427_noise, roof_640x427_noise_Lapalacian_zero_padding, roof_size, 1);
			imageIo.output("roof_640x427_noise_Lapalacian4_zero_padding.raw", 640 * 427, roof_640x427_File, roof_640x427_noise_Lapalacian_zero_padding);

			hw4_1.HW4_1_ad_hoc(roof_640x427, roof_640x427_Lapalacian_ad_hoc, roof_size, 1);
			imageIo.output("roof_640x427_Lapalacian4_ad_hoc.raw", 640 * 427, roof_640x427_File, roof_640x427_Lapalacian_ad_hoc);
			hw4_1.HW4_1_ad_hoc(roof_640x427_noise, roof_640x427_noise_Lapalacian_ad_hoc, roof_size, 1);
			imageIo.output("roof_640x427_noise_Lapalacian4_ad_hoc.raw", 640 * 427, roof_640x427_File, roof_640x427_noise_Lapalacian_ad_hoc);

			hw4_1.HW4_1_replication(roof_640x427, roof_640x427_Lapalacian_replication, roof_size, 1);
			imageIo.output("roof_640x427_Lapalacian4_replication.raw", 640 * 427, roof_640x427_File, roof_640x427_Lapalacian_replication);
			hw4_1.HW4_1_replication(roof_640x427_noise, roof_640x427_noise_Lapalacian_replication, roof_size, 1);
			imageIo.output("roof_640x427_noise_Lapalacian4_replication.raw", 640 * 427, roof_640x427_File, roof_640x427_noise_Lapalacian_replication);
			//---------
			hw4_1.HW4_1_smaller_output(roof_640x427, roof_640x427_Lapalacian_smaller_output, roof_size, 2);
			imageIo.output("roof_640x427_Lapalacia8_smaller_output.raw", 640 * 427, roof_640x427_File, roof_640x427_Lapalacian_smaller_output);
			hw4_1.HW4_1_smaller_output(roof_640x427_noise, roof_640x427_noise_Lapalacian_smaller_output, roof_size, 2);
			imageIo.output("roof_640x427_noise_Lapalacian8_smaller_output.raw", 640 * 427, roof_640x427_File, roof_640x427_noise_Lapalacian_smaller_output);

			hw4_1.HW4_1_zero_padding(roof_640x427, roof_640x427_Lapalacian_zero_padding, roof_size, 2);
			imageIo.output("roof_640x427_Lapalacian8_zero_padding.raw", 640 * 427, roof_640x427_File, roof_640x427_Lapalacian_zero_padding);
			hw4_1.HW4_1_zero_padding(roof_640x427_noise, roof_640x427_noise_Lapalacian_zero_padding, roof_size, 2);
			imageIo.output("roof_640x427_noise_Lapalacian8_zero_padding.raw", 640 * 427, roof_640x427_File, roof_640x427_noise_Lapalacian_zero_padding);

			hw4_1.HW4_1_ad_hoc(roof_640x427, roof_640x427_Lapalacian_ad_hoc, roof_size, 2);
			imageIo.output("roof_640x427_Lapalacian8_ad_hoc.raw", 640 * 427, roof_640x427_File, roof_640x427_Lapalacian_ad_hoc);
			hw4_1.HW4_1_ad_hoc(roof_640x427_noise, roof_640x427_noise_Lapalacian_ad_hoc, roof_size, 2);
			imageIo.output("roof_640x427_noise_Lapalacian8_ad_hoc.raw", 640 * 427, roof_640x427_File, roof_640x427_noise_Lapalacian_ad_hoc);

			hw4_1.HW4_1_replication(roof_640x427, roof_640x427_Lapalacian_replication, roof_size, 2);
			imageIo.output("roof_640x427_Lapalacian8_replication.raw", 640 * 427, roof_640x427_File, roof_640x427_Lapalacian_replication);

			hw4_1.HW4_1_replication(roof_640x427_noise, roof_640x427_noise_Lapalacian_replication, roof_size, 2);
			imageIo.output("roof_640x427_noise_Lapalacian8_replication.raw", 640 * 427, roof_640x427_File, roof_640x427_noise_Lapalacian_replication);
			
			delete[] roof_640x427_Lapalacian_smaller_output;
			delete[] roof_640x427_Lapalacian_zero_padding; 
			delete[] roof_640x427_Lapalacian_ad_hoc; 
			delete[] roof_640x427_Lapalacian_replication;
			delete[] roof_640x427_noise_Lapalacian_smaller_output;
			delete[] roof_640x427_noise_Lapalacian_zero_padding;
			delete[] roof_640x427_noise_Lapalacian_ad_hoc;
			delete[] roof_640x427_noise_Lapalacian_replication;
			break;
		case 2:
			//HW4_1_2
			printf("4_1_2 answer\n");
			hw4_1.HW4_1_replication(roof_640x427, roof_640x427_sobel_x_replication, roof_size, 3);
			imageIo.output("roof_640x427_Sobel_Gy_replication.raw", 640 * 427, roof_640x427_File, roof_640x427_sobel_x_replication);
			hw4_1.HW4_1_replication(roof_640x427, roof_640x427_sobel_y_replication, roof_size, 4);
			imageIo.output("roof_640x427_Sobel_Gx_replication.raw", 640 * 427, roof_640x427_File, roof_640x427_sobel_y_replication);
			
			for (int r = 0; r < 427; r++) {
				for (int c = 0; c < 640; c++) {
					Gx = *(roof_640x427_sobel_x_replication + r * 640 + c);
					Gy = *(roof_640x427_sobel_y_replication + r * 640 + c);
					value = sqrt(pow(Gx, 2) + pow(Gy, 2));
					*(roof_640x427_sobel_combine_replication + r * 640 + c) = floor(value);
				}
			}
			imageIo.output("roof_640x427_Sobel_combine_replication.raw", 640 * 427, roof_640x427_File, roof_640x427_sobel_combine_replication);

			hw4_1.HW4_1_replication(roof_640x427_noise, roof_640x427_noise_sobel_x_replication, roof_size, 3);
			imageIo.output("roof_640x427_noise_Sobel_Gy_replication.raw", 640 * 427, roof_640x427_File, roof_640x427_noise_sobel_x_replication);
			hw4_1.HW4_1_replication(roof_640x427_noise, roof_640x427_noise_sobel_y_replication, roof_size, 4);
			imageIo.output("roof_640x427_noise_Sobel_Gx_replication.raw", 640 * 427, roof_640x427_File, roof_640x427_noise_sobel_y_replication);

			for (int r = 0; r < 427; r++) {
				for (int c = 0; c < 640; c++) {
					Gx = *(roof_640x427_noise_sobel_x_replication + r * 640 + c);
					Gy = *(roof_640x427_noise_sobel_y_replication + r * 640 + c);
					value = sqrt(pow(Gx, 2) + pow(Gy, 2));
					*(roof_640x427_noise_sobel_combine_replication + r * 640 + c) = floor(value);
				}
			}

			imageIo.output("roof_640x427_noise_Sobel_combine_replication.raw", 640 * 427, roof_640x427_File, roof_640x427_noise_sobel_combine_replication);
			
			delete[] roof_640x427_sobel_x_replication;
			delete[] roof_640x427_sobel_y_replication;
			delete[] roof_640x427_sobel_combine_replication;
			delete[] roof_640x427_noise_sobel_x_replication;
			delete[] roof_640x427_noise_sobel_y_replication;
			delete[] roof_640x427_noise_sobel_combine_replication;
			break;
		case 3:
			printf("4_2_1 answer\n");
			//HW4_2_1
			hw4_2.HW4_2_1_replication(block_white_256, block_white_256_mean, block_white_size, ker_size_4_2_1, 5, "histogram of block_white_256_mean.png");
			imageIo.output("block_white_256_mean.raw", 256 * 256, block_white_256_File, block_white_256_mean);
			hw4_2.HW4_2_1_replication(chessboard_256, chessboard_256_mean, block_white_size, ker_size_4_2_1, 5, "histogram of chessboard_256_mean.png");
			imageIo.output("chessboard_256_mean.raw", 256 * 256, chessboard_256_File, chessboard_256_mean);
		
			delete[] block_white_256_mean;
			delete[] chessboard_256_mean;
			break;
		case 4:
			printf("4_2_2 answer\n");
			//HW4_2_2
		

			hw4_2.HW4_2_2_replication(baboon_256, baboon_256_0_8, baboon_size, baboon_ker_size3, 0.8);
			imageIo.output("baboon_256_0_8_filter_3.raw", 256 * 256, baboon_256_File, baboon_256_0_8);
			hw4_2.HW4_2_2_replication(baboon_256, baboon_256_1_3, baboon_size, baboon_ker_size3, 1.3);
			imageIo.output("baboon_256_1_3_filter_3.raw", 256 * 256, baboon_256_File, baboon_256_1_3);
			hw4_2.HW4_2_2_replication(baboon_256, baboon_256_2_0, baboon_size, baboon_ker_size3, 2.0);
			imageIo.output("baboon_256_2_0_filter_3.raw", 256 * 256, baboon_256_File, baboon_256_2_0);

			hw4_2.HW4_2_2_replication(baboon_256, baboon_256_0_8, baboon_size, baboon_ker_size5, 0.8);
			imageIo.output("baboon_256_0_8_filter_5.raw", 256 * 256, baboon_256_File, baboon_256_0_8);
			hw4_2.HW4_2_2_replication(baboon_256, baboon_256_1_3, baboon_size, baboon_ker_size5, 1.3);
			imageIo.output("baboon_256_1_3_filter_5.raw", 256 * 256, baboon_256_File, baboon_256_1_3);
			hw4_2.HW4_2_2_replication(baboon_256, baboon_256_2_0, baboon_size, baboon_ker_size5, 2.0);
			imageIo.output("baboon_256_2_0_filter_5.raw", 256 * 256, baboon_256_File, baboon_256_2_0);
			
			delete[] baboon_256_0_8;
			delete[] baboon_256_1_3;
			delete[] baboon_256_2_0;
			break;
		case 5:
			printf("4_2_3 answer\n");
			//HW4_2_3
			
			hw4_2.HW4_2_3_replication_median(house_blur_noise_790x720, house_blur_noise_790x720_median, house_size, house_ker_size_5);
			imageIo.output("house_blur_noise_790x720_median.raw", 790 * 720, house_blur_noise_790x720_File, house_blur_noise_790x720_median);

			hw4_2.HW4_2_3_replication_sharpen(house_blur_noise_790x720_median, house_blur_noise_790x720_improve, house_size, house_ker_size_3, 6);
			//imageIo.output("house_blur_noise_790x720__ori_lap.raw", 790 * 720, house_blur_noise_790x720_File, house_blur_noise_790x720_improve);

			hw4_1.HW4_1_replication(house_blur_noise_790x720_median, house_blur_noise_790x720_improve_x, house_size, 3);
			imageIo.output("house_blur_noise_790x720_sobel_Gy.raw", 790 * 720, house_blur_noise_790x720_File, house_blur_noise_790x720_improve_x);
			hw4_1.HW4_1_replication(house_blur_noise_790x720_median, house_blur_noise_790x720_improve_y, house_size, 4);
			imageIo.output("house_blur_noise_790x720_sobel_Gx.raw", 790 * 720, house_blur_noise_790x720_File, house_blur_noise_790x720_improve_y);

			for (int r = 0; r < 720; r++) {
				for (int c = 0; c < 790; c++) {
					Gx = *(house_blur_noise_790x720_improve_x + r * 790 + c);
					Gy = *(house_blur_noise_790x720_improve_y + r * 790 + c);

					value = sqrt(pow(Gx, 2) + pow(Gy, 2));
					value = *(house_blur_noise_790x720_median + r * 790 + c) - floor(value * 0.4);
					if (value > 255) {
						value = 255;

					}
					else if (value < 0) {
						value = 0;
					}
					*(house_blur_noise_790x720_improve + r * 790 + c) = value;

				}
			}
			imageIo.output("house_blur_noise_790x720_median_sobel.raw", 790 * 720, house_blur_noise_790x720_File, house_blur_noise_790x720_improve);
		
			histNum_r = hist.calHist(house_blur_noise_790x720_improve, 720, 790);
			histNum_m = hist.calHist(house_blur_noise_790x720_median, 720, 790);
			hist.calHistMatching(house_blur_noise_790x720_improve, house_blur_noise_790x720_improve_match, histNum_r, histNum_m, 720, 790, 720, 790);
			imageIo.output("house_blur_noise_790x720_median_sobel_match.raw", 790 * 720, house_blur_noise_790x720_File, house_blur_noise_790x720_improve_match);
			
			delete[] house_blur_noise_790x720_median;
			delete[] house_blur_noise_790x720_improve;
			delete[] house_blur_noise_790x720_improve_x;
			delete[] house_blur_noise_790x720_improve_y;
			delete[] house_blur_noise_790x720_improve_match;
			break;
		case 6:
			//HW4_3
			printf("4_3 answer\n");
			hw4_3.HW4_3_replication(tsukuba_683x512, tsukuba_683x512_3, tsukuba_size, tsu_ker_size_3, "histogram of tsukuba_683x512_3.png");
			hw4_3.HW4_3_replication(tsukuba_683x512, tsukuba_683x512_5, tsukuba_size, tsu_ker_size_5, "histogram of tsukuba_683x512_5.png");
			hw4_3.HW4_3_replication(tsukuba_683x512, tsukuba_683x512_7, tsukuba_size, tsu_ker_size_7, "histogram of tsukuba_683x512_7.png");
			imageIo.output("tsukuba_683x512_3.raw", 683 * 512, tsukuba_683x512_File, tsukuba_683x512_3);
			imageIo.output("tsukuba_683x512_5.raw", 683 * 512, tsukuba_683x512_File, tsukuba_683x512_5);
			imageIo.output("tsukuba_683x512_7.raw", 683 * 512, tsukuba_683x512_File, tsukuba_683x512_7);
			
			delete[] tsukuba_683x512_3;
			delete[] tsukuba_683x512_5;
			delete[] tsukuba_683x512_7;
			break;

		default:
			printf("Wrong input number\n");
		}
	}
	delete[] roof_640x427;
	delete[] roof_640x427_noise;
	delete[] block_white_256;
	delete[] chessboard_256;
	delete[] baboon_256;
	delete[] house_blur_noise_790x720;
	delete[] tsukuba_683x512; 
}

