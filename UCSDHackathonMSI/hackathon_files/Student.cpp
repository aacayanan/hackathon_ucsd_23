#include <iostream>
#include <ctime>
#include <string>
#include "Student.h"
using namespace std;

Student::Student() {
    id = "";
    firstName = "";
    lastInital = ' ';
    setStartTime();
}

Student::Student(string sid, string name, char inital) {
    id = sid;
    firstName = name;
    lastInital = inital;
    setStartTime();
}

Student::~Student() {}

void Student::setID(string sid) {
    id = sid;
}

string Student::getID() const {
    return id;
}

void Student::setFirstName(string fn) {
    firstName = fn;

}

void Student::setLastInital(char in) {
    lastInital = in;
}

string Student::getName() const {
    return (firstName + " " + lastInital);
}


// fix this
void Student::setStartTime() {
    time_t tt;
    struct tm* ti;
    time(&tt);
    ti = localtime(&tt);
    startTime = asctime(ti);
}

string Student::getStartTime() const {
    return startTime;
}