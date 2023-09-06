#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "FT.h"
using namespace std;
using namespace cv;

class HW5_3 {
private:
    FT ft;
public:
    void methodI(Mat src_m, unsigned char* src, Mat mark_m, unsigned char* mark, int row, int col, string name) {
        for (int i = 0; i < row * col; i++) {
            src_m.at<uchar>(i) = *(src + i);
        }
        Mat padded;                            //expand input image to optimal size
        int m = getOptimalDFTSize(src_m.rows);
        int n = getOptimalDFTSize(src_m.cols); // on the border add zero values
        copyMakeBorder(src_m, padded, 0, m - src_m.rows, 0, n - src_m.cols, BORDER_CONSTANT, Scalar::all(0));

        Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
        Mat complexI;

        merge(planes, 2, complexI);         // Add to the expanded another plane with zeros

        dft(complexI, complexI);
        split(complexI, planes);       
        

        Mat magI_ori;
        Mat magI_after;
        magnitude(planes[0], planes[1], magI_ori);// planes[0] = magnitude
       
        magI_ori += Scalar::all(1);                    // switch to logarithmic scale
        log(magI_ori, magI_ori);
        // crop the spectrum, if it has an odd number of rows or columns
        magI_ori = magI_ori(Rect(0, 0, magI_ori.cols & -2, magI_ori.rows & -2));
      
        ft.center(magI_ori);

        normalize(magI_ori, magI_ori, 0, 1, NORM_MINMAX);
        //imshow("original image spectrum magnitude", magI_ori);
        
        ft.center(planes[0]);
        ft.center(planes[1]);

        double w = 30;
        for (int i = 0; i < row * col; i++) {
            planes[0].at<float>(i) += w * (*(mark + i));
            planes[1].at<float>(i) += w * (*(mark + i));
          
        }
        magnitude(planes[0], planes[1], magI_after);// planes[0] = magnitude
        magI_after += Scalar::all(1);                    // switch to logarithmic scale
        log(magI_after, magI_after);
        // crop the spectrum, if it has an odd number of rows or columns
        magI_after = magI_after(Rect(0, 0, magI_after.cols & -2, magI_after.rows & -2));

        //ft.center(magI_after);

        normalize(magI_after, magI_after, 0, 1, NORM_MINMAX);
        //imshow("methodI spectrum magnitude", magI_after);
        magI_after *= 255;
        imwrite("methodI spectrum magnitude.png", magI_after);
        merge(planes, 2, complexI);
        idft(complexI, complexI);
        split(complexI, planes);
       
        magnitude(planes[0], planes[1], planes[0]);
        Mat magI2 = planes[0];
        normalize(magI2, magI2, 0, 1, NORM_MINMAX);
        //imshow(name, magI2);
        magI2 *= 255;
        imwrite(name, magI2);
        waitKey(0);
    }
    void methodII(Mat src_m, unsigned char* src, Mat mark_m, unsigned char* mark, int row, int col, string name) {
        for (int i = 0; i < row * col; i++) {
            src_m.at<uchar>(i) = *(src + i);
            mark_m.at<uchar>(i) = *(mark + i);
        }
        Mat padded;  
        Mat padded_mark;
        int m = getOptimalDFTSize(row);
        int n = getOptimalDFTSize(col); // on the border add zero values
        copyMakeBorder(src_m, padded, 0, m - src_m.rows, 0, n - src_m.cols, BORDER_CONSTANT, Scalar::all(0));
        copyMakeBorder(mark_m, padded_mark, 0, m - mark_m.rows, 0, n - mark_m.cols, BORDER_CONSTANT, Scalar::all(0));
        Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
        Mat planes_mark[] = { Mat_<float>(padded_mark), Mat::zeros(padded_mark.size(), CV_32F) };
        Mat complexI;
        Mat complexI_mark;
        merge(planes, 2, complexI);         // Add to the expanded another plane with zeros
        merge(planes_mark, 2, complexI_mark);
        dft(complexI, complexI);
        dft(complexI_mark, complexI_mark);

        split(complexI, planes);
        split(complexI_mark, planes_mark);

        Mat magI_ori;
        Mat magI_ori_mark;
        Mat magI_after;
        magnitude(planes[0], planes[1], magI_ori);// planes[0] = magnitude
        magnitude(planes_mark[0], planes_mark[1], magI_ori_mark);// planes[0] = magnitude

        magI_ori += Scalar::all(1);                    // switch to logarithmic scale
        magI_ori_mark += Scalar::all(1);
        log(magI_ori, magI_ori);
        log(magI_ori_mark, magI_ori_mark);
   
        magI_ori = magI_ori(Rect(0, 0, magI_ori.cols & -2, magI_ori.rows & -2));
        magI_ori_mark = magI_ori_mark(Rect(0, 0, magI_ori_mark.cols & -2, magI_ori_mark.rows & -2));
        ft.center(magI_ori);
        ft.center(magI_ori_mark);

        normalize(magI_ori, magI_ori, 0, 1, NORM_MINMAX);
        normalize(magI_ori_mark, magI_ori_mark, 0, 1, NORM_MINMAX);
        //imshow("original image spectrum magnitude", magI_ori);
        //imshow("mark image spectrum magnitude", magI_ori_mark);

        double w = 0.1;
        for (int i = 0; i < row * col; i++) {
            planes[0].at<float>(i) += w * planes_mark[0].at<float>(i);
            planes[1].at<float>(i) += w * planes_mark[1].at<float>(i);
           
        }
        magnitude(planes[0], planes[1], magI_after);// planes[0] = magnitude
        magI_after += Scalar::all(1);                    // switch to logarithmic scale
        log(magI_after, magI_after);
        // crop the spectrum, if it has an odd number of rows or columns
        magI_after = magI_after(Rect(0, 0, magI_after.cols & -2, magI_after.rows & -2));

        ft.center(magI_after);

        normalize(magI_after, magI_after, 0, 1, NORM_MINMAX);
        //imshow("methodII spectrum magnitude", magI_after);
        magI_after *= 255;
        imwrite("methodII spectrum magnitude.png", magI_after);
        merge(planes, 2, complexI);
        idft(complexI, complexI);
        split(complexI, planes);

        magnitude(planes[0], planes[1], planes[0]);
        Mat magI2 = planes[0];
        normalize(magI2, magI2, 0, 1, NORM_MINMAX);

        //imshow(name, magI2);
        magI2 *= 255;
        imwrite(name, magI2);
        waitKey(0);
    }
};