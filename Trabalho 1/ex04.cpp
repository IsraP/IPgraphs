#include <stdio.h>
#include <iostream>

using namespace std;

// Grafo não-direcionado ponderado (gndp)

class Matriz
{
public:
    int matriz[50][50];
    int contVertices;

    Matriz() {}

    Matriz(int contVertices)
    {
        this->contVertices = contVertices;

        for (int i = 0; i < contVertices; i++)
        {
            for (int j = 0; j < contVertices; j++)
            {
                matriz[i][j] = 0;
            }
        }
    }

    // O meétodo addPeso faz a adição do peso nas arestas de modo
    // não-direcionado, adicionando então relações simétricas na matriz
    void addPeso(int i, int j, int peso)
    {
        --i;
        --j;

        matriz[i][j] = peso;
        matriz[j][i] = peso;
    }

    void printGrafo()
    {
        for (int i = 0; i < contVertices; i++)
        {
            cout << "|\t";
            for (int j = 0; j < contVertices; j++)
            {
                cout << matriz[i][j] << "\t";
            }
            cout << "|\n";
        }
    }
};

int main()
{
    Matriz *gndp = new Matriz(5);

    gndp->addPeso(1, 2, 2);
    gndp->addPeso(2, 4, 24);
    gndp->addPeso(3, 3, 16);
    gndp->addPeso(3, 5, 10);
    gndp->addPeso(4, 3, 32);
    gndp->addPeso(5, 1, 12);

    gndp->printGrafo();

    return 0;
}