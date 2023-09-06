#pragma once
class ZoomingAndShrinking {
private:

public:
	//2.(1)
	unsigned char* nearestNeighborZooming(int ori_img_size, int zoo_img_size, unsigned char* ori_img);
	unsigned char* nearestNeighborShrinking(int ori_img_size, int shr_img_size, unsigned char* ori_img);
	unsigned char* bilinearZooAndShr(int ori_img_size, int zoo_img_size, unsigned char* ori_img);
	int computeBilinearInterpolation(float r, float c, int x1, int y1, int x2, int y2, int y1_val, int y2_val, int y3_val, int y4_val);
	float matrix(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p);
};
