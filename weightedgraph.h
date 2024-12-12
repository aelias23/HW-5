#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H
#include <vector>
#include "Vertex.h"

class WeightedGraph
{
    public:
        WeightedGraph(int);
        bool isEmpty();
        void addVertex(Vertex*);
        void addEdge(int, int, int);
        bool isFull();
        void DFS(Vertex*);
        void BFS(Vertex*);
        void isPath(Vertex*, Vertex*);

    protected:
        int indexIs(Vertex*);
        void clearMarks();
        void doDFS(Vertex*);
        void doBFS(Vertex*);
        bool hasPath(Vertex*, Vertex*, vector<bool>&);

    private:
        static const int NULL_EDGE = 0;
        int m_numVertices;
        int m_maxVertices;
        vector <Vertex*> m_vertices;
        vector <vector <int>> m_edges;
        vector <bool> m_marks;
        vector<Vertex*> m_path;
        int m_pathLength;

};

#endif // WEIGHTEDGRAPH_H
