#ifndef _CAMERAEFFECT_H_
#define _CAMERAEFFECT_H_
#include <opencv/highgui.h>
using namespace cv;

class CameraEffect
{
public:
	CameraEffect();

	// Set which camera must use it.
	void SetCamera(int);

	bool Initialize();
	bool Render();
	void Shutdown();

	// Get values.
	IplImage* GetImage();
	Mat GetMatrix();

private:
	int camera_index;
	CvCapture* capture;
	IplImage* color_frame;

};

#endif