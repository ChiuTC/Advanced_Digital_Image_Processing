#pragma once
#define _CRT_SECURE_NO_DEPRECATE //careful
#include <cstdio>
class ImageIO {
private:

public:
	unsigned char* input(const char input_file[], int img_size, int memory_size, FILE* img_file);
	void output(const char output_file[], int img_size, int memory_size, FILE* img_file, unsigned char* out_img);
};