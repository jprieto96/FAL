// Jose Ramon Prieto del Prado y Santiago Gabriel y Galan
// E58 y E24


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// Coste de la funcion -> O(log n) n numero de elementos
/*
		{ c0 si n = 2
T(n) =	{
		{ T(n/2) + c1 si n > 2

		Haviendo el despliegue da O(log n)

*/
char presoEscapado(std::vector<char> const& v, int ini, int fin) {
	if (ini + 2 == fin) // Dos elementos
		return v[ini] + 1; // Cuando tenemos dos elementos siempre devolvemos el del medio
	else { // Tres o mas elementos
		int mitad = (ini + fin) / 2;
		if (v[mitad] - v[ini] == mitad - ini)
			return presoEscapado(v, mitad, fin);
		else
			return presoEscapado(v, ini, mitad + 1);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	char primero, ultimo, sol;
	std::cin >> primero >> ultimo;
	std::vector<char> v(ultimo - primero);

	for (int i = 0; i < v.size(); i++) {
		std::cin >> v[i];
	}

	if (v[0] == primero && v[v.size() - 1] == ultimo) {
		sol = presoEscapado(v, 0, v.size());
	}
	else {
		if (v[0] != primero)
			sol = primero;
		else if (v[v.size() - 1] != ultimo)
			sol = ultimo;
	}

	std::cout << sol << "\n";
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