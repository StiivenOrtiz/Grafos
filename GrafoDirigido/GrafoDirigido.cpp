#include "GrafoDirigido.hpp"

template <class T>
GrafoDirigido<T>::GrafoDirigido()
{
    this->grafo.clear();
}

template <class T>
GrafoDirigido<T>::~GrafoDirigido()
{
    this->grafo.clear();
}

template <class T>
int GrafoDirigido<T>::ordenGrafo()
{
    return this->grafo.size();
}

template <class T>
int GrafoDirigido<T>::obtenerPosicion(T vertice)
{
    for (int i = 0; i < this->grafo.size(); i++)
        if (this->grafo[i].first == vertice)
            return i;

    return -1;
}

template <class T>
bool GrafoDirigido<T>::existeVertice(T vertice)
{
    for (int i = 0; i < this->grafo.size(); i++)
        if (this->grafo[i].first == vertice)
            return true;

    return false;
}

template <class T>
void GrafoDirigido<T>::desmarcarGrafo()
{
    for (pair<T, bool> a : this->visitados)
        this->visitados[a.first] = false;
}

template <class T>
void GrafoDirigido<T>::marcarVertice(T vertice)
{
    this->visitados[vertice] = true;
}

template <class T>
void GrafoDirigido<T>::desmarcarVertice(T vertice)
{
    this->visitados[vertice] = false;
}

template <class T>
void GrafoDirigido<T>::imprimirVisitados()
{
    for (pair<T, bool> a : this->visitados)
        cout << a.first << " " << a.second << endl;
}

template <class T>
void GrafoDirigido<T>::agregarVertice(T vertice)
{
    bool esta = existeVertice(vertice);

    if (!esta)
    {
        this->grafo.push_back({vertice, {}});
        this->visitados[vertice] = false;
    }
}

template <class T>
void GrafoDirigido<T>::agregarArista(T vertice, T verticeApuntado, int costo)
{
    agregarVertice(vertice);
    agregarVertice(verticeApuntado);
    int i = obtenerPosicion(vertice);

    if (this->grafo[i].first == vertice)
    {
        bool esta = false;
        for (int j = 0; j < this->grafo[i].second.size(); j++)
            if (this->grafo[i].second[j].first == verticeApuntado)
            {
                this->grafo[i].second[j].second = costo;
                esta = true;
                break;
            }

        if (!esta)
            this->grafo[i].second.push_back({verticeApuntado, costo});
    }
}

template <class T>
bool GrafoDirigido<T>::hayCamino(T verticeInicial, T verticeFinal)
{
    if (existeVertice(verticeInicial) && existeVertice(verticeFinal))
    {
        desmarcarGrafo();
        return hayCaminoP(verticeInicial, verticeFinal);
    }
    else
        return false;
}

template <class T>
bool GrafoDirigido<T>::hayCaminoInd(int verticeInicial, int verticeFinal)
{
    if (existeVertice(obtenerVertice(verticeInicial)) && existeVertice(obtenerVertice(verticeFinal)))
    {
        desmarcarGrafo();
        return hayCaminoP(obtenerVertice(verticeInicial), obtenerVertice(verticeFinal));
    }
    else
        return false;
}

template <class T>
bool GrafoDirigido<T>::hayCaminoP(T verticeInicial, T verticeFinal)
{
    int i = obtenerPosicion(verticeInicial);

    if (i != -1)
    {
        for (int j = 0; j < this->grafo[i].second.size(); j++)
            if (this->grafo[i].second[j].first == verticeFinal)
                return true;
        for (int j = 0; j < this->grafo[i].second.size(); j++)
            if (!visitados[this->grafo[i].second[j].first])
            {
                visitados[this->grafo[i].second[j].first] = true;
                if (hayCamino(this->grafo[i].second[j].first, verticeFinal))
                    return true;
            }
    }
    return false;
}

