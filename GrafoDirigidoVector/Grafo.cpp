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
    this->visitados[this->grafo.size() - 1] = false;
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
        if (posSucesor < this->grafo.size())
        {
            bool esta = false;
            for (int i = 0; i < this->grafo[posVertice].second.size(); i++)
                if (this->grafo[posVertice].second[i].first == posSucesor)
                {
                    esta = true;
                    this->grafo[posVertice].second[i].second == costo;
                }
            if (esta == false)
                this->grafo[posVertice].second.push_back({posSucesor, costo});
        }
        else
            cout << "El vertice en la posicion " << posSucesor << " no existe." << endl;
    else
        cout << "El vertice en la posicion " << posVertice << " no existe." << endl;
}

/// @brief Elimina un vertice desde la posición de un vertice.
/// @tparam info
/// @param posVertice
template <class info>
void Grafo<info>::elimVertice(int posVertice)
{
    vector<pair<int, int>>::iterator itSuce;
    if (posVertice < this->grafo.size())
    {
        for (int i = 0; i < this->grafo.size(); i++)
        {
            vector<pair<int, int>> suce = sucesoresCosto(i);
            for (itSuce = suce.begin(); itSuce != suce.end(); itSuce++)
                if (itSuce->first == posVertice)
                {
                    suce.erase(itSuce);
                    break;
                }

            for (itSuce = suce.begin(); itSuce != suce.end(); itSuce++)
                if (itSuce->first > posVertice)
                    itSuce->first -= 1;

            this->grafo[i].second = suce;
        }
        for (int i = posVertice; i < (this->grafo.size() - 1); i++)
            this->grafo[i] = this->grafo[i + 1];
        this->grafo.pop_back();

        unordered_map<int, bool>::iterator itVisitados;
        unordered_map<int, bool> copia;
        for (itVisitados = this->visitados.begin(); itVisitados != this->visitados.end(); itVisitados++)
            if (itVisitados->first > posVertice)
                copia[itVisitados->first - 1] = itVisitados->second;
        this->visitados.clear();
        this->visitados = copia;
    }
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
    if (posVertice < this->grafo.size())
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
    if (posVertice < this->grafo.size())
        this->visitados[posVertice] = false;
    else
        cout << "El vertice en la posicion " << posVertice << " no existe." << endl;
}

/// @brief Desmarca todos los vértices del grafo
template <class info>
void Grafo<info>::desmarcarGrafo()
{
    unordered_map<int, bool>::iterator it;
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
    return this->grafo.size();
}

/// @brief Informa si el vértice v está marcado
/// @tparam info
/// @param posVertice
/// @return
template <class info>
bool Grafo<info>::marcadoVertice(int posVertice)
{
    if (posVertice < this->grafo.size())
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
        cout << "[" << i << "]" << this->grafo[i].first << "(" << this->visitados[i] << ") -> ";
        for (int j = 0; j < this->grafo[i].second.size(); j++)
        {
            cout << "{V: " << this->grafo[i].second[j].first << " - C: " << this->grafo[i].second[j].second << "}";
            if (j != (this->grafo[i].second.size() - 1))
                cout << ", ";
        }
        cout << endl;
    }
}

/// @brief Determinar si existe un camino entre dos vértices v1 y v2 de un grafo acíclico.
/// @tparam info
/// @param posVertice1
/// @param posVertice2
/// @return
template <class info>
bool Grafo<info>::hayCamino1(int posVertice1, int posVertice2)
{
    if (posVertice1 < this->grafo.size())
        if (posVertice2 < this->grafo.size())
            if ((posVertice1 == posVertice2) || (costoArco(posVertice1, posVertice2) != -1))
                return true;
            else
            {
                vector<int> suc = sucesores(posVertice1);
                for (int i = 0; i < suc.size(); i++)
                    if (hayCamino1(suc[i], posVertice2) == true)
                    {
                        suc.~vector();
                        return true;
                    }
                return false;
            }
        else
            cout << "El vertice en la posicion " << posVertice2 << " no existe." << endl;
    else
        cout << "El vertice en la posicion " << posVertice1 << " no existe." << endl;
    return false;
}

/// @brief Determinar si existe un camino entre dos vértices v1 y v2 de un grafo cíclico.
/// @tparam info
/// @param posVertice1
/// @param posVertice2
/// @return
template <class info>
bool Grafo<info>::hayCamino2(int posVertice1, int posVertice2)
{
    if (posVertice1 < this->grafo.size())
        if (posVertice2 < this->grafo.size())
            if ((posVertice1 == posVertice2) || (costoArco(posVertice1, posVertice2) != -1))
                return true;
            else
            {
                vector<int> suc = sucesores(posVertice1);
                marcarVertice(posVertice1);

                for (int i = 0; i < suc.size(); i++)
                    if (!marcadoVertice(suc[i]) && hayCamino2(suc[i], posVertice2))
                    {
                        suc.~vector();
                        return true;
                    }
                return false;
            }
        else
            cout << "El vertice en la posicion " << posVertice2 << " no existe." << endl;
    else
        cout << "El vertice en la posicion " << posVertice1 << " no existe." << endl;
    return false;
}