#include "FiltrHough.h"

FiltrHough::FiltrHough()
{
	Matrixes = Vector<Mat>();
}

Mat FiltrHough::GetMatrix()
{

	return DisplayName;
}

Vector<Mat> FiltrHough::GetMatrixes()
{
	return Matrixes;
}

bool FiltrHough::Initialize()
{
	return true;
}

bool FiltrHough::Render(Mat image)
{
	DisplayName = Mat(image);
	cvtColor(DisplayName, src_gray, CV_BGR2GRAY);

	GaussianBlur(src_gray, src_gray, Size(9,9), 2, 2);

	vector<Vec3f> circles;
	HoughCircles(src_gray, circles, CV_HOUGH_GRADIENT, 1, src_gray.rows/8, 200, 50, 0, 0);

	for(size_t i=0; i<circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);

		// circle center.
		//circle(DisplayName, center, 3, Scalar(0,255,0), -1, 8, 0);
		// circle outline.
		//circle(DisplayName, center, radius, Scalar(0,0,255), 3, 8, 0);

		Rect Region = Rect(circles[i][0]-radius, circles[i][1]-radius,2*radius, 2*radius);
		Mat image_roi = image(Region);

		Matrixes.push_back(image_roi);
	}

	return true;
}

void FiltrHough::Shutdown()
{
}