#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
using namespace std;

class ImageIO {
private:

public:
	unsigned char* input(const char input_file[], int img_size, int memory_size, FILE* img_file) {

		unsigned char* img = new unsigned char[memory_size];//assign memory for input file

		img_file = fopen(input_file, "rb");//open input file and save to img_file(FILE struct)
		if (img_file == NULL) {
			//LOG("Can't open the file");
		}
		else {
			//cout << "Open" << " " << input_file << " " << "successfully" << endl;

		}
		int numRead = fread(img, 1, img_size, img_file);

		if (numRead == 0)
		{
			//LOG("Fail to read the file");
		}
		else {
			//cout << "Read" << " " << input_file << " " << "successfully" << endl;
			numRead = 0;
		}
		fclose(img_file);
		return img;
	}
	void output(const char output_file[], int img_size, FILE* img_file, unsigned char* out_img) {
		//out_img = new unsigned char[memory_size];
		img_file = fopen(output_file, "wb");
		int numWrite = fwrite(out_img, 1, img_size, img_file);
		if (numWrite == 0) {
			//LOG("Fail to Write the data") << endl;
		}
		else {
			//cout << "Write" << " " << output_file << " " << "successfully" << endl;
		}
		fclose(img_file);
		//delete[] out_img;
	}



};