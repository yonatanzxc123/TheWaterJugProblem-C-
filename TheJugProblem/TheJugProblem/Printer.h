#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <chrono>

class Printer {

public:
    void printInstructions(int numOp)
    {
        std::cout << "Number of operations : " << numOp << std::endl;
        std::cout << "Operations :" << std::endl;
        std::cout << "1. Fill small jug" << std::endl;
        std::cout << "2. Transfer from small jug to large jug" << std::endl;
        std::cout << "3. Fill small jug" << std::endl;
        std::cout << "4. Transfer from small jug to large jug" << std::endl;
        std::cout << "5. Empty large jug" << std::endl;
        std::cout << "6. Transfer from small jug to large jug" << std::endl;
    }

};