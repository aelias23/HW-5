#include "vertex.h"

Vertex::Vertex(string name)
{
    m_title = name;
}

string Vertex::getTitle()
{
    return m_title;
}

void Vertex::setTitle(string name)
{
    m_title = name;
}