template <class T>
void GrafoDirigido<T>::eliminarVertice(T vertice)
{
    int indice = obtenerPosicion(vertice);

    if (indice != -1)
    {
        for (int i = indice; i < grafo.size(); i++)
        {
            if (this->grafo[i].first == vertice)
            {
                this->grafo[i] = this->grafo[i + 1];
                indice = i;
            }
            if ((i > indice) && (i != (grafo.size() - 1)) && (indice != -1))
                this->grafo[i] = this->grafo[i + 1];
        }

        this->grafo.pop_back();
        eliminarAristasHacia(vertice);
        this->visitados.erase(vertice);
    }
}

template <class T>
void GrafoDirigido<T>::eliminarAristasHacia(T vertice)
{
    for (int i = 0; i < this->grafo.size(); i++)
    {
        int indice = -1;
        for (int j = 0; j < this->grafo[i].second.size(); j++)
        {
            if (this->grafo[i].second[j].first == vertice)
            {
                this->grafo[i].second[j] = this->grafo[i].second[j + 1];
                indice = j;
            }
            if ((j > indice) && (j != (grafo[i].second.size() - 1)) && (indice != -1))
                this->grafo[i].second[j] = this->grafo[i].second[j + 1];
        }

        if (indice != -1)
            this->grafo[i].second.pop_back();
    }
}

template <class T>
void GrafoDirigido<T>::eliminarAristasdDe(T vertice)
{
    int indice = obtenerPosicion(vertice);
    if (indice != -1)
        this->grafo[indice].second.clear();
}

template <class T>
void GrafoDirigido<T>::imprimirTransversalDesde(T vertice)
{
    desmarcarGrafo();
    impTransD(vertice);
}

template <class T>
void GrafoDirigido<T>::impTransD(T vertice)
{
    int indice = obtenerPosicion(vertice);

    if ((indice != -1) && (!visitados[this->grafo[indice].first]))
    {
        cout << this->grafo[indice].first << endl;
        marcarVertice(this->grafo[indice].first);

        for (int i = 0; i < this->grafo[indice].second.size(); i++)
            impTransD(this->grafo[indice].second[i].first);
    }
}

template <class T>
void GrafoDirigido<T>::imprimirTransversal()
{
    if (this->grafo.size() > 0)
    {
        desmarcarGrafo();
        imprimirTransversalDesde(this->grafo[0].first);
    }
}

template <class T>
void GrafoDirigido<T>::imprimirGrafo()
{
    for (int i = 0; i < this->grafo.size(); i++)
    {
        cout << this->grafo[i].first;
        for (int j = 0; j < this->grafo[i].second.size(); j++)
            cout << " {" << this->grafo[i].second[j].first << ", " << this->grafo[i].second[j].second << "}";
        cout << endl;
    }
}

template <class T>
int GrafoDirigido<T>::costoArista(T vertice, T verticeApuntado)
{
    int i = obtenerPosicion(vertice);

    if (i != -1)
    {
        for (int j = 0; j < this->grafo[i].second.size(); j++)
            if (this->grafo[i].second[j].first == verticeApuntado)
                return this->grafo[i].second[j].second;
    }
    else
        return -1;
}

template <class T>
T GrafoDirigido<T>::obtenerVertice(int indice)
{
    return this->grafo[indice].first;
}

template <class T>
vector<pair<T, int>> GrafoDirigido<T>::sucesoresConCosto(T vertice)
{
    return this->grafo[obtenerPosicion(vertice)].second;
}

template <class T>
vector<T> GrafoDirigido<T>::sucesoresSinCosto(T vertice)
{
    int indice = obtenerPosicion(vertice);
    vector<T> aristas;

    for (pair<T, int> par : this->grafo[indice].second)
        aristas.push_back(par.first);

    return aristas;
}

template <class T>
vector<pair<T, int>> GrafoDirigido<T>::sucesoresConCostoInd(int indice)
{
    return this->grafo[indice].second;
}

template <class T>
vector<T> GrafoDirigido<T>::sucesoresSinCostoInd(int indice)
{
    vector<T> sucesores;

    for (pair<T, int> par : this->grafo[indice].second)
        sucesores.push_back(par.first);

    return sucesores;
}