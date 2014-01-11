#ifndef _FILTRHOUGH_H_
#define _FILTRHOUGH_H_
#include <opencv/cv.h>
#include <opencv/highgui.h>
using namespace cv;

class FiltrHough
{
public:
	FiltrHough();

	Mat GetMatrix();

	bool Initialize();
	bool Render(Mat);
	void Shutdown();

	Vector<Mat> GetMatrixes();

private:
	Mat DisplayName;
	Mat src_gray;

	Vector<Mat> Matrixes;
};

#endif