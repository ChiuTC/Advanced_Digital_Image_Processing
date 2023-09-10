#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "ImageIO.h"
#include "HW1_1_2_a_b_c_d.cpp"
#include "HW1_1_2_e.cpp"
#include "HW1_1_3_a_b.cpp"
#include "HW1_2_b.cpp"

using namespace std;
ImageIO imageIo;

int main() {
	//----------FILE定義-------------
	FILE* file{};

	//----------圖像大小定義-------------
	int image_size = 256 * 256;
	int A1_img_size = 128 * 128;
	int A2_img_size = 64 * 128;
	int A3_img_size = 128 * 192;
	int A4_img_size = 192 * 192;
	int A5_img_size = 64 * 64;
	int combine_img_size = 256 * 256;
	int j_img_size = 466 * 621;
	int memory_size = image_size * sizeof(unsigned char);

	//----------配置記憶體空間-------------
	unsigned char* lena = new unsigned char[memory_size];
	unsigned char* lena_rotate = new unsigned char[memory_size];
	unsigned char* lena_ver = new unsigned char[memory_size];
	unsigned char* lena_hor = new unsigned char[memory_size];
	unsigned char* A1 = new unsigned char[A1_img_size * sizeof(unsigned char)];
	unsigned char* A2 = new unsigned char[A2_img_size * sizeof(unsigned char)];
	unsigned char* A3 = new unsigned char[A3_img_size * sizeof(unsigned char)];
	unsigned char* A4 = new unsigned char[A4_img_size * sizeof(unsigned char)];
	unsigned char* A5 = new unsigned char[A5_img_size * sizeof(unsigned char)];
	unsigned char* combine = new unsigned char[memory_size];
	unsigned char* lena_add_value45 = new unsigned char[memory_size];
	unsigned char* lena_add_randomValue = new unsigned char[memory_size];
	unsigned char* jackieChen = new unsigned char[j_img_size * sizeof(unsigned char)];

	//----------圖片讀取-------------
	lena = imageIo.input("./HW1_images_file/lena256.raw", image_size, memory_size, file);
	A1 = imageIo.input("./HW1_images_file/A1.raw", A1_img_size, A1_img_size * sizeof(unsigned char), file);
	A2 = imageIo.input("./HW1_images_file/A2.raw", A2_img_size, A2_img_size * sizeof(unsigned char), file);
	A3 = imageIo.input("./HW1_images_file/A3.raw", A3_img_size, A3_img_size * sizeof(unsigned char), file);
	A4 = imageIo.input("./HW1_images_file/A4.raw", A4_img_size, A4_img_size * sizeof(unsigned char), file);
	A5 = imageIo.input("./HW1_images_file/A5.raw", A5_img_size, A5_img_size * sizeof(unsigned char), file);
	jackieChen = imageIo.input("./HW1_images_file/JackieChen.raw", j_img_size, j_img_size * sizeof(unsigned char), file);

	HW1_1_2_a_b_c_d hw1_1_2(lena);
	HW1_1_2_e hw1_1_2_e;
	HW1_1_3_a_b hw1_1_3;
	HW1_2_b hw1_2;
	printf("1: 1_2_a answer\n2: 1_2_b answer\n3: 1_2_c answer\n4: 1_2_d answer\n5: 1_2_e answer\n6: 1_3_a answer\n7: 1_3_b answer\n8: 2_b answer\n");
	printf("Enter the question number to select output result or press -1 to exit\n");
	int input = 0;
	while (input != -1) {

		scanf("%d", &input);

		switch (input) {
		case -1:
			break;
		case 1:
			printf("1_2_a answer\n");
			hw1_1_2.a();
			break;
		case 2:
			printf("1_2_b answer\n");
			hw1_1_2.b("lena256_out.raw", image_size, memory_size, file, lena);
			break;
		case 3:
			printf("1_2_c answer\n");
			lena_rotate = hw1_1_2.c(memory_size);
			imageIo.output("lena_rotate.raw", image_size, memory_size, file, lena_rotate);
			break;
		case 4:
			printf("1_2_d answer\n");
			lena_ver = hw1_1_2.d_ver(memory_size);
			lena_hor = hw1_1_2.d_hor(memory_size);
			imageIo.output("lena_ver.raw", image_size, memory_size, file, lena_ver);
			imageIo.output("lena_hor.raw", image_size, memory_size, file, lena_hor);
			break;
		case 5:
			printf("1_2_e answer\n");
			combine = hw1_1_2_e.answer(memory_size, A1, A2, A3, A4, A5);
			imageIo.output("combine.raw", combine_img_size, memory_size, file, combine);
			break;
		case 6:
			printf("1_3_a answer\n");
			lena_add_value45 = hw1_1_3.a(lena);
			imageIo.output("lena_add_value45.raw", image_size, memory_size, file, lena_add_value45);
			break;
		case 7:
			printf("1_3_b answer\n");
			lena_add_randomValue = hw1_1_3.b(lena);
			imageIo.output("lena_add_randomValue.raw", image_size, memory_size, file, lena_add_randomValue);
			break;
		case 8:
			printf("2_b answer\n");
			hw1_2.b(lena, jackieChen);
			break;
		default:
			printf("Wrong input number\n");

		}
	}
	delete[] lena;
	delete[] lena_rotate;
	delete[] lena_ver;
	delete[] lena_hor;
	delete[] A1;
	delete[] A2;
	delete[] A3;
	delete[] A4;
	delete[] A5;
	delete[] combine;
	delete[] lena_add_value45;
	delete[] lena_add_randomValue;
	return 0;
}
