#include <cstdlib>
#include <stdio.h>
#include <cstdio>
#include "MORPH.h"
#include <time.h>


using namespace std;
	
vec2::vec2() {
	r = 0;
	c = 0;
}

vec2::vec2(int r_, int c_) {
	r = r_;
	c = c_;
}

nlabelsList::nlabelsList() {
	label_value = nullptr;
	label_size = 0;
}

kernal::kernal(unsigned char* element_, vec2 size_, vec2 origin_) {
	element = element_;
	size = size_;
	origin = origin_;
	flag_num = 0;
}

labelInfo::labelInfo() {
	start = 0;
	end = 0;
	value = 0;
	change_num = 0;
	pre_value = 0;
	img_size.r = 0;
	img_size.c = 0;
	relation.reserve(2000);//use 10000  for more region
	isLabelExist.resize(2000, false);//use 10000 for more region
	labelInWhere.resize(2000, -1);//use 10000 for more region
	first.resize(200, 0);//use 1000 for more region
}

void MORPH::binary(unsigned char* src, unsigned char* dst, vec2 img_size, int threshold) {
	for (int r = 0; r < img_size.r; r++) {
		for (int c = 0; c < img_size.c; c++) {
			if (*(src + r * img_size.c + c) > threshold) {
				*(dst+ r * img_size.c + c) = 0;
			}
			else {
				*(dst + r * img_size.c + c) = 255;
			}
		}
	}
}
bool MORPH::isStructingElementEqual(unsigned char* src, vec2 src_origin, kernal ker) {
	unsigned char index = ker.size.r / 2;// 3/2=1
	bool equal = true;
	int padding_size_r = (800 + index * 2);
	int padding_size_c = (800 + index * 2);
	unsigned char src_val = *(src + (src_origin.r) * padding_size_c + (src_origin.c));
	unsigned char ker_val = 0;
	if (src_val != 255) {
		equal = false;
		return equal;
	}
	for (int x = -index; x <= index; x++) {//(r, c) (-1,-1) (0, -1) (1 ,-1)  (-1, 0) (0, 0) (1, 0)  (-1, 1), (0, 1) (1, 1) 左上到右下
		for (int y = -index; y <= index; y++) {
		    src_val = *(src + (src_origin.r + y) * padding_size_c + (src_origin.c + x));
		    ker_val = *(ker.element + (ker.origin.r + y) * (ker.size.c) + (ker.origin.c + x));
	
		    if (src_val != ker_val) {
				equal = false;
				return equal;
			}
		}
	}
	return equal;
}

bool MORPH::isOriginElementEqual(unsigned char* src, vec2 src_origin, kernal ker, vec2 image_size) {
	unsigned char index = ker.size.r / 2;// 3/2=1
	bool equal = true;
	int padding_size_r = (image_size.r + index * 2);
	int padding_size_c = (image_size.c + index * 2);
	unsigned char src_origin_val = *(src + src_origin.r * padding_size_c + src_origin.c);
	unsigned char ker_origin_val = *(ker.element + ker.origin.r * (ker.size.c) + (ker.origin.c));
	//printf("%d ,%d\n", src_origin_val, ker_origin_val);
	if (src_origin_val != ker_origin_val) {
		equal = false;
	}
	return equal;
}

unsigned char* MORPH::padding(unsigned char* src, vec2 size, vec2 image_size, unsigned char type) {
	unsigned char index = 0;
	
	index = size.r / 2;
	
	
	//index = 1;
	
	
	int padding_size_r = (image_size.r + index * 2);
	int padding_size_c = (image_size.c + index * 2);
	unsigned char* dst = new unsigned char[padding_size_r * padding_size_c * sizeof(unsigned char)];
	
	
	for (int r = 0; r < padding_size_r; r++) {
		for (int c = 0; c < padding_size_c; c++) {
			if (type == 0) {
				*(dst + r * padding_size_c + c) = 0;
			}
			else {
				*(dst + r * padding_size_c + c) = 255;
			}
		
		}
	}
	//總 (0~801)
	////(1~800),(1~800)
	//(0~799),(0~799)
	for (int r = index; r < padding_size_r - index; r++) {
		for (int c = index; c < padding_size_c - index; c++) {
			*(dst + r * padding_size_c + c) = *(src + (r - index) * image_size.c + (c - index));
		}
	}
	return dst;
}
void MORPH::thinning(unsigned char* src, kernal ker, kernal ker_mirror, vec2 image_size, string type,string type_mirror, unsigned char flag) {
	unsigned char* srcC = new unsigned char[image_size.r * image_size.c * sizeof(unsigned char)];
	for (int i = 0; i < image_size.r * image_size.c; i++) {
		if (*(src + i) == 255) {
			*(srcC + i) = 0;
		}
		else {
			*(srcC + i) = 255;
		}
	}
	unsigned char* erosion = new unsigned char[image_size.r * image_size.c * sizeof(unsigned char)];
	unsigned char* erosion2 = new unsigned char[image_size.r * image_size.c * sizeof(unsigned char)];
	
	unsigned char* AstarB = new unsigned char[image_size.r * image_size.c * sizeof(unsigned char)];
	erode(src, erosion, ker, image_size, type, flag);
	int count = 0;
	unsigned char* element = new unsigned char[ker.size.r * ker.size.c * sizeof(unsigned char)];
	kernal ker_back(element, ker.size, ker.origin);
	for (int i = 0; i < ker.size.r * ker.size.c; i++) {
		if (*(ker.element + i) == 255) {
			*(ker_back.element + i) = 0;
		}
		else if (*(ker.element + i) == 0) {
			*(ker_back.element + i) = 255;
			count += 1;
		}
		else if (*(ker.element + i) == 128) {
			*(ker_back.element + i) = 128;
			count += 1;
		}
	}
	ker_back.flag_num = count;
	
	erode(srcC, erosion2, ker_back, image_size, type, flag);
	
	/*for (int i = 0; i < image_size.r * image_size.c; i++) {
		if (*(erosion2 + i) == 255) {
			*(erosion2 + i) = 0;
		}
		else {
			*(erosion2 + i) = 255;
		}
	}*/
	
	
	for (int i = 0; i < image_size.r * image_size.c; i++) {
		if (*(erosion + i) == 255 && *(erosion2 + i) == 255) {
			*(AstarB + i) = 255;
		}
		else {
			*(AstarB + i) = 0;
		}
	}
	for (int i = 0; i < image_size.r * image_size.c; i++) {

		*(src + i) = *(erosion2 + i);

	}
	/*for (int i = 0; i < image_size.r * image_size.c; i++) {
		if (*(AstarB + i) == 255) {
			*(src + i) = 0;
		}
	}*/
}

