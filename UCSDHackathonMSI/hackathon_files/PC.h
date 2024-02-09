#ifndef PC_H
#define PC_H
#include <string>
#include "ComputerNumStack.h"
using namespace std;

class PC {
    private:
        string computerNumber;
        bool isAvailable;
        int totalRows;
        int totalComputers;
        string computerLayout;

    public:
        PC();

        string getComputerNumber() const { return computerNumber; }
        void initalizeLayout(ComputerNumStack&);
        bool Availability(ComputerNumStack&);

};
#endif