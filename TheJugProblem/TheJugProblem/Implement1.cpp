#include "Implement1.h"
#include <algorithm>
#include <unordered_map>


using namespace std;


void Implement1::buildJugGraph(int L, int S, Graph& g)
{
    for (int x = 0; x <= L; ++x)
    {
        for (int y = 0; y <= S; ++y)
        {
            pair<int, int> u{ x,y };

			// 1. small jug fill
            if (y < S) g.AddEdge(u, { x, S });
			// 2. large jug fill
            if (x < L) g.AddEdge(u, { L, y });
            // 3. small emptying
            if (y > 0) g.AddEdge(u, { x, 0 });
			// 4. large emptying
            if (x > 0) g.AddEdge(u, { 0, y });
            // 5. pouring large to small 
            if (y > 0 && x < L)
            {
                int d = min(y, L - x);
                g.AddEdge(u, { x + d, y - d });
            }
            // 6. pouring small to large
            if (x > 0 && y < S)
            {
                int d = min(x, S - y);
                g.AddEdge(u, { x - d, y + d });
            }
        }
    }
}


Solution Implement1::solveUsingBFS(int L, int S, int W)
{
    if (W > L)            
        return { false,{} };

    Graph g((L + 1) * (S + 1)); // saving room for the proper amount of vertexes
    buildJugGraph(L, S, g); // building all of the edges

    unordered_map<pair<int, int>, pair<int, int>, PairHash> parent;
    pair<int, int> start{ 0,0 }, goal{ W,0 };

    if (!g.BFS(start, goal, parent))
        return { false,{} };

    // recreating path for the print
    vector<pair<int, int>> path;
    for (auto v = goal;;)
    {
        path.push_back(v);
        if (v == start) break;
        v = parent[v];
    }
    reverse(path.begin(), path.end());
    return { true, path };
}