kernal MORPH::getSE(vec2 size, vec2 origin, bool change) {
	unsigned char* element = new unsigned char[size.r * size.c * sizeof(unsigned char)];
	kernal ker(element, size, origin);
	if (change == false) {
		*(ker.element + 0 * size.r + 0) = 0;
		*(ker.element + 0 * size.r + 1) = 0;
		*(ker.element + 0 * size.r + 2) = 1;
		*(ker.element + 0 * size.r + 3) = 0;
		*(ker.element + 0 * size.r + 4) = 0;

		*(ker.element + 1 * size.r + 0) = 1;
		*(ker.element + 1 * size.r + 1) = 1;
		*(ker.element + 1 * size.r + 2) = 1;
		*(ker.element + 1 * size.r + 3) = 1;
		*(ker.element + 1 * size.r + 4) = 1;

		*(ker.element + 2 * size.r + 0) = 1;
		*(ker.element + 2 * size.r + 1) = 1;
		*(ker.element + 2 * size.r + 2) = 1;
		*(ker.element + 2 * size.r + 3) = 1;
		*(ker.element + 2 * size.r + 4) = 1;

		*(ker.element + 3 * size.r + 0) = 1;
		*(ker.element + 3 * size.r + 1) = 1;
		*(ker.element + 3 * size.r + 2) = 1;
		*(ker.element + 3 * size.r + 3) = 1;
		*(ker.element + 3 * size.r + 4) = 1;

		*(ker.element + 4 * size.r + 0) = 0;
		*(ker.element + 4 * size.r + 1) = 0;
		*(ker.element + 4 * size.r + 2) = 1;
		*(ker.element + 4 * size.r + 3) = 0;
		*(ker.element + 4 * size.r + 4) = 0;
	}
	else {
		*(ker.element + 0 * size.r + 0) = 0;
		*(ker.element + 0 * size.r + 1) = 1;
		*(ker.element + 0 * size.r + 2) = 1;
		*(ker.element + 0 * size.r + 3) = 1;
		*(ker.element + 0 * size.r + 4) = 0;

		*(ker.element + 1 * size.r + 0) = 0;
		*(ker.element + 1 * size.r + 1) = 1;
		*(ker.element + 1 * size.r + 2) = 1;
		*(ker.element + 1 * size.r + 3) = 1;
		*(ker.element + 1 * size.r + 4) = 0;

		*(ker.element + 2 * size.r + 0) = 1;
		*(ker.element + 2 * size.r + 1) = 1;
		*(ker.element + 2 * size.r + 2) = 1;
		*(ker.element + 2 * size.r + 3) = 1;
		*(ker.element + 2 * size.r + 4) = 1;

		*(ker.element + 3 * size.r + 0) = 0;
		*(ker.element + 3 * size.r + 1) = 1;
		*(ker.element + 3 * size.r + 2) = 1;
		*(ker.element + 3 * size.r + 3) = 1;
		*(ker.element + 3 * size.r + 4) = 1;

		*(ker.element + 4 * size.r + 0) = 0;
		*(ker.element + 4 * size.r + 1) = 1;
		*(ker.element + 4 * size.r + 2) = 1;
		*(ker.element + 4 * size.r + 3) = 1;
		*(ker.element + 4 * size.r + 4) = 0;
	}

	return ker;
}
kernal MORPH::getStructuringElement(vec2 size, vec2 origin, string type = "0", unsigned char flag = 0) {
	unsigned char* element = new unsigned char[size.r * size.c * sizeof(unsigned char)];//3x3 = 9

	kernal ker(element, size, origin);

	if (type == "0") {
		for (int r = 0; r < size.r; r++) {
			for (int c = 0; c < size.c; c++) {
				*(ker.element + r * size.r + c) = flag;
				if (*(ker.element + r * size.r + c) == flag) {
					ker.flag_num += 1;
				}
			}
		}
		
	}
	else if (type == "1") {	
		if (flag > 0) {
			*(ker.element + 0 * size.r + 0) = 0;
			*(ker.element + 0 * size.r + 1) = flag;
			*(ker.element + 0 * size.r + 2) = 0;
			*(ker.element + 1 * size.r + 0) = flag;
			*(ker.element + 1 * size.r + 1) = flag;
			*(ker.element + 1 * size.r + 2) = flag;
			*(ker.element + 2 * size.r + 0) = 0;
			*(ker.element + 2 * size.r + 1) = flag;
			*(ker.element + 2 * size.r + 2) = 0;
		}
		else {
			*(ker.element + 0 * size.r + 0) = 255;
			*(ker.element + 0 * size.r + 1) = flag;
			*(ker.element + 0 * size.r + 2) = 255;
			*(ker.element + 1 * size.r + 0) = flag;
			*(ker.element + 1 * size.r + 1) = flag;
			*(ker.element + 1 * size.r + 2) = flag;
			*(ker.element + 2 * size.r + 0) = 255;
			*(ker.element + 2 * size.r + 1) = flag;
			*(ker.element + 2 * size.r + 2) = 255;
		}
		ker.flag_num = 5;
	}
	else if (type == "2") {
		*(ker.element + 0 * size.r + 0) = flag;
		*(ker.element + 0 * size.r + 1) = flag;
		ker.flag_num = 2;
	}
	else if (type == "3") {
		if (flag > 0) {
			*(ker.element + 0 * size.r + 0) = 0;
			*(ker.element + 0 * size.r + 1) = 0;
			*(ker.element + 0 * size.r + 2) = 0;
			*(ker.element + 1 * size.r + 0) = 128;
			*(ker.element + 1 * size.r + 1) = flag;
			*(ker.element + 1 * size.r + 2) = 128;
			*(ker.element + 2 * size.r + 0) = flag;
			*(ker.element + 2 * size.r + 1) = flag;
			*(ker.element + 2 * size.r + 2) = flag;
			
		}
		else {
			*(ker.element + 0 * size.r + 0) = flag;
			*(ker.element + 0 * size.r + 1) = flag;
			*(ker.element + 0 * size.r + 2) = flag;
			*(ker.element + 1 * size.r + 0) = 128;
			*(ker.element + 1 * size.r + 1) = 0;
			*(ker.element + 1 * size.r + 2) = 128;
			*(ker.element + 2 * size.r + 0) = 0;
			*(ker.element + 2 * size.r + 1) = 0;
			*(ker.element + 2 * size.r + 2) = 0;
			
		}
		ker.flag_num = 7;
	}
	else if (type == "4") {
		if (flag > 0) {
			*(ker.element + 0 * size.r + 0) = 128;
			*(ker.element + 0 * size.r + 1) = 0;
			*(ker.element + 0 * size.r + 2) = 0;
			*(ker.element + 1 * size.r + 0) = flag;
			*(ker.element + 1 * size.r + 1) = flag;
			* (ker.element + 1 * size.r + 2) = 0;
			*(ker.element + 2 * size.r + 0) = flag;
			*(ker.element + 2 * size.r + 1) = flag;
			*(ker.element + 2 * size.r + 2) = 128;
			
		}
		else {
			*(ker.element + 0 * size.r + 0) = 128;
			*(ker.element + 0 * size.r + 1) = flag;
			*(ker.element + 0 * size.r + 2) = flag;
			*(ker.element + 1 * size.r + 0) = 0;
			*(ker.element + 1 * size.r + 1) = 0;
			*(ker.element + 1 * size.r + 2) = flag;
			*(ker.element + 2 * size.r + 0) = 0;
			*(ker.element + 2 * size.r + 1) = 0;
			*(ker.element + 2 * size.r + 2) = 128;
			
		}
		ker.flag_num = 7;
	}

	else if (type == "5") {
		if (flag > 0) {
			*(ker.element + 0 * size.r + 0) = flag;
			*(ker.element + 0 * size.r + 1) = 128;
			*(ker.element + 0 * size.r + 2) = 0;
			*(ker.element + 1 * size.r + 0) = flag;
			*(ker.element + 1 * size.r + 1) = flag;
			*(ker.element + 1 * size.r + 2) = 0;
			*(ker.element + 2 * size.r + 0) = flag;
			*(ker.element + 2 * size.r + 1) = 128;
			*(ker.element + 2 * size.r + 2) = 0;
			
		}
		else {
			*(ker.element + 0 * size.r + 0) = 0;
			*(ker.element + 0 * size.r + 1) = 128;
			*(ker.element + 0 * size.r + 2) = flag;
			*(ker.element + 1 * size.r + 0) = 0;
			*(ker.element + 1 * size.r + 1) = 0;
			*(ker.element + 1 * size.r + 2) = flag;
			*(ker.element + 2 * size.r + 0) = 0;
			*(ker.element + 2 * size.r + 1) = 128;
			*(ker.element + 2 * size.r + 2) = flag;
			
		}
		ker.flag_num = 7;
	}
	else if (type == "6") {
		if (flag > 0) {
			*(ker.element + 0 * size.r + 0) = flag;
			*(ker.element + 0 * size.r + 1) = flag;
			*(ker.element + 0 * size.r + 2) = 128;
			*(ker.element + 1 * size.r + 0) = flag;
			*(ker.element + 1 * size.r + 1) = flag;
			*(ker.element + 1 * size.r + 2) = 0;
			*(ker.element + 2 * size.r + 0) = 128;
			*(ker.element + 2 * size.r + 1) = 0;
			*(ker.element + 2 * size.r + 2) = 0;
			
		}
		else {
			*(ker.element + 0 * size.r + 0) = 0;
			*(ker.element + 0 * size.r + 1) = 0;
			*(ker.element + 0 * size.r + 2) = 128;
			*(ker.element + 1 * size.r + 0) = 0;
			*(ker.element + 1 * size.r + 1) = 0;
			*(ker.element + 1 * size.r + 2) = flag;
			*(ker.element + 2 * size.r + 0) = 128;
			*(ker.element + 2 * size.r + 1) = flag;
			*(ker.element + 2 * size.r + 2) = flag;
			
		}
		ker.flag_num = 7;
	}
	else if (type == "7") {
		if (flag > 0) {
			*(ker.element + 0 * size.r + 0) = flag;
			*(ker.element + 0 * size.r + 1) = flag;
			*(ker.element + 0 * size.r + 2) = flag;
			*(ker.element + 1 * size.r + 0) = 128;
			*(ker.element + 1 * size.r + 1) = flag;
			*(ker.element + 1 * size.r + 2) = 128;
			*(ker.element + 2 * size.r + 0) = 0;
			*(ker.element + 2 * size.r + 1) = 0;
			*(ker.element + 2 * size.r + 2) = 0;
			
		}
		else {
			*(ker.element + 0 * size.r + 0) = 0;
			*(ker.element + 0 * size.r + 1) = 0;
			*(ker.element + 0 * size.r + 2) = 0;
			*(ker.element + 1 * size.r + 0) = 128;
			*(ker.element + 1 * size.r + 1) = 0;
			*(ker.element + 1 * size.r + 2) = 128;
			*(ker.element + 2 * size.r + 0) = flag;
			*(ker.element + 2 * size.r + 1) = flag;
			*(ker.element + 2 * size.r + 2) = flag;
			
		}
		ker.flag_num = 7;
	}
	else if (type == "8") {
		if (flag > 0) {
			*(ker.element + 0 * size.r + 0) = 128;
			*(ker.element + 0 * size.r + 1) = flag;
			*(ker.element + 0 * size.r + 2) = flag;
			*(ker.element + 1 * size.r + 0) = 0;
			*(ker.element + 1 * size.r + 1) = flag;
			*(ker.element + 1 * size.r + 2) = flag;
			*(ker.element + 2 * size.r + 0) = 0;
			*(ker.element + 2 * size.r + 1) = 0;
			*(ker.element + 2 * size.r + 2) = 128;
			
		}
		else {
			*(ker.element + 0 * size.r + 0) = 128;
			*(ker.element + 0 * size.r + 1) = 0;
			*(ker.element + 0 * size.r + 2) = 0;
			*(ker.element + 1 * size.r + 0) = flag;
			*(ker.element + 1 * size.r + 1) = 0;
			*(ker.element + 1 * size.r + 2) = 0;
			*(ker.element + 2 * size.r + 0) = flag;
			*(ker.element + 2 * size.r + 1) = flag;
			*(ker.element + 2 * size.r + 2) = 128;
			
		}
		ker.flag_num = 7;
	}
	else if (type == "9") {
		if (flag > 0) {
			*(ker.element + 0 * size.r + 0) = 0;
			*(ker.element + 0 * size.r + 1) = 128;
			*(ker.element + 0 * size.r + 2) = flag;
			*(ker.element + 1 * size.r + 0) = 0;
			*(ker.element + 1 * size.r + 1) = flag;
			*(ker.element + 1 * size.r + 2) = flag;
			*(ker.element + 2 * size.r + 0) = 0;
			*(ker.element + 2 * size.r + 1) = 128;
			*(ker.element + 2 * size.r + 2) = flag;
			
		}
		else {
			*(ker.element + 0 * size.r + 0) = flag;
			*(ker.element + 0 * size.r + 1) = 128;
			*(ker.element + 0 * size.r + 2) = 0;
			*(ker.element + 1 * size.r + 0) = flag;
			*(ker.element + 1 * size.r + 1) = 0;
			*(ker.element + 1 * size.r + 2) = 0;
			*(ker.element + 2 * size.r + 0) = flag;
			*(ker.element + 2 * size.r + 1) = 128;
			*(ker.element + 2 * size.r + 2) = 0;
			
		}
		ker.flag_num = 7;
	}
	else if (type == "10") {
		if (flag > 0) {
			*(ker.element + 0 * size.r + 0) = 0;
			*(ker.element + 0 * size.r + 1) = 0;
			*(ker.element + 0 * size.r + 2) = 128;
			*(ker.element + 1 * size.r + 0) = 0;
			*(ker.element + 1 * size.r + 1) = flag;
			*(ker.element + 1 * size.r + 2) = flag;
			*(ker.element + 2 * size.r + 0) = 128;
			*(ker.element + 2 * size.r + 1) = flag;
			*(ker.element + 2 * size.r + 2) = flag;
			
		}
		else {
			*(ker.element + 0 * size.r + 0) = flag;
			*(ker.element + 0 * size.r + 1) = flag;
			*(ker.element + 0 * size.r + 2) = 128;
			*(ker.element + 1 * size.r + 0) = flag;
			*(ker.element + 1 * size.r + 1) = 0;
			*(ker.element + 1 * size.r + 2) = 0;
			*(ker.element + 2 * size.r + 0) = 128;
			*(ker.element + 2 * size.r + 1) = 0;
			*(ker.element + 2 * size.r + 2) = 0;
			
		}
		ker.flag_num = 7;
	}
	return ker;
}

