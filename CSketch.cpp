#include "stdafx.h"
#include "CSketch.h"
#include "cvui.h"



CSketch::CSketch(int comport, int rows, int cols)
{
	_control.init_com(comport);
	_canvas = cv::Mat::zeros(rows, cols, CV_8UC3);
	cvui::init("Etch-A-Sketch");
	
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


		
		if (cvui::button(_canvas, 200, 200, "EXIT"))
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
	
	_X_joystick = _control.get_analog(1, 26);
	_Y_joystick = _control.get_analog(1, 2);

}
void CSketch::update()
{

	


	
}


void CSketch::draw()
{
	cv::imshow("Etch-A-Sketch", _canvas);
}