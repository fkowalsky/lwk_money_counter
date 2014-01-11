#ifndef _SHOWEFFECT_H_
#define _SHOWEFFECT_H_
#include <opencv/cv.h>
#include <opencv/highgui.h>
using namespace cv;

class ShowEffect
{
public:
	ShowEffect();
	
	void SetImage(Mat);
	void SetText(char*);
	void SetTitle(char*);

	bool RenderText();
	bool Initialize(int,int);
	bool Render();
	void Shutdown();

private:
	int width;
	int height;
	char* Title;

	Mat DisplayImage;

	char* Text;
};

#endif