unsigned char* MORPH::grayScaleErode(unsigned char* src, unsigned char* dst, vec2 image_size, bool change) {
	vec2 size(5, 5);
	vec2 ori(2, 2);
	kernal ker = getSE(size, ori, change);
	unsigned char index = ker.size.r / 2;
	int padding_size_r = (image_size.r + index * 2);
	int padding_size_c = (image_size.c + index * 2);
	
	unsigned char* padding_src = new unsigned char[padding_size_r * padding_size_c * sizeof(unsigned char)];
	vec2 pre_ori(0, 0);
	padding_src = padding(src, ker.size, image_size, 1);
	unsigned char min = 255;
	for (int r = index; r < padding_size_r - index; r++) {
		for (int c = index; c < padding_size_c - index; c++) {
			min = 255;
			for (int x = -index; x <= index; x++) {
				for (int y = -index; y <= index; y++) {
					unsigned char val = *(padding_src + (r + x) * padding_size_c + (c + y)) - *(ker.element + (x + index) * ker.size.c + (y + index));
					if (val < min) {
						min = val;
					}
				}
			}
			*(dst + (r - index) * image_size.c + (c - index)) = min;
		}
	}
	return dst;
}

unsigned char* MORPH::grayScaleDilate(unsigned char* src, unsigned char* dst, vec2 image_size, bool change) {
	vec2 size(5, 5);
	vec2 ori(2, 2);
	kernal ker = getSE(size, ori, change);
	unsigned char index = ker.size.r / 2;
	int padding_size_r = (image_size.r + index * 2);
	int padding_size_c = (image_size.c + index * 2);
	
	unsigned char* padding_src = new unsigned char[padding_size_r * padding_size_c * sizeof(unsigned char)];
	vec2 pre_ori(0, 0);
	padding_src = padding(src, ker.size, image_size, 0);
	unsigned char max = 0;
	for (int r = index; r < padding_size_r - index; r++) {
		for (int c = index; c < padding_size_c - index; c++) {
			max = 0;
			for (int x = -index; x <= index; x++) {
				for (int y = -index; y <= index; y++) {
					unsigned char val = *(padding_src + (r + x) * padding_size_c + (c + y)) + *(ker.element + (x + index) * ker.size.c + (y + index));
					if (val > max) {
						max = val;
					}
				}
			}
			*(dst + (r - index) * image_size.c + (c - index)) = max;
		}
	}
	return dst;
}


