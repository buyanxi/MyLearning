#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/freetype.hpp"

using namespace std;
using namespace cv;

int main()
{
    Mat srcImg = imread("./1.jpg");

    char pchText[128];
    snprintf(pchText, 128, "%s", "Linux putText 中文测试");

    cv::Ptr<cv::freetype::FreeType2> ft2 = cv::freetype::createFreeType2();
    ft2->loadFontData("/usr/share/fonts/simsun.ttc", 0);
    ft2->putText(srcImg, pchText, cv::Point(10, 50), 20, cv::Scalar(255, 255, 0), 1, 8, true);

    imwrite("./out.jpg", srcImg);

    return 0;
}
