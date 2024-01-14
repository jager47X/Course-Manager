//
//  Course.cpp
//  Course
//
//  Created by Anita Hovsepian on 10/27/21.
//

#include <iostream>
#include <string>
#include "Course.h"
using namespace std;

Course::Course(string cnum, string cn, string md, double u, Date  sD, Date eD, Time sT, Time eT) :courseNum(cnum), courseName(cn), meetingDays(md), units(u), startDate(sD), endDate(eD),startTime(sT),endTime(eT)
{

}
Course::~Course()
{
    cout << "A course has been deleted." << endl;
}
Course& Course::setCourseNum(string num)
{
    courseNum = num;
    return *this;
}
Course& Course::setCourseName(string name)
{
    courseName = name;
    return *this;
}
Course& Course::setmeetingDays(string day)
{
    meetingDays = day;
    return *this;
}
Course& Course::setunits(double unit)
{
    this->units = unit;
    return *this;
}
string Course::getCourseNum()const
{
    return courseNum;
}
string Course::getCourseName()const
{
    return courseName;
}
string Course::getmeetingDays()const
{
    return meetingDays;
}
double Course::getunits()const
{
    return units;
}
Date Course::getStartDate()  {

    return startDate;
}
Date Course::getEndDate() {
    return endDate;
}
Time Course::getStartTime() {
    
    return startTime;
}
Time Course::getEndTime() {
    return endTime;
}
void Course::setStartDate(Date date) {
    startDate=date;
}
void Course::setEndDate(Date date) {
    endDate = date;
    
}

void Course::setStartTime(Time time) {
    startTime = time;
    
}
void Course::setEndTime(Time time) {
    endTime = time;
  
}
ostream& operator<<(ostream& output,  Course& course) {

    output <<"Course Info:     " << course.courseNum <<" -- " << course.courseName<<endl;
    output <<"# of Units:      " << course.units<<endl;
    output <<"Course Dates:    " << course.startDate << "-" << course.endDate << endl;
    output <<"Meeting Days:    " << course.meetingDays << endl;
    output <<"Meeting TIme:    " << course.startTime <<" - "<<course.endTime << endl;
    output <<"Daily Duration:  "; course.calcDailyDuration(course.startTime, course.endTime); output << endl;

    return output;
}

Time Course::calcDailyDuration(Time& startTime,Time& endTime) {

    Time duration;
    duration= endTime-startTime;
    
    return duration;
}