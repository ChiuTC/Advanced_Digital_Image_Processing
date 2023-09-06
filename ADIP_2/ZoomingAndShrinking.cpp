#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include <math.h>
#include "ZoomingAndShrinking.h"

using namespace std;

unsigned char* ZoomingAndShrinking::nearestNeighborZooming(int ori_img_size, int zoo_img_size, unsigned char* ori_img) {
	unsigned char* img = new unsigned char[zoo_img_size];
	int ori_size = sqrt(ori_img_size);
	int zoo_size = sqrt(zoo_img_size);
	int ratio = zoo_size / ori_size;
	int index = 0;
	for (int i = 0; i < ori_img_size; i++) {
		if (index % zoo_size == 0 && i != 0) {
			index += (zoo_size - ori_size) * ratio ;//跳列
		}
		for (int num = 0; num < ratio; num++) {
			for (int next_row = 0; next_row < (ratio*zoo_size); next_row += zoo_size) {
				*(img + (index + num + next_row)) = *(ori_img + i);
			}
		}
		index += ratio;
	}
	return img;
}
unsigned char* ZoomingAndShrinking::nearestNeighborShrinking(int ori_img_size, int shr_img_size, unsigned char* ori_img) {
	unsigned char* img = new unsigned char[shr_img_size];
	int ori_size = sqrt(ori_img_size);
	int shr_size = sqrt(shr_img_size);
	int ratio =  ori_size / shr_size;
	int index = 0;
	for (int i = 0; i < shr_img_size; i++) {
		if (index % ori_size == 0 && i != 0) {
			index += (ori_size - shr_size) * ratio;//跳列
		}
		*(img + i) = *(ori_img + (index));
		index += ratio;
	}
	return img;
}
float ZoomingAndShrinking::matrix(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p) {
	float mat3_1 = f * k * p + g * l * n + j * o * h - h * k * n - l * o * f - g * j * p;
	float mat3_2 = b * k * p + c * l * n + j * o * d - d * k * n - l * o * b - j * c * p;
	float mat3_3 = b * g * p + c * h * n + f * o * d - n * g * d - h * o * b - c * f * p;
	float mat3_4 = b * g * l + c * h * j + f * k * d - d * g * j - h * k * b - c * f * l;
	float value = a * mat3_1 - e * mat3_2 + i * mat3_3 - m * mat3_4;
	//printf("martrix:%f,%f,%f,%f,%f\n",mat3_1, mat3_2, mat3_3, mat3_4, value);
	return value;
}
int ZoomingAndShrinking::computeBilinearInterpolation(float r_f, float c_f, int x1, int y1, int x2, int y2, int y1_val, int y2_val, int y3_val, int y4_val) {
	//y1_val = a * x1 + b * y1 + c * x1 * y1 + d //133 //2//2
	//y2_val = a * x1 + b * y2 + c * x1 * y2 + d
	//y3_val = a * x2 + b * y1 + c * x2 * y1 + d
	//y4_val = a * x2 + b * y2 + c * x2 * y2 + d
	float delta = matrix(
		x1, y1, x1 * y1, 1,
		x1, y2, x1 * y2, 1,
		x2, y1, x2 * y1, 1, 
		x2, y2, x2 * y2, 1);
	float delta_a = matrix(
		y1_val, y1, x1 * y1, 1,
		y2_val, y2, x1 * y2, 1,
		y3_val, y1, x2 * y1, 1,
		y4_val, y2, x2 * y2, 1);
	float delta_b = matrix(
		x1, y1_val, x1 * y1, 1,
		x1, y2_val, x1 * y2, 1,
		x2, y3_val, x2 * y1, 1, 
		x2, y4_val, x2 * y2, 1);
	float delta_c = matrix(
		x1, y1, y1_val, 1,
		x1, y2, y2_val, 1,
		x2, y1, y3_val, 1,
		x2, y2, y4_val, 1);
	float delta_d = matrix(
		x1, y1, x1 * y1, y1_val, 
		x1, y2, x1 * y2, y2_val,
		x2, y1, x2 * y1, y3_val,
		x2, y2, x2 * y2, y4_val);
	//printf("delta: %f\n", delta);
	float a_val = delta_a / delta;
	float b_val = delta_b / delta;
	float c_val = delta_c / delta;
	float d_val = delta_d / delta;
	int interpolate_v = round(a_val * r_f + b_val * c_f + c_val * r_f * c_f + d_val);
	/*if (r_f >= 428 && c_f >= 472) {
		printf("xy:%d, %d, %d, %d\n", x1, y1, x2, y2);
		printf("abcd:%f, %f, %f, %f\n", a_val, b_val, c_val, d_val);
		printf("(%f,%f)\n", r_f, c_f);
		printf("y:%d, %d, %d, %d => %d\n", y1_val, y2_val, y3_val, y4_val, interpolate_v);
		printf("delta %f, %f ,%f ,%f ,%f\n", delta_a, delta_b, delta_c, delta_d, delta);
	}*/
	return interpolate_v;
}
unsigned char* ZoomingAndShrinking::bilinearZooAndShr(int ori_img_size, int dst_img_size, unsigned char* ori_img) {
	float ori_size = sqrt(ori_img_size);//512
	float dst_size = sqrt(dst_img_size);//256
	float ratio = ori_size / dst_size;
	unsigned char* img = new unsigned char[dst_img_size];
	int arr_len = 0;
	// s = d*ratio d = s/ratio
	int index = 0;
	if (ori_img_size == 128 * 128) {
		unsigned char ori_arr[128][128];

		for (int r = 0; r < ori_size; r++) {
			for (int c = 0; c < ori_size; c++) {
				ori_arr[r][c] = *(ori_img + index);
				//printf("[%d,%d] %d\n", r,c,ori_arr[r][c]);
                index++;
			}
		}
		index = 0;
		for (int r = 0; r < dst_size; r++) {
			for (int c = 0; c < dst_size; c++) {
				int interpolate_v = 0;
				int cor_r = (r + 0.5) * ratio - 0.5;//找到zoo對應在ori矩陣的座標
				int cor_c = (c + 0.5) * ratio - 0.5;//找到zoo對應在ori矩陣的座標
				
				float cor_r_f = (r + 0.5) * ratio - 0.5;
				float cor_c_f = (c + 0.5) * ratio - 0.5;
			
				if (cor_c == ori_size - 1 && cor_r == ori_size - 1) {
					interpolate_v = computeBilinearInterpolation(cor_r_f, cor_c_f, cor_r, cor_c, cor_r - 1, cor_c - 1,
						ori_arr[cor_r][cor_c], ori_arr[cor_r][cor_c - 1], ori_arr[cor_r - 1][cor_c], ori_arr[cor_r - 1][cor_c - 1]);
				}
				else if(cor_c == ori_size - 1){
					interpolate_v = computeBilinearInterpolation(cor_r_f, cor_c_f, cor_r, cor_c, cor_r + 1, cor_c - 1,
						ori_arr[cor_r][cor_c], ori_arr[cor_r][cor_c - 1], ori_arr[cor_r + 1][cor_c], ori_arr[cor_r + 1][cor_c - 1]);

				}
				else if (cor_r == ori_size - 1) {
					interpolate_v = computeBilinearInterpolation(cor_r_f, cor_c_f, cor_r, cor_c, cor_r - 1, cor_c + 1,
						ori_arr[cor_r][cor_c], ori_arr[cor_r][cor_c + 1], ori_arr[cor_r - 1][cor_c], ori_arr[cor_r - 1][cor_c + 1]);
				}
				else {
					interpolate_v = computeBilinearInterpolation(cor_r_f, cor_c_f, cor_r, cor_c, cor_r + 1, cor_c + 1,
					ori_arr[cor_r][cor_c], ori_arr[cor_r][cor_c + 1], ori_arr[cor_r + 1][cor_c], ori_arr[cor_r + 1][cor_c + 1]);
				}
				*(img + index) = interpolate_v;
				index++;
			}
		}
		index = 0;
	}
	else if (ori_img_size == 512 * 512) {
		unsigned char ori_arr[512][512];
		
		for (int r = 0; r < ori_size; r++) {
			for (int c = 0; c < ori_size; c++) {
				ori_arr[r][c] = *(ori_img + index);
				//printf("%d\n", ori_arr[r][c]);
				index++;
			}
		}
		index = 0;
		for (int r = 0; r < dst_size; r++) {
			for (int c = 0; c < dst_size; c++) {
				int interpolate_v = 0;
	
				float cor_r_f = (r + 0.5) * ratio - 0.5;
				float cor_c_f = (c + 0.5) * ratio - 0.5;
				int x0 = floor(cor_r_f);
				int x1 = ceil(cor_r_f);
				int y0 = floor(cor_c_f);
				int y1 = ceil(cor_c_f);
				float R1 = ((x1 - cor_r_f) / (x1 - x0)) * ori_arr[x1][y0] + ((cor_r_f - x0) / (x1 - x0)) * ori_arr[x1][y1];
				float R2 = ((x1 - cor_r_f) / (x1 - x0)) * ori_arr[x0][y0] + ((cor_r_f - x0) / (x1 - x0)) * ori_arr[x0][y1];
				interpolate_v = ((y1 - cor_c_f) / (y1 - y0)) * R1 + ((cor_c_f - y0) / (y1 - y0)) * R2;
				//interpolate_v = computeBilinearInterpolation(cor_r_f, cor_c_f, x0, y0, x1, y1,
					//ori_arr[x0][y0], ori_arr[x0][y1], ori_arr[x1][y0], ori_arr[x1][y1]);
			    //}
				*(img + index) = interpolate_v;
				index++;
			}
		}
		index = 0;
	}
	else {
		unsigned char* duck_zoom_in = new unsigned char[ori_img_size * sizeof(unsigned char)];
		int index = 0;
		for (int r = 108; r <= 249; r++) {
			for (int i = 900 * r + 177; i <= 900 * r + 276; i++) {
				*(duck_zoom_in + index) = *(ori_img + i);
				index++;
			}
		}
		index = 0;

		unsigned char duck_zoom_in_arr[142][100];
		
		for (int r = 0; r < 142; r++) {
			for (int c = 0; c < 100; c++) {
				duck_zoom_in_arr[r][c] = *(duck_zoom_in + index);
				index++;
			}
		}
		index = 0;
		ratio = 0.5;
		for (int r = 0; r < 284; r++) {
			for (int c = 0; c < 200; c++) {
				int interpolate_v = 0;
				int cor_r = (r + 0.5) * ratio - 0.5;//找到zoo對應在ori矩陣的座標
				int cor_c = (c + 0.5) * ratio - 0.5;//找到zoo對應在ori矩陣的座標

				float cor_r_f = (r + 0.5) * ratio - 0.5;
				float cor_c_f = (c + 0.5) * ratio - 0.5;

				
				if (cor_c == 100 - 1 && cor_r == 142 - 1) {
					interpolate_v = computeBilinearInterpolation(cor_r_f, cor_c_f, cor_r, cor_c, cor_r - 1, cor_c - 1,
						duck_zoom_in_arr[cor_r][cor_c], duck_zoom_in_arr[cor_r][cor_c - 1], duck_zoom_in_arr[cor_r - 1][cor_c], duck_zoom_in_arr[cor_r - 1][cor_c - 1]);
				}
				else if (cor_c == 100 - 1) {
					interpolate_v = computeBilinearInterpolation(cor_r_f, cor_c_f, cor_r, cor_c, cor_r + 1, cor_c - 1,
						duck_zoom_in_arr[cor_r][cor_c], duck_zoom_in_arr[cor_r][cor_c - 1], duck_zoom_in_arr[cor_r + 1][cor_c], duck_zoom_in_arr[cor_r + 1][cor_c - 1]);

				}
				else if (cor_r == 142 - 1) {
					interpolate_v = computeBilinearInterpolation(cor_r_f, cor_c_f, cor_r, cor_c, cor_r - 1, cor_c + 1,
						duck_zoom_in_arr[cor_r][cor_c], duck_zoom_in_arr[cor_r][cor_c + 1], duck_zoom_in_arr[cor_r - 1][cor_c], duck_zoom_in_arr[cor_r - 1][cor_c + 1]);
				}
				else {
					interpolate_v = computeBilinearInterpolation(cor_r_f, cor_c_f, cor_r, cor_c, cor_r + 1, cor_c + 1,
						duck_zoom_in_arr[cor_r][cor_c], duck_zoom_in_arr[cor_r][cor_c + 1], duck_zoom_in_arr[cor_r + 1][cor_c], duck_zoom_in_arr[cor_r + 1][cor_c + 1]);
				}
				*(img + index) = interpolate_v;
				//printf("%d\n", interpolate_v);
				index++;
			}
		}
		index = 0;
	}
	return img;
}
