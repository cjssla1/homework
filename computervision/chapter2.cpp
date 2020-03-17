
#include <iostream>
#include <opencv2/opencv.hpp>
#include <random>

using namespace std;
using namespace cv;

std::random_device rd; 
std::mt19937 mersenne(rd());
std::uniform_int_distribution<> die(1, 255);


//5번 문제
void problem5()
{
	//행렬 생성 = 캔버스 생성
	Mat image = Mat(600, 800, CV_8UC3, Scalar(0, 0, 0));

	//원을 캔버스 위에 그림
	circle(image, Point(100, 100), 50, Scalar(255, 0, 0), 0);

	//캔버스를 화면에 출력
	imshow("Image", image);
	waitKey(0);
}

//6번 과제를 위한 마우스 이벤트 처리하는 함수
void onMouse(int event, int x, int y, int flags, void* param)
{
	if(event == EVENT_LBUTTONDOWN)
	{//마우스 왼쪽 버튼 클릭
		Mat& img = *(Mat*)(param);
		//원을 그림
		circle(img, Point(x, y), 100, Scalar(die(mersenne), die(mersenne), die(mersenne)), -1);
		imshow("src", img);
	}
	else if (event == EVENT_RBUTTONDOWN)
	{//마우스 오른쪽 버튼 클릭
		Mat& img = *(Mat*)(param);
		//사각형을 그림
		rectangle(img, Point(x - 50, y - 50), Point(x + 50, y + 50), 
			Scalar(die(mersenne), die(mersenne), die(mersenne)), -1);
		imshow("src", img);
	}
}

void problem6()
{
	//캔버스(윈도우) 생성
	Mat src = Mat(600, 800, CV_8UC3, Scalar(0, 0, 0));
	imshow("src", src);

	setMouseCallback("src", onMouse, &src);
	waitKey(0);
}

int main()
{
	problem5();
	//problem6();
	return 0;
}

