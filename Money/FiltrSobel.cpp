#include "FiltrSobel.h"

FiltrSobel::FiltrSobel()
{
	scale = 0;
	delta = 0;
	ddepth = 0;
}

void FiltrSobel::SetDelta(int delta)
{
	this->delta = delta;
}

void FiltrSobel::SetScale(int scale)
{
	this->scale = scale;
}

void FiltrSobel::SetDepth(int ddepth)
{
	this->ddepth = ddepth;
}

Mat FiltrSobel::GetMatrix()
{
	return grad;
}

bool FiltrSobel::Initialize()
{
	return true;
}

bool FiltrSobel::Render(Mat colorImage)
{
	GaussianBlur(colorImage, colorImage, Size(3,3), 0, 0, BORDER_DEFAULT);
	cvtColor(colorImage, src_gray, CV_RGB2GRAY);

	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;

	// Gradient X
	cv::Sobel( src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	// Gradient Y
	cv::Sobel( src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);

	convertScaleAbs(grad_x, abs_grad_x);
	convertScaleAbs(grad_y, abs_grad_y);
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);

	return true;
}

void FiltrSobel::Shutdown()
{
}