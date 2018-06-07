#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string.h>
#include <fstream>

using namespace std;
using namespace cv;

void showImage(const char *winName, InputArray imgMat, int x, int y);
void outToFile(const char *fileName, const string content);

const char codeLib[] = "@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
const char *imgFileName = "20161023140920353.jpg";
const char *outFileName = "test.txt";

int main() {
    cout << strlen(codeLib) << " : " << codeLib << endl;
    Mat srcImg = imread(imgFileName);
    Mat grayImg;
    cvtColor(srcImg, grayImg, COLOR_RGB2GRAY);

    string str;

    for(int y = 0; y < grayImg.rows; y++) {
        for (int x = 0; x < grayImg.cols; x++) {
            int grayVal = (int)grayImg.at<uchar>(y, x);
//            cout << grayVal << endl;
            int index = 69.0 / 255.0 * grayVal;
            str += codeLib[index];
        }
        str += "\r\n";
    }

    cout << str << endl;
    outToFile(outFileName, str);
    showImage("src", srcImg, 0, 0);
    showImage("gray", grayImg, 100, 100);
    waitKey(0);
    return 0;
}

void showImage(const char *winName, InputArray imgMat, int x, int y){
    namedWindow(winName, WINDOW_AUTOSIZE);
    moveWindow(winName, x, y);
    imshow(winName, imgMat);
}

void outToFile(const char *fileName, const string content){
    ofstream outStream;
    outStream.open(fileName);
    outStream << content << endl;
    outStream.close();
}