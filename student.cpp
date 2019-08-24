// student.cpp
#include "student.h"
#include <iostream>
#include <iomanip>

student::student() {}

// Student initializer w/ given attributes
student::student(string name, int uniqueID, float GPA) {
    this->GPA = GPA;
    this->name = name;
    this->uniqueID = uniqueID;
}

// Student deconstructor
student::~student() {}

// Prints the student's attributes
void student::printStudent() {
  if (this->uniqueID == -1) {
    cout << "not found";
    return;
  } else{
    cout << this->name << ", " << this->uniqueID << ", "  << setprecision(1) << fixed << this->getGPA()
         << "";
  }
}

// Returns student's name
string student::getName() { return this->name; }

// Returns student's GPA
float student::getGPA() { return this->GPA; }

// Checks to see if given student is less than comparing student
bool student::operator<(student rhs) {
    if (this->uniqueID < rhs.uniqueID) {
        return true;
    } else
        return false;
}

// Checks to see if given student is greater than comparing student
bool student::operator>(student rhs) {
    if (this->uniqueID > rhs.uniqueID) {
        return true;
    } else
        return false;
}

// Checks to see if given student is equal to comparing student
bool student::operator==(student rhs) {
    if (this->uniqueID == rhs.uniqueID) {
        return true;
    } else
        return false;
}
