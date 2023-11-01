//g++ -std=c++11 main.cpp -o prueba;

#include <iostream>

#include "grafo.h"

int main(){
    //Crear grafo   
    Grafo<int, int> grafo;

    grafo.insertarVertice(1);
    grafo.insertarVertice(2);
    grafo.insertarVertice(3);
    grafo.insertarVertice(4);

    grafo.insertarArista(1, 2, 4);

    grafo.insertarArista(3, 4, 1);

    std::vector<int> prueba = grafo.componenteVertice(1);

    std::cout << "Componente nodo 1:" << std::endl;

    for(int i=0; i<prueba.size(); i++){
        std::cout << prueba[i] << " ";
    }

    std::cout << "\nComponente nodo 3." << std::endl;
    prueba = grafo.componenteVertice(3);

    for(int i=0; i<prueba.size(); i++){
        std::cout << prueba[i] << " ";
    }

    std::cout << "\nPrim nodo 1:" << std::endl;

    grafo.mostrarMatrizAdyacencia();
    
    return 0;
}