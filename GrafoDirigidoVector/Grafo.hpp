#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template <class info>
class Grafo
{
private:
    // Vector de pares que incluye un par de informacion y sucesores: posSucesor, costo
    vector<pair<info, vector<pair<int, int>>>> grafo;
    unordered_map<int, bool> visitados;

public:
    // Constructoras
    Grafo();

    // Modificadoras
    void insVertice(info informacion);
    void insArco(int posVertice, int posSucesor, int costo);
    void elimVertice(int posVertice);
    void elimArco(int posVertice, int posSucesor);
    void marcarVertice(int posVertice);
    void desmarcarVertice(int posVertice);
    void desmarcarGrafo();

    // Analizadoras
    int costoArco(int posVertice, int posSucesor);
    vector<pair<int, int>> sucesoresCosto(int posVertice);
    vector<int> sucesores(int posVertice);
    info infoVertice(int posVertice);
    int ordenGrafo();
    bool marcadoVertice(int posVertice);
    void imprimirGrafo();
    bool hayCamino1(int posVertice1, int posVertice2);
    bool hayCamino2(int posVertice1, int posVertice2);
    int costoMinimo1(int posVertice1, int posVertice2);
    vector<int> costoMinimo2(int posVertice1, int posVertice2, int costo);
    vector<int> sumideros();

    // Destructora
    ~Grafo();
};