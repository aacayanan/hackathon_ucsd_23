#include <iostream>
#include <unordered_map>
#include "PC.h"
#include "PC.cpp"
#include "ComputerNumStack.h"
#include "ComputerNumStack.cpp"
#include "Student.h"
#include "Student.cpp"
#include "Waitlist.h"
#include "Waitlist.cpp"
using namespace std;

void StudentCheckIn(Student&, PC, unordered_map<string, string>&, Waitlist, ComputerNumStack, string &);
void StudentToComputer(ComputerNumStack, Student, unordered_map<string, string>);
void StudentCheckOut(Student, unordered_map<string, string>, Waitlist);
void StudentToLimbo(Waitlist, string&);

int main() {
    bool exitStatus = false;
    string inLimbo;
    unordered_map<string, string> studentMap;
    PC room;
    ComputerNumStack available;
    Waitlist waitingList;
    room.initalizeLayout(available);
    string id, name;
    char lastInital;

    while (!exitStatus) {
        Student ucsd;
        cout << "Enter your student ID: ";
        cin >> id;
        if (id == "admin") {
            exitStatus = true;
            break;
        }
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your last initial: ";
        cin >> lastInital;
        ucsd.setID(id);
        ucsd.setFirstName(name);
        ucsd.setLastInital(lastInital);
        StudentCheckIn(ucsd, room, studentMap, waitingList, available, inLimbo);
    }
    
}



void StudentCheckIn(Student &stu, PC rm, unordered_map<string, string> &sMap, Waitlist WL, ComputerNumStack av, string &limbo) {
    if (stu.getID() == limbo) {
        StudentToComputer(av, stu, sMap);
    }

    if (sMap.find(stu.getID()) == sMap.end()) {
        // ID not in system
        if (rm.Availability(av)) {
            StudentToComputer(av, stu, sMap);
        } else {
            WL.enqueue(stu);
        }
    }

    if (sMap.find(stu.getID()) != sMap.end()) {
        // ID is in system -> go checkout
        StudentCheckOut(stu, sMap, WL);
        StudentToLimbo(WL, limbo);
    }
}

void StudentToComputer(ComputerNumStack av, Student s, unordered_map<string, string> map) {
    string str;
    av.pop(str);
    map[s.getID()] = str;
}


void StudentCheckOut(Student s, unordered_map<string, string> map, Waitlist WL) {
    map.erase(s.getID());
}

void StudentToLimbo(Waitlist WL, string &limbo) {
    if (!WL.isEmpty()) {
        WL.dequeue(limbo);
    }
}

