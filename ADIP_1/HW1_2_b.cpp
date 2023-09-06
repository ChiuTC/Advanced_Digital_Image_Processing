#define _CRT_SECURE_NO_DEPRECATE
#include <opencv2/opencv.hpp>
#include <cstdlib>
#include <stdio.h>
#include <cstdio>
//#include <opencv2/highgui.hpp>
//#include <opencv2/imgcodecs.hpp>
using namespace cv;
using namespace std;
class HW1_2_b{
private:
	
public:
	
	void b(unsigned char* img_lena, unsigned char* img_j) {
		
		// 這邊是練習用opencv show lena圖以及將lena圖儲存為jpg檔的部分
		Mat mat_lena(256, 256, CV_8UC1, img_lena);//row,col
		imwrite("lena256out_opencv.jpg", mat_lena);
		imshow("lena in opencv", mat_lena);
		waitKey(0);
		destroyAllWindows();
		//----------------
		
		// 2.b小題的部分如下
		int j_height = 466;
		int j_width = 621;
		Mat mat_j(j_height, j_width, CV_8UC1, img_j);
		
		putText(mat_j, "111318051", Point(230, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 4, 8);//Point(x,y)
		putText(mat_j, "Amazing!", Point(250, 400), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 4, 8);
		imwrite("JackieChen_with_some_word.png", mat_j);
		imshow("JackieChen image with some word", mat_j);
		waitKey(0);
		destroyAllWindows();
	}

};