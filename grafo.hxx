#include "grafo.h"

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <iomanip>
#include <functional>

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
		if (vertices[i] == vert) {
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
bool Grafo<T, U>::insertarArista(T ori, T des, U cos) {
	bool res = false;
	int i_origen = buscarVerticeIndice(ori); //Se busca indice origen
	int i_destino = buscarVerticeIndice(des); //Se busca inidice destino

	if ( i_origen != -1 && i_destino != -1 ) { //Si se encontraron ambos, se puede seguir
		
		if(this->matriz_adyacencia[i_origen][i_destino] == 0) { //Si no hay arista, se puede insertar
			this->matriz_adyacencia[i_origen][i_destino] = cos;
			res = true;
		}
	}

	return res;
}

template < class T, class U>
U Grafo<T,U>::costoArista(T ori, T des){
	U res = -1; //Si no se encuentra devuelve -1
	int i_origen = buscarVerticeIndice(ori); //Se busca indice origen
	int i_destino = buscarVerticeIndice(des); //Se busca inidice destino

	if ( i_origen != -1 && i_destino != -1 ) {
		res = this->matriz_adyacencia[i_origen][i_destino];
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
			std::cout << "Index [" << i << "][" << j << "] = " << this->matriz_adyacencia[i][j] << "\n";
		}
		std::cout << std::endl;
	}
}

template <class T, class U>
void Grafo<T,U>::prim(T vertice){
	std::vector<T> verticesVisitados; //Conjunto de vertices visitados
	std::vector<std::pair<T, T> > aristasUtilizadas; //Conjunto de aristas utilizadas
	std::vector<T> verticesPosibles = this->componenteVertice(vertice); //Conjunto de vertices posibles (Total)
	//std::vector<T> verticesDisponibles = verticesPosibles; //Conjunto de vertices disponibles
	std::priority_queue<std::pair<T, T>, std::vector<std::pair<T, T>>, std::greater<std::pair<T, T>>> minHeap;

	verticesVisitados.push_back(vertice); //Agregar primer vertice como visitado

	int peso = 0;

	//añadir aristas del vertice a la cola de prioridad
	for(int i=0; i<verticesPosibles.size(); i++){
		peso = buscarArista(vertice, verticesPosibles[i]);

		if(peso != -1){
			minHeap.push(std::make_pair(peso, verticesPosibles[i]));
		}
	}

	T actual = vertice;

	while(verticesVisitados.size() != verticesPosibles.size()){
		//Buscar arista de menor costo en el min heap
			//Si el vertice destino no ha sido visitado
				//Agregar vertice destino como visitado
				//Agregar arista a arbol de expansion minima
				//Agregar aristas al min heap

		
		std::pair<T, T> arista = minHeap.top();

		minHeap.pop();

		actual = arista.second;

		verticesVisitados.push_back(actual);

		//verticesDisponibles.erase(std::remove(verticesDisponibles.begin(), verticesDisponibles.end(), actual), verticesDisponibles.end());

		aristasUtilizadas.push_back(arista);

		std::cout << "Valor actual: " << actual << std::endl;


	}
}

template <class T, class U>
void Grafo<T,U>::dijkstra(T vertice){
	//Falta que en el resultado se imprima el numero del nodo en pred, en vez del consecutivo

	bool nodoEncontrado = false;
	//Se utilizará -1 para representar vacio e infinito

	//Inicialización de vectores para hacer Dijkstra
	std::vector<int> dist;
	std::vector<T> pred;
	std::vector<T> S;
	std::vector<T> Q;

	//Esto se hace para estar en el estado inicial segun como se muestra en las diapositivas
	for(int j=0; j<cantVertices(); j++){
			
			//Para el nodo de inicio
			if(this->vertices[j] == vertice) {
				dist.push_back(0); //La distancia hacia si mismo es 0
				pred.push_back(j);
				nodoEncontrado = true;
			}
			//Para los demás nodos
			else{
				dist.push_back(-1);
				pred.push_back(-1);
			}
			Q.push_back(j);
	}

	if(!nodoEncontrado) {
		return;
	}

	//Se repetira hasta que se terminen de comprobar todos los nodos
	while (Q.size() != 0)
	{
		//Escoger el menor nodo disponible
		int nodo_elegido = -1;
		int valor_nodo_elegido = -1;

		for(int j=0; j<dist.size(); j++){
			//Busca el nodo con menor valor
			if(dist[j] != -1 && (dist[j] <= valor_nodo_elegido || valor_nodo_elegido == -1)) {
				//Comprueba que el nodo no se halla revisado antes
				for (int a: Q)
				{
					if(j == a) {
						nodo_elegido = j;
						valor_nodo_elegido = dist[j];
					}
				}
			}
		}

		//Para las aristas del vertice,  verifica que el camino hasta ese nodo implica menos costo que el que ya tenga asignado y lo recalcula
		for(int j=0; j<cantVertices(); j++){
			if(this->matriz_adyacencia[nodo_elegido][j] > 0) {
				if(dist[j] > this->matriz_adyacencia[nodo_elegido][j] + valor_nodo_elegido || dist[j] == -1) {
					dist[j] = this->matriz_adyacencia[nodo_elegido][j] + valor_nodo_elegido;
					pred[j] = nodo_elegido;
				}
			}
		}

		//Al finalizar el nodo, lo pone en S y lo quita de Q
		for (int i = 0; i < Q.size(); i++)
		{
			if(Q[i] == nodo_elegido) {
				S.push_back(Q[i]);
				Q.erase(Q.begin() + i);
			}
		}
		
		//Prints de cada paso para verificar que todo esta en orden
		std::cout << "\nDist ";
		for (int a: dist)
		{
			std::cout <<std::setw(5) << a;
		}
		std::cout << "\nPred ";
		for (int a: pred)
		{
			std::cout <<std::setw(5) << a;
		}
		std::cout << "\nS    ";
		for (int a: S)
		{
			std::cout <<std::setw(5) << a;
		}
		std::cout << "\nQ    ";
		for (int a: Q)
		{
			std::cout <<std::setw(5) << a;
		}

		std::cout << "\n==========" << std::endl;
	}

	std::cout << "La secuencia hasta cada nodo desde el nodo " << vertice << " con el menor costo " << std::endl;
	for (int i = 0; i < S.size(); i++)
	{
		int at = pred[i];
		std::cout << "Nodo " << this->vertices[i] << ": (costo " << std::setw(5) <<dist[i] << "): ";
		std::stack<T> rt;
		if(vertice == this->vertices[i]) {
			std::cout << "Es el nodo de inicio ";
		}
		else {
			rt.push(this->vertices[at]);
			while (at != pred[at])
			{
				at = pred[at];
				rt.push(this->vertices[at]);
			}
			while (!rt.empty()) {
				T elemento = rt.top();
				std::cout << elemento << " ";
				rt.pop();
			}
		}
		std::cout << std::endl;
	}
}