#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "FT.h"

using namespace std;
using namespace cv;

class HW5_2 {
private:
    FT ft;
public:
    void ButterworthLPF(Mat src_m, unsigned char* src, double D0, double n, double row, double col, string img_name, string mag_name) {
        for (int i = 0; i < row * col; i++) {
            src_m.at<uchar>(i) = *(src + i);
        }
        Mat padded;                            //expand input image to optimal size
        int m = getOptimalDFTSize(src_m.rows);
        int n_ = getOptimalDFTSize(src_m.cols); // on the border add zero values
        copyMakeBorder(src_m, padded, 0, m - src_m.rows, 0, n_ - src_m.cols, BORDER_CONSTANT, Scalar::all(0));

        Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
        Mat complexI;

        merge(planes, 2, complexI);         // Add to the expanded another plane with zeros

        dft(complexI, complexI);

        split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
        //magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
        //Mat magI = planes[0];
        //magI += Scalar::all(1);                    // switch to logarithmic scale
        //log(magI, magI);
        //// crop the spectrum, if it has an odd number of rows or columns
        planes[0] = planes[0](Rect(0, 0, planes[0].cols & -2, planes[0].rows & -2));
        planes[1] = planes[1](Rect(0, 0, planes[1].cols & -2, planes[1].rows & -2));
        ft.center(planes[0]);
        ft.center(planes[1]);
        //normalize(magI, magI, 0, 1, NORM_MINMAX); // Transform the matrix with float values into a
 
        vector<double> D;
        D.reserve(row * col);
        vector<double> H;
        H.reserve(row * col);
        for (int u = 0; u < row; u++){
            for (int v = 0; v < col; v++) {
                //printf("[%d,%d]%f\n", u,v, sqrt(pow(u - (row / 2.0f), 2) + pow(v - (col / 2.0f), 2)));
                D.push_back(sqrt(pow(u - (row / 2.0f), 2) + pow(v - (col / 2.0f), 2)));
                //printf("%f\n", D[u * col + v]);
                H.push_back(1 / (1 + pow((D[u * col + v] / D0), 2 * n)));
                //printf("%f\n", H[u * col + v]);
            }
        }
      
        for (int i = 0; i < row * col; i++) {
            planes[0].at<float>(i) *= H[i];
            planes[1].at<float>(i) *= H[i];
            //printf("%f\n", H[i]);
        }

        //to mag

        Mat magI;
        magnitude(planes[0], planes[1], magI);   
        magI += Scalar::all(1);                  
        log(magI, magI);
        normalize(magI, magI, 0, 1, NORM_MINMAX); 
        //imshow(mag_name, magI);
      
        double max = magI.at<float>(0);
        for (int i = 1; i < row * col; i++) {
            if (magI.at<float>(i) > max) {
                max = magI.at<float>(i);
            }
        }
        for (int i = 0; i < row * col; i++) {
            magI.at<float>(i) /= max;
            magI.at<float>(i) *= 255;
            //printf("%f\n", magI.at<float>(i));
        }
        imwrite(mag_name, magI);

        //to image
        merge(planes, 2, complexI);
        idft(complexI, complexI);
        split(complexI, planes);
        magnitude(planes[0], planes[1], planes[0]);

        Mat magI2 = planes[0];
        normalize(magI2, magI2, 0, 1, NORM_MINMAX);
        //imshow(img_name, magI2);
        max = magI2.at<float>(0);
        for (int i = 1; i < row * col; i++) {
            if (magI2.at<float>(i) > max) {
                max = magI2.at<float>(i);
            }
        }
        for (int i = 0; i < row * col; i++) {
            magI2.at<float>(i) /= max;
            magI2.at<float>(i) *= 255;
            //printf("%f\n", magI.at<float>(i));
        }

        imwrite(img_name, magI2);
        waitKey(0);
      
    }
    void ButterworthHPF(Mat src_m, unsigned char* src, double D0, double n, double row, double col, string img_name, string mag_name) {
        for (int i = 0; i < row * col; i++) {
            src_m.at<uchar>(i) = *(src + i);
        }
        Mat padded;                            //expand input image to optimal size
        int m = getOptimalDFTSize(src_m.rows);
        int n_ = getOptimalDFTSize(src_m.cols); // on the border add zero values
        copyMakeBorder(src_m, padded, 0, m - src_m.rows, 0, n_ - src_m.cols, BORDER_CONSTANT, Scalar::all(0));

        Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
        Mat complexI;

        merge(planes, 2, complexI);         // Add to the expanded another plane with zeros

        dft(complexI, complexI);

        split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
        //magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
        //Mat magI = planes[0];
        //magI += Scalar::all(1);                    // switch to logarithmic scale
        //log(magI, magI);
        //// crop the spectrum, if it has an odd number of rows or columns
        planes[0] = planes[0](Rect(0, 0, planes[0].cols & -2, planes[0].rows & -2));
        planes[1] = planes[1](Rect(0, 0, planes[1].cols & -2, planes[1].rows & -2));
        ft.center(planes[0]);
        ft.center(planes[1]);
        //normalize(magI, magI, 0, 1, NORM_MINMAX); // Transform the matrix with float values into a

        vector<double> D;
        D.reserve(row * col);
        vector<double> H;
        H.reserve(row * col);
        for (int u = 0; u < row; u++) {
            for (int v = 0; v < col; v++) {
             
                D.push_back(sqrt(pow(u - (row / 2.0f), 2) + pow(v - (col / 2.0f), 2)));
                //printf("%f\n", D[u * col + v]);
                H.push_back(1 / (1 + pow((D0 / D[u * col + v]), 2 * n)));
                //printf("%f\n", H[u * col + v]);
            }
        }

        for (int i = 0; i < row * col; i++) {
            planes[0].at<float>(i) *= H[i];
            planes[1].at<float>(i) *= H[i];
            //printf("%f\n", H[i]);
        }
        //to mag
        Mat magI;
        magnitude(planes[0], planes[1], magI);
        magI += Scalar::all(1);
        log(magI, magI);
        normalize(magI, magI, 0, 1, NORM_MINMAX);
        //imshow(mag_name, magI);

        double max = magI.at<float>(0);
        for (int i = 1; i < row * col; i++) {
            if (magI.at<float>(i) > max) {
                max = magI.at<float>(i);
            }
        }
        for (int i = 0; i < row * col; i++) {
            magI.at<float>(i) /= max;
            magI.at<float>(i) *= 255;
            //printf("%f\n", magI.at<float>(i));
        }
        if (mag_name != "N") {
            imwrite(mag_name, magI);
        }
    
        //to image
        merge(planes, 2, complexI);
        idft(complexI, complexI);
        split(complexI, planes);
        magnitude(planes[0], planes[1], planes[0]);

        Mat magI2 = planes[0];
        normalize(magI2, magI2, 0, 1, NORM_MINMAX);
        //imshow(img_name, magI2);
        max = magI2.at<float>(0);
        for (int i = 1; i < row * col; i++) {
            if (magI2.at<float>(i) > max) {
                max = magI2.at<float>(i);
            }
        }
        for (int i = 0; i < row * col; i++) {
            magI2.at<float>(i) /= max;
            magI2.at<float>(i) *= 255;
            //printf("%f\n", magI.at<float>(i));
        }
        if (img_name != "N") {
            imwrite(img_name, magI2);
        }

        waitKey(0);
    }
    void HFEmphasisFilter(Mat src_m, unsigned char* src, double D0, double n, double row, double col, string img_name) {
        for (int i = 0; i < row * col; i++) {
            src_m.at<uchar>(i) = *(src + i);
        }
        Mat padded;                            //expand input image to optimal size
        int m = getOptimalDFTSize(src_m.rows);
        int n_ = getOptimalDFTSize(src_m.cols); // on the border add zero values
        copyMakeBorder(src_m, padded, 0, m - src_m.rows, 0, n_ - src_m.cols, BORDER_CONSTANT, Scalar::all(0));

        Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
        Mat complexI;

        merge(planes, 2, complexI);         // Add to the expanded another plane with zeros

        dft(complexI, complexI);

        split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
    
        planes[0] = planes[0](Rect(0, 0, planes[0].cols & -2, planes[0].rows & -2));
        planes[1] = planes[1](Rect(0, 0, planes[1].cols & -2, planes[1].rows & -2));
        ft.center(planes[0]);
        ft.center(planes[1]);
        //normalize(magI, magI, 0, 1, NORM_MINMAX); // Transform the matrix with float values into a

        vector<double> D;
        D.reserve(row * col);
        vector<double> H;
        H.reserve(row * col);
        for (int u = 0; u < row; u++) {
            for (int v = 0; v < col; v++) {

                D.push_back(sqrt(pow(u - (row / 2.0f), 2) + pow(v - (col / 2.0f), 2)));
                //printf("%f\n", D[u * col + v]);
                H.push_back(1 / (1 + pow((D0 / D[u * col + v]), 2 * n)));
                //printf("%f\n", H[u * col + v]);
            }
        }

        for (int i = 0; i < row * col; i++) {
            planes[0].at<float>(i) = planes[0].at<float>(i) * (1 + 2 * H[i]);
            planes[1].at<float>(i) = planes[1].at<float>(i) * (1 + 2 * H[i]);
         
            //printf("%f\n", H[i]);
        }
        merge(planes, 2, complexI);
        idft(complexI, complexI);
        split(complexI, planes);
        magnitude(planes[0], planes[1], planes[0]);

        Mat magI2 = planes[0];
        normalize(magI2, magI2, 0, 1, NORM_MINMAX);
        //imshow(img_name, magI2);
        double max = magI2.at<float>(0);
        for (int i = 1; i < row * col; i++) {
            if (magI2.at<float>(i) > max) {
                max = magI2.at<float>(i);
            }
        }
        for (int i = 0; i < row * col; i++) {
            magI2.at<float>(i) /= max;
            magI2.at<float>(i) *= 255;
            //printf("%f\n", magI.at<float>(i));
        }
        if (img_name != "N") {
            imwrite(img_name, magI2);
        }

        waitKey(0);
    }
};