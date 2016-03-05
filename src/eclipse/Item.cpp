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


string Item::printItem() const
{
	stringstream output;
	output << this->name << endl;
	output << this->price << endl;
	output << this->id << endl;
	output << this->quantity << endl;
	output << this->totCost << endl;
	output << this->purchDate.DisplayDate() << endl;
	return output.str();

}