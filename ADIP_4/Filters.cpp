#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "Filters.h"
#include <math.h>
#define PI 3.1415926


vec2::vec2() {
	r = 0;
	c = 0;
}
vec2::vec2(int r_, int c_) {
	r = r_;
	c = c_;
}
kernal::kernal(vec2 size_) {
	element = new double[size_.r * size_.c * sizeof(double)];
	size = size_;
}
kernal Filters::getFilters(vec2 size, unsigned char mode) {

	kernal ker(size);
	switch (mode) {
		//Laplacian filter 1
		case 1:
			*(ker.element + 0 * size.r + 0) = 0;
			*(ker.element + 0 * size.r + 1) = -1;
			*(ker.element + 0 * size.r + 2) = 0;
			*(ker.element + 1 * size.r + 0) = -1;
			*(ker.element + 1 * size.r + 1) = 4;
			*(ker.element + 1 * size.r + 2) = -1;
			*(ker.element + 2 * size.r + 0) = 0;
			*(ker.element + 2 * size.r + 1) = -1;
			*(ker.element + 2 * size.r + 2) = 0;
			break;
		//Laplacian filter 2
		case 2:
			for (int r = 0; r < size.r; r++) {
				for (int c = 0; c < size.c; c++) {
					if (r == 1 && c == 1) {
						*(ker.element + r * size.r + c) = 8;
					}
					else {
						*(ker.element + r * size.r + c) = -1;
					}
				}
			}
			break;
		//Sobel filter x
		case 3:
			*(ker.element + 0 * size.r + 0) = -1;
			*(ker.element + 0 * size.r + 1) = 0;
			*(ker.element + 0 * size.r + 2) = 1;
			*(ker.element + 1 * size.r + 0) = -2;
			*(ker.element + 1 * size.r + 1) = 0;
			*(ker.element + 1 * size.r + 2) = 2;
			*(ker.element + 2 * size.r + 0) = -1;
			*(ker.element + 2 * size.r + 1) = 0;
			*(ker.element + 2 * size.r + 2) = 1;
			break;
		//Sobel filter y
		case 4:
			*(ker.element + 0 * size.r + 0) = -1;
			*(ker.element + 0 * size.r + 1) = -2;
			*(ker.element + 0 * size.r + 2) = -1;
			*(ker.element + 1 * size.r + 0) = 0;
			*(ker.element + 1 * size.r + 1) = 0;
			*(ker.element + 1 * size.r + 2) = 0;
			*(ker.element + 2 * size.r + 0) = 1;
			*(ker.element + 2 * size.r + 1) = 2;
			*(ker.element + 2 * size.r + 2) = 1;
			break;
		//mean filter
		case 5:
			for (int r = 0; r < size.r; r++) {
				for (int c = 0; c < size.c; c++) {
					*(ker.element + r * size.r + c) = 1.0f / (ker.size.r * ker.size.c);
					//printf("%f\n", *(ker.element + r * size.r + c));
				}
			}
			break;
		//ori+lap filter
		case 6 :
			*(ker.element + 0 * size.r + 0) = -1;
			*(ker.element + 0 * size.r + 1) = -1;
			*(ker.element + 0 * size.r + 2) = -1;
			*(ker.element + 1 * size.r + 0) = -1;
			*(ker.element + 1 * size.r + 1) =  9 ;
			*(ker.element + 1 * size.r + 2) = -1;
			*(ker.element + 2 * size.r + 0) = -1;
			*(ker.element + 2 * size.r + 1) = -1;
			*(ker.element + 2 * size.r + 2) = -1;
			break;
		default:
			for (int r = 0; r < size.r; r++) {
				for (int c = 0; c < size.c; c++) {
					*(ker.element + r * size.r + c) = 255;
				}
			}
	}
	return ker;
}
kernal Filters::getGaussuaFilters(vec2 size, double sigma) {
	kernal ker(size);
	unsigned char index = size.r / 2;
	double sum = 0;
	for (int r = -index; r <= index; r++) {
		for (int c = -index; c <= index; c++) {
			double val = (1.0f / (2 * PI * pow(sigma, 1)))* exp(-(pow(r, 2) + pow(c, 2)) / (2 * pow(sigma, 2)));
			*(ker.element + (r + index) * size.c + (c + index)) = val;
			sum += val;
			//printf("%f,", val);
		}
	}
	for (int r = -index; r <= index; r++) {
		for (int c = -index; c <= index; c++) {
			double val = *(ker.element + (r + index) * size.c + (c + index));
			val /= sum;
			*(ker.element + (r + index) * size.c + (c + index)) = val;
			//printf("%f,", val);
		}
	}
	//printf("\n");
	return ker;
}
unsigned char Filters::doMedianFilter(unsigned char* src, vec2 src_origin, vec2 size, vec2 src_size) {
	unsigned char index = size.r / 2;
	unsigned char median_index = floor((size.r * size.c) / 2);
	unsigned char temp = 0;
	unsigned char c = 0;
	unsigned char* sort_arr = new unsigned char[size.r * size.c * sizeof(unsigned char)];
	//save neighbors to array


	

	for (int x = -index; x <= index; x++) {
		for (int y = -index; y <= index; y++) {	
			*(sort_arr + c) = *(src + (src_origin.r + x) * src_size.c + (src_origin.c + y));
			c += 1;
		}
	}
	//sort from min to max
	for (int i = 0; i < size.r * size.c; i++) {
		for (int j = i; j < size.r * size.c; j++) {
			if (*(sort_arr + j) < *(sort_arr + i)) {
				temp = *(sort_arr + j);
				*(sort_arr + j) = *(sort_arr + i);
				*(sort_arr + i) = temp;
			}

		}
	}
	//for (int i = 0; i < size.r * size.c; i++) {
	//	printf("%d,", *(sort_arr + i));
	//}
	//printf("\n");
	//printf("%d\n", *(sort_arr + median_index));
	/*if (*(sort_arr + median_index) == 255 || *(sort_arr + median_index) == 0) {
		printf("x");
	}*/
	return *(sort_arr + median_index);
}
void Filters::ad_hoc_filters(unsigned char* src, unsigned char* dst, vec2 ker_size, vec2 src_size) {
	unsigned char index = ker_size.r / 2;// 3/2 = 1
	int padding_size_r = (src_size.r + index * 2);
	int padding_size_c = (src_size.c + index * 2);
	vec2 size(3, 3);
	vec2 origin(0, 0);
	int mean = 0;
	for (int r = 0; r < src_size.r; r++) {
		for (int c = 0; c < src_size.c; c++) {
			mean+= *(src + r * padding_size_c + c);
		}
	}
	mean /= src_size.r * src_size.c;
	//printf("mean :%d", mean);
	for (int r = 0; r < padding_size_r; r++) {
		for (int c = 0; c < padding_size_c; c++) {
			*(dst + r * padding_size_c + c) = mean;
		}
	}
	for (int r = index, x = 0; r < padding_size_r - index, x < src_size.r; r++, x++) {
		for (int c = index, y = 0; c < padding_size_c - index, y < src_size.c; c++, y++) {
			*(dst + r * padding_size_c + c) = *(src + x * src_size.c + y);
		}
	}
}
void Filters::zeroPadding(unsigned char* src, unsigned char* dst, vec2 ker_size, vec2 src_size) {
	unsigned char index = ker_size.r / 2;// 3/2 = 1
	int padding_size_r = (src_size.r + index * 2);
	int padding_size_c = (src_size.c + index * 2);
	//initial with 0
	for (int r = 0; r < padding_size_r; r++) {
		for (int c = 0; c < padding_size_c; c++) {
			*(dst + r * padding_size_c + c) = 0;
		}
	}
   
	for (int r = index, x = 0; r < padding_size_r - index, x < src_size.r; r++, x++) {
		for (int c = index, y  = 0; c < padding_size_c - index, y < src_size.c; c++, y++) {
			*(dst + r * padding_size_c + c) = *(src + x * src_size.c + y);
		}
	}

	
}
void Filters::replication(unsigned char* src, unsigned char* dst, vec2 ker_size, vec2 src_size) {
	unsigned char index = ker_size.r / 2;// 3/2 = 1
	int padding_size_r = (src_size.r + index * 2);
	int padding_size_c = (src_size.c + index * 2);
	//0~641
	//1~640
	//0~639
	for (int r = index, x = 0; r < padding_size_r - index, x < src_size.r; r++, x++) {
		for (int c = index, y = 0; c < padding_size_c - index, y < src_size.c; c++, y++) {
			*(dst + r * padding_size_c + c) = *(src + x * src_size.c + y);
		}
	}
	//r =2 c=2~ size -1
	//r = 0 c= 0~siz-1
	// i = 2
	for (int i = index; i >= 1; i--) {
		for (int c = i; c < padding_size_c - i; c++) {
			*(dst + (i - 1) * padding_size_c + c) = *(dst + i * padding_size_c + c);
		}
		for (int r = i; r < padding_size_r - i; r++) {
			*(dst + r * padding_size_c + ((padding_size_c - 1) - i + 1)) = *(dst + r * padding_size_c + ((padding_size_c - 1) - i));
		}
		for (int c = i; c < padding_size_c - i; c++) {
			*(dst + ((padding_size_r - 1) - i + 1) * padding_size_c + c) = *(dst + ((padding_size_r - 1) - i) * padding_size_c + c);
		}
		for (int r = i; r < padding_size_r - i; r++) {
			*(dst + r * padding_size_c + (i - 1)) = *(dst + r * padding_size_c + (i));
		}
		*(dst + (i - 1) * padding_size_c + (i - 1)) = *(dst + i * padding_size_c + i);
		*(dst + (i - 1) * padding_size_c + ((padding_size_c - 1) - i + 1)) = *(dst + i * padding_size_c + ((padding_size_c - 1) - i));
		*(dst + ((padding_size_r - 1) - i + 1) * padding_size_c + ((padding_size_c - 1) - i + 1)) = *(dst + ((padding_size_r - 1) - i) * padding_size_c + ((padding_size_c - 1) - i));
		*(dst + ((padding_size_r - 1) - i + 1) * padding_size_c + (i - 1)) = *(dst + ((padding_size_r - 1) - i) * padding_size_c + i);
	}	
}
unsigned char Filters::doConvolution(unsigned char* src, vec2 src_origin, kernal ker, vec2 src_size) {
	unsigned char index = ker.size.r / 2;// 3/2 = 1
	unsigned char value = 0;
	double temp = 0;
	double src_val = 0;
	double ker_val = 0;
	for (int x = -index; x <= index; x++) {
		for (int y = -index; y <= index; y++) {
			src_val = *(src + (src_origin.r + x) * src_size.c + (src_origin.c + y));
			ker_val = *(ker.element + (x + index) * ker.size.c + (y + index));
			//printf("%d,%d :", x, y);
			//printf("%f,%f\n", src_val, ker_val);
			temp += src_val * ker_val;
		}
	}
	//printf("%f\n", temp);
	if (temp < 0) {
		temp = 0;
	}
	
	else if (temp > 255) {
		temp = 255;
	}
	value = round(temp);
	return value;

	//printf("%d\n", value);
}


