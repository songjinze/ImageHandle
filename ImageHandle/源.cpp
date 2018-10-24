#include <iostream>
#include <opencv2/opencv.hpp>
#define PI 3.1415926

using namespace cv;
using namespace std;
int main(int argc, char* agrv[])
{
	Mat image = imread("road.jpg"); //����ͼƬ
	Mat grayImage;  
	cv::cvtColor(image, grayImage,cv::COLOR_RGB2GRAY);     //��Ϊ�Ҷ�ͼ
	Mat binaryImage;
	cv::threshold(grayImage, binaryImage, 100, 255, CV_THRESH_BINARY);   //��ֵ��

	// ͸�ӱ任������Ҫ������������޸�
	Point2f src[] = { {100,300},{200,100},{500,300},{400,100} };     
	Point2f dst[] = { {50,300},{100,0},{550,300},{500,0} };

	Mat transform = cv::getPerspectiveTransform(src, dst);
	Mat warpImage;
	cout << binaryImage.size();
	cout << transform;
	cv::warpPerspective(binaryImage, warpImage, transform, binaryImage.size());

	//������
	

	cv::namedWindow("hough");
	cv::imshow("hough", binaryImage);
	cv::waitKey(0);
	return 0;
}

