
#include <iostream>
#include <opencv2/opencv.hpp>
#include <random>

using namespace std;
using namespace cv;

std::random_device rd; 
std::mt19937 mersenne(rd());
std::uniform_int_distribution<> die(1, 255);


//5�� ����
void problem5()
{
	//��� ���� = ĵ���� ����
	Mat image = Mat(600, 800, CV_8UC3, Scalar(0, 0, 0));

	//���� ĵ���� ���� �׸�
	circle(image, Point(100, 100), 50, Scalar(255, 0, 0), 0);

	//ĵ������ ȭ�鿡 ���
	imshow("Image", image);
	waitKey(0);
}

//6�� ������ ���� ���콺 �̺�Ʈ ó���ϴ� �Լ�
void onMouse(int event, int x, int y, int flags, void* param)
{
	if(event == EVENT_LBUTTONDOWN)
	{//���콺 ���� ��ư Ŭ��
		Mat& img = *(Mat*)(param);
		//���� �׸�
		circle(img, Point(x, y), 100, Scalar(die(mersenne), die(mersenne), die(mersenne)), -1);
		imshow("src", img);
	}
	else if (event == EVENT_RBUTTONDOWN)
	{//���콺 ������ ��ư Ŭ��
		Mat& img = *(Mat*)(param);
		//�簢���� �׸�
		rectangle(img, Point(x - 50, y - 50), Point(x + 50, y + 50), 
			Scalar(die(mersenne), die(mersenne), die(mersenne)), -1);
		imshow("src", img);
	}
}

void problem6()
{
	//ĵ����(������) ����
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

