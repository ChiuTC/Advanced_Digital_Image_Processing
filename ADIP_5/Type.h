#pragma once
struct vec2 {
	int r, c;
	vec2();
	vec2(int r_, int c_);
};

struct kernal {
	double* element;
	vec2 size;
	//kernal();
	kernal(vec2 size_);
};