#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "ImageIO.cpp"
#include "HW2_1_1.h"
#include "HW2_1_2.cpp"
#include "HW2_2_1and2.cpp"
#include "HW2_2_3.cpp"
#include "HW2_3.cpp"
#include "HW2_4.cpp"


using namespace std;
ImageIO imageIo;
HW2_1_2 hw2_1_2;
HW2_2_1and2 hw2_2_1and2;
HW2_2_3 hw2_2_3;
HW2_3 hw2_3;
HW2_4 hw2_4;
AssessmentMethod assMethod;

int main() {
	FILE* file{};
	

	int image_size_256 = 256 * 256;
	int image_size_128 = 128 * 128;
	int image_size_512 = 512 * 512;

	int memory_size_256 = image_size_256 * sizeof(unsigned char);
	int memory_size_128 = image_size_128 * sizeof(unsigned char);
	int memory_size_512 = image_size_512 * sizeof(unsigned char);

	unsigned char* lena256 = new unsigned char[memory_size_256];
	unsigned char* lena256_blur_50 = new unsigned char[memory_size_256];
	unsigned char* lena256_blur_100 = new unsigned char[memory_size_256];
	unsigned char* lena128 = new unsigned char[memory_size_128];

	//zooming
	unsigned char* lena128_resize_256_n = new unsigned char[memory_size_256];
	unsigned char* lena128_resize_512_n = new unsigned char[memory_size_512];
	unsigned char* lena128_resize_256_b = new unsigned char[memory_size_256];
	unsigned char* lena128_resize_512_b = new unsigned char[memory_size_512];

	unsigned char* lena512 = new unsigned char[memory_size_512];
	unsigned char* lena512_blur_100 = new unsigned char[memory_size_512];
	//Shrinking
	unsigned char* lena512_resize_256_n = new unsigned char[memory_size_256];
	unsigned char* lena512_resize_128_n = new unsigned char[memory_size_128];
	unsigned char* lena512_resize_256_n_b = new unsigned char[memory_size_256];
	unsigned char* lena512_resize_128_n_b = new unsigned char[memory_size_128];

	unsigned char* lena512_resize_256_b = new unsigned char[memory_size_256];
	unsigned char* lena512_resize_128_b = new unsigned char[memory_size_128];
	unsigned char* lena512_resize_256_b_b = new unsigned char[memory_size_256];
	unsigned char* lena512_resize_128_b_b = new unsigned char[memory_size_128];
	//quantize
	unsigned char* baboon256 = new unsigned char[memory_size_256];
	unsigned char* baboon7 = new unsigned char[memory_size_256];
	unsigned char* baboon6 = new unsigned char[memory_size_256];
	unsigned char* baboon5 = new unsigned char[memory_size_256];
	unsigned char* baboon4 = new unsigned char[memory_size_256];
	unsigned char* baboon3 = new unsigned char[memory_size_256];
	unsigned char* baboon2 = new unsigned char[memory_size_256];
	unsigned char* baboon1 = new unsigned char[memory_size_256];
	unsigned char* lena7 = new unsigned char[memory_size_256];
	unsigned char* lena6 = new unsigned char[memory_size_256];
	unsigned char* lena5 = new unsigned char[memory_size_256];
	unsigned char* lena4 = new unsigned char[memory_size_256];
	unsigned char* lena3 = new unsigned char[memory_size_256];
	unsigned char* lena2 = new unsigned char[memory_size_256];
	unsigned char* lena1 = new unsigned char[memory_size_256];

	//bicubic
	unsigned char* duck900x660 = new unsigned char[900 * 600 * sizeof(unsigned char)];
	unsigned char* duck_zoom_in_2_bilinear = new unsigned char[284 * 200 * sizeof(unsigned char)];
	unsigned char* duck_zoom_in_2_bicubic = new unsigned char[284 * 200 * sizeof(unsigned char)];
	//map
	unsigned char* map100x100 = new unsigned char[100 * 100 * sizeof(unsigned char)];
	unsigned char* D4 = new unsigned char[100 * 100 * sizeof(unsigned char)];
	unsigned char* D8 = new unsigned char[100 * 100 * sizeof(unsigned char)];
	unsigned char* Dm = new unsigned char[100 * 100 * sizeof(unsigned char)];

	lena256 = imageIo.input("./HW2_images_file/lena256.raw", image_size_256, memory_size_256, file);
	lena256_blur_50 = imageIo.input("./HW2_images_file/lena256_blur_50.raw", image_size_256, memory_size_256, file);
	lena256_blur_100 = imageIo.input("./HW2_images_file/lena256_blur_100.raw", image_size_256, memory_size_256, file);
	lena128 = imageIo.input("./HW2_images_file/lena128.raw", image_size_128, memory_size_128, file);
	lena512 = imageIo.input("./HW2_images_file/lena512.raw", image_size_512, memory_size_512, file);
	lena512_blur_100 = imageIo.input("./HW2_images_file/lena512_blur_100.raw", image_size_512, memory_size_512, file);
	baboon256 = imageIo.input("./HW2_images_file/baboon256.raw", image_size_256, memory_size_256, file);
	duck900x660 = imageIo.input("./HW2_images_file/duck900x660.raw", 900 * 600, 900 * 600, file);
	map100x100 = imageIo.input("./HW2_images_file/map100x100.raw", 100 * 100, 100 * 100, file);
	//initial mse
	float mse_256_n_z = 0, mse_512_n_z = 0;
	float psnr_256_n_z = 0, psnr_512_n_z = 0;
	float mse_256_b_z = 0, mse_512_b_z = 0;
	float psnr_256_b_z = 0, psnr_512_b_z = 0;
	float mse_256_n_s = 0, mse_128_n_s = 0;
	float psnr_256_n_s = 0, psnr_128_n_s = 0;
	float mse_256_n_s_b = 0, mse_128_n_s_b = 0;
	float psnr_256_n_s_b = 0, psnr_128_n_s_b = 0;
	float mse_256_b_s = 0, mse_128_b_s = 0;
	float psnr_256_b_s = 0, psnr_128_b_s = 0;
	float mse_256_b_s_b = 0, mse_128_b_s_b = 0;
	float psnr_256_b_s_b = 0, psnr_128_b_s_b = 0;
	float mse_baboon1 = 0, mse_baboon2 = 0, mse_baboon3 = 0, mse_baboon4 = 0, mse_baboon5 = 0, mse_baboon6 = 0, mse_baboon7 = 0, mse_baboon8 = 0;
	float psnr_baboon1 = 0, psnr_baboon2 = 0, psnr_baboon3 = 0, psnr_baboon4 = 0, psnr_baboon5 = 0, psnr_baboon6 = 0, psnr_baboon7 = 0, psnr_baboon8 = 0;
	float mse_lena1 = 0, mse_lena2 = 0, mse_lena3 = 0, mse_lena4 = 0, mse_lena5 = 0, mse_lena6 = 0, mse_lena7 = 0, mse_lena8 = 0;
	float psnr_lena1 = 0, psnr_lena2 = 0, psnr_lena3 = 0, psnr_lena4 = 0, psnr_lena5 = 0, psnr_lena6 = 0, psnr_lena7 = 0, psnr_lena8 = 0;
	printf("1: 2_1_2 answer\n2: 2_2_1 answer\n3: 2_2_2 answer\n4: 2_2_3 answer\n5: 2_3 answer\n6: 2_4 answer\n");
	printf("Enter the question number to select output result or press -1 to exit\n");
	int input = 0;
	while (input != -1) {
		
		scanf("%d", &input);

		switch (input) {
		case -1:
			break;
		case 1:
			printf("2_1_2 answer\n");
			hw2_1_2.task(256, 256, lena256, lena256_blur_50, lena256_blur_100);
			delete[] lena256_blur_50;
			delete[] lena256_blur_100;
			break;
		case 2:
			printf("2_2_1 answer\n");
		    //nearestNeighborZooming
			lena128_resize_256_n = hw2_2_1and2.nNZ(image_size_128, image_size_256, lena128);
			lena128_resize_512_n = hw2_2_1and2.nNZ(image_size_128, image_size_512, lena128);
			imageIo.output("lena128_resize_256_nearest.raw", image_size_256, file, lena128_resize_256_n);
			imageIo.output("lena128_resize_512_nearest.raw", image_size_512, file, lena128_resize_512_n);
			mse_256_n_z = assMethod.MSE(256, 256, lena256, lena128_resize_256_n);
			mse_512_n_z = assMethod.MSE(512, 512, lena512, lena128_resize_512_n);
			psnr_256_n_z = assMethod.PSNR(mse_256_n_z);
			psnr_512_n_z = assMethod.PSNR(mse_512_n_z);
			//bilinearZooming
			lena128_resize_256_b = hw2_2_1and2.bilZooAndShr(image_size_128, image_size_256, lena128);
			lena128_resize_512_b = hw2_2_1and2.bilZooAndShr(image_size_128, image_size_512, lena128);
			imageIo.output("lena128_resize_256_bilinear.raw", image_size_256, file, lena128_resize_256_b);
			imageIo.output("lena128_resize_512_bilinear.raw", image_size_512, file, lena128_resize_512_b);
			mse_256_b_z = assMethod.MSE(256, 256, lena256, lena128_resize_256_b);
			mse_512_b_z = assMethod.MSE(512, 512, lena512, lena128_resize_512_b);
			psnr_256_b_z = assMethod.PSNR(mse_256_b_z);
			psnr_512_b_z = assMethod.PSNR(mse_512_b_z);
			printf("MSE between lena256 and lena256 (NearestNeighbor Zooming) = % .3f\n", mse_256_n_z);
			printf("PSNR between lena256 and lena256 (NearestNeighbor Zooming) = % .3f\n", psnr_256_n_z);
			printf("MSE between lena512 and lena512 (NearestNeighbor Zooming) = % .3f\n", mse_512_n_z);
			printf("PSNR between lena512 and lena512 (NearestNeighbor Zooming) = % .3f\n\n", psnr_512_n_z);
			printf("MSE between lena256 and lena256 (Bilinear Zooming) = % .3f\n", mse_256_b_z);
			printf("PSNR between lena256 and lena256 (Bilinear Zooming) = % .3f\n", psnr_256_b_z);
			printf("MSE between lena512 and lena512 (Bilinear Zooming) = % .3f\n", mse_512_b_z);
			printf("PSNR between lena512 and lena512 (Bilinear Zooming) = % .3f\n", psnr_512_b_z);
			delete[] lena128_resize_256_n;
			delete[] lena128_resize_512_n;
			delete[] lena128_resize_256_b;
			delete[] lena128_resize_512_b;
			break;
		case 3:
			printf("2_2_2 answer\n");
			//nearestNeighborShrinking
			//before blur
			lena512_resize_256_n = hw2_2_1and2.nNS(image_size_512, image_size_256, lena512);
			lena512_resize_128_n = hw2_2_1and2.nNS(image_size_512, image_size_128, lena512);
			imageIo.output("lena512_resize_256_nearest.raw", image_size_256, file, lena512_resize_256_n);
			imageIo.output("lena512_resize_128_nearest.raw", image_size_128, file, lena512_resize_128_n);
		    mse_256_n_s = assMethod.MSE(256, 256, lena256, lena512_resize_256_n);
			mse_128_n_s = assMethod.MSE(128, 128, lena128, lena512_resize_128_n);
			psnr_256_n_s = assMethod.PSNR(mse_256_n_s);
			psnr_128_n_s = assMethod.PSNR(mse_128_n_s);
			
			
			//after blur
			lena512_resize_256_n_b = hw2_2_1and2.nNS(image_size_512, image_size_256, lena512_blur_100);
			lena512_resize_128_n_b = hw2_2_1and2.nNS(image_size_512, image_size_128, lena512_blur_100);
			imageIo.output("lena512_resize_256_nearest_blur.raw", image_size_256, file, lena512_resize_256_n_b);
			imageIo.output("lena512_resize_128_nearest_blur.raw", image_size_128, file, lena512_resize_128_n_b);
			mse_256_n_s_b = assMethod.MSE(256, 256, lena256, lena512_resize_256_n_b);
			mse_128_n_s_b = assMethod.MSE(128, 128, lena128, lena512_resize_128_n_b);
			psnr_256_n_s_b = assMethod.PSNR(mse_256_n_s_b);
			psnr_128_n_s_b = assMethod.PSNR(mse_128_n_s_b);

			printf("MSE of lena256 and lena256 (NearestNeighbor Shrinking) before blur = % .3f\n", mse_256_n_s);
			printf("PSNR of lena256 and lena256 (NearestNeighbor Shrinking) before blur = % .3f\n", psnr_256_n_s);
			printf("MSE of lena256 and lena256 (NearestNeighbor Shrinking) after blur = % .3f\n", mse_256_n_s_b);
			printf("PSNR of lena256 and lena256 (NearestNeighbor Shrinking) after blur = % .3f\n\n", psnr_256_n_s_b);
			printf("MSE of lena128 and lena128 (NearestNeighbor Shrinking) before blur = % .3f\n", mse_128_n_s);
			printf("PSNR of lena128 and lena128 (NearestNeighbor Shrinking) before blur = % .3f\n", psnr_128_n_s);
			printf("MSE of lena128 and lena128 (NearestNeighbor Shrinking) after blur = % .3f\n", mse_128_n_s_b);
			printf("PSNR of lena128 and lena128 (NearestNeighbor Shrinking) after blur = % .3f\n\n", psnr_128_n_s_b);
			delete[] lena512_resize_256_n;
			delete[] lena512_resize_128_n;
			delete[] lena512_resize_256_n_b;
			delete[] lena512_resize_128_n_b;
			//bilinearShrinking
			//before blur
				
			lena512_resize_256_b = hw2_2_1and2.bilZooAndShr(image_size_512, image_size_256, lena512);
			lena512_resize_128_b = hw2_2_1and2.bilZooAndShr(image_size_512, image_size_128, lena512);
			imageIo.output("lena512_resize_256_bilinear.raw", image_size_256, file, lena512_resize_256_b);
			imageIo.output("lena512_resize_128_bilinear.raw", image_size_128, file, lena512_resize_128_b);
			mse_256_b_s = assMethod.MSE(256, 256, lena256, lena512_resize_256_b);
			mse_128_b_s = assMethod.MSE(128, 128, lena128, lena512_resize_128_b);
			psnr_256_b_s = assMethod.PSNR(mse_256_b_s);
			psnr_128_b_s = assMethod.PSNR(mse_128_b_s);
	
			
			//after blur
			lena512_resize_256_b_b = hw2_2_1and2.bilZooAndShr(image_size_512, image_size_256, lena512_blur_100);
			lena512_resize_128_b_b = hw2_2_1and2.bilZooAndShr(image_size_512, image_size_128, lena512_blur_100);
			imageIo.output("lena512_resize_256_bilinear_blur.raw", image_size_256, file, lena512_resize_256_b_b);
			imageIo.output("lena512_resize_128_bilinear_blur.raw", image_size_128, file, lena512_resize_128_b_b);
			mse_256_b_s_b = assMethod.MSE(256, 256, lena256, lena512_resize_256_b_b);
			mse_128_b_s_b = assMethod.MSE(128, 128, lena128, lena512_resize_128_b_b);
			psnr_256_b_s_b = assMethod.PSNR(mse_256_b_s_b);
			psnr_128_b_s_b = assMethod.PSNR(mse_128_b_s_b);
			printf("MSE of lena256 and lena256 (Bilinear Shrinking) before blur = % .3f\n", mse_256_b_s);
			printf("PSNR of lena256 and lena256 (Bilinear Shrinking) before blur = % .3f\n", psnr_256_b_s);
			printf("MSE of lena256 and lena256 (Bilinear Shrinking) after blur = % .3f\n", mse_256_b_s_b);
			printf("PSNR of lena256 and lena256 (Bilinear Shrinking) after blur = % .3f\n\n", psnr_256_b_s_b);
			printf("MSE of lena128 and lena128 (Bilinear Shrinking) before blur = % .3f\n", mse_128_b_s);
			printf("PSNR of lena128 and lena128 (Bilinear Shrinking) before blur = % .3f\n", psnr_128_b_s);
			printf("MSE of lena128 and lena128 (Bilinear Shrinking) after blur = % .3f\n", mse_128_b_s_b);
			printf("PSNR of lena128 and lena128 (Bilinear Shrinking) after blur = % .3f\n", psnr_128_b_s_b);
			delete[] lena512_resize_256_b;
			delete[] lena512_resize_128_b;
			delete[] lena512_resize_256_b_b;
			delete[] lena512_resize_128_b_b;
			break;
		case 4:
			printf("2_2_3 answer\n");
			duck_zoom_in_2_bilinear = hw2_2_1and2.bilZooAndShr(142 * 100, 284 * 200, duck900x660);
			imageIo.output("duck_zoom_in_bilinear.raw", 284 * 200, file, duck_zoom_in_2_bilinear);
			duck_zoom_in_2_bicubic = hw2_2_3.bicubic(144 * 102, 284 * 200, duck900x660);
			imageIo.output("duck_zoom_in_bicubic.raw", 284 * 200, file, duck_zoom_in_2_bicubic);
			printf("Generate answer\n");
			break;
		case 5:
			printf("2_3 answer\n");

			imageIo.output("baboon8.raw", 256 * 256, file, baboon256);
			baboon7 = hw2_3.quantize(baboon256, 256 * 256, 7);
			imageIo.output("baboon7.raw", 256 * 256, file, baboon7);
			baboon6 = hw2_3.quantize(baboon256, 256 * 256, 6);
			imageIo.output("baboon6.raw", 256 * 256, file, baboon6);
			baboon5 = hw2_3.quantize(baboon256, 256 * 256, 5);
			imageIo.output("baboon5.raw", 256 * 256, file, baboon5);
			baboon4 = hw2_3.quantize(baboon256, 256 * 256, 4);
			imageIo.output("baboon4.raw", 256 * 256, file, baboon4);
			baboon3 = hw2_3.quantize(baboon256, 256 * 256, 3);
			imageIo.output("baboon3.raw", 256 * 256, file, baboon3);
			baboon2 = hw2_3.quantize(baboon256, 256 * 256, 2);
			imageIo.output("baboon2.raw", 256 * 256, file, baboon2);
			baboon1 = hw2_3.quantize(baboon256, 256 * 256, 1);
			imageIo.output("baboon1.raw", 256 * 256, file, baboon1);
			
			imageIo.output("lena8.raw", 256 * 256, file, lena256);
			lena7 = hw2_3.quantize(lena256, 256 * 256, 7);
			imageIo.output("lena7.raw", 256 * 256, file, lena7);
			lena6 = hw2_3.quantize(lena256, 256 * 256, 6);
			imageIo.output("lena6.raw", 256 * 256, file, lena6);
			lena5 = hw2_3.quantize(lena256, 256 * 256, 5);
			imageIo.output("lena5.raw", 256 * 256, file, lena5);
			lena4 = hw2_3.quantize(lena256, 256 * 256, 4);
			imageIo.output("lena4.raw", 256 * 256, file, lena4);
			lena3 = hw2_3.quantize(lena256, 256 * 256, 3);
			imageIo.output("lena3.raw", 256 * 256, file, lena3);
			lena2 = hw2_3.quantize(lena256, 256 * 256, 2);
			imageIo.output("lena2.raw", 256 * 256, file, lena2);
			lena1 = hw2_3.quantize(lena256, 256 * 256, 1);
			imageIo.output("lena1.raw", 256 * 256, file, lena1);

			mse_baboon1 = assMethod.MSE(256, 256, baboon256, baboon1);
			mse_baboon2 = assMethod.MSE(256, 256, baboon256, baboon2);
			mse_baboon3 = assMethod.MSE(256, 256, baboon256, baboon3);
			mse_baboon4 = assMethod.MSE(256, 256, baboon256, baboon4);
			mse_baboon5 = assMethod.MSE(256, 256, baboon256, baboon5);
			mse_baboon6 = assMethod.MSE(256, 256, baboon256, baboon6);
			mse_baboon7 = assMethod.MSE(256, 256, baboon256, baboon7);
			mse_baboon8 = assMethod.MSE(256, 256, baboon256, baboon256);

			psnr_baboon1 = assMethod.PSNR(mse_baboon1);
			psnr_baboon2 = assMethod.PSNR(mse_baboon2);
			psnr_baboon3 = assMethod.PSNR(mse_baboon3);
			psnr_baboon4 = assMethod.PSNR(mse_baboon4);
			psnr_baboon5 = assMethod.PSNR(mse_baboon5);
			psnr_baboon6 = assMethod.PSNR(mse_baboon6);
			psnr_baboon7 = assMethod.PSNR(mse_baboon7);
			psnr_baboon8 = assMethod.PSNR(mse_baboon8);

			mse_lena1 = assMethod.MSE(256, 256, lena256, lena1);
			mse_lena2 = assMethod.MSE(256, 256, lena256, lena2);
			mse_lena3 = assMethod.MSE(256, 256, lena256, lena3);
			mse_lena4 = assMethod.MSE(256, 256, lena256, lena4);
			mse_lena5 = assMethod.MSE(256, 256, lena256, lena5);
			mse_lena6 = assMethod.MSE(256, 256, lena256, lena6);
			mse_lena7 = assMethod.MSE(256, 256, lena256, lena7);
			mse_lena8 = assMethod.MSE(256, 256, lena256, lena256);

			psnr_lena1 = assMethod.PSNR(mse_lena1);
			psnr_lena2 = assMethod.PSNR(mse_lena2);
			psnr_lena3 = assMethod.PSNR(mse_lena3);
			psnr_lena4 = assMethod.PSNR(mse_lena4);
			psnr_lena5 = assMethod.PSNR(mse_lena5);
			psnr_lena6 = assMethod.PSNR(mse_lena6);
			psnr_lena7 = assMethod.PSNR(mse_lena7);
			psnr_lena8 = assMethod.PSNR(mse_lena8);

			printf("MSE and PSNR between lena256 and lena256 (8 bits) = %f, %f\n", mse_lena8, psnr_lena8);
			printf("MSE and PSNR between lena256 and lena256 (7 bits) = %f, %f\n", mse_lena7, psnr_lena7);
			printf("MSE and PSNR between lena256 and lena256 (6 bits) = %f, %f\n", mse_lena6, psnr_lena6);
			printf("MSE and PSNR between lena256 and lena256 (5 bits) = %f, %f\n", mse_lena5, psnr_lena5);
			printf("MSE and PSNR between lena256 and lena256 (4 bits) = %f, %f\n", mse_lena4, psnr_lena4);
			printf("MSE and PSNR between lena256 and lena256 (3 bits) = %f, %f\n", mse_lena3, psnr_lena3);
			printf("MSE and PSNR between lena256 and lena256 (2 bits) = %f, %f\n", mse_lena2, psnr_lena2);
			printf("MSE and PSNR between lena256 and lena256 (1 bits) = %f, %f\n\n", mse_lena1, psnr_lena1);

			printf("MSE and PSNR between baboon256 and baboon256 (8 bits) = %f, %f\n", mse_baboon8, psnr_baboon8);
			printf("MSE and PSNR between baboon256 and baboon256 (7 bits) = %f, %f\n", mse_baboon7, psnr_baboon7);
			printf("MSE and PSNR between baboon256 and baboon256 (6 bits) = %f, %f\n", mse_baboon6, psnr_baboon6);
			printf("MSE and PSNR between baboon256 and baboon256 (5 bits) = %f, %f\n", mse_baboon5, psnr_baboon5);
			printf("MSE and PSNR between baboon256 and baboon256 (4 bits) = %f, %f\n", mse_baboon4, psnr_baboon4);
			printf("MSE and PSNR between baboon256 and baboon256 (3 bits) = %f, %f\n", mse_baboon3, psnr_baboon3);
			printf("MSE and PSNR between baboon256 and baboon256 (2 bits) = %f, %f\n", mse_baboon2, psnr_baboon2);
			printf("MSE and PSNR between baboon256 and baboon256 (1 bits) = %f, %f\n", mse_baboon1, psnr_baboon1);

			delete[] baboon1;
			delete[] baboon2;
			delete[] baboon3;
			delete[] baboon4;
			delete[] baboon5;
			delete[] baboon6;
			delete[] baboon7;
			delete[] lena7;
			delete[] lena6;
			delete[] lena5;
			delete[] lena4;
			delete[] lena3;
			delete[] lena2;
			delete[] lena1;
			break;
		case 6:
			printf("2_4 answer\n");
			D4 = hw2_4.CalD4(map100x100, D4);
			D8 = hw2_4.CalD8(map100x100, D8);
			Dm = hw2_4.CalDm(map100x100, Dm);
			imageIo.output("map_D4.raw", 100 * 100, file, D4);
			imageIo.output("map_D8.raw", 100 * 100, file, D8);
			imageIo.output("map_Dm.raw", 100 * 100, file, Dm);
			break;
		default:
			printf("Wrong input number\n");

		}

	}
	delete[] lena256;
	delete[] lena128;
	delete[] lena512;
	delete[] baboon256;
	delete[] duck900x660;
	delete[] map100x100;
	return 0;
}