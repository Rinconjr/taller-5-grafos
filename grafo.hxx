#include "grafo.h"

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <iomanip>
#include <functional>
#include <set>
#include <limits>

template <class T, class U>
Grafo<T, U>::Grafo(){
    this->vertices.clear(); //Garantizar que la lista esta vacia
}

template <class T, class U>
void Grafo<T, U>::setVertices(std::vector<T> v){
	this->vertices = v; // Copia los elementos de v en vertices
}

template <class T, class U>
void Grafo<T, U>::setAristas(std::vector<std::vector <U> > a){
	this->matriz_adyacencia = a; // Copia los elementos de a en matriz_adyacencia
}

template <class T, class U>
std::vector<T> Grafo<T, U>::getVertices(){
	return this->vertices; //Devuelve el vector de vertices
}

template <class T, class U>
std::vector<std::vector <U> > Grafo<T, U>::getAristas(){
	return this->matriz_adyacencia; //Devuelve la matriz de adyacencia
}

template <class T, class U>
int Grafo<T, U>::cantVertices() { 
    return this->vertices.size(); 
}

template <class T, class U>
int Grafo<T, U>::cantAristas() {
	//Recorre la matriz de adyacencia y si encuentra un valor distinto a 0, suma 1
	int suma = 0;
	for(int i = 0; i < cantVertices(); i++) {
		for(int j = 0; j < cantVertices(); j++) {
			if(matriz_adyacencia[i][j] != 0) { //Si hay arista (Valor distinto a 0)
				suma++;
			}
		}
	}

	return suma; //Devuelve valor acumulado
}

template <class T, class U>
bool Grafo<T, U>::buscarVertice(T vert) {
	if(cantVertices() == 0) { //Si no hay vertices, no hay nada que buscar
		return false;
	}

	for (int i = 0; i < cantVertices(); i++) {
		if (this->vertices[i] == vert) {
			return true; //Si se encuentra el vertice, se devuelve true
		}
	}

	return false; //Si no se encuentra, se devuelve false
}

//Funcion que devuelve la posicion del vertice en el vector de vertices
template <class T, class U>
int Grafo<T, U>::buscarVerticeIndice(T vert) {
	int indice = -1;
	for (int i = 0; i < cantVertices(); i++) {
		if (vertices[i].X == vert.X && vertices[i].Y == vert.Y) {
			indice = i;
		}
	}

	return indice; //Si no se encuentra, se devuelve -1. Caso contrario, devuelve el indice.
}

template <class T, class U>
bool Grafo<T, U>::insertarVertice(T vert) {
	bool res = false;

	if(buscarVerticeIndice(vert) == -1) { //Si el vertice no existe, se puede insertar
		//Se agrega el vertice al vector de vertices
		this->vertices.push_back(vert);

		//Se debe agregar una columna y una fila a la matriz de adyacencia
		
		int tam = cantVertices(); //Tamano de la matriz de adyacencia actualizada

		this->matriz_adyacencia.resize(tam); //Se agrega una fila

		for(int i = 0; i < cantVertices(); i++) {
			//Se agrega una columna
			this->matriz_adyacencia[i].resize(tam);
		}

		return true;
	}

	return res;
}

template <class T, class U>
T Grafo<T, U>::ObtenerVertice(int indice){
	return this->vertices[indice];
}

template <class T, class U>
bool Grafo<T,U>::eliminarVertice(T ver) {
	bool res = false;
	int i_vertice = buscarVerticeIndice(ver); //Se busca indice vertice

	if ( i_vertice != -1 ) { //Si se encuentra el vertice, se puede seguir
		//Se elimina el vertice del vector de vertices
		this->vertices.erase(this->vertices.begin() + i_vertice);

		//Se debe eliminar una columna y una fila a la matriz de adyacencia
		this->matriz_adyacencia.erase(this->matriz_adyacencia.begin() + i_vertice); //Se elimina la fila

		for(int i = 0; i < cantVertices(); i++) {
			this->matriz_adyacencia[i].erase(this->matriz_adyacencia[i].begin() + i_vertice);
		}	

		res = true;
	}

	return res;
}

