#include "Graph.h"
#include <algorithm>
#include <unordered_set>
#include <queue>


using namespace std;

// Constructor for Graph class
Graph::Graph(size_t n)
{
	vertices.reserve(n);
	adj_List.reserve(n);
}


// here we ensureVertex – insert(x, y) if missing, return numeric id
std::size_t Graph::ensureVertex(const std::pair<int, int>& v)
{
	auto result = indexByVertex.emplace(v, vertices.size());
	if (result.second)
	{         
		vertices.push_back(v);
		adj_List.emplace_back();
	}
	return result.first->second;  
}


// add directed edge u-> v to the graph FUN!
void Graph::AddEdge(const std::pair<int, int>& u,const std::pair<int, int>& v)
{
	std::size_t uid = ensureVertex(u);
	ensureVertex(v);                   

	auto& lst = adj_List[uid];

	// if duplicate do nothing
	if (std::find(lst.begin(), lst.end(), v) != lst.end()) return;

	// insert so that the list stays lexicographically sorted as tasked in the Matala		IDan i think we should check with something simple that the order is really right try to give a promt or somthing meh
	auto pos = std::find_if(lst.begin(), lst.end(), [&](const std::pair<int, int>& x) { return x > v; });
	lst.insert(pos, v);                // O(deg)
}


// get the adjacency list of vertex u
const std::list<std::pair<int, int>>&Graph::GetAdjList(const std::pair<int, int>& u) const
{
	auto it = indexByVertex.find(u);
	if (it == indexByVertex.end())
		throw std::out_of_range("vertex not found");

	return adj_List[it->second];
}


//Might be useless check if you even need this func punk
int numOfVertices(int largeJugSize, int smallJugSize)
{
	return (largeJugSize + 1) * (smallJugSize + 1); // plus 1 becuase jug can also hold 0 units of water
}


bool Graph::BFS(const pair<int, int>& src, const pair<int, int>& dst, unordered_map<pair<int, int>, pair<int, int>, PairHash>& parent) const
{
	unordered_set<pair<int, int>, PairHash> visited;
	queue<pair<int, int>> q;
	visited.insert(src);
	q.push(src);

	while (!q.empty())
	{
		auto u = q.front(); q.pop();
		if (u == dst) return true;
		for (const auto& v : GetAdjList(u))
		{
			if (!visited.count(v))
			{
				visited.insert(v);
				parent[v] = u;
				q.push(v);
			}
		}
	}
	return false;
}


