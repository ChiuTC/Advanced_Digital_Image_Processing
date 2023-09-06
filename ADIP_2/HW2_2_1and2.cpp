#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "zoomingAndShrinking.h"
#include "HW2_1_1.h"

using namespace std;
class HW2_2_1and2 {
private:

public:
	//2.(1)
	ZoomingAndShrinking zoomingAndShrinking;
	
	unsigned char* nNZ(int ori_img_size, int zoo_img_size, unsigned char* ori_img) {
		unsigned char* zoo_image = new unsigned char(zoo_img_size);
		zoo_image = zoomingAndShrinking.nearestNeighborZooming(ori_img_size, zoo_img_size, ori_img);
		return zoo_image;
	}
	unsigned char* nNS(int ori_img_size, int shr_img_size, unsigned char* ori_img) {
		unsigned char* shr_image = new unsigned char(shr_img_size);
		shr_image = zoomingAndShrinking.nearestNeighborShrinking(ori_img_size, shr_img_size, ori_img);
		return shr_image;
	}
	unsigned char* bilZooAndShr(int ori_img_size, int img_size, unsigned char* ori_img) {
		unsigned char* zoo_image = new unsigned char(img_size);
		zoo_image = zoomingAndShrinking.bilinearZooAndShr(ori_img_size, img_size, ori_img);
		return zoo_image;
	}
	
};