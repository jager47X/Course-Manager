//
//  CourseSchedule.cpp
//  CourseSchedule
//
//  Created by Anita Hovsepian on 10/27/21.
//
#include <iostream>
#include <string.h>
#include <algorithm>
#include "CourseSchedule.h"
using namespace std;
#include <iomanip>

//no implementation for our part

CourseSchedule::CourseSchedule(string st, Semester s,int max):studentName (st),semester(s),maxSize(max){
	
	course = new Course[maxSize];
	numCourses = 0;

}
CourseSchedule::~CourseSchedule() {
	delete[] course;
}

Semester CourseSchedule::getSemster()const {
	return semester;
}
string CourseSchedule::getStundentName() const {
	return studentName;
}
void CourseSchedule::setStudentName(string name) {
	studentName = name;
}
bool CourseSchedule::checkDates(Semester sem, Date begin, Date end) {//notsure
	if (sem.getStartDate() < begin) {
		return true;
	}
	if (sem.getEndDate() > end) {
		return true;
	}
	return false;
}

Course* CourseSchedule::AddCourse(Course* course, CourseSchedule& schedule) {
	
	
	bool date=checkDates(schedule.semester, schedule.course[numCourses].getStartDate() , schedule.course[numCourses].getEndDate());
	if (date == true) {
		
	schedule.course[numCourses] = *course;
		numCourses++;
		cout << "\nCourse was successfully added.";
	}else {
		cout << "\nCourse was not added due to date error.";
	}
	
	return course;
	
}

ostream& operator<<(ostream& output, CourseSchedule& schedule) {
	output << "ClASS SCHEDULE"<<endl;
	output << "------------------------" << endl;
	output << "Name: " << schedule.studentName << endl;
	output << "Semester: " << schedule.semester << endl;
	output << "Number of Classes: " << schedule.maxSize << endl;
	output << "--------------------------------"<<endl;
	for (int i = 0; i < schedule.numCourses; i++) {
		output << schedule.course[i] <<endl;
	}
	return output;
}

Course* CourseSchedule::removeCourse(Course* course, CourseSchedule& schedule,string courseNum) const {//notsure

	for (int i = 0; i < schedule.maxSize; i++) {
			
			if (courseNum == schedule.course[i].getCourseNum()) {
				
				
					schedule.course[i] = schedule.course[-1];
				
				


				cout << "Selected course was removed";
				return course;
			}

			
	}
	cout << "Selected course was not found";
	return course;
	
}

