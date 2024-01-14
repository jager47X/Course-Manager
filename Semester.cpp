#include "Semester.h"
#include <iostream>
using namespace std;

Semester::Semester(string n,Date sD,Date eD):name(n),startDate(sD),endDate(eD)
{
}

ostream& operator<<(ostream& output, const Semester&  semester) {
	output << "Semster:  " << semester.name << " (" << semester.startDate << "-" << semester.endDate << ")";
	return output;
}
istream& operator>>(istream& input, Semester& semester) {
	cout << "Semster:";
	input >> semester.name;
	cout << "Start Date:";
	input >> semester.startDate;
	cout << "End Date:";
	input>> semester.endDate;
	return input;
}

string Semester::getName() {
	return name;
}
Date Semester::getStartDate() {
	return startDate;
}
Date Semester::getEndDate() {
	return endDate;
}