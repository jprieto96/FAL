// Jose Ramon Prieto del Prado y Santiago Gabriel y Galan
// E58 y E24


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// Coste de la funcion -> O(log n)
int numeroATachar(std::vector<int> const& v, int ini, int fin, int numCantado) {
	int mitad = (ini + fin) / 2;
	if (ini + 1 == fin) // Un elemento
		if (ini + numCantado == v[ini])
			return v[ini];
		else
			return -1;
	else { // Dos o mas elementos
		if (numCantado + mitad > v[mitad])
			return numeroATachar(v, mitad, fin, numCantado);
		else if (numCantado + mitad < v[mitad])
			return numeroATachar(v, ini, mitad, numCantado);
		else
			return v[mitad];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n, numCantado;
	std::cin >> n;
	std::vector<int> v(n);

	std::cin >> numCantado;

	for (int i = 0; i < n; ++i) {
		std::cin >> v[i];
	}

	int sol = numeroATachar(v, 0, n, numCantado);
	// escribir sol
	if(sol != -1)
		std::cout << sol << "\n";
	else
		std::cout << "NO\n";
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