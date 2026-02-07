#include "stdafx.h"
#include "CSketch.h"
#include "cvui.h"



CSketch::CSketch(int comport, int rows, int cols)
{
	_control.init_com(comport);
	_canvas = cv::Mat::zeros(rows, cols, CV_8UC3);
	cvui::init("Etch-A-Sketch");
	cv::namedWindow("Etch-A-Sketch", cv::WINDOW_AUTOSIZE);

	cvui::window(_canvas, 10, 10, 200, 40, "Etch-A-Sketch");
	
}
	
CSketch::~CSketch()
{
}

void CSketch::run()
{
	while (true)
	{
		CSketch::gpio();
		CSketch::update();
		CSketch::draw();


		
		if (cvui::button(_canvas, 10, 10, "EXIT"))
		{
			cv::destroyWindow("Etch-A-Sketch");
			break;
		}
		
		int key = cv::waitKey(1) & 0xFF;
		if (key == 'q' || key == 'Q')
		{
			cv::destroyWindow("Etch-A-Sketch");
			break;
		}
		
	}
}

void CSketch::gpio()
{
	_joystick.x = _control.get_analog(1, 26);
	_joystick.y = _control.get_analog(1, 2);

}
void CSketch::update()
{
	_joystick.x -= 50;
	_joystick.y -= 50;
	_joystick.y *= -1;

	if (_joystick.x > 2 || _joystick.x < -2)
	{
		_position.x += _joystick.x / 10;

	}

	if (_joystick.y > 2 || _joystick.y <-2)
	{
		_position.y += _joystick.y / 10;
	}


	


	
}


void CSketch::draw()
{
	

	_canvas.setTo(cv::Scalar(0, 0, 0));

	

	cv::circle(_canvas, cv::Point(_position.x, _position.y), 6, cv::Scalar(0, 255, 0), cv::FILLED);

	cvui::window(_canvas, 10, 10, 200, 150, "Etch-A-Sketch");
	cvui::button(_canvas, 50, 50, "EXIT");

	cv::imshow("Etch-A-Sketch", _canvas);
}