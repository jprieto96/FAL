// Jose Ramon Prieto del Prado
// E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// El problema tiene un coste lineal -> 1 + n * (1+1+1) -> O(n)
void resolver(std::vector<int> & datos) {
	int buenos = 0; // O(1)
	for (int i = 0; i < (int)datos.size(); i++) { // n veces siendo n el tamaño del vector datos
		if (datos[i] % 2 == 0) { // O(1)
			datos[buenos] = datos[i]; // O(1)
			buenos++; // O(1)
		}
	}
	datos.resize(buenos);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int sizeVector;
	std::cin >> sizeVector;

	std::vector<int> datos(sizeVector);

	for (int i = 0; i < sizeVector; i++) std::cin >> datos[i];

	resolver(datos);

	for (int i = 0; i < (int) datos.size(); i++)
		std::cout << datos[i] << " ";
	
	std::cout << "\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}