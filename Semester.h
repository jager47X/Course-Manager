#pragma once
#ifndef SEMESTER_H
#define SEMESTER_H
#include <string>
#include <iostream>
#include <string.h>
#include "Date.h"
using namespace std;

class Semester
{

	friend ostream& operator<<(ostream& output, const Semester&  semester);
	friend istream& operator>>(istream& input, Semester&  semester);
private: 
	string name;
	Date startDate;
	Date endDate;

public:
	Semester(string="Fall 2021", Date=Date(), Date = Date());
	string getName();
	Date getStartDate();
	Date getEndDate();
};
#endif
