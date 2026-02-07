#pragma once
	
#include "CBase4618.h"

class CSketch : public CBase4618
{
public:
	CSketch(int comport, int rows, int cols);
	~CSketch();

	void run();
	
	void gpio();
	void update();
	void draw();

private:

	cv::Point2f _joystick;
	cv::Point _position;
	cv::Point _previousPosition;

	
};