#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "MORPH.h"
#include "a_star_algorithm.h"
using namespace std;

class HW6_4 {
private:
	MORPH morph;
	AStar::Generator generator;
public:
	HW6_4() {
		generator.setWorldSize({ 512, 512 });
	}
	void repairRoad(unsigned char* src, unsigned char* dst) {
		vec2 size_rec(1, 2);
		vec2 size_3x3(3, 3);
		vec2 ori(1, 1);
		vec2 image_size(512, 512);
		string type_3x3 = "0";
		string type_cross = "1";
		string type_rec = "2";
		string type_B1 = "3";
		string type_B2 = "4";
		string type_B3 = "5";
		string type_B4 = "6";
		string type_B5 = "7";
		string type_B6 = "8";
		string type_B7 = "9";
		string type_B8 = "10";

		unsigned char flag = 255;
		kernal ker_rec = morph.getStructuringElement(size_rec, ori, type_rec, flag);
		kernal ker_3x3 = morph.getStructuringElement(size_3x3, ori, type_3x3, flag);
		kernal ker_cross = morph.getStructuringElement(size_3x3, ori, type_cross, flag);
		kernal ker_B1 = morph.getStructuringElement(size_3x3, ori, type_B1, flag);
		kernal ker_B2 = morph.getStructuringElement(size_3x3, ori, type_B2, flag);
		kernal ker_B3 = morph.getStructuringElement(size_3x3, ori, type_B3, flag);
		kernal ker_B4 = morph.getStructuringElement(size_3x3, ori, type_B4, flag);
		kernal ker_B5 = morph.getStructuringElement(size_3x3, ori, type_B5, flag);
		kernal ker_B6 = morph.getStructuringElement(size_3x3, ori, type_B6, flag);
		kernal ker_B7 = morph.getStructuringElement(size_3x3, ori, type_B7, flag);
		kernal ker_B8 = morph.getStructuringElement(size_3x3, ori, type_B8, flag);

		//morph.erode(src, dst, ker_cross, image_size, type_cross, flag);
		morph.dilate(src, dst, ker_3x3, image_size, type_3x3, flag);
		morph.dilate(dst, dst, ker_3x3, image_size, type_3x3, flag);
		morph.dilate(dst, dst, ker_3x3, image_size, type_3x3, flag);
		morph.dilate(dst, dst, ker_3x3, image_size, type_3x3, flag);
		morph.dilate(dst, dst, ker_cross, image_size, type_cross, flag);
		morph.dilate(dst, dst, ker_cross, image_size, type_cross, flag);
		morph.dilate(dst, dst, ker_cross, image_size, type_cross, flag);
	    morph.dilate(dst, dst, ker_cross, image_size, type_cross, flag);
	    
		morph.erode(dst, dst, ker_3x3, image_size, type_3x3, flag);
		morph.erode(dst, dst, ker_3x3, image_size, type_3x3, flag);
		morph.erode(dst, dst, ker_3x3, image_size, type_3x3, flag);
		//thining
		for (int i = 0; i < 15; i++) {
			morph.erode(dst, dst, ker_B1, image_size, type_B1, flag);
			morph.erode(dst, dst, ker_B2, image_size, type_B2, flag);
			morph.erode(dst, dst, ker_B3, image_size, type_B3, flag);
			morph.erode(dst, dst, ker_B4, image_size, type_B4, flag);
			morph.erode(dst, dst, ker_B5, image_size, type_B5, flag);
			morph.erode(dst, dst, ker_B6, image_size, type_B6, flag);
			morph.erode(dst, dst, ker_B7, image_size, type_B7, flag);
			morph.erode(dst, dst, ker_B8, image_size, type_B8, flag);
		}
		
		
	}

	unsigned char* CalD8(unsigned char* map_512, unsigned char* D8) {
		for (int i = 0; i < 512 * 512; i++) {
			if (*(map_512 + i) == 0) {
				*(map_512 + i) = 255;
			}
			else {
				*(map_512 + i) = 0;
			}
		}

		unsigned char walls_arr[512][512];
		int index = 0;
		for (int i = 0; i < 512; i++) {
			for (int j = 0; j < 512; j++) {
				walls_arr[i][j] = *(map_512 + index);
				if (walls_arr[i][j] == 255) {
					generator.addCollision({ i,j });
					//printf("[%d,%d]\n", i, j);
				}
				index++;
			}
		}
		index = 0;
		generator.setHeuristic(AStar::Heuristic::D8);
		generator.setDiagonalMovement(true);
		//std::cout << "Generate D8 path\n";
		auto path = generator.findPath({ 198, 117 }, { 498, 397 });

		int count = -1;
		for (auto& coordinate : path) {
			//std::cout << coordinate.x << " " << coordinate.y << "\n";
			count += 1;
		}
		printf("The path of D8 is:%d\n", count);
		for (int i = 0; i < 512 * 512; i++) {
			*(D8 + i) = 255;
		}
		for (auto& coordinate : path) {
			for (int r = 0; r < 512; r++) {
				for (int c = 0; c < 512; c++) {
					if (r == coordinate.x && c == coordinate.y) {
						*(D8 + r * 512 + c) = 0;
					}
				}
			}
		}
		for (int i = 0; i < 512 * 512; i++) {
			if (*(D8 + i) == 0) {
				*(D8 + i) = 255;
			}
			else {
				*(D8 + i) = 0;
			}
		}
		return D8;

	}
};