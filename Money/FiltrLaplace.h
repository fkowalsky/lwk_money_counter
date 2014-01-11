#ifndef _FILTRLAPLACE_H_
#define _FILTRLAPLACE_H_
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
using namespace cv;

class FiltrLaplace
{
public:
	FiltrLaplace();

	// Set parameters.
	void SetKernelSize(int);
	void SetScale(int);
	void SetDelta(int);
	void SetDepth(int);

	Mat GetMatrix();

	bool Initialize();
	bool Render(Mat image);
	void Shutdown();

private:
	int kernel_size;
	int scale;
	int delta;
	int ddepth;

	Mat abs_dst;

};

#endif