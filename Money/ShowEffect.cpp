#include "ShowEffect.h"

// Constructor.
ShowEffect::ShowEffect()
{
	DisplayImage = NULL;
}

void ShowEffect::SetImage(Mat image)
{
	this->DisplayImage = image;
}

void ShowEffect::SetText(char* Text)
{
	this->Text = Text;
}

void ShowEffect::SetTitle(char* Title)
{
	this->Title = Title;
}

bool ShowEffect::Initialize(int width, int height)
{
	this->width;
	this->height;

	return true;
}

bool ShowEffect::RenderText()
{
	Size TextSize = getTextSize(Text, CV_FONT_HERSHEY_SIMPLEX, 0.5, 5, 0);
	Point org(10, 10+TextSize.height);
	int lineType = 8;

	putText(DisplayImage, Text, org, CV_FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255,255,255), 1, lineType);
	return true;
}

bool ShowEffect::Render()
{
	bool result;

	result = RenderText();
	if(!result)
		return false;

	//Show window.
	imshow(Title, DisplayImage);

	return true;
}

void ShowEffect::Shutdown()
{
}