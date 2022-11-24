#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template <class T>
class GrafoDirigido
{
private:
    // Vertice, <Vertice al que apunta, costo>
    vector<pair<T, vector<pair<T, int>>>> grafo;
    // Vertice, estado de la visita;
    unordered_map<T, bool> visitados;

public:
    // Constructor
    GrafoDirigido();
    // Destructor
    ~GrafoDirigido();

    // Metodos
    int ordenGrafo();
    int obtenerPosicion(T vertice);
    bool existeVertice(T vertice);
    void desmarcarGrafo();
    void marcarVertice(T vertice);
    void desmarcarVertice(T vertice);
    void imprimirVisitados();
    void agregarVertice(T vertice);
    void agregarArista(T vertice, T verticeApuntado, int costo);
    bool hayCamino(T verticeInicial, T verticeFinal);
    bool hayCaminoInd(int verticeInicial, int verticeFinal);
    void eliminarVertice(T vertice);
    void eliminarAristasHacia(T vertice);
    void eliminarAristasdDe(T vertice);
    void imprimirTransversalDesde(T vertice);
    void imprimirTransversal();
    void imprimirGrafo();
    int costoArista(T vertice, T verticeApuntado);
    T obtenerVertice(int indice);
    vector<pair<T, int>> sucesoresConCostoInd(int indice);
    vector<pair<T, int>> sucesoresConCosto(T vertice);
    vector<T> sucesoresSinCostoInd(int indice);
    vector<T> sucesoresSinCosto(T vertice);

protected:
    bool hayCaminoP(T verticeInicial, T verticeFinal);
    void impTransD(T vertice);
};