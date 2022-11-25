#include <iostream>
#include "Grafo.cpp"

using namespace std;

void PruebaImprimir(Grafo<char> grafo);
void imprimirCosto(Grafo<char> grafo, int v1, int v2);
void imprimirOrden(Grafo<char> grafo);
void imprimirInfo(Grafo<char> grafo, int v);
void imprimirHayCamino1(Grafo<char> grafo, int v1, int v2);
void imprimirHayCamino2(Grafo<char> grafo, int v1, int v2);
void imprimirCostoMinimo1(Grafo<char> grafo, int v1, int v2);
void imprimirCostoMinimo2(Grafo<char> grafo, int v1, int v2);
void imprimirSumideros(Grafo<char> grafo);

int main()
{
    Grafo<char> g;
    g.insVertice('A'); // 0
    g.insVertice('B'); // 1
    g.insVertice('C'); // 2
    g.insVertice('D'); // 3
    g.insVertice('E'); // 4
    g.insVertice('F'); // 5
    g.insVertice('G'); // 6
    g.insVertice('H'); // 7

    g.insArco(0, 0, 0); // 0 -> 0
    // g.insArco(3, 7, 3); // 3 -> 7
    g.insArco(0, 1, 1); // 0 -> 1
    g.insArco(1, 2, 1); // 1 -> 2
    g.insArco(2, 3, 1); // 2 -> 3
    g.insArco(3, 4, 1); // 3 -> 4
    g.insArco(4, 5, 1); // 4 -> 5
    g.insArco(5, 6, 1); // 5 -> 6
    g.insArco(6, 7, 5); // 6 -> 7
    // g.insArco(7, 0, 1); // 7 -> 8
    cout << endl;

    PruebaImprimir(g);
    imprimirCosto(g, 0, 1);
    imprimirOrden(g);
    imprimirInfo(g, 0);
    // imprimirHayCamino1(g, 0, 1);
    // imprimirHayCamino2(g, 0, 7);
    // imprimirCostoMinimo1(g, 0, 7);
    // imprimirCostoMinimo2(g, 0, 7);
    imprimirSumideros(g);

    return 0;
}

void PruebaImprimir(Grafo<char> grafo)
{

    cout << "Imprimir grafo" << endl;
    grafo.imprimirGrafo();
    cout << endl;
}

void imprimirCosto(Grafo<char> grafo, int v1, int v2)
{
    cout << "Imprimir costo" << endl;
    cout << grafo.costoArco(v1, v2) << endl;
    cout << endl;
}

void imprimirOrden(Grafo<char> grafo)
{
    cout << "Imprimir orden" << endl;
    cout << grafo.ordenGrafo() << endl;
    cout << endl;
}

void imprimirInfo(Grafo<char> grafo, int v)
{
    cout << "Imprimir info" << endl;
    cout << grafo.infoVertice(v) << endl;
    cout << endl;
}

void imprimirHayCamino1(Grafo<char> grafo, int v1, int v2)
{
    cout << "Imprimir HayCamino1" << endl;
    cout << grafo.hayCamino1(v1, v2) << endl;
    cout << endl;
}

void imprimirHayCamino2(Grafo<char> grafo, int v1, int v2)
{
    grafo.desmarcarGrafo();
    cout << "Imprimir HayCamino2" << endl;
    cout << grafo.hayCamino2(v1, v2) << endl;
    cout << endl;
}

void imprimirCostoMinimo1(Grafo<char> grafo, int v1, int v2)
{
    grafo.desmarcarGrafo();
    cout << "Imprimir CostoMinimo1" << endl;
    cout << grafo.costoMinimo1(v1, v2) << endl;
    cout << endl;
}

void imprimirCostoMinimo2(Grafo<char> grafo, int v1, int v2)
{
    grafo.desmarcarGrafo();
    cout << "Imprimir CostoMinimo2" << endl;
    vector<int> x = grafo.costoMinimo2(v1, v2, 0);
    for (int i = 0; i < x.size(); i++)
        cout << x[i] << endl;
    cout << endl;
}

void imprimirSumideros(Grafo<char> grafo)
{
    cout << "Imprimir Sumideros" << endl;
    vector<int> x = grafo.sumideros();
    for (int i = 0; i < x.size(); i++)
        cout << x[i] << endl;
    cout << endl;
}