template <class T, class U>
bool Grafo<T, U>::insertarArista(long ori, long des, U cos) {
	bool res = false;
	
	if ( ori >= 0 && des >= 0 && ori <= this->vertices.size() && des <= this->vertices.size()) { //Si se encontraron ambos, se puede seguir
		
		if(this->matriz_adyacencia[ori][des] == 0) { //Si no hay arista, se puede insertar
			this->matriz_adyacencia[ori][des] = cos;
			res = true;
		}
	}

	return res;
}

template < class T, class U>
U Grafo<T,U>::ObtenerCosto(unsigned long ori, unsigned long des){

	U res = 0;

	if ( ori >= 0 && des >= 0 && ori <= this->vertices.size() && des <= this->vertices.size() ) {
		res = this->matriz_adyacencia[ori][des];
	}

	return res;
}

template <class T, class U>
bool Grafo<T, U>::buscarArista(T ori, T des) { //Retorna el valor de la posicion (costo)
	bool res = false;

	int i_origen = buscarVerticeIndice(ori); //Se busca indice origen
	int i_destino = buscarVerticeIndice(des); //Se busca inidice destino

	if ( i_origen != -1 && i_destino != -1 ) {
		res = true;
	}

	return res;
}

template <class T, class U>
bool Grafo<T, U>::eliminarArista(T ori, T des) {
	bool res = false;
	int i_origen = buscarVerticeIndice(ori); //Se busca indice origen
	int i_destino = buscarVerticeIndice(des); //Se busca inidice destino

	if ( i_origen != -1 && i_destino != -1 ) {
		this->matriz_adyacencia[i_origen][i_destino] = 0; //Se elimina la arista (Cambiando el costo a 0)
		res = true;
	}

	return res;
}

template <class T, class U>
void Grafo<T,U>::recorridoPlano(){
	for(int i = 0; i < this->cantVertices(); i++){
		std::cout << this->vertices[i] << " ";
    }
}

template <class T, class U>
void Grafo<T, U>::dfs(T vertice) {
	std::vector<T> visitados;
	std::stack<T> pila;
	bool visitado = false;

	pila.push(vertice);

	while(!pila.empty()){
		T aux = pila.top();
		pila.pop();

		visitado = false;

		for(int i=0; i<visitados.size(); i++){ //Encontrar si ya fue visitado o no
			if(aux == visitados[i]){
				visitado = true;
				break;
			}
		}

		if(!visitado){ //Si no ha sido visitado
			std::cout << aux << " "; //Imprimir valor nodo
			visitados.push_back(aux); //Marcar como visitado

			for(int i=0; i<cantVertices(); i++){ //Agregar a la pila los adyacentes
				if(buscarArista(aux, vertices[i])){
					pila.push(this->vertices[i]);
				}
			}
		}
	}
}

template <class T, class U>
void Grafo<T,U>::bfs(T vertice){
	std::vector<T> visitados;
	std::queue<T> cola;
	bool visitado = false;

	cola.push(vertice);

	while(!cola.empty()){
		T aux = cola.front();
		cola.pop();

		visitado = false;

		for(int i=0; i<visitados.size(); i++){ //Encontrar si ya fue visitado o no
			if(aux == visitados[i]){
				visitado = true;
				break;
			}
		}

		if(!visitado){ //Si no ha sido visitado
			std::cout << aux << " "; //Imprimir valor nodo
			visitados.push_back(aux); //Marcar como visitado

			for(int i=0; i<cantVertices(); i++){ //Agregar a la cola los adyacentes
				if(buscarArista(aux, vertices[i])){
					cola.push(this->vertices[i]);
				}
			}
		}
	}
}

