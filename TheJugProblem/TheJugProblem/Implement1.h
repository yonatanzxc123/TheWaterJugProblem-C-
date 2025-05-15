#pragma once
#include "Graph.h"
#include <vector>


class Implement1
{
public:
     Solution solveUsingBFS(int L, int S, int W);

private:
     void buildJugGraph(int L, int S, Graph& g);
};