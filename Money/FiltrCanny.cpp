#include "FiltrCanny.h"

// Constructor.
FiltrCanny::FiltrCanny()
{
	max_lowThreshold = new const int(100);
}

// Set edge tresh.
void FiltrCanny::SetEdgeTresh(int edgeTresh)
{
	this->edgeThresh = edgeThresh;
}

// Set low threshold.
void FiltrCanny::SetLowThreshold(int lowThreshold)
{
	this->lowThreshold = lowThreshold;
}

// Set max threshold.
void const FiltrCanny::SetMaxLowTreshold(int value)
{
	this->max_lowThreshold = new const int(value);
}

// Set ratio.
void FiltrCanny::SetRatio(int ratio)
{
	this->ratio = ratio;
}

// Set kernel size.
void FiltrCanny::SetKernelSize(int kernel_size)
{
	this->kernel_size = kernel_size;
}

// Get result matrix.
Mat FiltrCanny::GetMatrix()
{
	return dst;
}

bool FiltrCanny::Initialize()
{
	return true;
}

// Redering a filtr canny.
bool FiltrCanny::Render(Mat colorImage)
{
	dst.create(colorImage.size(), colorImage.type());
	cvtColor(colorImage, src_gray, CV_BGR2GRAY);

	blur(src_gray, detected_edges, Size(3,3));
	Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);

	dst = Scalar::all(0);
	colorImage.copyTo(dst, detected_edges);

	return true;
}

void FiltrCanny::Shutdown()
{
}