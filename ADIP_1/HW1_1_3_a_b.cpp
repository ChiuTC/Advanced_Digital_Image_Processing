#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <time.h> 

class HW1_1_3_a_b {
private:


public:
	unsigned char* a(unsigned char* lena) {
		int temp = 0;
		unsigned char* lena_add_value = new unsigned char[256*256];
		for (int i = 0; i < 256 * 256; i++) {
			*(lena_add_value + i) = *(lena + i);
		}
		for (int i = 0; i < 256; i++) {
			for (int j = 0; j < 256; j++) {
				if (*(lena_add_value + temp) > 210) {
					*(lena_add_value + temp) = 255;
				}
				else {
					*(lena_add_value + temp) += 45;
				}
				temp++;
			}
		}
		temp = 0;
		return lena_add_value;
	}
	unsigned char* b(unsigned char* lena) {
		unsigned char* lena_add_randomValue = new unsigned char[256 * 256];
		for (int i = 0; i < 256 * 256; i++) {
			*(lena_add_randomValue + i) = *(lena + i);
		}
		
		srand(time(NULL));
		/* «ü©w¶Ã¼Æ½d³ò */
		int min = -55;
		int	 max = 56;
		int temp = 0;


		for (int i = 0; i < 256; i++) {
			for (int j = 0; j < 256; j++) {
				int ranNum = rand() % (max - min + 1) + min;
				if (int(*(lena_add_randomValue + temp)) + ranNum > 255) {
					*(lena_add_randomValue + temp) = 255;
				}
				else if (int(*(lena + temp)) + ranNum < 0) {
					*(lena_add_randomValue + temp) = 0;
				}
				else {
					*(lena_add_randomValue + temp) += ranNum;
				}
				temp++;
			}
		}
		temp = 0;
		return lena_add_randomValue;
	}
};