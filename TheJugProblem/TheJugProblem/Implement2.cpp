#include "Implement2.h"
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

std::vector<std::pair<int, int>> Implement2::CalculateAdjList(const std::pair<int, int>& u, int L, int S, const std::unordered_set<std::pair<int, int>, PairHash>& visited)
{
    int l = u.first;      // large
    int s = u.second;     // small
    std::vector<std::pair<int, int>> nbrs;

    /* 1. Fill small */
    if (s < S) nbrs.push_back({ l, S });

    /* 2. Fill large */
    if (l < L) nbrs.push_back({ L, s });

    /* 3. Empty small */
    if (s > 0) nbrs.push_back({ l, 0 });

    /* 4. Empty large */
    if (l > 0) nbrs.push_back({ 0, s });

    /* 5. Pour small to large */
    if (s > 0 && l < L)
    {
        int d = std::min(s, L - l);
        nbrs.push_back({ l + d, s - d });
    }

    /* 6. Pour large to small */
    if (l > 0 && s < S)
    {
        int d = std::min(l, S - s);
        nbrs.push_back({ l - d, s + d });
    }

    std::sort(nbrs.begin(), nbrs.end());
    nbrs.erase(std::remove_if(nbrs.begin(), nbrs.end(), [&](const std::pair<int, int>& v) { return visited.count(v) != 0; }), nbrs.end());
    return nbrs;
}


Solution Implement2::solveBFS_onTheFly(int L, int S, int W)
{
    if (W > L) 
     return { false,{} };

    typedef std::pair<int, int> State;
    const State start(0, 0), goal(W, 0);

    std::queue<State>                               q;
    std::unordered_set<State, PairHash>              visited;
    std::unordered_map<State, State, PairHash>        parent;

    visited.insert(start);
    q.push(start);

    bool found = false;
    while (!q.empty() && !found)
    {
        State u = q.front(); 
        q.pop();

        // generate the direct neighbors
        std::vector<State> nbrs =
            CalculateAdjList(u, L, S, visited);

        for (const State& v : nbrs)
        {
            visited.insert(v);
            parent[v] = u;
            if (v == goal) 
            { 
                found = true; 
                break; 
            }
            q.push(v);
        }
    }

    if (!found) 
      return { false,{} };

    // reconstruct path 
    std::vector<State> path;
    for (State v = goal;;)
    {
        path.push_back(v);
        if (v == start) break;
        v = parent[v];
    }
    std::reverse(path.begin(), path.end());
    return { true, path };
}
