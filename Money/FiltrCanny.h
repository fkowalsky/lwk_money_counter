#ifndef _FILTRCANNY_H_
#define _FILTRCANNY_H_
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
using namespace cv;

class FiltrCanny
{
public:
	FiltrCanny();

	// Set parameters.
	void SetEdgeTresh(int);
	void SetLowThreshold(int);
	void const SetMaxLowTreshold(int);
	void SetRatio(int);
	void SetKernelSize(int);

	Mat GetMatrix();

	bool Initialize();
	bool Render(Mat);
	void Shutdown();

private:
	int edgeThresh;
	int lowThreshold;
	int const* max_lowThreshold;
	int ratio;
	int kernel_size;

	Mat src_gray;
	Mat dst, detected_edges;
};

#endif