unsigned char* MORPH::erode(unsigned char* src, unsigned char* dst, kernal ker, vec2 image_size, string type , unsigned char flag) {
	unsigned char index = ker.size.r / 2;

	int padding_size_r = (image_size.r + index * 2);
	int padding_size_c = (image_size.c + index * 2);

	unsigned char* padding_src = new unsigned char[padding_size_r * padding_size_c * sizeof(unsigned char)];
	vec2 pre_ori(0, 0);
	if (type == "3" || type == "4" || type == "5" || type == "6" || type == "7" || type == "8" || type == "9" || type == "10") {
		padding_src = padding(src, ker.size, image_size, 0);
	}
	else {
		padding_src = padding(src, ker.size, image_size, 1);
	}
	int count = 0;
	if (type == "0" || type == "1") {
		for (int r = index; r < padding_size_r - index; r++) {
			for (int c = index; c < padding_size_c - index; c++) {
				pre_ori.r = r;
				pre_ori.c = c;
				//if (isStructingElementEqual(padding_src, pre_ori, ker)) {
				//	*(dst + (r - index) * 800 + (c - index)) = 255;//reserve
				//}
				//else {
				//	*(dst + (r - index) * 800 + (c - index)) = 0;//delete
				//}
				count = 0;
				if (index == 1 && *(padding_src + r * padding_size_c + c) == flag) {
					for (int x = -index; x <= index; x++) {//(r, c) (-1,-1) (0, -1) (1 ,-1)  (-1, 0) (0, 0) (1, 0)  (-1, 1), (0, 1) (1, 1) 左上到右下
						for (int y = -index; y <= index; y++) {
							if (*(ker.element + ((x + index) * ker.size.c) + (y + index)) == *(padding_src + (r + x) * padding_size_c + (c + y)) && *(ker.element + ((x + index) * ker.size.c) + (y + index)) == flag){
								count += 1;
								
							}
							//printf("%d\n", *(ker.element + ((x + index) * ker.size.c) + (y + index)));
						}
					}
					if (count == ker.flag_num) {
						*(dst + (r - index) * image_size.c + (c - index)) = flag;
						
					}
					else {
						if (flag > 0) {
							*(dst + (r - index) * image_size.c + (c - index)) = 0;
						}
						else {
							*(dst + (r - index) * image_size.c + (c - index)) = 255;
						}
					}
					//printf("%d,%d\n", *(padding_src + r * padding_size_c + c), *(dst + (r - index) * image_size.c + (c - index)));
					/*if (
						*(padding_src + (r - 1) * padding_size_c + (c - 1)) == flag
						&& *(padding_src + (r - 1) * padding_size_c + (c)) == flag 
						&& *(padding_src + (r - 1) * padding_size_c + (c + 1)) == flag 
						&&*(padding_src + (r)*padding_size_c + (c - 1)) == flag 
						&& *(padding_src + (r)*padding_size_c + (c)) == flag
						&& *(padding_src + (r)*padding_size_c + (c + 1)) == flag 
						&&*(padding_src + (r + 1) * padding_size_c + (c - 1)) == flag 
						&& *(padding_src + (r + 1) * padding_size_c + (c)) == flag 
						&& *(padding_src + (r + 1) * padding_size_c + (c + 1)) == flag) {
						*(dst + (r - index) * image_size.c + (c - index)) = flag;
					}
					else {
						if (flag > 0) {
							*(dst + (r - index) * image_size.c + (c - index)) = 0;
						}
						else {
							*(dst + (r - index) * image_size.c + (c - index)) = 255;
						}
					}*/
				}
				else {
					if (flag > 0) {
						*(dst + (r - index) * image_size.c + (c - index)) = 0;
					}
					else {
						*(dst + (r - index) * image_size.c + (c - index)) = 255;
					}
				}
			}
		}
	}
	else if (type == "2") {
		for (int r = index; r < padding_size_r - index; r++) {
			for (int c = index; c < padding_size_c - index; c++) {
				pre_ori.r = r;
				pre_ori.c = c;
				if (*(padding_src + r * padding_size_c + c) == flag) {
					if ( *(padding_src + (r)*padding_size_c + (c)) == flag && *(padding_src + (r)*padding_size_c + (c + 1)) == flag) {
						*(dst + (r - index) * image_size.c + (c - index)) = flag;
					}
					else {
						if (flag > 0) {
							*(dst + (r - index) * image_size.c + (c - index)) = 0;
						}
						else {
							*(dst + (r - index) * image_size.c + (c - index)) = 255;
						}
					}
				}
				else {
					if (flag > 0) {
						*(dst + (r - index) * image_size.c + (c - index)) = 0;
					}
					else {
						*(dst + (r - index) * image_size.c + (c - index)) = 255;
					}
				}
			}
		}
	}
	else if (type == "3" || type == "4" || type == "5" || type == "6" || type == "7" || type == "8" || type == "9" || type == "10") {
		for (int r = index; r < padding_size_r - index; r++) {
			for (int c = index; c < padding_size_c - index; c++) {
				pre_ori.r = r;
				pre_ori.c = c;		
				count = 0;	
					for (int x = -index; x <= index; x++) {
						for (int y = -index; y <= index; y++) {
							if (*(ker.element + ((x + index) * ker.size.c) + (y + index)) != 128) {
								if (*(ker.element + ((x + index) * ker.size.c) + (y + index)) == *(padding_src + (r + x) * padding_size_c + (c + y))) {
									count += 1;
								}
							}	
						}
					}
					if (count == ker.flag_num) {
						if (flag > 0) {
							*(dst + (r - index) * image_size.c + (c - index)) = 0;
						}
						else {
							*(dst + (r - index) * image_size.c + (c - index)) = 255;
						}
					}
					else {
						*(dst + (r - index) * image_size.c + (c - index)) = *(padding_src + (r)*padding_size_c + (c));
					}
				}			
		}
	}
	return dst;
}

