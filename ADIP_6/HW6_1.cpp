#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "MORPH.h"
using namespace std;

class HW6_1 {
private:
	MORPH morph;
public:
	void binaryImageMorph(unsigned char* src, unsigned char* dst) {
		vec2 size_rec(1, 2);
		vec2 size_3x3(3, 3);
		vec2 ori(1, 1);
		vec2 ori_rec(0, 0);
		vec2 image_size(512, 512);
		string type_3x3 = "0";
		string type_cross = "1";
		string type_rec = "2";
		
		unsigned char flag = 0;
		unsigned char flag2 = 255;
		kernal ker_rec = morph.getStructuringElement(size_rec, ori_rec, type_rec, flag);
		kernal ker_3x3 = morph.getStructuringElement(size_3x3, ori, type_3x3, flag);
		kernal ker_3x3_2 = morph.getStructuringElement(size_3x3, ori, type_3x3, flag2);
		kernal ker_cross = morph.getStructuringElement(size_3x3, ori, type_cross, flag);
		kernal ker_cross_2 = morph.getStructuringElement(size_3x3, ori, type_cross, flag2);

	
		morph.erode(src, dst, ker_rec, image_size, type_rec, flag);
		morph.erode(dst, dst, ker_rec, image_size, type_rec, flag);
		morph.erode(dst, dst, ker_rec, image_size, type_rec, flag);
		
		morph.dilate(dst, dst, ker_3x3, image_size, type_3x3, flag);
		morph.dilate(dst, dst, ker_3x3, image_size, type_3x3, flag);
		morph.dilate(dst, dst, ker_cross, image_size, type_cross, flag);

		morph.dilate(dst, dst, ker_3x3_2, image_size, type_3x3, flag2);

		morph.dilate(dst, dst, ker_cross, image_size, type_cross, flag);
		morph.dilate(dst, dst, ker_cross, image_size, type_cross, flag);
		morph.dilate(dst, dst, ker_cross, image_size, type_cross, flag);

		morph.dilate(dst, dst, ker_3x3_2, image_size, type_3x3, flag2);
		morph.dilate(dst, dst, ker_cross, image_size, type_cross, flag);
		morph.dilate(dst, dst, ker_cross, image_size, type_cross, flag);
	
		morph.erode(dst, dst, ker_cross, image_size, type_cross, flag);
		morph.dilate(dst, dst, ker_cross, image_size, type_cross, flag);

	}
};