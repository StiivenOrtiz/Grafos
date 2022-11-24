#include "Grafo.hpp"
#include <vector>

/// @brief Constructora del grafo.
/// @tparam info
template <class info>
Grafo<info>::Grafo()
{
    this->grafo.clear();
    this->visitados.clear();
}

/// @brief Destructor del grafo.
/// @tparam info
template <class info>
Grafo<info>::~Grafo()
{
    this->grafo.clear();
    this->visitados.clear();
}

/// @brief Insetar un vertice al grafo.
/// @tparam info
/// @param informacion
template <class info>
void Grafo<info>::insVertice(info informacion)
{
    this->grafo.push_back({informacion, {}});
    this->visitados[(this->grafo.size() - 1)] = false;
}

/// @brief inserta un arco desde la posición de un vertice a otro.
/// @tparam info
/// @param posVertice
/// @param posSucesor
/// @param costo
template <class info>
void Grafo<info>::insArco(int posVertice, int posSucesor, int costo)
{
    if (posVertice < this->grafo.size())
        this->grafo[posVertice].second.push_back({posSucesor, costo});
    else
        cout << "El vertice no existe." << endl;
}

/// @brief Elimina el arco entre la posción de un vertice a otro.
/// @tparam info
/// @param posVertice
/// @param posSucesor
template <class info>
void Grafo<info>::elimArco(int posVertice, int posSucesor)
{
    if (posVertice < this->grafo.size())
    {
        if (posSucesor < this->grafo.size())
        {
            vector<pair<int, int>>::iterator it;
            bool encontrado = false;

            for (it = this->grafo[posVertice].second.begin(); it != this->grafo[posVertice].second.end(); it++)
                if (it->first == posSucesor)
                {
                    this->grafo.erase(it);
                    encontrado = true;
                    break;
                }

            if (encontrado == false)
                cout << "El vertice en la posicion " << posSucesor << " no es sucesor del vertice en la posicion " << posVertice << "." << endl;
        }
        else
            cout << "El vertice en la posicion " << posSucesor << " no existe." << endl;
    }
    else
        cout << "El vertice en la posicion " << posVertice << " no existe." << endl;
}

/// @brief Informa si el vértice v está marcado
/// @tparam info
/// @param posVertice
template <class info>
void Grafo<info>::marcarVertice(int posVertice)
{
    if (posVertice < this->visitados.size())
        this->visitados[posVertice] = true;
    else
        cout << "El vertice en la posicion " << posVertice << " no existe." << endl;
}

/// @brief Desmarca el vértice
/// @tparam info
/// @param posVertice
template <class info>
void Grafo<info>::desmarcarVertice(int posVertice)
{
    if (posVertice < this->visitados.size())
        this->visitados[posVertice] = false;
    else
        cout << "El vertice en la posicion " << posVertice << " no existe." << endl;
}

/// @brief Desmarca todos los vértices del grafo
template <class info>
void Grafo<info>::desmarcarGrafo()
{
    map<int, bool>::iterator it;
    for (it = this->visitados.begin(); it != this->visitados.end(); it++)
        it->second = false;
}

/// @brief Retorna el costo de la posción de un vertice a otro, si no lo consigue retorna -1.
/// @tparam info
/// @param posVertice
/// @param posSucesor
/// @return
template <class info>
int Grafo<info>::costoArco(int posVertice, int posSucesor)
{
    if (posVertice < this->grafo.size())
    {
        if (posSucesor < this->grafo.size())
        {
            vector<pair<int, int>>::iterator it;
            bool encontrado = false;

            for (it = this->grafo[posVertice].second.begin(); it != this->grafo[posVertice].second.end(); it++)
                if (it->first == posSucesor)
                {
                    return it->second;
                    encontrado = true;
                    break;
                }

            if (encontrado == false)
                cout << "El vertice en la posicion " << posSucesor << " no es sucesor del vertice en la posicion " << posVertice << "." << endl;
        }
        else
            cout << "El vertice en la posicion " << posSucesor << " no existe." << endl;
    }
    else
        cout << "El vertice en la posicion " << posVertice << " no existe." << endl;

    return -1;
}

/// @brief Retorna los sucesores con su respectivo costo de la posción de un vertice.
/// @tparam info
/// @param posVertice
/// @return
template <class info>
vector<pair<int, int>> Grafo<info>::sucesoresCosto(int posVertice)
{
    vector<pair<int, int>> suce;
    if (posVertice < this->grafo.size())
        suce = this->grafo[posVertice].second;
    else
        cout << "El vertice en la posicion " << posVertice << " no existe." << endl;
    return suce;
}

template <class info>
vector<int> Grafo<info>::sucesores(int posVertice)
{
    vector<int> suce;
    if (posVertice < this->grafo.size())
        for (int i = 0; i < this->grafo[posVertice].second.size(); i++)
            suce.push_back(this->grafo[posVertice].second[i].first);
    else
        cout << "El vertice en la posicion " << posVertice << " no existe." << endl;
    return suce;
}

/// @brief Retorna la información de la posción de un vertice.
/// @tparam info
/// @param posVertice
/// @return
template <class info>
info Grafo<info>::infoVertice(int posVertice)
{
    info informacion;
    if (posVertice < this->grafo.size())
        informacion = this->grafo[posVertice].first;
    else
        cout << "El vertice en la posicion " << posVertice << " no existe." << endl;
    return informacion;
}

/// @brief Retorna la cantidad de vertices existentes en el grafo.
/// @tparam info
/// @return
template <class info>
int Grafo<info>::ordenGrafo()
{
    return this->visitados.size();
}

/// @brief Informa si el vértice v está marcado
/// @tparam info
/// @param posVertice
/// @return
template <class info>
bool Grafo<info>::marcadoVertice(int posVertice)
{
    if (posVertice < this->visitados.size())
        return this->visitados[posVertice];
    else
        cout << "El vertice en la posicion " << posVertice << " no existe." << endl;
    return false;
}

/// @brief Imprime el grafo
/// @tparam info
template <class info>
void Grafo<info>::imprimirGrafo()
{
    for (int i = 0; i < this->grafo.size(); i++)
    {
        cout << this->grafo[i].first << ",[" << this->visitados[i] << "] -> ";
        for (int j = 0; j < this->grafo[i].second.size(); j++)
        {
            cout << "[" << this->grafo[i].second[j].first << "-" << this->grafo[i].second[j].second << "]";
            if (j != (this->grafo[i].second.size() - 1))
                cout << ", ";
        }
        cout << endl;
    }
}