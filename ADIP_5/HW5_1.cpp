#define _CRT_SECURE_NO_DEPRECATE //careful
#define LOG(x) cout << x << endl
#include <iostream>
#include <cstdio>
#include "FT.h"
#include "Hist.h"
using namespace std;
using namespace cv;

class HW5_1 {
private:
    FT ft;
    Hist hist;
public:
    vector<complex_t> doMyDFT(unsigned char* src, unsigned char* dst, double row, double col) {
        vector<double> mag;
        vector<complex_t> complexI;
   
        mag.reserve(row * col);
        complexI.reserve(row * col);
        printf("Wait about 15 minutes\n");
        for (double u = 0; u < row; u++) {
            for (double v = 0; v < col; v++) {
                complexI.push_back(ft.DFT(src, row, col, u, v));
                mag.push_back(log(1 + sqrt(pow(complexI[u * col + v].real(), 2) + pow(complexI[u * col + v].imag(), 2))));
            }
            //printf("%.1f%%\n", (u / row)*100);
            
        }
        double max = mag[0];
        double min = mag[0];
        for (int i = 1; i < row * col; i++) {
            if (mag[i] > max) {
                max = mag[i];
            }
            if (mag[i] < min) {
                min = mag[i];
            }
        }
        double scale = 255.0f / (max - min);
        for (int i = 0; i < row * col; i++) {
             *(dst + i) = uchar((mag[i] - min) * scale);
             //printf("%d\n", int(val[i]));
        }
        return complexI;
    }

    void doMyIDFT(vector<complex_t> src, unsigned char* dst, double row, double col) {
        vector<double> mag;
        vector<complex_t> complexI;
      
        mag.reserve(row * col);
        complexI.reserve(row * col);
        printf("Wait about 15 minutes\n");
        for (double u = 0; u < row; u++) {
            for (double v = 0; v < col; v++) {
                //printf("xx");
                complexI.push_back(ft.IDFT(src, row, col, u, v));
                
                mag.push_back(sqrt(pow(complexI[u * col + v].real(), 2) + pow(complexI[u * col + v].imag(), 2)));
            }
            //printf("%.1f%%\n", (u / row) * 100);
           
        }
        double max = mag[0];
        double min = mag[0];
        for (int i = 1; i < row * col; i++) {
            if (mag[i] > max) {
                max = mag[i];
            }
            if (mag[i] < min) {
                min = mag[i];
            }
        }
        double scale = 255.0f / (max - min);
        for (int i = 0; i < row * col; i++) {
            *(dst + i) = uchar((mag[i] - min) * scale);
            //printf("%d\n", int(val[i]));
        }
    }

    dftData doDFT(Mat src_m, unsigned char* src, int row, int col, int flags, string name) {
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

		dft(complexI, complexI, flags);

        Mat magI = ft.toLogScale(complexI, planes);
  
        ft.center(magI);
        
        normalize(magI, magI, 0, 1, NORM_MINMAX); // Transform the matrix with float values into a
        dftData dft_data;
        dft_data.complexI = complexI;
        dft_data.D = magI;
        // viewable image form (float between values 0 and 1)
        
       
        //imshow("Input Image", src_m);    // Show the result
        //imshow("spectrum magnitude", magI);
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
        waitKey(0);
        if (name != "none") {
            imwrite(name, magI);
        }

        return dft_data;
	}
    Mat doIDFT(Mat src_m, unsigned char* src, int row, int col, string name) {
      
        Mat padded;                            //expand input image to optimal size
        int m = getOptimalDFTSize(src_m.rows);
        int n = getOptimalDFTSize(src_m.cols); // on the border add zero values
        copyMakeBorder(src_m, padded, 0, m - src_m.rows, 0, n - src_m.cols, BORDER_CONSTANT, Scalar::all(0));

        Mat planes[] = { Mat::zeros(padded.size(), CV_32F), Mat::zeros(padded.size(), CV_32F) };
        Mat complexI;
        src_m.copyTo(complexI);
        idft(complexI, complexI);
        split(complexI, planes);
        magnitude(planes[0], planes[1], planes[0]);
        Mat magI = planes[0];
        normalize(magI, magI, 0, 1, NORM_MINMAX);
       
        //imshow(name, magI);
        waitKey(0);
        magI *= 255;
        imwrite(name, magI);
        return magI;
    }
    void doMyDCT(unsigned char* src, unsigned char* dst, double row, double col) {

        vector<double> mag;
       
        mag.reserve(row * col);
        printf("Wait about 10 minutes");
        for (double u = 0; u < row; u++) {
            for (double v = 0; v < col; v++) {
                mag.push_back(log(1 + abs(ft.DCT(src, row, col, u, v))));
            }
            //printf("%.1f%%\n", (u / row) * 100);
            
        } 

        double max = mag[0];
        double min = mag[0];
        for (int i = 1; i < row * col; i++) {
            if (mag[i] > max) {
                max = mag[i];
            }
            if (mag[i] < min) {
                min = mag[i];
            }
        }
        double scale = 255.0f / (max - min);
     
        for (int i = 0; i < row * col; i++) { 
            *(dst + i) = int((mag[i] - min) * scale);
            //printf("%d\n", int(val[i]));
        }
    }
    void doMyIDCT(unsigned char* src, unsigned char* dst, double row, double col) {

        vector<double> mag;

        mag.reserve(row * col);

        for (double r = 0; r < row; r++) {
            for (double c = 0; c < col; c++) {
                mag.push_back(ft.IDCT(src, row, col, r, c));
            }
            printf("%.1f%%\n", (r / row) * 100);
        }
        double max = mag[0];
        for (int i = 1; i < row * col; i++) {
            if (mag[i] > max) {
                max = mag[i];
            }
        }
        for (int i = 0; i < row * col; i++) {
            mag[i] /= max;
            mag[i] *= 255.0f;
            //printf("%f\n", val[i]);
            if (mag[i] > 255) {
                mag[i] = 255;
            }
            else if (mag[i] < 0) {
                mag[i] = 0;
            }
            *(dst + i) = int(mag[i]);
            //printf("%d\n", int(val[i]));
        }
    }

};