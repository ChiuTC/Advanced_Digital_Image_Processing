#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include <math.h>

class Resize {
public:
	unsigned char* bilinear(float ori_img_size, float shr_img_size, unsigned char* ori_img) {
		unsigned char* img = new unsigned char[shr_img_size];
		float ratio = 1.2;
		unsigned char ori_arr[621][621];
		int index = 0;
		for (int r = 0; r < 621; r++) {
			for (int c = 0; c < 621; c++) {
				if (r < 78) {
					ori_arr[r][c] = 255;
				}
				else if (r > 543) {
					ori_arr[r][c] = 255;
				}
				else {
					ori_arr[r][c] = *(ori_img + index);
					index++;
				}
				
			}
		}
		index = 0;
		for (int r = 0; r < 512; r++) {
			for (int c = 0; c < 512; c++) {
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
				
				*(img + index) = interpolate_v;
				//printf("%d\n", interpolate_v);
				index++;
			}
		}
		index = 0;
		return img;
	}
};
