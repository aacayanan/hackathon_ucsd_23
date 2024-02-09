#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student {
    private:
        string id;
        string firstName;
        char lastInital;
        string startTime;

    public:
        Student();
        Student(string, string, char);
        ~Student();

        string getID() const;
        string getName() const;
        void setStartTime();
        string getStartTime() const;
        void setID(string);
        void setFirstName(string);
        void setLastInital(char);
};
#endif