#pragma once


#include "Serial.h"

/**
*
* @brief Controls the microcontroller via serial communication
*
* This class contains functions to initialize, send and receive data from the microcontroller.
*
*@auther Johnny Liu
*
*/
class CControl
{

private:

	Serial _com;///< Serial communication object

public:

	CControl();

	~CControl();

	/**@brief Initializes the serial communication with the microcontroller
	* 
	* @param comport The COM port number to use for communication
	* @return nothing to return
	* 
	*/
	void init_com(int comport);


	/**@brief Retrieves data from the microcontroller
	* 
	* @param type The type of data to retrieve
	* @param channel The channel number to retrieve data from
	* @param result Reference to store the retrieved data
	* 
	*/
	void get_data(int type, int channel, int& result);

	/**@brief Sends data to the microcontroller
	* 
	* @param type The type of data to send
	* @param channel The channel number to send data to
	* @param val The value to send
	* 
	*/
	bool set_data(int type, int channel, int val);

	float get_analog(int type, int channel);

	bool get_button(int channel);

};