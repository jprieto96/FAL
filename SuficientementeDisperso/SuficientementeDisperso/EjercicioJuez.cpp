// Santiago Gabriel y Galán Puelles, Jose Ramón Prieto del Prado
// E24 y E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
bool sufDisperso(std::vector<int> const& v, int ini, int fin, int k) {
	int mitad = (ini + fin) / 2;
	if (ini + 1 == fin) // Vector de un elemento
		return true;
	else {	// Vector de dos o mas elementos
		bool correcto1 = sufDisperso(v, ini, mitad, k);
		bool correcto2 = sufDisperso(v, mitad, fin, k);
		return correcto1 && correcto2 && std::abs(v[fin - 1] - v[ini]) >= k;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, k;
	std::cin >> n;
	if (!std::cin)
		return false;
	std::cin >> k;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i];

	if (sufDisperso(v, 0, n, k))
		std::cout << "SI\n";
	else
		std::cout << "NO\n";

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




