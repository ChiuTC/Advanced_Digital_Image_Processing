#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>

class HW2_2_3 {
private:
public:
	float weight(float x, float a) {
		float value = 0;
		if (fabsf(x)<=1) {
			value = static_cast<float>(a + 2)* static_cast<float>(pow(x, 3)) - static_cast<float>((a + 3) * pow(x, 2)) + 1;
		}
		else if (fabsf(x)>1 && fabsf(x)<2) {
			value = static_cast<float>(a * pow(x, 3)) - static_cast <float>(5 * a * pow(x, 2)) + static_cast < float>(8 * a * x - 4 * a);
		}
		else {
			value = 0;
		}
		return value;
	}
	
	unsigned char* bicubic(int ori_img_size, int dst_img_size, unsigned char* ori_img) {

		unsigned char* duck_zoom_in = new unsigned char[144 * 102 * sizeof(unsigned char)];
		int index = 0;
		for (int r = 107; r <= 250; r++) {
			for (int i = 900 * r + 176; i <= 900 * r + 277; i++) {
				*(duck_zoom_in + index) = *(ori_img + i);
				index++;
			}
		}
		index = 0;
		unsigned char* img = new unsigned char[dst_img_size];

		unsigned char duck_zoom_in_arr[144][102];
	
		float ratio = 0.5;

		for (int r = 0; r < 144; r++) {
			for (int c = 0; c < 102; c++) {
				duck_zoom_in_arr[r][c] = *(duck_zoom_in + index);
				//printf("[%d,%d] %d\n", r,c,ori_arr[r][c]);
				index++;
			}
		}
		index = 0;
		for (int r = 0; r < 284; r++) {
			for (int c = 0; c < 200; c++) {
				float interpolate_v = 0;
				int interpolate = 0;
			
				float cor_r_f = ((r+2) + 0.5) * ratio - 0.5;
				float cor_c_f = ((c+2) + 0.5) * ratio - 0.5;
	
				if (cor_c_f < 1) {
					cor_c_f = 1.5;
				}
				int x1 = floor(cor_r_f);
				int x2 = ceil(cor_r_f);
				int y1 = floor(cor_c_f);
				int y2 = ceil(cor_c_f);
				int x0 = x1 - 1;
				int x3 = x2 + 1;
				int y0 = y1 - 1;
				int y3 = y2 + 1;
				int arr_x[4] = { x0, x1, x2, x3 };
				int arr_y[4] = { y0, y1, y2, y3 };
				//printf("[%f,%f]%d,%d,%d,%d,%d,%d,%d,%d\n", cor_r_f, cor_c_f, x0, x1, x2, x3, y0, y1, y2, y3);
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j <4 ; j++) {
						
						interpolate_v = interpolate_v + static_cast<float>(duck_zoom_in_arr[arr_x[i]][arr_y[j]]) * weight(fabsf(cor_r_f - arr_x[i]), -0.5)* weight(fabsf(cor_c_f - arr_y[j]), -0.5);
						//printf("%d,%f,%f\n", ori_arr[arr_x[i]][arr_y[j]], weight(fabsf(cor_r_f - arr_x[i]), -0.5), weight(fabsf(cor_c_f - arr_y[j]), -0.5));
						//printf("%.2f\n", interpolate_v);
					}
				}
	
				interpolate = static_cast<__int32>(interpolate_v);
				//printf("%d\n", interpolate);
				*(img + index) = interpolate;
				
				index++;
			}
		}
		index = 0;
		return img;
	}
};