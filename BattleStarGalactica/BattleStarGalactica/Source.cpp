// Jose Ramon Prieto del Prado
// E58

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>

// función que resuelve el problema
// Tiene un coste de O(n log n) -> n número de elementos
/*
		{c0 si n == 0
T(n) =	{
		{2T(n/2) + n log n si n >= 1

		Haciendo despliegue -> O(n log n)
*/
int resolver(std::vector<int>& v, int ini, int fin) {

	if (ini >= fin) 
		return 0;
	else {
		int mitad = (ini + fin) / 2;
		int izq = resolver(v, ini, mitad);
		int der = resolver(v, mitad + 1, fin);
		int i = ini, j = mitad + 1, cont = 0;

		while (i <= mitad && j <= fin) {
			if (v[i] > v[j]) {
				cont += (mitad - i + 1);
				++j;
			}
			else ++i;
		}

		std::sort(v.begin() + ini, v.begin() + fin + 1); // O(n log n)
		return izq + der + cont;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num;
	std::cin >> num;

	if (!std::cin)
		return false;

	std::vector<int> v(num);

	for (int& aux : v)
		std::cin >> aux;

	int sol = resolver(v, 0, num - 1);

	// escribir sol
	std::cout << sol << "\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to datos.txt:
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}