/*
 * Store.cpp
 *
 *  Created on: Feb 26, 2016
 *      Author: Nick
 */

#include "Store.h"

Store::Store() {

	ifstream inFile;
	// TODO Auto-generated constructor stub

}

Store::~Store() {
	cout << "test" << endl;
	// TODO Auto-generated destructor stub
}

Date Store::ConvertDate(string dateIn)
{
	Date temp;
	string pt1 = dateIn.substr(0,2);
	string pt2 = dateIn.substr(3,2);
	string pt3 = dateIn.substr(6);
	unsigned int month = atoi(pt1.c_str());
	unsigned int day = atoi(pt2.c_str());
	unsigned int year = atoi(pt3.c_str());
	temp.SetDate(month, day, year);
	return temp;

}
