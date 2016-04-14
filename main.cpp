#include "opencv2/opencv.hpp"
#include "cv.h"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>                    

#include<iostream>
#include<fstream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	CvCapture* capture = cvCaptureFromCAM(0);//读取摄像头
	if (capture == NULL)
	{
		printf("没有检测到摄像头");
		return 0;
	}
	cvNamedWindow("video", 1);
	for (;;)
	{
		IplImage* frame = cvQueryFrame(capture);
		if (!frame)
			break;
		cvShowImage("video", frame);
		if (cvWaitKey(100) >= 0)
			break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("video");
	return 0;
}

//int main(int argc, char** argv)
//{
//	CvCapture* capture = cvCaptureFromCAM(-1);
//	IplImage* img = 0;
//	cvNamedWindow("image", CV_WINDOW_AUTOSIZE);
//	char c = cvWaitKey(3);
//	while (c != 27)
//	{
//		if (!cvGrabFrame(capture))
//		{              // capture a frame   
//			printf("Could not grab a frame\n\7");
//			exit(0);
//		}
//		img = cvRetrieveFrame(capture);           // retrieve the captured frame  
//		cvShowImage("image", img);
//		c = cvWaitKey(20);
//	}
//	cvDestroyWindow("image");
//	cvReleaseCapture(&capture);
//	return 0;
//}