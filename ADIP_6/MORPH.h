#pragma once
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <cstdio>
#include "MORPH.h"
#include <time.h>
#include <iostream>
using namespace std;
struct vec2 {
	int r, c;
	vec2();
	vec2(int r_, int c_);
};

struct kernal {
	unsigned char* element;
	vec2 size;
	vec2 origin;
	unsigned char flag_num;
	//kernal();
	kernal(unsigned char* element_, vec2 size_, vec2 origin_);
};
struct nlabelsList {
	unsigned int* label_value;
	unsigned int label_size;
	nlabelsList();
};
struct labelInfo {
	int start, end;
	int value;
	int change_num;
	int pre_value;
	vec2 img_size;
	std::vector<__int16> relation;
	std::vector<__int16> first;
	std::vector<bool> isLabelExist;
	std::vector<__int16> labelInWhere;
	labelInfo();
}; 

class MORPH {
private:
	bool isStructingElementEqual(unsigned char* src, vec2 src_origin, kernal ker);
	bool isOriginElementEqual(unsigned char* src, vec2 src_origin, kernal ker, vec2 image_size);
	unsigned char* padding(unsigned char* src, vec2 size, vec2 image_size, unsigned char type);
	unsigned __int16 doLabel(unsigned __int16* dst, vec2 point, unsigned __int16 label, labelInfo* label_info);
	void doList(unsigned __int16* dst, vec2 point, labelInfo * label_info);
	void calRelationList(unsigned __int16 upper, unsigned __int16 left, labelInfo* label_info);
public:
	void binary(unsigned char* img, unsigned char* dst, vec2 img_size, int threshold);
	kernal getStructuringElement(vec2 size, vec2 origin, string type, unsigned char flag);
	kernal getSE(vec2 size, vec2 origin, bool change);
	unsigned char* erode(unsigned char* src, unsigned char* dst, kernal ker, vec2 image_size, string type, unsigned char flag);
	unsigned char* dilate(unsigned char* src, unsigned char* dst, kernal ker, vec2 image_size, string type,  unsigned char flag);
	unsigned char* grayScaleErode(unsigned char* src, unsigned char* dst, vec2 image_size, bool change);
	unsigned char* grayScaleDilate(unsigned char* src, unsigned char* dst, vec2 image_size, bool change);
	nlabelsList connectedComponents(unsigned char* src, unsigned __int16* dst, int row, int col);
	void thinning(unsigned char* src, kernal ker, kernal ker_mirror, vec2 image_size, string type, string type_mirror, unsigned char flag);
	
};

