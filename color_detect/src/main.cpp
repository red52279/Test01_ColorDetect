#include <iostream>
#include <vector>
#include <cstring>
#include <detect/detect.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

const string BlueVideoPath = "../videos/blue.avi";
const string BlueVideoPath = "../videos/green.avi";
const string BlueVideoPath = "../videos/blue_green.avi";

Scalar AimHSVColorBlue(215, 0.5, 0.5);
Scalar BlueRange(10, 0.5, 0.5);

Scalar AimHSVColorGreen(160.0, 0.5, 0.5);
Scalar GreenRange(20, 0.5, 0.5);

int main(int argc, char* argv[])
{
	Mat CapImg;
	VideoCapture Cap(BlueVideoPath);
	namedWindow("detect");
	int color_HSVBLUE = 215;

	while (1)
	{
		Cap.read(CapImg);
		if (CapImg.empty())
			return -1;

		detect(CapImg, AimHSVColorBlue, BlueRange);
		
		imshow("detect", CapImg);
		int c = waitKey(1);
		if ((c & 255) == 27)
		{
			return 0;
		}
	}

	waitKey(0);

	return 0;
}
