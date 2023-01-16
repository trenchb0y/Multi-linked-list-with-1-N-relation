#include "iniHeader.h"

adrStudent createStudentNode(infotypeS x){
    adrStudent P = new studentNode;
    P->info = x;
    P->child = NULL;
    P->next = NULL;
    return P;
}

adrCourse createCourseNode(infotypeC x){
    adrCourse P = new courseNode;
    P->info = x;
    P->next = NULL;
    return P;
}

void insertStudentNode(adrStudent &studentList, adrStudent p){
    if(studentList->info.name == ""){
        studentList = p;
    } else {
        adrStudent Q = studentList;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = p;
    }
}

void insertCourseNode(adrCourse &courseList, adrCourse p){
    if(courseList->info.courseName == ""){
        courseList = p;
    } else {
        adrCourse Q = courseList;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = p;
    }
}

adrStudent findStudentNode(adrStudent studentList, std::string sid){
    adrStudent Q = studentList;
    while(Q->next != NULL){
        if(Q->info.sid == sid){
            return Q;
        }
        Q = Q->next;
    }
    if(Q->info.sid == sid){
        return Q;
    }
    return NULL;
}

adrCourse findCourseNode(adrCourse courseList, std::string courseID){
    adrCourse Q = courseList;
    while(Q->next != NULL){
        if(Q->info.courseID == courseID){
            return Q;
        }
        Q = Q->next;
    }
    if(Q->info.courseID == courseID){
        return Q;
    }
    return NULL;
}

void showStudentList(adrStudent studentList){
    std::cout << "\nDisplaying all student data inside list...";
    while(studentList != NULL){
        std::cout << "\nName\t: " << studentList->info.name << "\nNIM\t: " << studentList->info.sid << "\nMajor\t: " << studentList->info.major << std::endl;
        studentList = studentList->next;
    }
}

void showCourseList(adrCourse courseList){
    std::cout << "\nDisplaying all course data inside list...";
    while(courseList != NULL){
        std::cout << "\nCourse\t\t: " << courseList->info.courseName << "\nCourse ID\t: " << courseList->info.courseID << std::endl;
        courseList = courseList->next;
    }
}

void enroll(adrStudent studentList, adrCourse courseList, std::string sid, std::string courseID){
    adrStudent student = findStudentNode(studentList, sid);
    adrCourse course = findCourseNode(courseList, courseID);

    adrChild P = new childNode;
    P->next = NULL;
    P->course = course;
    if(student->child == NULL){
        student->child = P;
    } else {
        adrChild Q = student->child;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }
}

void showData(adrStudent studentList){
//    std::cout << "\nDisplaying data for student " << sid;
    while(studentList != NULL){
        std::cout << "\nName\t: " << studentList->info.name << "\nNIM\t: " << studentList->info.sid << "\nMajor\t: " << studentList->info.major << std::endl;
        if(studentList->child != NULL){
            std::cout << "Enrolled to: ";
            adrChild P = studentList->child;
            while(P != NULL){
                std::cout << P->course->info.courseName << " ";
                P = P->next;
            }
            std::cout << std::endl;
        } else {
            std::cout << "Student has not enroll to any course\n";
        }
        studentList = studentList->next;
    }
}

int selectMenu() {
    std::cout << "====== MENU ======" << std::endl;
    std::cout << "1. Input Student" << std::endl;
    std::cout << "2. Input Course" << std::endl;
    std::cout << "3. Show Student List" << std::endl;
    std::cout << "4. Show Course List" << std::endl;
    std::cout << "5. Enroll Student" << std::endl;
    std::cout << "6. Show Student Data" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Input Menu: ";

    int input = 0;
    std::cin >> input;

    return input;
}
