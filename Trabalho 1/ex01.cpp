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

    void removeOut(int label)
    {
        for (int i = 0; i < size; i++)
        {
            if (out[i]->label == label)
                out[i]->label = -1;
        }
    }

    void printAllOut()
    {
        int cont = 0;
        for (int i = 0; i < size && cont != size; i++)
            if (out[i]->label != -1)
            {
                cont++;
                cout << out[i]->label << " ";
            }
    }
};

class GrafoDNP
{
public:
    Vertice *vertices[100];
    int size;

    GrafoDNP()
    {
    }

    void addVertice(int labelIn, int labelOut)
    {
        if (vertices[labelIn] == nullptr)
        {
            vertices[labelIn] = new Vertice(labelIn);

            vertices[labelIn]->addOut(labelOut);

            size++;
        }
        else
            vertices[labelIn]->addOut(labelOut);

        if (vertices[labelOut] == nullptr)
        {
            vertices[labelOut] = new Vertice(labelOut);
            size++;
        }
    }

    void addVertice(int label)
    {
        if (vertices[label] == nullptr)
        {
            vertices[label] = new Vertice(label);

            size++;
        }
    }

    void removeVertice(int label)
    {
        for (int i = 0; i < 100; i++)
        {
            if (vertices[i] != nullptr)
            {
                if (vertices[i]->label == label)
                {
                    vertices[i] = nullptr;
                    size--;
                }
                else
                    vertices[i]->removeOut(label);
            }
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
    GrafoDNP *gdnp = new GrafoDNP();

    gdnp->addVertice(0, 1);
    gdnp->addVertice(0, 2);
    gdnp->addVertice(1, 2);
    gdnp->addVertice(1, 3);
    gdnp->addVertice(2, 1);
    gdnp->removeVertice(2);

    gdnp->printGrafo();

    return 0;
}