#include "FiltrLaplace.h"

// Constructor.
FiltrLaplace::FiltrLaplace()
{
	kernel_size = 0;
	scale = 0;
	delta = 0;
	ddepth = 0;
}

// Set delta.
void FiltrLaplace::SetDelta(int delta)
{
	this->delta = delta;
}

// Set depth.
void FiltrLaplace::SetDepth(int ddepth)
{
	this->ddepth = ddepth;
}

// Set kernel size.
void FiltrLaplace::SetKernelSize(int kernel_size)
{
	this->kernel_size = kernel_size;
}

// Set scale.
void FiltrLaplace::SetScale(int scale)
{
	this->scale = scale;
}

bool FiltrLaplace::Initialize()
{
	return true;
}

// Get result matrix.
Mat FiltrLaplace::GetMatrix()
{
	return abs_dst;
}

// Rendering filtr laplace.
bool FiltrLaplace::Render(Mat colorImage)
{
	Mat grayImage;

	GaussianBlur(colorImage, colorImage, Size(3,3), 0, 0, BORDER_DEFAULT);
	cvtColor(colorImage, grayImage, CV_RGB2GRAY);

	Mat dst;

	Laplacian(grayImage, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(dst, abs_dst);

	return true;
}

void FiltrLaplace::Shutdown()
{
}