unsigned char* MORPH::dilate(unsigned char* src, unsigned char* dst, kernal ker, vec2 image_size, string type, unsigned char flag) {
	unsigned char index = ker.size.r / 2;

	int padding_size_r = (image_size.r + index * 2);
	int padding_size_c = (image_size.c + index * 2);

	unsigned char* padding_src = new unsigned char[padding_size_r * padding_size_c * sizeof(unsigned char)];
	vec2 pre_ori(0, 0);
	padding_src = padding(src, ker.size, image_size, 0);

	if (type == "0" || type == "1" || type == "3" || type == "4" || type == "5" || type == "6" || type == "7" || type == "8" || type == "9" || type == "10") {
		
		for (int r = index; r < padding_size_r - index; r++) {
			for (int c = index; c < padding_size_c - index; c++) {
				pre_ori.r = r;
				pre_ori.c = c;
				
				if (isOriginElementEqual(padding_src, pre_ori, ker, image_size)) {
					for (int x = -index; x <= index; x++) {//(r, c) (-1,-1) (0, -1) (1 ,-1)  (-1, 0) (0, 0) (1, 0)  (-1, 1), (0, 1) (1, 1) 左上到右下
						for (int y = -index; y <= index; y++) {
							if (*(ker.element + ((x + 1) * ker.size.c) + (y + 1)) == flag) {
								if (r - index + x >= 0 && (c - index + y) >= 0 && r - index + x < image_size.r && c - index + y < image_size.c) {
									*(dst + (r - index + x) * image_size.c + (c - index + y)) = flag;	
								}
							}
						}
					}
				}
				else {
					if (flag > 0) {
						*(dst + (r - index) * image_size.c + (c - index)) = 0;
					}
					else {
						*(dst + (r - index) * image_size.c + (c - index)) = 255;
					}
				}
			}
		}
	}
	else if (type == "2") {
		for (int r = index; r < padding_size_r - index; r++) {
			for (int c = index; c < padding_size_c - index; c++) {
				pre_ori.r = r;
				pre_ori.c = c;
				if (isOriginElementEqual(padding_src, pre_ori, ker, image_size)) {
					for (int x = 0; x < 1; x++) {
						for (int y = 0; y < 2; y++) {
							if (*(ker.element + (x) * ker.size.c) + (y) == flag) {
								if (r - index + x >= 0 && (c - index + y) >= 0 && r - index + x < image_size.r && c - index + y < image_size.c) {
									*(dst + (r - index + x) * image_size.c + (c - index + y)) = flag;
									
								}
							}
						}
					}
				}
				else {
					if (flag > 0) {
						*(dst + (r - index) * image_size.c + (c - index)) = 0;
					}
					else {
						*(dst + (r - index) * image_size.c + (c - index)) = 255;
					}
				}
			}
		}
	}
	return dst;
}

