#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
using namespace std;

class HW1_1_2_e {
private:
	int A1_arr[128][128];
	int A2_arr[64][128];
	int A3_arr[192][128];
	int A4_arr[192][192];
	int A5_arr[64][64];
public:
	unsigned char* answer(int memory_size, unsigned char* A1, unsigned char* A2, unsigned char* A3, unsigned char* A4, unsigned char* A5) {
		
		int All_arr[256][256]{};
		for (int i = 0; i < 256 ; i++) {
			for (int j = 0; j < 256 ; j++)
				All_arr[i][j] = 0;
		}
		unsigned char* All = new unsigned char[memory_size];
		//----------------A1-------------------
		int temp = 0;
		for (int j = 0; j < 128; j++) {
			for (int i = 127; i > -1; i--) {
				A1_arr[i][j] = *(A1 + temp);
				temp++;
			}
		}
		temp = 0;
		
		//----------------A2-------------------
		for (int i = 63; i > -1; i--) {
			for (int j = 127; j > -1; j--) {
				A2_arr[i][j] = *(A2 + temp);
				temp++;
			}
		}
		temp = 0;
		//----------------A3-------------------
		for (int j = 127; j > -1; j--) {
			for (int i = 0; i < 192; i++) {
				A3_arr[i][j] = *(A3 + temp);
				temp++;
			}
		}
		temp = 0;
		//----------------A4-------------------
		for (int i = 0; i < 192; i++) {
			for (int j = 0; j < 192; j++) {

				A4_arr[i][j] = *(A4 + temp);
				temp++;
			}
		}
		temp = 0;

		//----------------A5-------------------
		for (int i = 63; i > -1; i--) {
			for (int j = 63; j > -1; j--) {
				A5_arr[i][j] = *(A5 + temp);
				temp++;
			}
		}
		temp = 0;
		
		//--------------combine-----------------
		for (int r = 128, i = 0; r < 256, i < 128; r++, i++) {
			for (int c = 128, j = 0; c < 256, j < 128; c++, j++) {
				All_arr[r][c] = A1_arr[i][j];
			}
		}
		
		for (int r = 0, i = 0; r < 192, i < 192; r++, i++) {
			for (int c = 64, j = 0; c < 256, j < 192; c++, j++) {
				if (A4_arr[i][j] != 0) {
					All_arr[r][c] = A4_arr[i][j];
				}
			}
		}
		for (int r = 0, i = 0; r < 64, i < 64; r++, i++) {
			for (int c = 192, j = 0; c < 256, j < 64; c++, j++) {
				All_arr[r][c] = A5_arr[i][j];
			}
		}
		for (int r = 192, i = 0; r < 256, i < 64; r++, i++) {
			for (int c = 0, j = 0; c < 128, j < 128; c++, j++) {
				All_arr[r][c] = A2_arr[i][j];
			}
		}
		for (int r = 0, i = 0; r < 192, i < 192; r++, i++) {
			for (int c = 0, j = 0; c < 128, j < 128; c++, j++) {
				if (A3_arr[i][j] != 0) {
					All_arr[r][c] = A3_arr[i][j];
				}
			}
		}
		
		int index = 0;
		for (int r = 0; r < 256; r++) {
			for (int c = 0; c < 256; c++) {
				*(All + index) = All_arr[r][c];
				index++;
			}
		}
		
		index = 0;
		return All;
		
	}
};