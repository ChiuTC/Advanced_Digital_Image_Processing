#pragma once
#include <iostream>
#include <cstdio>
#include "FT.h"
using namespace std;
struct histSize {
	float count;
	histSize();
};
//struct vec2 {
//	int r, c;
//	vec2();
//	vec2(int r_, int c_);
//};
class Hist {
private:
public:
	histSize* calHist(unsigned char* src, int row, int col);
	void calLocalHist(unsigned char* src, histSize* histNum, vec2 src_origin, vec2 src_size, vec2 ker_size);
	void calHistEqu(unsigned char* src, unsigned char* dst, histSize* histNum, int row, int col);
	unsigned char calLocalHistEqu(unsigned char* src, unsigned char* dst, histSize* histNum, vec2 src_origin, vec2 src_size, vec2 ker_size);
	void plotHist(histSize* hisNum, string name);
	void calHistMatching(unsigned char* src, unsigned char* dst, histSize* histNum_r, histSize* histNum_m, int row, int col, int row_m, int col_m);
};