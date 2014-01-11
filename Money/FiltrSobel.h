#ifndef _FLITRSOBEL_H_
#define _FILTRSOBEL_H_
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
using namespace cv;

class FiltrSobel
{
public:
	FiltrSobel();

	void SetScale(int);
	void SetDelta(int);
	void SetDepth(int);

	Mat GetMatrix();

	bool Initialize();
	bool Render(Mat);
	void Shutdown();

private:
	int scale;
	int delta;
	int ddepth;

	Mat src_gray;
	Mat grad;

};

#endif