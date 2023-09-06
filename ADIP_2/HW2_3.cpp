#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;
class HW2_3 {
private:

public:
	unsigned char* quantize(unsigned char* img, int img_size, int k_bit) {
		unsigned char* out_img = new unsigned char[img_size];
		int size = sqrt(img_size);//256
		int range_num = pow(2, k_bit);//2
		int range = size / range_num; //128
		int init = 0;
		int value = 0;
	    int add = (size - 1) / (range_num - 1);//255
		for (int x = 0; x < range_num; x++) {
			for (int i = 0; i < img_size; i++) {
				if (*(img + i) >= init && *(img + i) < init + range)
					*(out_img + i) = value;
				
			}
			init += range;
			value += add;			
		}
		return out_img;
	}


};