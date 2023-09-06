#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "FT.h"
#include "Hist.h"
#include "Filters.h"
using namespace std;
using namespace cv;

class HW5_4 {
private:
    FT ft;
    Hist hist;
    Filters filters;
public:
    void HomomorphicFilter(Mat src_m, unsigned char* src, double D0, double c, double rH, double rL, double row, double col, string img_name) {
        for (int i = 0; i < row * col; i++) {
            src_m.at<uchar>(i) = *(src + i);
        }
        //imshow("src", src_m);
        Mat padded;                            //expand input image to optimal size
        int m = getOptimalDFTSize(src_m.rows);
        int n_ = getOptimalDFTSize(src_m.cols); // on the border add zero values
        copyMakeBorder(src_m, padded, 0, m - src_m.rows, 0, n_ - src_m.cols, BORDER_CONSTANT, Scalar::all(0));

        Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
        Mat complexI;
        //planes[0] /= 255.0f;
        planes[0] += Scalar::all(1);
        log(planes[0], planes[0]);
        merge(planes, 2, complexI);         // Add to the expanded another plane with zeros

        dft(complexI, complexI);

        split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
       
        /*planes[0] = planes[0](Rect(0, 0, planes[0].cols & -2, planes[0].rows & -2));
        planes[1] = planes[1](Rect(0, 0, planes[1].cols & -2, planes[1].rows & -2));*/
        ft.center(planes[0]);
        ft.center(planes[1]);
        //normalize(magI, magI, 0, 1, NORM_MINMAX); // Transform the matrix with float values into a

        vector<double> D;
        D.reserve(row * col);
        vector<double> H;
        H.reserve(row * col);
        vector<double> G;
        G.reserve(row * col);
       
        for (int u = 0; u < row; u++) {
            for (int v = 0; v < col; v++) {
                D.push_back(sqrt(powf(u - (row / 2.0f), 2) + powf(v - (col / 2.0f), 2)));
                G.push_back(1.0f - (expf(-c * (powf((D[u * col + v]), 2) / powf(D0, 2)))));
                H.push_back((rH - rL) * (G[u * col + v]) + rL);
                //printf("%.16f\n", expf(-c * pow((D[u * col + v]), 2) / pow(D0, 2)));
            }
        }

        for (int i = 0; i < row * col; i++) {
            planes[0].at<float>(i) = planes[0].at<float>(i) * (0.25 + 1.5 * H[i]);
            planes[1].at<float>(i) = planes[1].at<float>(i) * (0.25 + 1.5 * H[i]);
            //printf("%f\n", H[i]);
        }

        //to mag

        Mat magI;
        magnitude(planes[0], planes[1], magI);
        magI += Scalar::all(1);
        log(magI, magI);
        normalize(magI, magI, 0, 1, NORM_MINMAX);
        //imshow("mag", magI);

 

        //to image
        merge(planes, 2, complexI);
        idft(complexI, complexI);
        split(complexI, planes);
        magnitude(planes[0], planes[1], planes[0]);

        Mat magI2 = planes[0];
      
        normalize(magI2, magI2, 0, 1, NORM_MINMAX);
        exp(magI2, magI2);
        magI2 -= 1.0;
        //imshow(img_name, magI2);
        magI2 *= 255;
        imwrite(img_name, magI2);
        waitKey(0);

    }
    void HistgramEqu(unsigned char* src, unsigned char* dst, int row, int col) {
        histSize* histNum = hist.calHist(src, row, col);
        hist.calHistEqu(src, dst, histNum, row, col);
    }
    void LocalHistEqu(unsigned char* src, unsigned char* dst, vec2 src_size, vec2 ker_size) {
        vec2 pre_origin(0, 0);

        unsigned char index = ker_size.r / 2;// 3/2=1
        //padding
        int padding_size_r = (src_size.r + index * 2);
        int padding_size_c = (src_size.c + index * 2);
        vec2 padding_src_size(padding_size_r, padding_size_c);
        unsigned char* padding_src = new unsigned char[padding_size_r * padding_size_c * sizeof(unsigned char)];
        filters.replication(src, padding_src, ker_size, src_size);
        unsigned char max_value = 0;
        histSize* histNum = new histSize[256];
        for (int r = index; r < padding_size_r - index; r++) {
            for (int c = index; c < padding_size_c - index; c++) {
                //printf("%d,%d\n", r, c);
                pre_origin.r = r;
                pre_origin.c = c;
                //printf("%d\n", *(padding_src + r * padding_size_c + c));
                hist.calLocalHist(padding_src, histNum, pre_origin, padding_src_size, ker_size);
                *(dst + (pre_origin.r - index) * src_size.c + (pre_origin.c - index)) =
                    hist.calLocalHistEqu(padding_src, dst, histNum, pre_origin, padding_src_size, ker_size);
            }
        }
    }
  
};