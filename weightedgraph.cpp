#include "weightedgraph.h"
#include <iostream>
#include <queue>

WeightedGraph::WeightedGraph(int size)
{
    m_numVertices = 0;
    m_maxVertices = size;
    m_vertices.resize(size);
    for (int i = 0; i < size; i++) {
        m_vertices[i] = NULL;
    }

    m_marks.resize(size);

    int rows = size;
    int columns = size;
    m_edges.resize(rows, vector<int>(columns, 0));
}

void WeightedGraph::addVertex(Vertex* aVertex)
{
    m_vertices[m_numVertices] = aVertex;
    for (int i = 0; i < m_maxVertices; i++) {
        m_edges[m_numVertices][i] = NULL_EDGE;
        m_edges[i][m_numVertices] = NULL_EDGE;
    }
    m_numVertices++;
}

void WeightedGraph::addEdge(int fromVertex, int toVertex, int weight)
{
    if (fromVertex >= 0 && fromVertex < m_numVertices && toVertex >= 0 && toVertex < m_numVertices) {
        int row = indexIs(m_vertices[fromVertex]);
        int column = indexIs(m_vertices[toVertex]);
        m_edges[row][column] = weight;
    } else {
        cout << "Error: Invalid vertex index!" << endl;
    }
}

int WeightedGraph::indexIs(Vertex* aVertex)
{
    int i = 0;
    while (i < m_numVertices) {
        if (m_vertices[i] == aVertex) {
            return i;
        }
        i++;
    }
    return -1;
}

void WeightedGraph::clearMarks()
{
    for (int i = 0; i < m_numVertices; i++) {
        m_marks[i] = false;
    }
}

void WeightedGraph::doDFS(Vertex* aVertex)
{
    int ix, ix2;
    if (aVertex == NULL) return;

    cout << aVertex->getTitle() << " ";
    ix = indexIs(aVertex);
    m_marks[ix] = true;

    for (int i = 0; i < m_numVertices; i++) {
        ix2 = indexIs(m_vertices[i]);
        if (m_edges[ix][ix2] != NULL_EDGE) {
            if (m_marks[ix2] == false)
                doDFS(m_vertices[i]);
        }
    }
}

void WeightedGraph::DFS(Vertex* aVertex)
{
    clearMarks();
    doDFS(aVertex);
    m_path.clear();
    m_pathLength = 0;
}

void WeightedGraph::doBFS(Vertex* aVertex)
{
    int ix, ix2;
    queue <Vertex*> que;
    ix = indexIs(aVertex);
    m_marks[ix] = true;
    vector<int> distance(m_numVertices, -1);
    distance[ix] = 0;
    que.push(aVertex);

    while (!que.empty()) {
        Vertex* node = que.front();
        que.pop();
        ix = indexIs(node);
        cout << node->getTitle() << " (Distance: " << distance[ix] << ") ";

        for (int i = 0; i < m_numVertices; i++) {
            ix2 = indexIs(m_vertices[i]);
            if (m_edges[ix][ix2] != NULL_EDGE) {
                if (m_marks[ix2] == false) {
                    m_marks[ix2] = true;
                    distance[ix2] = distance[ix] + 1;
                    que.push(m_vertices[i]);
                }
            }
        }
    }
}

void WeightedGraph::BFS(Vertex* aVertex)
{
    clearMarks();
    vector<int> distance(m_numVertices, -1);
    distance[indexIs(aVertex)] = 0;
    doBFS(aVertex);
}
