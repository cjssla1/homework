
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat origin = imread("1.jpeg");
Mat temp =origin.clone();

Mat roi;
int mx1, my1, mx2, my2;
bool cropping = false;

Rect change(int x1,int y1, int x2, int y2)
{
	int start_x = 0;
	int start_y = 0;
	int width = 0;
	int height = 0;
	if (x1 > x2){	start_x = x2;	width = x1 - x2;}
	else {			start_x = x1;	width = x2 - x1;}

	if (y1 > y2) {	start_y = y2;	height = y1 - y2;}
	else{			start_y = y1;	height = y2 - y1;}

	return Rect(start_x,start_y,width,height);
}


void onMouse(int event, int x, int y, int flags, void* param)
{
	Mat& img = *(Mat*)param;
	if(event == EVENT_MOUSEMOVE)
	{
		mx2 = x;
		my2 = y;
		
		if (cropping) 
		{

			rectangle(img, change(mx1,my1,mx2,my2), Scalar(0, 255, 0), 2);
			imshow("image", img);
			img = origin.clone();
		}
	}
	else if (event == EVENT_LBUTTONDOWN)
	{
		img = origin.clone();
		mx1 = x;
		my1 = y;
		cropping = true;
		imshow("image", img);
	}
	else if ( event == EVENT_LBUTTONUP)
	{
		cropping = false;
		rectangle(img, change(mx1, my1, mx2, my2), Scalar(0, 255, 0), 2);
		imshow("image", img);
	}
}

int main()
{ 
	
	imshow("image", temp);
	Mat clone = origin.clone();

	setMouseCallback("image", onMouse,&temp);

	while(1)
	{
		int key = waitKey(100);
		if (key == 'q') break;
		else if(key == 'c')
		{
			roi = clone(change(mx1, my1, mx2, my2));
			imshow("result.jpg", roi);
		}
	}
	return 0;
}
