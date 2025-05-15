#include "Implement1.h"
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
        std::cerr << "Bad input\n";
        return 1;
    }

    auto t0 = std::chrono::steady_clock::now();
    Solution sol = Implement1::solveUsingBFS(L, S, W);
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
