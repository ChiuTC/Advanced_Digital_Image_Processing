#pragma once
using namespace std;
#include "Type.h"
class Filters {
private:

public:
	kernal getFilters(vec2 size, unsigned char mode);
	kernal getGaussuaFilters(vec2 size, double sigma);
	unsigned char doMedianFilter(unsigned char* src, vec2 src_origin, vec2 size, vec2 src_size);
	void zeroPadding(unsigned char* src, unsigned char* dst, vec2 ker_size, vec2 src_size);
	void ad_hoc_filters(unsigned char* src, unsigned char* dst, vec2 ker_size, vec2 src_size);
	void replication(unsigned char* src, unsigned char* dst, vec2 ker_size, vec2 src_size);
	unsigned char doConvolution(unsigned char* src, vec2 src_origin, kernal ker, vec2 src_size);
};


