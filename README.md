# Course Schedule Management System

## Table of Contents
- [Introduction](#introduction)
- [Classes](#classes)
  - [Time Class](#time-class)
  - [Date Class](#date-class)
  - [Semester Class](#semester-class)
  - [Course Class](#course-class)
  - [CourseSchedule Class](#courseschedule-class)
- [Main Function](#main-function)
- [Program Flow](#program-flow)
- [Conclusion](#conclusion)

## 1. Introduction
The Course Schedule Management System is a console-based application developed in C++. This system allows users to create, manage, and display course schedules within a semester. The program utilizes various classes to represent time, dates, semesters, courses, and the overall course schedule.

## 2. Classes
### 2.1 Time Class(#time-class)
Represents a specific time.
- Attributes:
  - Hours
  - Minutes
- Methods:
  - Overloaded extraction operator (>>) for input.

### 2.2 Date Class
Represents a specific date.
- Attributes:
  - Day
  - Month
  - Year
- Methods:
  - Overloaded extraction operator (>>) for input.

### 2.3 Semester Class
Represents a semester.
- Attributes:
  - Semester name
  - Start date
  - End date
- Methods:
  - Constructor to initialize the semester.

### 2.4 Course Clas
Represents a course.
- Attributes:
  - Course number
  - Course name
  - Meeting days
  - Units
  - Start time
  - End time
  - Start date
  - End date
- Methods:
  - Setter methods to set course details.

### 2.5 CourseSchedule Class
Manages a collection of courses within a semester.
- Attributes:
  - Name of the schedule owner
  - Semester information
  - Maximum number of courses
  - Collection of courses
- Methods:
  - AddCourse: Adds a new course to the schedule.
  - removeCourse: Removes a course from the schedule.
  - Overloaded extraction operator (<<) to print the schedule.

## 3. Main Function
Collects information such as the owner's name, semester details, and maximum number of courses.
Provides a menu-driven interface for users to:
- Enter a new course
- Remove a course
- Print the semester schedule
- Quit the program

## 4. Program Flow
User inputs basic information like name, semester details, and maximum number of courses.
Menu-driven interface allows users to:
- Enter new courses with details such as course number, name, meeting days, units, and time.
- Remove a course based on the course number.
- Print the current semester schedule.
- Quit the program.
Course information is stored and managed using the CourseSchedule class.

## 5. Conclusion
The Course Schedule Management System provides a simple and effective way to manage courses within a semester. The modular design of classes allows for easy extension and modification. Additional features, error handling, and user interface improvements can be added to enhance the functionality and user experience of the system.
