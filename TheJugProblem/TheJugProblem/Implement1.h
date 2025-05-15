#pragma once
#include "Graph.h"
#include <vector>


struct Solution
{
    bool                                solvable;
    std::vector<std::pair<int, int>>     path;   // (large, small) 
};

class Implement1
{
public:
    static Solution solveUsingBFS(int L, int S, int W);

private:
    static void buildJugGraph(int L, int S, Graph& g);
};