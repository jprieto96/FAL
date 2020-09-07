// Jose Ramon Prieto del Prado y Santiago Gabriel y Galan
// E58 y E24


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// funcion de orden -> O(log n) siendo n el numero de elmentos
int buscarElementoPerdido(std::vector<int> const& v1, std::vector<int> const& v2, int ini1, int fin1, int ini2, int fin2) {
	if (ini2 == fin2) // 0 elementos
		return v1[ini1];
	else if (ini2 + 1 == fin2) // 1 elemento
		return (v1[ini1] == v2[ini2]) ? v1[fin2] : v1[ini1];
	else { // Dos o mas elementos
		int mitad = (ini1 + fin1) / 2;
		if (v2[mitad] != v1[mitad])
			return buscarElementoPerdido(v1, v2, ini1, mitad, ini2, mitad);
		else
			return buscarElementoPerdido(v1, v2, mitad, fin1, mitad, fin2);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;
	std::vector<int> vectorEntero(n);
	std::vector<int> vectorSinUnNumero(n - 1);

	for (int i = 0; i < n; ++i) {
		std::cin >> vectorEntero[i];
	}

	for (int i = 0; i < n - 1; ++i) {
		std::cin >> vectorSinUnNumero[i];
	}

	int numeroQueFalta = buscarElementoPerdido(vectorEntero, vectorSinUnNumero, 0, n, 0, n-1);
	// escribir solucion
	std::cout << numeroQueFalta << "\n";
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