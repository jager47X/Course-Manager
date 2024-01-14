//
//  Course.h
//  Course
//
//  Created by Anita Hovsepian on 10/27/21.
//

#ifndef Course_h
#define Course_h
#include <iostream>
#include <string>
#include "Date.h"
#include "Time.h"
using namespace std;

class Course
{
    friend ostream& operator<<(ostream& output, Course& course);
  
private:
    string courseNum;
    string courseName;
    string meetingDays;
    double units;
    Date startDate;
    Date endDate;
    Time startTime;
    Time endTime;
public:
    Course(string = " ", string = " ", string = " ", double = 0.0, Date = Date(), Date = Date(), Time = Time(), Time = Time());
    ~Course();

    Course& setCourseNum(string);
    Course& setCourseName(string);
    Course& setmeetingDays(string);
    Course& setunits(double);

    string getCourseNum()const;
    string getCourseName()const;
    string getmeetingDays()const;
    double getunits()const;
    Date getStartDate();
    Date getEndDate();
    Time getStartTime();
    Time getEndTime();
    void setStartDate(Date date);
    void setEndDate(Date date);
    void setStartTime(Time time);
    void setEndTime(Time time);

    Time calcDailyDuration(Time& startTime, Time& endTime);
};

#endif /* Course_h */
