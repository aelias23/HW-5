#ifndef VERTEX_H
#define VERTEX_H

#include <string>
using namespace std;

class Vertex
{
    public:
        Vertex(string);
        string getTitle();
        void setTitle(string);

    protected:

    private:
        string m_title;
};

#endif // VERTEX_H
