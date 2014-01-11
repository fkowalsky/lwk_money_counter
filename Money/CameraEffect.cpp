#include "CameraEffect.h"

// Constructor.
CameraEffect::CameraEffect()
{
	camera_index = 0;
	capture = NULL;
	color_frame = NULL;
}

// Set camera's index.
void CameraEffect::SetCamera(int camera_index)
{
	this->camera_index = camera_index;
}

IplImage* CameraEffect::GetImage()
{
	// Get image.
	return color_frame;
}

Mat CameraEffect::GetMatrix()
{
	Mat src(color_frame);

	// Get matrix.
	return src;
}

bool CameraEffect::Initialize()
{
	// Get camera.
	capture = cvCaptureFromCAM(camera_index);
	if(!capture)
		return false;

	return true;
}

bool CameraEffect::Render()
{
	// Get rendered image from camera.
	color_frame = cvQueryFrame(capture);
	if(!color_frame)
		return false;

	return true;
}

void CameraEffect::Shutdown()
{
	cvReleaseCapture(&capture);
}