#pragma once  
#include <iostream>  
#include <vector>  
#include <list>  

class Graph  
{  
private:  
   // Vector of pairs<int, int> representing vertices  
   std::vector<std::pair<int, int>> vertices;  

   // Vector of linked lists, where each linked list contains pairs<int, int>  
   std::vector<std::list<std::pair<int, int>>> adj_List;  

public:  
   // Constructor  
   Graph(int n)  
   {  
       vertices.resize(n);  
       adj_List.resize(n);  
   }  

   // Making an empty graph with n vertices  
   Graph* MakeEmptyGraph(int n)  
   {  
       return new Graph(n);  
   }  

   // Adding an edge   need to fix so it will be both pair types 
   void AddEdge(int u, std::pair<int, int> v)
   {  
       adj_List[u].push_back(v);  
   }  

   // Sorting and returning an adjacency list of a vertex  
   auto GetAdjList(int u) -> std::list<std::pair<int, int>>
   {  
       adj_List[u].sort();  
       return adj_List[u];  
   }  
};
