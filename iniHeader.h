#ifndef INIHEADER_H_INCLUDED
#define INIHEADER_H_INCLUDED
#include <iostream>
typedef struct studentNode *adrStudent;
typedef struct childNode *adrChild;
typedef struct courseNode *adrCourse;

struct infotypeS {
    std::string name, sid, major;
};

struct infotypeC {
    std::string courseName, courseID;
};

struct studentNode {
    infotypeS info;
    adrChild child;
    adrStudent next;
};

struct childNode {
    adrCourse course;
    adrChild next;
};

struct courseNode {
    infotypeC info;
    adrCourse next;
};

adrStudent createStudentNode(infotypeS x);
void insertStudentNode(adrStudent &studentList, adrStudent p);
adrStudent findStudentNode(adrStudent studentList, std::string sid);
void showStudentList(adrStudent studentList);

adrCourse createCourseNode(infotypeC x);
void insertCourseNode(adrCourse &courseList, adrCourse p);
adrCourse findCourseNode(adrCourse courseList, std::string courseID);
void showCourseList(adrCourse courseList);

void enroll(adrStudent studentList, adrCourse courseList, std::string nim, std::string courseID);
void showData(adrStudent studentList);

int selectMenu();
#endif // INIHEADER_H_INCLUDED
