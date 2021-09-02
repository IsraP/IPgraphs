#include <stdio.h>
#include <iostream>
using namespace std;

class Vertice
{

public:
    int label;
    int size;
    Vertice *out[];

    Vertice()
    {
        size = 0;
    }

    Vertice(int label)
    {
        size = 0;
        this->label = label;
    }

    void addOut(Vertice *v)
    {
        out[size] = v;
        size++;
    }

    void addOut(int label)
    {
        Vertice *v = new Vertice(label);
        out[size] = v;
        size++;
    }

    bool contains(int labelCheck)
    {
        int cont = 0;
        for (int i = 0; i < size && cont != size; i++)
        {
            if (out[i]->label == labelCheck)
                return true;
        }
        return false;
    }

    void printAllOut()
    {
        int cont = 0;
        for (int i = 0; i < size && cont != size; i++)
        {
            cont++;
            cout << out[i]->label << " ";
        }
    }
};

class GrafoNDNP
{
public:
    Vertice *vertices[100];
    int size;

    GrafoNDNP()
    {
        size = 0;
    }

    GrafoNDNP(int newSize)
    {
        for (int i = 0; i < newSize; i++)
            addVertice(i);
    }

    void addVertice(int labelIn, int labelOut)
    {
        if (vertices[labelIn] == nullptr)
        {
            vertices[labelIn] = new Vertice(labelIn);
            size++;
        }

        if (vertices[labelOut] == nullptr)
        {
            vertices[labelOut] = new Vertice(labelOut);
            size++;
        }

        if (!vertices[labelIn]->contains(labelOut))
            vertices[labelIn]->addOut(labelOut);

        if (!vertices[labelOut]->contains(labelIn))
            vertices[labelOut]->addOut(labelIn);
    }

    void addVertice(int label)
    {
        if (vertices[label] == nullptr)
        {
            vertices[label] = new Vertice(label);

            size++;
        }
    }

    void printGrafo()
    {
        int cont = 0;
        for (int i = 0; i < 100 && cont != size; i++)
        {
            if (vertices[i] != nullptr)
            {
                cout << vertices[i]->label << "-> ";
                vertices[i]->printAllOut();
                cout << '\n';
                cont++;
            }
        }
    }
};

int main(void)
{
    GrafoNDNP *gndnp = new GrafoNDNP(5);

    gndnp->addVertice(0, 1);
    gndnp->addVertice(0, 2);
    gndnp->addVertice(1, 2);
    gndnp->addVertice(1, 3);

    gndnp->printGrafo();

    return 0;
}