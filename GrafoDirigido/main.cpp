#include <iostream>
#include "GrafoDirigido.cpp"

using namespace std;

void imprimir(GrafoDirigido<vector<int>> grafo);

int main()
{

    GrafoDirigido<char> grafo;
    grafo.agregarArista('A', 'B', 0);
    grafo.agregarArista('A', 'C', 0);
    grafo.agregarArista('A', 'D', 0);
    grafo.agregarArista('A', 'E', 0);
    grafo.agregarArista('B', 'F', 0);
    grafo.agregarArista('C', 'G', 0);
    grafo.agregarArista('D', 'H', 5);
    grafo.agregarArista('E', 'I', 0);

    cout << endl;
    grafo.imprimirGrafo();
    cout << endl;
    grafo.imprimirTransversal();
    cout << endl;
    cout << grafo.costoArista('D', 'H') << endl;
    cout << endl;

    // VECTOR ( PAIR ( PAIR ( x, y ), base ), VECTOR ( PAIR ( x, y ) , costo ) )
    // vector<pair<pair<pair<int, int>, char>, vector<pair<pair<int, int>, float>>>> grafo;

    GrafoDirigido<vector<int>> grafo;

    return 0;
}

// void imprimir(GrafoDirigido<vector<int>> grafo)
// {
//     for (int i = 0; i < grafo.ordenGrafo(); i++)
//     {
//     }
// }