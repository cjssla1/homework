
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat origin = imread("1.jpeg");
Mat temp =origin.clone();

Mat roi;
int mx1, my1, mx2, my2;
bool cropping = false;

void onMouse(int event, int x, int y, int flags, void* param)
{
	Mat& img = *(Mat*)param;
	if(event == EVENT_MOUSEMOVE)
	{
		mx2 = x;
		my2 = y;
		
		if (cropping) 
		{
			rectangle(img, Rect(mx1, my1, mx2 - mx1, my2 - my1), Scalar(0, 255, 0), 2);
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
		rectangle(img, Rect(mx1, my1, mx2 - mx1, my2 - my1), Scalar(0, 255, 0), 2);
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
			roi = clone(Rect(mx1, my1, mx2 - mx1, my2 - my1));
			imshow("result.jpg", roi);
		}
	}
	return 0;
}