void MORPH::calRelationList(unsigned __int16 upper, unsigned __int16 left, labelInfo* label_info) {
	bool upperExist = label_info->isLabelExist[upper];
	bool leftExist = label_info->isLabelExist[left];
	unsigned __int16 upperInWhere = 0;
	unsigned __int16 leftInWhere = 0;
	unsigned __int16 upperIndex = 0;
	unsigned __int16 leftIndex = 0;
	
	//都存在，如果不在同一組裡，則把left的組移到upper的組
	//{5,9,-1} {7,8,12,-1}
	if (upperExist && leftExist) {
		//printf("%d,%d\n", label_info->labelInWhere[upper], label_info->labelInWhere[left]);
		upperInWhere = label_info->labelInWhere[upper];
		leftInWhere = label_info->labelInWhere[left];
		if (upperInWhere == leftInWhere) {
			return;
		}
		else if (upperInWhere != leftInWhere) {
			unsigned __int16 start = 0;
			unsigned __int16 end = 0;
			vector<__int16>::iterator it = find(label_info->relation.begin(), label_info->relation.end(), left);
			leftIndex = distance(label_info->relation.begin(), it);
			it = find(label_info->relation.begin(), label_info->relation.end(), upper);
			upperIndex = distance(label_info->relation.begin(), it);
			//printf("label_info->relation.size():%d\n", label_info->relation.size());
			//for (int i = leftIndex; i < label_info->relation.size(); i++) {

			//	if (label_info->labelInWhere[label_info->relation[i]] != leftInWhere) {
			//		end = i - 1;
			//		break;
			//	}
			//	else {
			//		end = i;
			//	}
			//}
			////printf("end :%d\n", end);
			//for (int i = leftIndex; i >= 0; i--) {	
			//	if (label_info->labelInWhere[label_info->relation[i]] != leftInWhere) {
			//		start = i + 1;
			//		break;
			//	}
			//	else {
			//		start = i;
			//	}
			//}
			////printf("start :%d\n", start);
			//for (int i = start; i <= end; i++) {
			//	label_info->labelInWhere[label_info->relation[i]] = label_info->labelInWhere[upper];
			//}

			for (__int16 i = 0; i < label_info->relation.size(); i++) {
					if (label_info->labelInWhere[label_info->relation[i]] == leftInWhere) {
						label_info->labelInWhere[label_info->relation[i]] = upperInWhere;
					}	
			}
		}
	}
	//只有一個value存在
	else if (upperExist || leftExist) {
		//{1, 2, -1, 3, 4, -1} = > {1, 2, -1, 3, 4, 5, -1}
		//假設upper不存在(5)插入到left(4)之後
		if (!upperExist) {
			vector<__int16>::iterator it = find(label_info->relation.begin(), label_info->relation.end(), left);
			label_info->relation.insert(label_info->relation.begin() + distance(label_info->relation.begin(), it) + 1, upper);
			label_info->isLabelExist[upper] = true;
			label_info->labelInWhere[upper] = label_info->labelInWhere[left];
		}
		//{1, 2, -1, 3, 4, 5, -1}=>{1, 2, 6, -1, 3, 4, 5, -1}
		//假設left不存在(6)插入到upper(2)之後
		else if (!leftExist) {
			vector<__int16>::iterator it = find(label_info->relation.begin(), label_info->relation.end(), upper);
			label_info->relation.insert(label_info->relation.begin() + distance(label_info->relation.begin(), it) + 1, left);
			label_info->isLabelExist[left] = true;
			label_info->labelInWhere[left] = label_info->labelInWhere[upper];
		}	
	}
	//都不存在
	//{1,2,-1,3,4,-1}
	else if(!(upperExist && leftExist)) {
		//printf("u:%d, l:%d\n", upper, left);
		label_info->relation.push_back(upper);
		label_info->relation.push_back(left);
		//label_info->relation.push_back(-1);
		label_info->isLabelExist[upper] = true; 
		label_info->isLabelExist[left] = true; 
		label_info->labelInWhere[upper] = label_info->value;
		label_info->labelInWhere[left] = label_info->value;
		label_info->first[label_info->value] = upper;
		label_info->value += 1;
		//printf("label_info->value:%d\n", label_info->value);
	}
	//return relation;
}

