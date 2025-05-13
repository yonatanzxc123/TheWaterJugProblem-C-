#include "Graph.h"
#include <unordered_set>

using namespace std;



int numOfVertices(int largeJugSize, int smallJugSize)
{
	return (largeJugSize + 1) * (smallJugSize + 1); // plus 1 becuase jug can also hold 0 units of water
}
// V = {(x,y) | 0 <= x <= lagreJugSize, 0 <= y <= smallJugSize}
auto createVertices(int largeJugSize, int smallJugSize)
{
	unordered_set<pair<int,int>> VerticesSet;

	for (int i = 0; i < largeJugSize; i++)
	{
		for (int j = 0; i < smallJugSize; j++)
		{

			VerticesSet.insert({ i,j });

		}
	}
}
void allPossibleEdges(int largeJugSize, int smallJugSize, unordered_set<pair<int, int>> VerticesSet)
{
	// 1. Fill small jug

	for (int i = 0; i < largeJugSize; i++)
	{
		for (int j = 0; i < smallJugSize; j++)
		{
			// 1. Fill Large jug Edges

			if ((VerticesSet.find({ largeJugSize, j }) && (VerticesSet.find({ i, j })) != VerticesSet.end()))
			{
				// add edge
				AddEdge(i, { largeJugSize, j });
			}



			VerticesSet.insert({ i,j });

		}
	}
	

	
	// 2. Transfer from small jug to large jug
	
	// 3. Fill large jug
	
	// 4. Transfer from large jug to small jug
	
	// 5. Empty small jug
	// 6. Empty large jug
	// BFS does the following 1) tells us if there is a path from u to v 2) what is the lengnth of the shortest path from u to v
	// V is the number of vertices in the graph  and V = {(x,y) | 0 <= x <= lagreJugSize, 0 <= y <= smallJugSize}


/// BFS does the following 1) tells us if there is a path from u to v 2) what is the lengnth of the shortest path from u to v
//  V is the number of vertices in the graph  and V = {(x,y) | 0 <= x <= lagreJugSize, 0 <= y <= smallJugSize}