template <class T, class U>
std::vector<T> Grafo<T,U>::componenteVertice(T vertice){ //Es el mismo bfs pero devuelve visitados
	std::vector<T> visitados;
	std::queue<T> cola;
	bool visitado = false;

	cola.push(vertice);

	while(!cola.empty()){
		T aux = cola.front();
		cola.pop();

		visitado = false;

		for(int i=0; i<visitados.size(); i++){ //Encontrar si ya fue visitado o no
			if(aux == visitados[i]){
				visitado = true;
				break;
			}
		}

		if(!visitado){ //Si no ha sido visitado
			visitados.push_back(aux); //Marcar como visitado

			for(int i=0; i<cantVertices(); i++){ //Agregar a la cola los adyacentes
				if(buscarArista(aux, vertices[i])){
					cola.push(this->vertices[i]);
				}
			}
		}
	}

	return visitados;
}

template <class T, class U>
void Grafo<T,U>::mostrarMatrizAdyacencia(){
	for(int i=0; i<cantVertices(); i++){
		for(int j=0; j<cantVertices(); j++){
			std::cout << "Indice [" << i << "][" << j << "] = " << this->matriz_adyacencia[i][j] << "\n";
		}
		std::cout << std::endl;
	}
}

template <class T, class U>
std::vector<std::vector<unsigned long>>Grafo<T,U>::prim(unsigned long ori){
	int n = vertices.size();  // número de nodos

    std::vector<U> cost(n, std::numeric_limits<U>::max());  // costo mínimo de origen a i
    std::vector<unsigned long> prev(n, std::numeric_limits<unsigned long>::max());  // nodo anterior en el camino óptimo
    std::vector<bool> inMST(n, false);  // si el nodo i está en el MST

    std::priority_queue<std::pair<U, unsigned long>, std::vector<std::pair<U, unsigned long>>, std::greater<std::pair<U, unsigned long>>> pq;
    cost[ori] = 0;
    pq.push({0, ori});

    while (!pq.empty()) {
        unsigned long u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (unsigned long v = 0; v < n; ++v) {
            if (matriz_adyacencia[u][v] && !inMST[v] && matriz_adyacencia[u][v] < cost[v]) {
                cost[v] = matriz_adyacencia[u][v];
                pq.push({cost[v], v});
                prev[v] = u;
            }
        }
    }

    std::vector<std::vector<unsigned long>> rutaPrim(n);
    for (unsigned long i = 0; i < n; ++i) {
        if (prev[i] != std::numeric_limits<unsigned long>::max() || i == ori) {
            unsigned long nodo = i;
            while (nodo != std::numeric_limits<unsigned long>::max()) {
                rutaPrim[i].push_back(nodo);
                nodo = prev[nodo];
            }
        }
    }

    return rutaPrim; //Se retorna la rutaPrim
}

template <class T, class U>
std::vector<std::vector<unsigned long>> Grafo<T,U>::dijkstra(unsigned long vertice) {
    int n = vertices.size();  // Número de nodos

    std::vector<U> dist(n, std::numeric_limits<U>::max());  // Costo mínimo desde el vértice de origen hasta el nodo i. Numeric_limits para representar infinito
    std::vector<unsigned long> pred(n, std::numeric_limits<unsigned long>::max());  // Nodo predecesor en el camino
    std::vector<bool> inMST(n, false);  // Si el nodo i está en el MST

    std::priority_queue<std::pair<U, unsigned long>, std::vector<std::pair<U, unsigned long>>, std::greater<std::pair<U, unsigned long>>> pq;
    dist[vertice] = 0;
    pq.push({0, vertice});

    while (!pq.empty()) {
        unsigned long u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (unsigned long v = 0; v < n; ++v) {
            if (matriz_adyacencia[u][v] && !inMST[v] && dist[u] + matriz_adyacencia[u][v] < dist[v]) {
                dist[v] = dist[u] + matriz_adyacencia[u][v];
                pq.push({dist[v], v});
                pred[v] = u;
            }
        }
    }

    std::vector<std::vector<unsigned long>> rutaDijkstra(n);

    for (unsigned long i = 0; i < n; ++i) {
        if (pred[i] != std::numeric_limits<unsigned long>::max() || i == vertice) {
            unsigned long nodo = i;
            while (nodo != std::numeric_limits<unsigned long>::max()) {
                rutaDijkstra[i].push_back(nodo);
                nodo = pred[nodo];
            }
        }
    }

    return rutaDijkstra; //se retorna la rutaDijkstra
}