#pragma once  
#include <iostream>  
#include <vector>  
#include <list> 
#include <algorithm>
#include <unordered_map>
#include <stdexcept> 
#include <utility>     // std::pair
#include <unordered_set>





// Helper func for std::pair<int,int> (we transform the pair into a single number value so we can have indexs)
struct PairHash
{
    std::size_t operator()(const std::pair<int, int>& p) const noexcept
    {
        return (static_cast<std::size_t>(p.first) << 16) ^ static_cast<std::size_t>(p.second);
    }
};

struct Solution
{
    bool                                solvable;
    std::vector<std::pair<int, int>>     path;   // (large, small) 
};


class Graph  
{  
private:  
   // Vector of pairs<int, int> representing vertices  
   std::vector<std::pair<int, int>> vertices;  

   // Vector of linked lists, where each linked list contains pairs<int, int>  
   std::vector<std::list<std::pair<int, int>>> adj_List; 
   std::unordered_map<std::pair<int, int>,std::size_t, PairHash> indexByVertex; // (x,y)  -> id

   // helper: make sure a vertex exists and return its id 
   std::size_t ensureVertex(const std::pair<int, int>& v);

public:  
    explicit Graph(size_t n = 0);       


   static Graph* MakeEmptyGraph(std::size_t n = 0) { return new Graph(n); }

    void AddEdge(const std::pair<int, int>& u,const std::pair<int, int>& v);

    const std::list<std::pair<int, int>>&GetAdjList(const std::pair<int, int>& u) const;

    bool BFS(const std::pair<int, int>& src, const std::pair<int, int>& dst, std::unordered_map<std::pair<int, int>, std::pair<int, int>, PairHash>& parent) const;

};


