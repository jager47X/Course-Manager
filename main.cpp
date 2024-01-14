#include <iostream>
#include <string>
using namespace std;

#include<string.h>
#include "Time.h"
#include "Course.h"
#include "Date.h"
#include "Semester.h"
#include "CourseSchedule.h"

int main()
{


    string name,semsterName;
    int maxClass;
    Date startDate;
    Date endDate;

    cout << "NAME:";
    getline(cin, name);
    cout << "\nSemester:";
    getline(cin, semsterName);
    cout << "\nSemester Start Date:";
    cin >> startDate;
    cout << "\nSemester End Date:";
    cin >> endDate;
    cout << "\nNumber of courses:";
    cin >> maxClass;
    Semester sem(semsterName, startDate, endDate);




    Date StartClass;
    Date EndClass;
    Time startTime;
    Time endTime;
    char choice=' ';
    bool exit=false;
    string courseNum, courseNa, meet;
    double unit;
    CourseSchedule CourseS(name, sem, maxClass);


    while (exit!=true) {
        Course* course = new Course;
        cout << "\n\n1)Enter a new course";
        cout << "\n2)Remove a course";
        cout << "\n3)Print a Semster Schdule";
        cout << "\nQ)Quit the program"<<endl;
        cin >> choice;
        switch(choice){
            case '1':
                cout << "\nNumber of course:";
                cin >> courseNum;
                cout << "\nName of course:";
                cin >> courseNa;
                cout << "\nday of course:";
                cin >> meet;
                cout << "\nUnit of course:";
                cin >> unit;
                cout << "\nStart Time of the course:";
                cin >> startTime;
                cout << "\nEnd Time of the course:";
                cin >> endTime;
                cout << "\nStart Date of the course:";
                cin >> StartClass;
                cout << "\nEnd Date of the course:";
                cin >> EndClass;


                course->setCourseNum(courseNum);
                course->setCourseName(courseNa);
                course->setmeetingDays(meet);
                course->setunits(unit);
                course->setStartTime(startTime);
                course->setEndTime(endTime);
                course->setStartDate(startDate);
                course->setEndDate(endDate);

                CourseS.AddCourse(course, CourseS);
                break;
            case '2':

                cout << "\nThe course number to remove:"; \
            cin >> courseNum;
                CourseS.removeCourse(course,CourseS,courseNum);
                break;
            case '3':
                cout << CourseS;
                break;
            case 'q':
            case 'Q':
                exit = true;

                break;
            defalut:
                cout << "Select from 1-3 or Q\n";
        }

    }





    system("PAUSE");
    return 0;
}