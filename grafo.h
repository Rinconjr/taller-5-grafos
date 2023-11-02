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
        void prim(T vertice);

        void mostrarMatrizAdyacencia();

        T ObtenerVertice(int indice);

        //Implementar recorridos (Prioridad)
        //Recorrido PRIM
        //Recorrido Dijkstra
        void dijkstra(T vertice);

        //Recorrido Euler
        //Recorrido Hamilton
};


#include "grafo.hxx"

#endif