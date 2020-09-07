// Santiago Gabriel y Galán Puelles, Jose Ramón Prieto del Prado
// E24 y E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
// Complejidad de la funcion O(log n) 
int resolver(std::vector<int> const& v, int ini, int fin) {
	if (ini + 1 == fin) // Vector de un elemento
		return v[ini];
	else {	// Vector de dos o mas elementos
		int mitad = (ini + fin) / 2;
		if (v[mitad] < v[mitad - 1] && v[mitad] < v[ini])
			return resolver(v, mitad, fin);
		else
			return resolver(v, ini, mitad);	
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

	int numMinimo = resolver(v, 0, n);

	std::cout << numMinimo << "\n";

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




