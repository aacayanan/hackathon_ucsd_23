#ifndef COMPUTERNUMSTACK_H
#define COMPUTERNUMSTACK_H
#include <string>
using namespace std;

class ComputerNumStack {
    protected:
        struct StackNode {
            string value;
            StackNode *next;
        };

        StackNode *top;

    public:
        ComputerNumStack() {top = nullptr;}

        ~ComputerNumStack();

        void push(string);
        void pop(string &);
        bool isEmpty();
        void displayStack() const;

};
#endif