unsigned __int16 MORPH::doLabel(unsigned __int16* dst, vec2 point, unsigned __int16 label, labelInfo* label_info) {
	unsigned __int16 label_ = label;
	unsigned __int16 upper = 0;
	unsigned __int16 left = 0;
	if (label_info->end == 1) {
		label_info->start = point.c;
	}
	
	if ((point.r - 1) < 0 ) {
		upper = 0;
	}else {
		upper = *(dst + (point.r - 1) * label_info->img_size.c + point.c);
	}

	if ((point.c - 1) < 0) {
		left = 0;
	}else {
		left = *(dst + (point.r) * label_info->img_size.c + (point.c - 1));
	}
	//printf("%d,%d\n", upper, left);
	//附近有兩個label值，選擇比較小的
	if ( upper > 0 && left > 0) {
		if (upper > left) {
			*(dst + point.r * label_info->img_size.c + point.c) = left;
		}
		else if (left > upper) {
			//ori
			*(dst + point.r * label_info->img_size.c + point.c) = upper;
			//把dst裡面當前row的label 變成 upper
			//effi
			//printf("%d, %d\n", label_info->start, label_info->end);
			/*for (int i = 0; i < label_info->end; i++) {
				*(dst + point.r * 800 + label_info->start + i) = upper;
			}
			label_info->change_num += 1;
			label_info->pre_value = left;*/
			
		}
		else if (left == upper) {
			*(dst + point.r * label_info->img_size.c + point.c) = left;
		}
	}
	//附近只有一個label值
	else if (upper > 0 || left > 0) {
		if (upper > 0) {
			*(dst + point.r * label_info->img_size.c + point.c) = upper;
		}
		else if (left > 0) {
			*(dst + point.r * label_info->img_size.c + point.c) = left;
		}
	}
	//附近沒有label值
	else if (upper == 0 && left == 0) {
		label_ += 1;
		*(dst + point.r * label_info->img_size.c + point.c) = label_;
	}

	return label_;
}
void MORPH::doList(unsigned __int16* dst, vec2 point, labelInfo* label_info) {
	unsigned __int16 upper = 0;
	unsigned __int16 left = 0;

	if ((point.r - 1) < 0) {
		upper = 0;
	}else {
		upper = *(dst + (point.r - 1) * label_info->img_size.c + point.c);
	}

	if ((point.c - 1) < 0) {
		left = 0;
	}else {
		left = *(dst + (point.r) * label_info->img_size.c + (point.c - 1));
	}
	//附近有兩個label值
	if (upper > 0 && left > 0) {
		if (upper > left) {
			calRelationList(left, upper, label_info);
		}
		/*else if (label_info->change_num > 0) {
			calRelationList(upper, label_info->pre_value, label_info);
		}*/
		else if (left > upper) {
			calRelationList(upper, left, label_info);
		}
	}

	//return relation;
}

