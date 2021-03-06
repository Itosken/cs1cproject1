/*
 * Item.cpp
 *
 *  Created on: Feb 26, 2016
 *      Author: Nick
 */

#include "Item.h"

Item::Item() {
	name.clear();
	this->id = 0;
	this->quantity = 0;
	this->price = 0;
	this->totCost = 0;
	this->totwTax = 0;

}

Item::~Item() {
	// TODO Auto-generated destructor stub
}

void Item::SetAll(string name, float price, int quantity, Date date, double id)
{
	this->name = name;
	this->price = price;
	this->quantity = quantity;
	this->purchDate = date;
	this->id = id;
	Item::CalcTotCost();
	Item::CalcTotwTax();
}

void Item::SetId(double id)
{
	this->id = id;
}

void Item::SetPrice(float price)
{
	this->price = price;
}

void Item::SetName(string name)
{
	this->name = name;
}
void Item::SetDate(Date date)
{
	this->purchDate = date;
}
double Item::GetId() const
{
	return this->id;
}
float Item::GetPrice() const
{
	return this->price;
}
string Item::GetName() const
{
	return this->name;
}

Date Item::GetDate() const
{
	return this ->purchDate;
}

int Item::GetQty() const
{
	return this->quantity;
}

void Item::CalcTotCost()
{
this->totCost = this->price * this->quantity;
}

void Item::CalcTotwTax()
{
	this->totwTax = this->totCost +(this->totCost * .0825);
}

float Item::getTotwTax()const{
	return this->totwTax;
}
float Item::getTotCost()const{
	return this->totCost;
}

string Item::printItem()
{
	stringstream output;
	string formattedNum;

	output << "| " << left << setw(26) << this->name;
	formattedNum = floatToString(price);
	output << "|" << right << setw(9) << formattedNum;
	output << " |   " << fixed << setprecision(0) <<this->id;
	output << "   |" << setw(10) << this->quantity;
	formattedNum = floatToString(totCost);
	output << "        |" << setw(9) << fixed << setprecision(2) << formattedNum;
	formattedNum = floatToString(totwTax);
	output << " |" << setw(12) << fixed << setprecision(2) << formattedNum;
	output << " |  " << this->purchDate.DisplayDate() << "   |" << endl;
	return output.str();
}

string Item::floatToString(float num)
{
	stringstream numString;

	numString << "$" <<  fixed << setprecision(2) << num;
	return numString.str();
}
