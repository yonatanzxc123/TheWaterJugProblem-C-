#include "Implement1.h"
#include "Implement2.h"
#include "Printer.h"  
#include <iostream>  

using namespace std;  

int main()  
{  
    int W, S, L;
    int showTime;
    int implementType;
    if (!(std::cin >> L >> S >> W >> implementType >> showTime))
    {
        std::cout << "Invalid input\n";
        return 1;
    }

    if (L < 0 || S < 0 || W < 0)
    {
        std::cout << "Invalid input";
        return 1;
    }
    if (S > L || W > L)
    {
        std::cout << "Invalid input";
        return 1;
    }

    Solution sol;

    auto t0 = std::chrono::steady_clock::now();

    if (implementType == 1)                // full pre-built graph
    {
        Implement1 solver;
        sol = solver.solveUsingBFS(L, S, W);
    }
    else if (implementType == 2)           // on-the-fly BFS
    {
        Implement2 solver;
        sol = solver.solveBFS_onTheFly(L, S, W);
    }
    else
    {
        std::cerr << "Invalid input";
        return 1;
    }

    
    auto t1 = std::chrono::steady_clock::now();

    if (!sol.solvable)
    {
        std::cout << "No solution.\n";
    }
    else
    {
        Printer().print(sol.path);
    }

    if (showTime == 1)
    {
        auto micro =
            std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
        std::cout << "Function took " << micro << " microseconds.\n";
    }
}
