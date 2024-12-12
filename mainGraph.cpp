/*
   Program that implements a weighted directed graph
   Author: Abdiel Elias
   Date: 12/12/2024
*/
#include <iostream>
#include "Vertex.h"
#include "WeightedGraph.h"

using namespace std;

int main()
{
    WeightedGraph myGraph(10);
    Vertex *aVertex, *bVertex, *cVertex, *dVertex, *eVertex;

    aVertex = new Vertex("A"); // node 0
    myGraph.addVertex(aVertex);
    bVertex = new Vertex("B");   // node 1
    myGraph.addVertex(bVertex);
    cVertex = new Vertex("C");   // node 2
    myGraph.addVertex(cVertex);
    dVertex = new Vertex("D");   // node 3
    myGraph.addVertex(dVertex);
    eVertex = new Vertex("E");   // node 4
    myGraph.addVertex(eVertex);

    myGraph.addEdge(0,2,12);
    myGraph.addEdge(0,3,60);
    myGraph.addEdge(1,0,10);
    myGraph.addEdge(2,1,20);
    myGraph.addEdge(2,3,32);
    myGraph.addEdge(4,0,7);

    cout << "DFS: ";
    myGraph.DFS(eVertex);
    cout << endl;

    cout << "BFS: ";
    myGraph.BFS(eVertex);
    cout << endl;

    return 0;
}
