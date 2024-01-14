#include <iostream>
#include <iomanip>
using namespace std;
#include "Time.h"
//Constructor function to initialize private data
//remember a constructor is called whenever a new object of
//a class data type is instantiated, if a constructor is not defined the C++ do 
//nothing constructor is run, it is better to ALWAYS have your own contructor
//once you have your own constructor the default is no longer available
//Constructors can and should be overloaded
//Constructors cannot be const since they always manipulate private data
Time::Time(int h, int m ):hour(h),minute(m)
{
    string hour12 = " "; double decimal = 0.0;
    setTime(hour, minute);
}
/*SET FUNCTIONS: Never const since they need to modify private member data*/
//setTime function now is set up to enable cascading
Time& Time::setTime(int hour, int minute)
{
    setHour(hour);
    setMinute(minute);
    return *this;
}
//setHour function is now set up to enable cascading
Time& Time::setHour(int h)
{
    hour = (h >= 0 && h < 24) ? h : 0;  //validates hour, if valid set to h, else set to 0
        return *this;
}
//setMinute function is now set up to enable cascading
Time& Time::setMinute(int m)
{
    minute = (m >= 0 && m < 60) ? m : 0;  //validates minute, if valid set to m, else set to 0
        return *this;
}

/*GET FUNCTIONS:  Do not modify private member data normally always const*/
//get Hour
int Time::getHour() const  //must be const since prototype is const
{
    return hour;
}
//get Minute
int Time::getMinute() const  //must be const since prototype is const
{
    return minute;
}

/*PRINT FUNCTIONS:  Normally do not modify private member data so should be const*/
void Time::printUniversal()const  //must be const since prototype is const
{
    cout << decimal;
    cout << setfill('0') << setw(2) << hour << ":"
       << setw(2) << minute << endl;
}
void Time::printStandard()const  //must be const since prototype is const
{
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
        << setfill('0') << setw(2) << minute << (hour < 12 ? "AM" : "PM") << endl;
}

 ostream& operator<<(ostream& output, const Time& time){

     output << ((time.hour == 0 || time.hour == 12) ? 12 : time.hour % 12) << ":"
         << setfill('0') << setw(2) << time.minute<< " " << ((time.hour12== "AM") ? "AM" : "PM");
    
     return output;
}

 istream& operator>>(istream& input, Time& time)
 {
     cout << "Input the time in standard time format[HH:MM (AM or PM)] \n";
     input >> time.hour;
     input.ignore();
     input >> time.minute;
     input >> time.hour12;

     if (time.hour > 12 || time.hour < 0) {//defalut values
         time.hour = 0;
     }
     if (time.minute > 60 || time.minute < 0) {
         time.minute = 0;
     }
     if (time.hour12 != "AM" || time.hour12 != "PM") {
             time.hour12="AM";
     }

     return input;
 }
 void Time::convertStandardToUniversal(Time& time){

     if (time.hour12 == "PM") {
         time.hour += 12;

     }

 }

 Time operator-(Time& first, Time& second) {
     Time third;
     third.decimal = (((double)first.hour / 1.0 - (double)second.hour / 1.0)+ (((double)first.minute / 60.0))- ((double)second.minute / 60.0));
     cout << third.decimal;
     return  third;
 }
