#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>

using namespace std;

class HW3_1 {
private:
public:
	unsigned char* bitPlaneSlicing(unsigned char* src, unsigned char* dst, int num) {
		//128 64 32 16 8 4 2 1
		for (int r = 0; r < 512; r++) {
			for (int c = 0; c < 512; c++) {
				*(dst + r * 512 + c) = ((*(src + r * 512 + c) & num) / num) * 255;
				//printf("%d, %d, %d\n", *(dst + r * 512 + c), *(src + r * 512 + c), num);
			}
		}
		return dst;
	}
	unsigned char* binary(unsigned char* src, unsigned char* dst) {
		for (int r = 0; r < 512; r++) {
			for (int c = 0; c < 512; c++) {
				if(*(src + r * 512 + c) > 170)
				*(dst + r * 512 + c) = 255;
				else {
					*(dst + r * 512 + c) = 0;
				}
			}
		}
		return dst;
	}
	unsigned char* bitPlaneSynthesize(unsigned char* plane0, unsigned char* plane1, unsigned char* plane2, unsigned char* plane3,
		unsigned char* plane4, unsigned char* plane5, unsigned char* plane6, unsigned char* plane7, unsigned char* plane) {
		for (int r = 0; r < 512; r++) {
			for (int c = 0; c < 512; c++) {
				*(plane + r * 512 + c) = *(plane7 + r * 512 + c) / 255 * 128 | *(plane6 + r * 512 + c) / 255 * 64
					| *(plane5 + r * 512 + c) / 255 * 32 | *(plane4 + r * 512 + c) / 255 * 16 | *(plane3 + r * 512 + c) / 255 * 8
					| *(plane2 + r * 512 + c) / 255 * 4 | *(plane1 + r * 512 + c) / 255 * 2 | *(plane0 + r * 512 + c) / 255 * 1;
			}
		}
		return plane;
	}
};