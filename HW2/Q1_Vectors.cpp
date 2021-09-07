/*  Nick Sweeting 2013/10/08
    Student List (OOP)
    MIT Lisence
    g++ Vectors.cpp -o main && ./main
    Example of using vectors to store a list of students and their GPAs.
    It is referred from: https://github.com/pirate/Cpp-Data-Structures/
*/

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Student {
    string firstName;
    string lastName;
    int studentID;
    double GPA;
};

void printStudents(vector<Student> students) {
    cout<<" The total number of students is "<<students.size()<<endl;
    
    for (int i=0; i<students.size();i++){
    cout<<"-------------------------------------"<<endl;
    cout<<" Student First Name: "<<students[i].firstName<<endl;
    cout<<" Student Last Name: "<<students[i].lastName<<endl;
    cout<<" Student ID: "<<students[i].studentID<<endl;
    cout<<" Student GPA: "<<students[i].GPA<<endl;
     
    }
    cout<<"-------------------------------------"<<endl;
};

vector<Student> addStudent(vector<Student> students) {

    Student newStudent;

    cout << "First Name: ";
    cin >> newStudent.firstName;
    cout << "Last Name: ";
    cin >> newStudent.lastName;
    cout << "ID: ";
    cin >> newStudent.studentID;
    cout << "GPA: ";
    cin >> newStudent.GPA;
    students.push_back(newStudent);
    
    return students;
}

vector<Student> delStudent(vector<Student> students) {
    int studentIDtoDel;
    cout << "ID of student to delete: ";
    cin >> studentIDtoDel;
    cout << "ID to delete: " << studentIDtoDel << endl;
    
    vector<Student> newStudents;
    bool del=false;
    for (int i=0; i<students.size();i++){
       
       if (students[i].studentID!=studentIDtoDel){
           newStudents.push_back(students[i]);}
       else{
         del=true;
         cout<<"Student was successfully delete!"<<endl;
       }}
    if (del==false){
        cout<<"No such a student or Enter correct student ID!"<<endl;}
    return newStudents;
}

int main() {
    vector<Student> students;
    string input;

    while (true) {
        cout<<"Input operation: ";
        cin >> input;

        if (input == "ADD" || input == "a" || input == "add") {
            students = addStudent(students);
        }
        else if (input == "PRINT" || input == "p" || input == "print") {
            printStudents(students);
        }
        else if (input == "DELETE" || input == "d" || input == "delete") {
            students = delStudent(students);
        }
        else if (input == "QUIT" || input == "q" || input == "quit") {
            return 0;
        }
        cout<<"\n";
    }
}