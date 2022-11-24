#include <iostream>
#include "Grafo.cpp"

using namespace std;

int main()
{
    Grafo<char> grafo;
    grafo.insVertice('A'); // 0
    grafo.insVertice('B'); // 1
    grafo.insVertice('C'); // 2
    grafo.insVertice('D'); // 3
    grafo.insVertice('E'); // 4
    grafo.insVertice('F'); // 5
    grafo.insVertice('G'); // 6
    grafo.insVertice('H'); // 7

    grafo.insArco(0, 0, 0); // 0 -> 0
    grafo.insArco(0, 1, 1); // 0 -> 1
    grafo.insArco(1, 2, 2); // 1 -> 2
    grafo.insArco(2, 3, 3); // 2 -> 3
    grafo.insArco(3, 4, 4); // 3 -> 4
    grafo.insArco(4, 5, 5); // 4 -> 5
    grafo.insArco(5, 6, 6); // 5 -> 6
    grafo.insArco(6, 7, 7); // 6 -> 7
    grafo.insArco(7, 0, 8); // 7 -> 8

    cout << endl;
    grafo.imprimirGrafo();
    cout << endl;

    // cout << grafo.costoArco(3, 0) << "\n\n";

    // cout << grafo.ordenGrafo() << "\n\n";

    // char sx = grafo.infoVertice(0);
    // cout << sx << "\n\n";

    // cout << grafo.hayCamino1(0, 7) << endl; // No se puede usar porque el grafo de prueba es cíclico
    cout << endl;
    cout << grafo.hayCamino2(0, 7) << endl;
    // cout << "xd" << endl;

    return 0;
}