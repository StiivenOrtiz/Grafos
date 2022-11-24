#include <iostream>
#include "Grafo.cpp"

using namespace std;

int main()
{
    Grafo<char> grafo;
    grafo.insVertice('A');
    grafo.insVertice('B');
    grafo.insVertice('C');
    grafo.insVertice('J');

    grafo.insArco(0, 1, 1);
    grafo.insArco(1, 2, 2);
    grafo.insArco(2, 3, 1);
    grafo.insArco(0, 2, 4);
    grafo.insArco(0, 3, 4);

    cout << endl;
    grafo.imprimirGrafo();
    cout << endl;

    cout << grafo.costoArco(0, 3) << "\n\n";

    cout << grafo.ordenGrafo() << "\n\n";

    char sx = grafo.infoVertice(0);
    cout << sx << endl;

    return 0;
}