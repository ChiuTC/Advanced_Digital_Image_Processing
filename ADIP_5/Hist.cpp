#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "Hist.h"


using namespace std;


histSize::histSize() {
	count = 0;
}

histSize* Hist::calHist(unsigned char* src, int row, int col) {
	//800x600個gray value
	// 0~255個選擇
	histSize* histNum = new histSize[256];

	int index = 0;
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			index = *(src + r * col + c);
			//printf("%d\n", index);
			histNum[index].count += 1;
		}
	}
	return histNum;
}

void Hist::calLocalHist(unsigned char* src, histSize* histNum, vec2 src_origin, vec2 src_size, vec2 ker_size) {
	unsigned char index = ker_size.r / 2;// 3/2 = 1

	int val = 0;

	for (int r = -index; r <= index; r++) {
		for (int c = -index; c <= index; c++) {
			val = *(src + (src_origin.r + r) * src_size.c + (src_origin.c + c));
			//printf("%d\n", val);
			histNum[val].count += 1;
		}
	}
}

void Hist::plotHist(histSize* hisNum, string name) {

	//normalize and find max_h
	hisNum[0].count /= 100;
	float max_h = hisNum[0].count;

	for (int i = 1; i < 256; i++) {
		hisNum[i].count /= 100;
		if (hisNum[i].count > max_h) {
			max_h = hisNum[i].count;
		}
	}
	//printf("max high:%f\n", max_h);
	//plot
	cv::Mat histImage(128, 256, CV_8UC1, cv::Scalar(230));
	for (int i = 0; i < 256; i++) {
		float value = ((max_h - float(hisNum[i].count)) / max_h) * 128;
		//printf("%f\n", value);
		cv::line(histImage, cv::Point(i, 128), cv::Point(i, round(value)), cv::Scalar(100));
	}

	cv::imwrite(name, histImage);
	cv::namedWindow(name, cv::WINDOW_NORMAL);
	cv::resizeWindow(name, 256 * 4, 107 * 4);
	cv::imshow(name, histImage);
	cv::waitKey(0);

}

void Hist::calHistEqu(unsigned char* src, unsigned char* dst, histSize* histNum, int row, int col) {
	int val = 0;
	float n = row * col;
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			val = *(src + r * col + c);
			float sum = 0;
			for (int j = 0; j <= val; j++) {
				sum += ((histNum[j].count) / n);//histNum[j].count = 累積到目前的gray value，每個出現的數量總和
				if (sum > 1) {
					sum = 1;
					break;
				}
			}
			sum *= 255;
			if (sum > 255) {
				sum = 255;
			}
			else if (sum < 0) {
				sum = 0;
			}
			*(dst + r * col + c) = round(sum);
		}
	}
}
unsigned char Hist::calLocalHistEqu(unsigned char* src, unsigned char* dst, histSize* histNum, vec2 src_origin, vec2 src_size, vec2 ker_size) {

	unsigned char index = ker_size.r / 2;// 3/2 = 1
	unsigned char src_val = *(src + (src_origin.r) * src_size.c + (src_origin.c));
	float n = ker_size.r * ker_size.c;
	float sum = 0;
	for (int j = 0; j <= src_val; j++) {
		//printf("count:%f\n", histNum[j].count);
		sum += ((histNum[j].count) / n);//histNum[j].count = 累積到目前的gray value，每個出現的數量總和
		if (sum > 1) {
			sum = 1;
			break;
		}
	}
	//printf("sum:%f\n", sum);
	sum *= 255;

	if (sum > 255) {
		sum = 255;
	}
	else if (sum < 0) {
		sum = 0;
	}

	for (int i = 0; i < 256; i++) {
		histNum[i].count = 0;
	}
	return round(sum);
}

void Hist::calHistMatching(unsigned char* src, unsigned char* dst, histSize* histNum_r, histSize* histNum_m, int row, int col, int row_m, int col_m) {
	int val = 0;
	float n = row * col;
	int k = 0;
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			val = *(src + r * col + c);
			float sum = 0;

			for (int j = 0; j <= val; j++) {
				sum += ((histNum_r[j].count) / n);//T(rk)

				if (sum > 1) {
					sum = 1;
					break;
				}
			}
			//rk 代表第k個像素
			//nk k=0~L-1 代表第k個像素之灰階值總數
			//sum = T(rk)=Pr(rj)=nj/n 
			//sum = G(zk)=Pr(zk)=nk/n
			//sum_z = G(z^)=Pr(z^k)=n^k/n
			//T(r) = s,G(z) = s
			//gray value s = sum* 255
			//gray value z = sumz*255
			float sum_z = 0;
			int z_min = val;
			//k = val;
			for (int z = k; z <= 255; z++) {
				sum_z += ((histNum_m[z].count) / (row_m * col_m));//G(zk)
				if (sum_z - sum >= 0) {
					z_min = z;
					break;
				}
			}

			*(dst + r * col + c) = z_min;
		}
	}
}