nlabelsList MORPH::connectedComponents(unsigned char* src, unsigned __int16* dst, int row, int col) {
	//copy to dst
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			*(dst + r * col + c) = *(src + r * col + c);
		}
	}
	unsigned __int16 label = 0;
	
	labelInfo* label_info = new labelInfo[sizeof(labelInfo)];
	
	label_info->img_size.r = row;
	label_info->img_size.c = col;
	vec2 pre_point(0, 0);
	for (int r = 0; r < label_info->img_size.r; r++) {
		for (int c = 0; c < label_info->img_size.c; c++) {
			pre_point.r = r;
			pre_point.c = c;
			if (*(src + r * label_info->img_size.c + c) == 255) {
				//label_info->end += 1;
				label = doLabel(dst, pre_point, label, label_info);
				doList(dst, pre_point, label_info);
				//printf("[%d,%d] label = %d\n", r, c, *(dst + r * 800 + c));
			}
			else {
				/*label_info->start = 0;
				label_info->end = 0;
				label_info->change_num = 0;
				label_info->pre_value = 0;*/
			}
		    //printf("[%d,%d] label = %d\n", r, c, *(dst + r * 800 + c));
		}
	/*	label_info->start = 0;
		label_info->end = 0;
		label_info->change_num = 0;
		label_info->pre_value = 0;*/
	}
	//printf("dolabel and dolist\n");
	//unsigned char nlabels_relation_size = 1;
	//unsigned char index = 1;

	//printf("nlabels_relation_size:%d\n", nlabels_relation_size);
	//printf("xx:%d\n", label_info->labelInWhere[*(dst + 354582)]);
	//second pass
	for (int x = 0; x < label_info->img_size.r * label_info->img_size.c; x++) {
	    if (*(dst + x) != 0 && label_info->labelInWhere[*(dst + x)] != -1) {
			//*(dst + x) = cor_table[*(dst + x)];
			*(dst + x) = label_info->first[label_info->labelInWhere[*(dst + x)]];
			//printf("%d\n", *(dst + x));
		}
	}
	//printf("second pass\n");
	vector<__int16> diff_label;
	diff_label.reserve(100);
	bool exist = false;
	for (int i = 0; i < label_info->img_size.r * label_info->img_size.c; i++) {
		//printf("%d\n", *(dst + i));
		for (int x = 0; x < diff_label.size(); x++) {
			if (diff_label[x] == *(dst + i)) {
				exist = true;
				break;
			}
		}
		if (!exist) {
			diff_label.push_back(*(dst + i));
		}
		exist = false;
	}
	/*for (int x = 0; x < diff_label.size(); x++) {
		printf("diff_label:%d\n", diff_label[x]);
	}*/
	unsigned int* nlabels = new unsigned int[diff_label.size() * sizeof(unsigned int)];
	for (int i = 0; i < diff_label.size(); i++) {
		*(nlabels + i) = diff_label[i];
	}
	nlabelsList list;

	list.label_size = diff_label.size();
	list.label_value = nlabels;
	//printf("connectedComponents\n");
	return list;
}


