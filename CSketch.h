#pragma once
	
#include <array>
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

	float GB_value;
	cv::Point2f _joystick;
	cv::Point _position;
	cv::Point _previousPosition;
	int value;
	int _button_A, _button_B;
	int _change;


	const std::array<cv::Scalar, 3> _colors = {
	cv::Scalar(0,   0,   255), // red    (B,G,R)
	cv::Scalar(0,   255, 0),   // green
	cv::Scalar(255, 0,   0),   // blue
	};

	std::size_t _colorIndex = 0;

};
	