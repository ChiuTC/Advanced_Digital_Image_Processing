#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "filters.h"
using namespace std;

class HW4_1 {
private:
	Filters filters;
public:
	
	//smaller output
	void HW4_1_smaller_output(unsigned char* src, unsigned char* dst, vec2 src_size, unsigned char filter_type) {
		vec2 ker_size(3, 3);
		vec2 origin(0, 0);
		kernal ker(ker_size);
		ker = filters.getFilters(ker_size, filter_type);
		unsigned char index = ker.size.r / 2;// 3/2=1
		
		for (int r = index; r < src_size.r - index; r++) {
			for (int c = index; c < src_size.c - index; c++) {
				origin.r = r;
				origin.c = c;
				*(dst + origin.r * src_size.c + origin.c) = filters.doConvolution(src, origin, ker, src_size);
			}
		}
	}
	void HW4_1_ad_hoc(unsigned char* src, unsigned char* dst, vec2 src_size, unsigned char filter_type) {
		vec2 ker_size(3, 3);
		vec2 pre_origin(0, 0);
		kernal ker(ker_size);
		unsigned char index = ker.size.r / 2;// 3/2=1
		//padding
		int padding_size_r = (src_size.r + index * 2);
		int padding_size_c = (src_size.c + index * 2);
		vec2 padding_src_size(padding_size_r, padding_size_c);
		unsigned char* padding_src = new unsigned char[padding_size_r * padding_size_c * sizeof(unsigned char)];

		filters.ad_hoc_filters(src, padding_src, ker_size, src_size);
		ker = filters.getFilters(ker_size, filter_type);
		for (int r = index; r < padding_size_r - index; r++) {
			for (int c = index; c < padding_size_c - index; c++) {	
				pre_origin.r = r;
				pre_origin.c = c;
				*(dst + (pre_origin.r - index) * src_size.c + (pre_origin.c - index)) =
					filters.doConvolution(padding_src, pre_origin, ker, padding_src_size);
			}
		}
	}
	void HW4_1_zero_padding(unsigned char* src, unsigned char* dst, vec2 src_size, unsigned char filter_type) {
		vec2 ker_size(3, 3);
		vec2 pre_origin(0, 0);
		kernal ker(ker_size);
		unsigned char index = ker.size.r / 2;// 3/2=1
		//padding
		int padding_size_r = (src_size.r + index * 2);
		int padding_size_c = (src_size.c + index * 2);
		vec2 padding_src_size(padding_size_r, padding_size_c);
		unsigned char* padding_src = new unsigned char[padding_size_r * padding_size_c * sizeof(unsigned char)];
		
		filters.zeroPadding(src, padding_src, ker_size, src_size);
		ker = filters.getFilters(ker_size, filter_type);
		for (int r = index; r < padding_size_r - index; r++) {
			for (int c = index; c < padding_size_c - index; c++) {
				//printf("%d,%d\n", r, c);
				pre_origin.r = r;
				pre_origin.c = c;
				*(dst + (pre_origin.r - index) * src_size.c + (pre_origin.c - index)) = 
					filters.doConvolution(padding_src, pre_origin, ker, padding_src_size);
			}
		}
	}
	void HW4_1_replication(unsigned char* src, unsigned char* dst, vec2 src_size, unsigned char filter_type) {
		vec2 ker_size(3, 3);
		vec2 pre_origin(0, 0);
		kernal ker(ker_size);
		unsigned char index = ker.size.r / 2;// 3/2=1
		//padding
		int padding_size_r = (src_size.r + index * 2);
		int padding_size_c = (src_size.c + index * 2);
		vec2 padding_src_size(padding_size_r, padding_size_c);
		unsigned char* padding_src = new unsigned char[padding_size_r * padding_size_c * sizeof(unsigned char)];

		filters.replication(src, padding_src, ker_size, src_size);
		ker = filters.getFilters(ker_size, filter_type);
		for (int r = index; r < padding_size_r - index; r++) {
			for (int c = index; c < padding_size_c - index; c++) {
				//printf("%d,%d\n", r, c);
				pre_origin.r = r;
				pre_origin.c = c;
				*(dst + (pre_origin.r - index) * src_size.c + (pre_origin.c - index)) =
					filters.doConvolution(padding_src, pre_origin, ker, padding_src_size);
			}
		}
	}
};