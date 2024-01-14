#pragma once
#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time
{
    friend  ostream& operator<<(ostream& output, const Time& time);
    friend istream& operator>>(istream& input, Time& time);
    friend Time operator-(Time&, Time&);
private:
    int hour;  //0-23 (24 hour clock format)
    int minute; //0-59
    string hour12;
    double decimal;//HH.MM (decimal format)
    void convertStandardToUniversal(Time& time);

public:
    //default constructor
    Time(int = 0, int = 0);
    void printUniversal() const;
    void printStandard()const;
    
    //set functions - not const since they modify private data
    //The & return type enables cascading
    Time& setTime(int, int);
    Time& setHour(int);
    Time& setMinute(int);
    
    //get functions - (normally always declared const)
    int getHour() const;
    int getMinute() const;

    //print functions - (normally always declared const since they do not 
    //modify private members, merely inspect

};
#endif