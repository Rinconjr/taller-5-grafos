//g++ -std=c++11 main.cpp -o prueba;
//g++ -std=c++11 taller_5_grafos.cxx -o taller_5_grafos;

#include <iostream>

#include "grafo.h"

int main(){
    //Crear grafo   
    Grafo<char, int> grafo;


    grafo.insertarVertice('a');
    grafo.insertarVertice('b');
    grafo.insertarVertice('c');
    grafo.insertarVertice('d');
    grafo.insertarVertice('e');
    grafo.insertarVertice('f');
    grafo.insertarVertice('g');
    grafo.insertarVertice('h');
    grafo.insertarVertice('i');

    //a
    grafo.insertarArista('a', 'b', 4);
    grafo.insertarArista('b', 'a', 4);
    grafo.insertarArista('a', 'h', 8);
    grafo.insertarArista('h', 'a', 8);

    //b
    grafo.insertarArista('b', 'c', 8);
    grafo.insertarArista('c', 'b', 8);
    grafo.insertarArista('b', 'h', 11);
    grafo.insertarArista('h', 'b', 11);

    //c
    grafo.insertarArista('c', 'i', 2);
    grafo.insertarArista('i', 'c', 2);
    grafo.insertarArista('c', 'd', 7);
    grafo.insertarArista('d', 'c', 7);
    grafo.insertarArista('c','f', 4);
    grafo.insertarArista('f', 'c', 4);

    //d
    grafo.insertarArista('d', 'e', 9);
    grafo.insertarArista('e', 'd', 9);
    grafo.insertarArista('d', 'f', 14);
    grafo.insertarArista('f', 'd', 14);

    //e
    grafo.insertarArista('e', 'f', 10);
    grafo.insertarArista('f', 'e', 10);

    //f
    grafo.insertarArista('f', 'g', 2);
    grafo.insertarArista('g', 'f', 2);

    //g
    grafo.insertarArista('g', 'i', 6);
    grafo.insertarArista('i', 'g', 6);
    grafo.insertarArista('g', 'h', 1);
    grafo.insertarArista('h', 'g', 1);

    //h
    grafo.insertarArista('h', 'i', 7);
    grafo.insertarArista('i', 'h', 7);


    //grafo.mostrarMatrizAdyacencia();

    grafo.prim('a');


    /*
    grafo.insertarVertice(1);
    grafo.insertarVertice(2);
    grafo.insertarVertice(3);
    grafo.insertarVertice(4);
    grafo.insertarVertice(5);
    grafo.insertarVertice(6);
    grafo.insertarVertice(7);
    grafo.insertarVertice(8);

    grafo.insertarArista(1, 2, 90);
    grafo.insertarArista(1, 3, 64);
    grafo.insertarArista(1, 4, 70);

    grafo.insertarArista(2, 1, 90);
    grafo.insertarArista(2, 4, 64);
    grafo.insertarArista(2, 5, 50);
    grafo.insertarArista(2, 6, 64);

    grafo.insertarArista(3, 1, 64);
    grafo.insertarArista(3, 4, 90);
    grafo.insertarArista(3, 7, 64);

    grafo.insertarArista(4, 1, 70);
    grafo.insertarArista(4, 2, 64);
    grafo.insertarArista(4, 3, 90);
    grafo.insertarArista(4, 5, 40);
    grafo.insertarArista(4, 7, 70);
    grafo.insertarArista(4, 8, 64);

    grafo.insertarArista(5, 2, 50);
    grafo.insertarArista(5, 4, 40);
    grafo.insertarArista(5, 6, 40);
    grafo.insertarArista(5, 8, 50);

    grafo.insertarArista(6, 2, 64);
    grafo.insertarArista(6, 5, 40);
    grafo.insertarArista(6, 8, 64);

    grafo.insertarArista(7, 3, 64);
    grafo.insertarArista(7, 4, 70);
    grafo.insertarArista(7, 8, 90);

    grafo.insertarArista(8, 4, 64);
    grafo.insertarArista(8, 5, 50);
    grafo.insertarArista(8, 6, 64);
    grafo.insertarArista(8, 7, 90);
    */
    
   /*
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

    grafo.dijkstra(1);
    */
    return 0;
}