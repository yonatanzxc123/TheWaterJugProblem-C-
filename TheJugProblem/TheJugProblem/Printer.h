#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <chrono>

class Printer {

public:
    void print(const std::vector<std::pair<int, int>>& path)
    {
        static const char* opNames[] = {
            "Fill small jug",
            "Fill large jug",
            "Empty small jug",
            "Empty large jug",
            "Transfer from small jug to large jug",
            "Transfer from large jug to small jug"
        };

        std::cout << "Number of operations: " << path.size() - 1 << '\n';
        std::cout << "Operations:\n";

        for (std::size_t i = 1; i < path.size(); ++i)
        {
            auto p = path[i - 1], q = path[i];
            std::string op;
            if (p.first == q.first)
            {
                op = (q.second > p.second) ? "Fill small jug"
                    : "Empty small jug";
            }
            else if (p.second == q.second)
            {
                op = (q.first > p.first) ? "Fill large jug"
                    : "Empty large jug";
            }
            else
            {
                op = (q.second < p.second) ? "Transfer from small jug to large jug"
                    : "Transfer from large jug to small jug";
            }


            std::cout << i << ". " << op << '\n';
        }
    }
};