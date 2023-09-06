#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "filters.h"
#include "hist.h"
using namespace std;

class HW4_2{
private:
	Filters filters;
	Hist hist;
public:
	void HW4_2_1_replication(unsigned char* src, unsigned char* dst, vec2 src_size, vec2 ker_size, unsigned char filter_type, string name) {
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
		histSize* histNum;
		histNum = hist.calHist(dst, src_size.r , src_size.c);
		hist.plotHist(histNum, name);

	}
	void HW4_2_2_replication(unsigned char* src, unsigned char* dst, vec2 src_size, vec2 ker_size, double sigma) {
		vec2 pre_origin(0, 0);
		kernal ker(ker_size);
		unsigned char index = ker.size.r / 2;// 3/2=1
		//padding
		int padding_size_r = (src_size.r + index * 2);
		int padding_size_c = (src_size.c + index * 2);
		vec2 padding_src_size(padding_size_r, padding_size_c);
		unsigned char* padding_src = new unsigned char[padding_size_r * padding_size_c * sizeof(unsigned char)];

		filters.replication(src, padding_src, ker_size, src_size);
		ker = filters.getGaussuaFilters(ker_size, sigma);
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
	void HW4_2_3_replication_median(unsigned char* src, unsigned char* dst, vec2 src_size, vec2 ker_size) {

		vec2 pre_origin(0, 0);
		kernal ker(ker_size);
		unsigned char index = ker.size.r / 2;// 3/2=1
		//padding
		int padding_size_r = (src_size.r + index * 2);
		int padding_size_c = (src_size.c + index * 2);
		vec2 padding_src_size(padding_size_r, padding_size_c);
		unsigned char* padding_src = new unsigned char[padding_size_r * padding_size_c * sizeof(unsigned char)];
		filters.replication(src, padding_src, ker_size, src_size);
	
		for (int r = index; r < padding_size_r - index; r++) {
			for (int c = index; c < padding_size_c - index; c++) {

				pre_origin.r = r;
				pre_origin.c = c;
				//printf("%d,%d\n", pre_origin.r, pre_origin.c);
				//printf("%d\n", *(padding_src + r * src_size.c + c));
				*(dst + (pre_origin.r - index) * src_size.c + (pre_origin.c - index)) = 
					filters.doMedianFilter(padding_src, pre_origin, ker_size, padding_src_size);		
			}
		}
		//printf("-----------------");
	}
	void HW4_2_3_replication_sharpen(unsigned char* src, unsigned char* dst, vec2 src_size, vec2 ker_size, unsigned char filter_type) {
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
};