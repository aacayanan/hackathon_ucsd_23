#ifndef WAITLIST_H
#define WAITLIST_H
#include "Student.h"

class Waitlist {
    private:
        struct QueueNode {
            string value;
            QueueNode *next;
        };

        QueueNode *front;
        QueueNode *rear;
        int studentCount;

    public:
        Waitlist();
        ~Waitlist();

        void enqueue(Student);
        void dequeue(string);
        bool isEmpty() const;
        bool isFull() const;
        void clear();
        int getStudentCountInQueue() const;
};
#endif