#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "filters.h"
#include "Hist.h"
using namespace std;

class HW4_3 {
private:
	Filters filters;
	Hist hist;
public:
	void HW4_3_replication(unsigned char* src, unsigned char* dst, vec2 src_size, vec2 ker_size, string name) {
		vec2 pre_origin(0, 0);

		unsigned char index = ker_size.r / 2;// 3/2=1
		//padding
		int padding_size_r = (src_size.r + index * 2);
		int padding_size_c = (src_size.c + index * 2);
		vec2 padding_src_size(padding_size_r, padding_size_c);
		unsigned char* padding_src = new unsigned char[padding_size_r * padding_size_c * sizeof(unsigned char)];
		filters.replication(src, padding_src, ker_size, src_size);
		unsigned char max_value = 0;
		histSize* histNum = new histSize[256];
		for (int r = index; r < padding_size_r - index; r++) {
			for (int c = index; c < padding_size_c - index; c++) {
				//printf("%d,%d\n", r, c);
				pre_origin.r = r;
				pre_origin.c = c;
				//printf("%d\n", *(padding_src + r * padding_size_c + c));
				hist.calLocalHist(padding_src, histNum, pre_origin, padding_src_size, ker_size);
				*(dst + (pre_origin.r - index) * src_size.c + (pre_origin.c - index)) = 
					hist.calLocalHistEqu(padding_src, dst, histNum, pre_origin, padding_src_size, ker_size);
			}
		}
		histSize* histNum2;
		histNum2 = hist.calHist(dst, src_size.r, src_size.c);
		hist.plotHist(histNum2, name);
	}
	
};