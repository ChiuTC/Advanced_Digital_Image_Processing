#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "MORPH.h"
using namespace std;

class HW6_2 {
private:
	MORPH morph;
public:
	void grayScaleImageErode(unsigned char* src, unsigned char* dst) {
		vec2 image_size(237, 613);
		morph.grayScaleErode(src, dst, image_size, false);
		
	}
	void grayScaleImageDilate(unsigned char* src, unsigned char* dst) {
		vec2 image_size(237, 613);
		morph.grayScaleDilate(src, dst, image_size, false);
	}
	void grayScaleImageOpening(unsigned char* src, unsigned char* dst) {
		vec2 image_size(237, 613);
		morph.grayScaleErode(src, dst, image_size, false);
		morph.grayScaleDilate(dst, dst, image_size, false);
	}
	void grayScaleImageClosing(unsigned char* src, unsigned char* dst) {
		vec2 image_size(237, 613);
		morph.grayScaleDilate(src, dst, image_size, false);
		morph.grayScaleErode(dst, dst, image_size, false);
	}
	void grayScaleImageErodeChange(unsigned char* src, unsigned char* dst) {
		vec2 image_size(237, 613);
		morph.grayScaleErode(src, dst, image_size, true);

	}
	void grayScaleImageDilateChange(unsigned char* src, unsigned char* dst) {
		vec2 image_size(237, 613);
		morph.grayScaleDilate(src, dst, image_size, true);
	}
};