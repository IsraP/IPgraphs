#include <stdio.h>
#include <iostream>

using namespace std;

// Grafo direcionado ponderado (gdp)

class Matriz
{
public:
    int matriz[50][50];
    int contVertices; // Tamanho da matriz

    Matriz() {}

    // O construtor recebe o tamanho da matriz a ser criada e a preenche
    // com o número 0 (para representar arestas sem peso)
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

    // O método addPeso recebe primeiramente 2 inteiros que representam os
    // vértices e um inteiro para o peso
    void addPeso(int i, int j, int peso)
    {
        matriz[--i][--j] = peso;
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
    Matriz *gdp = new Matriz(5);

    gdp->addPeso(1, 2, 2);
    gdp->addPeso(2, 4, 24);
    gdp->addPeso(3, 3, 16);
    gdp->addPeso(3, 5, 10);
    gdp->addPeso(4, 3, 32);
    gdp->addPeso(5, 1, 12);

    gdp->printGrafo();

    return 0;
}