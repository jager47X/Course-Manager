//
//  CourseSchedule.h
//  CourseSchedule
//
//  Created by Anita Hovsepian on 10/27/21.
//

#ifndef CourseSchedule_h
#define CourseSchedule_h
#include <iostream>
#include <string>
#include "Semester.h"
#include "Course.h"
using namespace std;

class CourseSchedule
{
    friend ostream& operator<<(ostream& output, CourseSchedule& schedule);
private:
    string studentName;
    Semester semester;
    Course *course; 
    int maxSize; //max num of courses for array
    int numCourses; // how many courses have been added 
    bool checkDates(Semester sem, Date begin, Date end);
    CourseSchedule (const CourseSchedule&);   // Disallow copy contructor.
    CourseSchedule& operator=(const CourseSchedule&); // Disallow assignment operator.
public:
    CourseSchedule(string = "", Semester= Semester(), int =0);
    ~CourseSchedule();
    string getStundentName()const;
    void setStudentName(string name);
    Semester getSemster()const;
    Course* AddCourse(Course* course, CourseSchedule& schedule);
    Course* removeCourse(Course* course, CourseSchedule& schedule, string courseNum)const;
    
   
};

#endif /* CourseSchedule_h */
