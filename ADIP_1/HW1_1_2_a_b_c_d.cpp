#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include <time.h>
#include "ImageIO.h"
using namespace std;

class HW1_1_2_a_b_c_d {
private:
	int lena_arr[256][256];
public:
	HW1_1_2_a_b_c_d(unsigned char* lena){
		int temp = 0;
		for (int i = 0; i < 256; i++) {
			for (int j = 0; j < 256; j++) {

				lena_arr[i][j] = *(lena + temp);
				temp++;
			}
		}
		temp = 0;
	}
	void a() {
		int temp = 0;
		printf("(1):[123,234] = >%d\n", lena_arr[123][234]);
		for (int i = 0; i < 256; i++) {
			for (int j = 0; j < 256; j++) {
				if (temp == 5043) {
					printf("(2-1):The intensity values of 5043 pixel => %d\n", lena_arr[i][j]);
					printf("(2-2):The coordinate in 5043 pixel [row,col] => [%d,%d]\n", i, j);
				}
				temp++;
			}
		}
		
	}
	void b(const char output_file[], int img_size, int memory_size, FILE* img_file, unsigned char* out_img) {
		ImageIO imageIo;
		imageIo.output(output_file, img_size, memory_size, img_file, out_img);
	}

	unsigned char* c(int memory_size) {
		FILE* lena_out_rotate;
		int lena_arr_ch[256][256] = { 0 };
		unsigned char* lena_rotate = new unsigned char[memory_size];

		//opposite 
		for (int r = 0, i = 0; r < 128, i < 128; r++, i++) {
			for (int c = 127, j = 0; c > -1, j < 128; c--, j++) {
				//lena_arr_lu[i][j] = *(lena + temp);
				lena_arr_ch[r][c] = lena_arr[i][j];
			}
		}
		//printf("lena_arr:%d\n",lena_arr[0][127]);
		//printf("lena_arr_ch:%d\n", lena_arr_ch[0][0]);

		//turn right
		for (int c = 255, i = 0; c > 127, i < 128; c--, i++) {
			for (int r = 0, j = 128; r < 128, j < 256; r++, j++) {
				lena_arr_ch[r][c] = lena_arr[i][j];
			}
		}

		// turn left
		for (int c = 0, i = 128; c < 128, i < 256; c++, i++) {
			for (int r = 255, j = 0; r > 127, j < 128; r--, j++) {
				lena_arr_ch[r][c] = lena_arr[i][j];

			}
		}
		/// nothing
		for (int r = 128; r < 256; r++) {
			for (int c = 128; c < 256; c++) {
				lena_arr_ch[r][c] = lena_arr[r][c];

			}
		}
		int index = 0;
		for (int r = 0; r < 256; r++) {
			for (int c = 0; c < 256; c++) {
				*(lena_rotate + index) = lena_arr_ch[r][c];
				index++;
			}
		}
		index = 0;
		return(lena_rotate);
	}
	
	unsigned char* d_ver(int memory_size) {
		srand(time(NULL));
		/* 指定亂數範圍 */
		int min = 0, max = 7;
		/* 參數定義 */
		bool exist = false;
		int ranNum = -1;
		int	current = 0;
		int n[8];
		int s_num = -1;
		int ver_arr[256][256];
		int r, c, i, j;
		int start = 0;
		/* 初始化矩陣為-1 */
		for (int i = 0; i < 8; i++) {
			n[i] = -1;
		}
		/* 不重複選取亂數判斷 */
		while (current < 8) {
			do {
				exist = false;
				ranNum = rand() % (max - min + 1) + min;
				//printf("ran:%d\n", ranNum);
				for (int i = 0; i < 8; i++) {
					if (n[i] == ranNum) {
						exist = true;
						break;
					}
				}//判斷ranNum是否存在於矩陣,exist = true的話就繼續做,=false的話就添加進去
			} while (exist);
			n[current] = ranNum;
			s_num = ranNum;
			current += 1;
			//printf("selNum:%d\n", s_num);
			//veritically
			for (r = 0, i = 0; r < 256, i < 256; r++, i++) {
				for (c = (s_num * 32), j = start; c < (s_num * 32 + 32), j < (start + 32); c++, j++) {
					ver_arr[i][j] = lena_arr[r][c];
				}
			}
			start += 32;
		}
		unsigned char* ver = new unsigned char[memory_size];
		int index = 0;
		for (int r = 0; r < 256; r++) {
			for (int c = 0; c < 256; c++) {
				*(ver + index) = ver_arr[r][c];
			
				index++;
			}
		}
		return ver;
	}
	unsigned char* d_hor(int memory_size) {
		srand(time(NULL));
		/* 指定亂數範圍 */
		int min = 0, max = 7;
		/* 參數定義 */
		bool exist = false;
		int ranNum = -1;
		int	current = 0;
		int n[8];
		int s_num = -1;
		int hor_arr[256][256];
		int r, c, i, j;
		int start = 0;
		/* 初始化矩陣為-1 */
		for (int i = 0; i < 8; i++) {
			n[i] = -1;
		}
		/* 不重複選取亂數判斷 */
		while (current < 8) {
			do {
				exist = false;
				ranNum = rand() % (max - min + 1) + min;
				//printf("ran:%d\n", ranNum);
				for (int i = 0; i < 8; i++) {
					if (n[i] == ranNum) {
						exist = true;
						break;
					}
				}//判斷ranNum是否存在於矩陣,exist = true的話就繼續做,=false的話就添加進去
			} while (exist);
			n[current] = ranNum;
			s_num = ranNum;
			current += 1;
			//printf("selNum:%d\n", s_num);
			//horizontally
			for (r = (s_num * 32), i = start; r < (s_num * 32 + 32), i < (start + 32); r++, i++) {
				for (c = 0, j = 0; c < 256, j < 256; c++, j++) {
					hor_arr[i][j] = lena_arr[r][c];
				}
			}
			start += 32;
		}
		unsigned char* hor = new unsigned char[memory_size];
		int index = 0;
		for (int r = 0; r < 256; r++) {
			for (int c = 0; c < 256; c++) {
				*(hor + index) = hor_arr[r][c];
				index++;
			}
		}
		return hor;
	}
};
