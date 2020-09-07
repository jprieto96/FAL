// Jose Ramón Prieto del Prado y Santiago Gabriel y Galán Puelles
// E58 y E24


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// funcion de orden -> O(log n) siendo n el numero de elmentos
int buscarMinimo(std::vector<int> const& v, int ini, int fin) {
	if (ini + 1 == fin) // Caso base con solo elemento
		return v[ini];
	else { // Dos o mas elementos
		int mitad = (ini + fin) / 2;
		if (v[mitad] < v[mitad - 1])
			return buscarMinimo(v, mitad, fin);
		else
			return buscarMinimo(v, ini, mitad);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;
	if (!std::cin)
		return false;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	int num = buscarMinimo(v, 0, n);
	std::cout << num << "\n";

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




