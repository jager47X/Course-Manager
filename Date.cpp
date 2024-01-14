#include <iostream>
using namespace std;
#include "Date.h"
//constructor validates month and calls utility function to validate day
Date::Date(int mn, int dy, int yr):month(mn), day(dy), year(yr)
{
    setDate(month, day, year);

}
//DESTRUCTOR
Date::~Date()
{

}
void Date::setDate(int mn, int dy, int yr)
{
    if (mn > 0 && mn <= 12)
    {
        month = mn;
    }

    else
    {
        month = 1;
        cout << "Month set to one - INVALID" << endl;  //BAD DESIGN!
    }

    year = yr;  //could also validate year

    day = checkDay(dy);  //to validate the day

    cout << endl;
}

//PRIVATE COST UTILITY FUNCTION
int Date::checkDay(int testDay) const
{
    static const int daysPerMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    if (testDay > 0 && testDay <= daysPerMonth[month])
    {
        return testDay;
    }

    //determine whether testDay is valid for a specific month
    if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year
        % 100 != 0)))
    {
        return testDay;
    }

    cout << "Invalid Day " << testDay << " was set to 1" << endl;
    return 1;  //keep data in valid state
}

ostream& operator<<(ostream& output, const Date& time) {

   output << time.month << '/' << time.day << '/' << time.year;

    return output;
}
istream& operator>>(istream& input, Date& time) {
    cout << "MM/DD/YYYY"<<endl;
    input >> time.month;
    input.ignore();
    input >> time.day;  
    input.ignore();  
    input >> time.year;

    return input;
}

int Date::getMonth()const {
    return month;
}
int Date::getDay()const {
    return day;
}
int Date::getYear()const {
    return year;
}
Date& Date::setMonth(int m) {
    month = m;
    return *this;
}
Date& Date::setDay(int d) {
    day = d;
    return *this;
}
Date& Date::setYear(int y) {
    year = y;
    return *this;
}

bool Date::operator>=(const Date& date)const {
    if (year >= date.year) {
        return true;
    }
    else if (month >= date.month) {
        return true;
    }
    else if (day >= date.day) {
        return true;
    }
    else {
        return false;
    }
}
bool Date::operator>(const Date& date)const {
    if (year > date.year) {
        return true;
    }
    else if (month > date.month) {
        return true;
    }
    else if (day > date.day) {
        return true;
    }
    else {
        return false;
    }
}
bool  Date::operator<=(const Date& date)const {
    if (year <= date.year) {
        return true;
    }
    else if (month <= date.month) {
        return true;
    }
    else if (day <= date.day) {
        return true;
    }
    else {
        return false;
    }
}
bool  Date::operator<(const Date& date)const {
    if (year < date.year) {
        return true;
    }
    else if (month < date.month) {
        return true;
    }
    else if (day < date.day) {
        return true;
    }
    else {
        return false;
    }

}
bool Date::operator==(const Date& date)const {
    if (year == date.year) {
    if (month == date.month) {
    if (day == date.day) {
        return true;
    }
    }
    }
    return false;
}
bool Date::operator!=(const Date& date)const {
    if (year != date.year) {
        if (month != date.month) {
            if (day != date.day) {
                return true;
            }
        }
    }
    return false;

}