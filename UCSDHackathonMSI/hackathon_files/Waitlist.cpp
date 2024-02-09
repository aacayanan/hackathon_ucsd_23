#include <iostream>
#include "Waitlist.h"
#include "Student.h"

Waitlist::Waitlist() {
    front = nullptr;
    rear = nullptr;
    studentCount = 0;
}

Waitlist::~Waitlist() {
    clear();
}

void Waitlist::enqueue(Student student) {
    QueueNode *newNode = nullptr;

    newNode = new QueueNode;
    newNode->value = student.getID();
    newNode->next = nullptr;

    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    studentCount++;
}


void Waitlist::dequeue(string ID) {
    QueueNode *temp = nullptr;

    if (isEmpty()) {
        cout << "queue empty..." << endl;
    } else {
        ID = front->value;
        temp = front;
        front = front->next;
        delete temp;
    }
    studentCount--;
}


bool Waitlist::isEmpty() const {
    bool status;
    if (studentCount > 0) {
        status = false;
    } else {
        status = true;
    }
    return status;
}

void Waitlist::clear() {
    string value;       // Dummy variable for dequeue

    while (!isEmpty()) {
        dequeue(value);
    }
}

int Waitlist::getStudentCountInQueue() const {
    return studentCount;
}