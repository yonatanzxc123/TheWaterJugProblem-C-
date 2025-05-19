#pragma once
#include "Graph.h"
#include <vector>
#include <utility>


class Implement2
{
public:
    Solution solveBFS_onTheFly(int L, int S, int W);

    std::vector<std::pair<int, int>> CalculateAdjList(const std::pair<int, int>& u, int L, int S, const std::unordered_set<std::pair<int, int>, PairHash>& visited);
};

