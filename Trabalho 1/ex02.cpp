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

    // Método que retorna true caso o valor pedido tenha sido encontrado na lista de adjacência do vértice
    bool contains(int labelCheck)
    {
        for (int i = 0; i < size; i++)
            if (out[i]->label == labelCheck)
                return true;

        return false;
    }

    void printAllOut()
    {
        for (int i = 0; i < size; i++)
            cout << out[i]->label << " ";
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
        if (vertices[labelIn] == nullptr) // As duas próximas verificações verificam se o vértice principal e secundário, respectivamente, já foram criados
        {
            vertices[labelIn] = new Vertice(labelIn);
            size++;
        }

        if (vertices[labelOut] == nullptr)
        {
            vertices[labelOut] = new Vertice(labelOut);
            size++;
        }

        if (!vertices[labelIn]->contains(labelOut)) // As duas seguintes verificações verificam se o vértice em questão possui ligação com o outro para evitar duplicatas
            vertices[labelIn]->addOut(labelOut);

        if (!vertices[labelOut]->contains(labelIn))
            vertices[labelOut]->addOut(labelIn);
    }

    void addVertice(int label)
    {
        if (vertices[label] == nullptr) // Verifica se o vértice em questão já foi criado
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
            if (vertices[i] != nullptr) // Pula espaços vazios no vetor
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