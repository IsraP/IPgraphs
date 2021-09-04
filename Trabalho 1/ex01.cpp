#include <stdio.h>
#include <iostream>
using namespace std;

class Vertice
{

public:
    int label;      // Conteúdo do vértice
    int size;       // Contador de tamanho
    Vertice *out[]; // Lista de adjacência do vértice

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

    // Esse método não liga o vértice principal o vértice sendo passado como parâmetro, visto que o importante era mostrar qual era a ligação, e não necessáriamente ligar os dois
    void addOut(int label)
    {
        Vertice *v = new Vertice(label);
        out[size] = v;
        size++;
    }

    void printAllOut()
    {
        for (int i = 0; i < size; i++)
            cout << out[i]->label << " ";
    }
};

class GrafoDNP
{
public:
    Vertice *vertices[100];
    int size;

    GrafoDNP()
    {
        size = 0;
    }

    GrafoDNP(int newSize)
    {
        for (int i = 0; i < newSize; i++) // Carrega o grafo inicialmente com newSize vértices
            addVertice(i);
    }

    void addVertice(int labelIn, int labelOut)
    {
        if (vertices[labelIn] == nullptr) // As três próximas verificações verificam se o vértice principal, secundário e principal já foram criados, respectivamente
        {
            vertices[labelIn] = new Vertice(labelIn);
            size++;
        }

        if (vertices[labelOut] == nullptr)
        {
            vertices[labelOut] = new Vertice(labelOut);
            size++;
        }

        vertices[labelIn]->addOut(labelOut);
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
            if (vertices[i] != nullptr) // Pula os vértices que não existem no vetor
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
    GrafoDNP *gdnp = new GrafoDNP(5);

    gdnp->addVertice(0, 1);
    gdnp->addVertice(0, 2);
    gdnp->addVertice(1, 2);
    gdnp->addVertice(1, 3);
    gdnp->addVertice(2, 1);

    gdnp->printGrafo();

    return 0;
}