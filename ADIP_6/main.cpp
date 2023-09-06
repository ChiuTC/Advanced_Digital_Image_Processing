#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "ImageIO.cpp"
#include "HW6_1.cpp"
#include "HW6_2.cpp"
#include "HW6_3.cpp"
#include "HW6_4.cpp"
using namespace std;
ImageIO imageIo;
HW6_1 hw6_1;
HW6_2 hw6_2;
HW6_3 hw6_3;
HW6_4 hw6_4;

int main() {
	FILE* input_file{};
	FILE* output_file{};
	unsigned char* words_512 = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* words_512_morph = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* check_613x237 = new unsigned char[237 * 613 * sizeof(unsigned char)];
	unsigned char* check_613x237_erode = new unsigned char[237 * 613 * sizeof(unsigned char)];
	unsigned char* check_613x237_dilate = new unsigned char[237 * 613 * sizeof(unsigned char)];
	unsigned char* check_613x237_opening = new unsigned char[237 * 613 * sizeof(unsigned char)];
	unsigned char* check_613x237_closing = new unsigned char[237 * 613 * sizeof(unsigned char)];
	unsigned char* check_613x237_erode_ch = new unsigned char[237 * 613 * sizeof(unsigned char)];
	unsigned char* check_613x237_dilate_ch = new unsigned char[237 * 613 * sizeof(unsigned char)];
	unsigned char* monster_600 = new unsigned char[600 * 600 * sizeof(unsigned char)];
	unsigned char* monster_600_morph = new unsigned char[600 * 600 * sizeof(unsigned char)];
	unsigned char* map_512 = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* map_512_morph = new unsigned char[512 * 512 * sizeof(unsigned char)];
	unsigned char* map_512_path = new unsigned char[512 * 512 * sizeof(unsigned char)];
	words_512 = imageIo.input("./HW6_images_file/words_512.raw", 512 * 512, 512 * 512 * sizeof(unsigned char), input_file);
	check_613x237 = imageIo.input("./HW6_images_file/check_613x237.raw", 237 * 613, 237 * 613 * sizeof(unsigned char), input_file);
	monster_600 = imageIo.input("./HW6_images_file/monster_600.raw", 600 * 600, 600 * 600 * sizeof(unsigned char), input_file);
	map_512 = imageIo.input("./HW6_images_file/map_512.raw", 512 * 512, 512 * 512 * sizeof(unsigned char), input_file);
	
	printf("1: 6_1 answer\n2: 6_2_1 answer\n3: 6_2_2 answer\n4: 6_3 answer\n5: 6_4 answer\n");
	printf("Enter the question number to select output result or press -1 to exit\n");
	int input = 0;
	while (input != -1) {

		scanf("%d", &input);

		switch (input) {
		case -1:

			break;
		case 1:
			//HW6_1
			hw6_1.binaryImageMorph(words_512, words_512_morph);
			imageIo.output("words_512_morph.raw", 512 * 512, output_file, words_512_morph);
			printf("6_1 answer\n");
			break;
		case 2:
			//HW6_2_1
			hw6_2.grayScaleImageErode(check_613x237, check_613x237_erode);
			imageIo.output("check_613x237_erode.raw", 613 * 237, output_file, check_613x237_erode);
			hw6_2.grayScaleImageDilate(check_613x237, check_613x237_dilate);
			imageIo.output("check_613x237_dilate.raw", 613 * 237, output_file, check_613x237_dilate);
			hw6_2.grayScaleImageOpening(check_613x237, check_613x237_opening);
			imageIo.output("check_613x237_opening.raw", 613 * 237, output_file, check_613x237_opening);
			hw6_2.grayScaleImageClosing(check_613x237, check_613x237_closing);
			imageIo.output("check_613x237_closing.raw", 613 * 237, output_file, check_613x237_closing);
			printf("6_2_1 answer\n");
			break;
		case 3:
			//HW6_2_2
			hw6_2.grayScaleImageErodeChange(check_613x237, check_613x237_erode_ch);
			imageIo.output("check_613x237_erode_rotate.raw", 613 * 237, output_file, check_613x237_erode_ch);
			hw6_2.grayScaleImageDilateChange(check_613x237, check_613x237_dilate_ch);
			imageIo.output("check_613x237_dilate_rotate.raw", 613 * 237, output_file, check_613x237_dilate_ch);
			printf("6_2_2 answer\n");
			break;
		case 4:
			//HW6_3
			hw6_3.trimap(monster_600, monster_600_morph);
			imageIo.output("monster_600_trimap.raw", 600 * 600, output_file, monster_600_morph);
			printf("6_3 answer\n");
			break;
		case 5:
			//HW6_4
			hw6_4.repairRoad(map_512, map_512_morph);
			imageIo.output("map_512_repair.raw", 512 * 512, output_file, map_512_morph);
			hw6_4.CalD8(map_512_morph, map_512_path);
			imageIo.output("map_512_path.raw", 512 * 512, output_file, map_512_path);
			printf("6_4 answer\n");
			break;
		}
	}
	


	
	
}