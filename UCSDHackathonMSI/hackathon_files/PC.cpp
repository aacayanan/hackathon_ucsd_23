#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "PC.h"
#include "json.hpp"
#include "ComputerNumStack.h"
using namespace std;

PC::PC() {
    ifstream jsonFileStream("./roomlayout.json");
    nlohmann::json roomLayout = nlohmann::json::parse(jsonFileStream);
    totalRows = roomLayout["totalRows"];
    computerLayout = roomLayout["roomLayout"];
    computerNumber = "";
}

void PC::initalizeLayout(ComputerNumStack &avail) {
    char row = 'A';
    int temp = 0;
    string blah;
    string blah2;

    for (int i = 0; i < totalRows; ++i) {
        for (int j = 0; j < computerLayout.length(); ++j) {
            if (computerLayout[j] == row) {
                blah = computerLayout[j+1];
                temp = stoi(blah);
                for (int k = 1; k <= temp; ++k) {
                    computerNumber += row;
                    blah2 = to_string(k);
                    computerNumber += blah2;
                    avail.push(computerNumber);
                    computerNumber = "";
                }
            }
        }
        row++;
    }
}

bool PC::Availability(ComputerNumStack &avail) {
    if (avail.isEmpty()) {
        isAvailable = false;
    } else {
        isAvailable = true;
    }
    return isAvailable;
}