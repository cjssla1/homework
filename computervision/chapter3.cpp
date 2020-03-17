
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void n1()//Mat 클래스
{
	Mat img = imread("1.jpeg");
	if (img.empty()) 
	{
		cout << "파일이 없음" << endl;
	}
	imshow("우주", img);

	cout << "행의 수 :" << img.rows << endl;
	cout << "열의 수 :" << img.cols << endl;
	cout << "행렬의 크기 :" << img.size() << endl;
	cout << "전체 화소 개수 :" << img.total() << endl;
	cout << "한 화소 크기 :" << img.elemSize() << endl;
	cout << "타입 :" << img.type() << endl;
	cout << "채널 :" << img.channels() << endl;
	waitKey(0);

}
void n2()
{
	Mat img = imread("3.png");
	if (img.empty())
	{
		cout << "파일이 없음" << endl;
	}
	imshow("lg", img);

	cout << img << endl;
	waitKey(0);
}
void n3()
{
	Mat M(400, 500, CV_8UC3);//* 채널 수만큼 행렬생김 
	randu(M, Scalar::all(0), Scalar::all(255));
	if (M.empty())
	{
		cout << "파일이 없음" << endl;
	}
	//cout << M;
	imshow("img", M);
	waitKey(0);
}
void n4() 
{
	Mat A = imread("2.jpg");
	Mat B = A;
	imshow("window 1", A);

	flip(B, B, 0);
	imshow("window 2", A);
	waitKey(0);
}
void n5() 
{
	Mat A = imread("4.jpg");
	Mat B = imread("4_2.png");
	
	Mat roi(A, Rect(B.cols/2,B.rows/2, B.cols, B.rows));
	B.copyTo(roi);

	imshow("result", A);
	Mat roi2(A, Rect(100, 150, 3, 3));
	cout << "행의 수 = " << roi2.rows << endl;
	cout << "열의 수 = " << roi2.cols << endl;
	cout << "roi2 = " << endl << roi2 << endl;
	waitKey(0);
}
void n6()
{
	vector<Point> points;
	vector<Scalar> scalars;
	vector<Size> sizes;
	vector<Rect> rects;
	vector<Range> ranges;

	for (int i = 0; i < 5; ++i) points.push_back(Point( i , i * 3 ));
	for (int i = 0; i < 5; ++i) scalars.push_back(Scalar(i + 1, i + 2, i + 3));
	for (int i = 0; i < 5; ++i) sizes.push_back(Size(i * 5, i * 2));
	for (int i = 0; i < 5; ++i) rects.push_back(Rect(i+1, i+1, i * 10, i * 20));
	for (int i = 0; i < 5; ++i) ranges.push_back(Range(i + 1, i * 10));

	
	cout << "Point 예제 : " << endl << points << endl;
	cout << endl << "Scalar 예제 : " << endl;
	for (int i = 0; i < 5; ++i) cout << scalars[i] << endl;
	cout << endl << "Size 예제 : " << endl;
	for (int i = 0; i < 5; ++i) cout << sizes[i] << endl;
	cout << endl << "Rect 예제 : " << endl;
	for (int i = 0; i < 5; ++i) cout << rects[i] << endl;
	cout << endl << "Range 예제 : " << endl;
	for (int i = 0; i < 5; ++i) cout << ranges[i] << endl;

}
void n7()
{
	Mat sourceImage = imread("1.jpeg", IMREAD_COLOR);
	imshow("source", sourceImage);

	//사이즈 변경
	resize(sourceImage, sourceImage, Size(200, 250));
	imshow("change", sourceImage);

	//행렬 변경
	Mat resh = sourceImage.reshape(0, 100);
	imshow("reshape",resh);
	
	
	Mat sourceImage2 = imread("2.jpg", IMREAD_COLOR);
	Mat sourceImage3 = imread("4.jpg", IMREAD_COLOR);
	imshow("source2", sourceImage2);
	imshow("source3", sourceImage3);

	//두 사진의 크기를 통일하고 이어붙이기
	resize(sourceImage2, sourceImage2, Size(250, 250));
	resize(sourceImage3, sourceImage3, Size(250, 250));
	sourceImage2.push_back(sourceImage3);
	imshow("2+3", sourceImage2);
	
	waitKey(0);
}

int main()
{
	n7();

	return 0;

}
