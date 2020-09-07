// Jose Ramon Prieto del Prado
// E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

/*
*	La funcion tiene coste lineal O(n) ya que todo lo que hay dentro del bucle es de orden constante O(1)
*	y como el bucle se repite n veces siendo n el tamaño del vector datos -> O(n) * O(1) = O(n)
*/
void pares(std::vector<int> & datos) {
	int k = 0; // O(1)
	for (int i = 0; i < (int)datos.size(); i++) { // n veces siendo n datos.size(), el tamaño del vector
		if ((datos[i] % 2 == 0 && k % 2 == 0) || (datos[i] % 2 == 1 && k % 2 == 1)) { // O(1)
			std::swap(datos[k], datos[i]); // O(1)
			k++; // O(1)
			if (k <= i) k++; // O(1)
		}
	}
	if (k % 2 == 1) k--; // O(1)
	datos.resize(k); // O(1)
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numDatos;
	std::cin >> numDatos;

	if (!std::cin) return false;

	std::vector<int> datos(numDatos);

	for (int i = 0; i < numDatos; i++) std::cin >> datos[i];

	pares(datos);

	for (int i = 0; i < (int)datos.size(); i++) std::cout << datos[i] << " ";
	std::cout << "\n";
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}