#ifndef _GRAFO_H__
#define _GRAFO_H__

#include <vector>

//Matriz de adyacencia
//T: Tipo de dato vertices (NODOS)
//U: Tipo de dato aristas (COSTOS)
template <class T, class U>
class Grafo {
    private:
        std::vector<T> vertices; //Nodos
        std::vector<std::vector <U>> matriz_adyacencia; //Vector de vectores de costos
    public:
        Grafo();
        void setVertices(std::vector<T> v);
        void setAristas(std::vector<std::vector <U>> a);
        std::vector<T> getVertices();
        std::vector<std::vector <U>> getAristas();
        int cantVertices();
        int cantAristas();
        bool buscarVertice(T vert);
        T ObtenerVertice(int indice);
        int buscarVerticeIndice(T vert);
        bool insertarVertice(T vert);
        bool eliminarVertice(T vert);
        bool insertarArista(long ori, long des, U cos);
        bool buscarArista(T ori, T des); 
        U ObtenerCosto(unsigned long ori, unsigned long des);
        bool eliminarArista(T ori, T des);
        void recorridoPlano();
        void dfs(T vertice);
        void bfs(T vertice);
        std::vector<T> componenteVertice(T vertice);
        void mostrarMatrizAdyacencia();
        std::vector<std::vector<unsigned long>>prim(unsigned long ori);
        std::vector<std::vector<unsigned long>> dijkstra(unsigned long vertice);
};

#include "grafo.hxx"

#endif