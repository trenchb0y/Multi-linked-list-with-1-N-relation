#include "iniHeader.h"
#include <iostream>
using namespace std;

int main()
{
//    SNodeAdr SL = new studentNode; infotypeS x1; int num; string name, nim, major;
//    CNodeAdr CL = new courseNode; infotypeC x2; string courseName, courseID;
//    string SID, CID;
//
//    cout << "How many student data to be inputted: ";
//    cin >> num;
//    for(int i = 1; i <= num; i++){
//        cout << "\nData " << i << endl;
//        cout << "Name\t: "; cin >> name; x1.name = name;
//        cout << "NIM\t: "; cin >> nim; x1.nim = nim;
//        cout << "Major\t: "; cin >> major; x1.major = major;
//        insertSNode(SL,createSNode(x1));
//    }
//
//    cout << "How many course data to be inputted: ";
//    cin >> num;
//    for(int i = 1; i <= num; i++){
//        cout << "\nData " << i << endl;
//        cout << "Course\t\t: "; cin >> courseName; x2.courseName = courseName;
//        cout << "Course ID\t: "; cin >> courseID; x2.courseID = courseID;
//        insertCNode(CL,createCNode(x2));
//    }
//
//    cout << "\nEnter SID: "; cin >> SID;
//    cout << "Course to be enrolled: "; cin >> CID;
//    connect(SL, CL, SID, CID);
//    cout << "\nEnter SID: "; cin >> SID;
//    cout << "Course to be enrolled: "; cin >> CID;
//    connect(SL, CL, SID, CID);
//
//    showData(SL, "130");
////    showListS(SL);
////    showListC(CL);
//    return 0;
    adrStudent SL = new studentNode; infotypeS x;
    string name, sid, major;
    int j, numS;

    adrCourse CL = new courseNode; infotypeC y;
    string courseName, courseID;
    int k, numC;

    int select;
    string confirm;


    j = 1;
    k = 1;
    select = selectMenu();
    while (select != 0) {
        switch (select) {
        case 1: {
            cout << "How many student data to be inputted: ";
            cin >> numC;
            for(int i = 1; i <= numC; i++){
                cout << "\nData " << j << endl;
                cout << "Name\t: "; cin >> name; x.name = name;
                cout << "NIM\t: "; cin >> sid; x.sid = sid;
                cout << "Major\t: "; cin >> major; x.major = major;
                insertStudentNode(SL,createStudentNode(x));
                j++;
            }
            sid = "";
        } break;
        case 2: {
            cout << "How many course data to be inputted: ";
            cin >> numS;
            for(int i = 1; i <= numS; i++){
                cout << "\nData " << k << endl;
                cout << "Course Name\t\t: "; cin >> courseName; y.courseName = courseName;
                cout << "Course ID\t\t: "; cin >> courseID; y.courseID = courseID;
                insertCourseNode(CL,createCourseNode(y));
                k++;
            }
            courseID = "";
        } break;
        case 3: {
            if(CL->info.courseName == ""){
                cout << "Please input student data first\n";
            } else {
                showStudentList(SL);
            }
        } break;
        case 4: {
            if(CL->info.courseName == ""){
                cout << "Please input course data first\n";
            } else {
                showCourseList(CL);
            }
        } break;
        case 5: {
            if(CL->info.courseName == ""){
                cout << "Please input course data first\n";
            } else {
                cout << "Student ID to be enrolled: "; cin >> sid;
                cout << "\nEnter Course ID: "; cin >> courseID;
                enroll(SL, CL, sid, courseID);
                cout << "\n" << sid << " is enrolled to " << courseID << endl;
            }
        } break;
        case 6:
//            cout << "Student ID to be displayed: "; cin >> sid;
            showData(SL);
        }
        cout << "Back to the main menu? (y/n): ";
        cin >> confirm;
        if (confirm == "y") {
            cout << endl;
            select = selectMenu();
        } else if (confirm == "n") {
            select = 0;
        }
    }
    cout << endl;
    cout << "PROGRAM TERMINATED";
    return 0;
}
