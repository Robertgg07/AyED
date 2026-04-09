 /*
 *  GRAFO.CPP - Implementación Clase Grafo
 *
 *
 *  Autor    : Robert García García
 *  Cursos   : 2025-26
 */

#include "grafo.h"

void GRAFO :: destroy()
{
    for (unsigned i = 0; i < n; i++)
    {
        LS[i].clear();
        if (dirigido == 1)
            LP[i].clear();
    }
    LS.clear();
    if (dirigido == 1)
        LP.clear();
}

void GRAFO :: build(char nombrefichero[85], int &errorapertura)
{
    ElementoLista dummy;
    ifstream textfile;
    textfile.open(nombrefichero);

    if (textfile.is_open())
    {
        errorapertura = 0;

        unsigned i, j, k;

        textfile >> n >> m >> dirigido;

        LS.resize(n);

        if (dirigido == 1)
            LP.resize(n);

        for (k = 0; k < m; k++)
        {
            textfile >> i >> j >> dummy.c;

            // Guardamos sucesor
            dummy.j = j - 1;
            LS[i - 1].push_back(dummy);

            // Si es NO dirigido, añadir simétrico
            if (dirigido == 0)
            {
                if (i != j)
                {
                    dummy.j = i - 1;
                    LS[j - 1].push_back(dummy);
                }
            }
        }

        textfile.close();

        // Si es dirigido,se construye ListaPredecesores
        if (dirigido == 1)
            ListaPredecesores();
    }
    else
    {
        errorapertura = 1;
    }
}

GRAFO::~GRAFO()
{
    destroy();
}

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura)
{
    build(nombrefichero, errorapertura);
}

void GRAFO::actualizar(char nombrefichero[85], int &errorapertura)
{
    destroy();
    build(nombrefichero, errorapertura);
}

unsigned GRAFO::Es_dirigido()
{
    return dirigido;
}

void GRAFO::Info_Grafo()
{
    cout << "Numero de nodos: " << n << endl;
    cout << "Numero de aristas: " << m << endl;

    if (dirigido == 1)
        cout << "Tipo: Grafo dirigido" << endl;
    else
        cout << "Tipo: Grafo no dirigido" << endl;
}

void Mostrar_Lista(vector<LA_nodo> L)
{
    for (unsigned i = 0; i < L.size(); i++)
    {
        cout << i + 1 << ": ";

        for (unsigned j = 0; j < L[i].size(); j++)
        {
            cout << "(" << L[i][j].j + 1 << "," << L[i][j].c << ") ";
        }

        cout << endl;
    }
}

void GRAFO::Mostrar_Listas(int l)
{
    if (dirigido == 0)
    {
        cout << "Lista de adyacencia:" << endl;
        Mostrar_Lista(LS);
    }
    else
    {
        if (l == 1)
        {
            cout << "Lista de sucesores:" << endl;
            Mostrar_Lista(LS);
        }
        else if (l == -1)
        {
            cout << "Lista de predecesores:" << endl;
            Mostrar_Lista(LP);
        }
    }
}

void GRAFO::ListaPredecesores()
{
    LP.clear();
    LP.resize(n);

    for (unsigned i = 0; i < n; i++)
    {
        for (unsigned j = 0; j < LS[i].size(); j++)
        {
            ElementoLista dummy;

            dummy.j = i;
            dummy.c = LS[i][j].c;

            LP[LS[i][j].j].push_back(dummy);
        }
    }
}

//Modificación: Dar la componente conexa de la clase