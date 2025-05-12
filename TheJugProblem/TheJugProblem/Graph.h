#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>


class Graph
{
private:
	int vertices;
	int edges;
	std::vector<std::list<std::size_t>> adj_;


public:
	//Constractor
	Graph(int n) : vertices(n), edges(0)
	{
		adj_.resize(n);
	}
	//Making an empty graph with n vertices
	Graph* MakeEmptyGraph(int n)
	{ 
		return new Graph(n); 
	};
	// adding Eddge
	void AddEdge(int u, int v)
	{
		adj_[u].push_back(v);
		++edges;
	}
	// Sorting and returning an adjacency list of a vertex
	auto GetAdj(int u) -> std::list<std::size_t>
	{
		adj_[u].sort();
		return adj_[u];
	}


};
