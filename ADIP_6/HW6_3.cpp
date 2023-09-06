#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "MORPH.h"
using namespace std;

class HW6_3 {
private:
	MORPH morph;
public:
	void trimap(unsigned char* src, unsigned char* dst) {
		vec2 image_size(600, 600);
		unsigned char* binary_img = new unsigned char[600 * 600 * sizeof(unsigned char)];
		unsigned char* inside_img = new unsigned char[600 * 600 * sizeof(unsigned char)];
		unsigned char* foreground = new unsigned char[600 * 600 * sizeof(unsigned char)];
		morph.binary(src, binary_img, image_size, 245);
		vec2 size_rec(1, 2);
		vec2 size_3x3(3, 3);
		vec2 ori(1, 1);

		string type_3x3 = "0";
		string type_cross = "1";
		string type_rec = "2";

		unsigned char flag = 255;
		kernal ker_rec = morph.getStructuringElement(size_rec, ori, type_rec, flag);
		kernal ker_3x3 = morph.getStructuringElement(size_3x3, ori, type_3x3, flag);
		kernal ker_cross = morph.getStructuringElement(size_3x3, ori, type_cross, flag);

		//remove noise
		morph.dilate(binary_img, binary_img, ker_3x3, image_size, type_3x3, flag);
		morph.dilate(binary_img, binary_img, ker_3x3, image_size, type_3x3, flag);
		morph.dilate(binary_img, binary_img, ker_3x3, image_size, type_3x3, flag);
		morph.erode(binary_img, binary_img, ker_3x3, image_size, type_3x3, flag);
		morph.erode(binary_img, binary_img, ker_3x3, image_size, type_3x3, flag);
		morph.erode(binary_img, binary_img, ker_3x3, image_size, type_3x3, flag);
		morph.dilate(binary_img, binary_img, ker_3x3, image_size, type_3x3, flag);
		morph.dilate(binary_img, binary_img, ker_3x3, image_size, type_3x3, flag);
		//inside image
		for (int i = 0; i < 600 * 600; i++) {
			*(inside_img + i) = *(binary_img + i);
		}
		morph.erode(inside_img, inside_img, ker_3x3, image_size, type_3x3, flag);
		morph.erode(inside_img, inside_img, ker_3x3, image_size, type_3x3, flag);
		//erode for get foreground
		morph.dilate(binary_img, foreground, ker_3x3, image_size, type_3x3, flag);
		morph.dilate(foreground, foreground, ker_3x3, image_size, type_3x3, flag);
		morph.dilate(foreground, foreground, ker_3x3, image_size, type_3x3, flag);
		morph.dilate(foreground, foreground, ker_3x3, image_size, type_3x3, flag);
		morph.dilate(foreground, foreground, ker_3x3, image_size, type_3x3, flag);
		morph.dilate(foreground, foreground, ker_3x3, image_size, type_3x3, flag);
	
	/*	for (int i = 0; i < 600 * 600; i++) {

			
			*(dst + i) = *(binary_img + i);
			
		}*/
		for (int i = 0; i < 600 * 600; i++) {

			*(inside_img + i) = *(foreground + i) - *(inside_img + i);
			if (*(inside_img + i) == 255) {
				*(binary_img + i) = 128;
				*(dst + i) = *(binary_img + i);
			}
			else {
				*(dst + i) = *(binary_img + i);
			}
		}
		
	}
};