// Jose Ramon Prieto del Prado y Santiago Gabriel y Galan
// E58 y E24


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// O(n) siendo n el número de elementos del vector
int comprobar(std::vector<int> v, int mitad) {
	int cont = 1;
	int aux = 0;
	for (int i = 0; i < (int)v.size(); i++) {
		aux += v[i];
		if (aux > mitad) {
			cont++;
			aux = v[i];
		}
	}
	return cont;
}

// función que resuelve el problema
// Tiene un coste de O(n log n) -> n número de elementos
/*
		{c0 si n == 0
T(n) =	{
		{T(n/2) + n si n >= 1

		T(n) = T(n/2) + n = T(n/2^2) + 2n = ......
		.... = T(n/2^k) + k * n = ..... = T(1) + log n * n pertenece a O(n log n)
		Para sacar T(1) necesito que 2^k = n -> k = log n
*/
int cargaCamion(std::vector<int> const& v, int min, int max, int viajesMaximos) {
	if (min == max)
		return min;
	else{
		int mitad = (min + max) / 2;
		int k = comprobar(v, mitad); // O(n) siendo n el número de elementos
		if (k <= viajesMaximos)
			return cargaCamion(v, min, mitad, viajesMaximos); // reducimos camion
		else
			return cargaCamion(v, mitad + 1, max, viajesMaximos); // aumentamos camion
	}
		
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numObrasArte, viajesMaximos, max = 0, sumas = 0;
	std::cin >> numObrasArte >> viajesMaximos;

	if (numObrasArte == 0 && viajesMaximos == 0)
		return false;

	std::vector<int> v(numObrasArte);
	for (int i = 0; i < numObrasArte; i++) {
		std::cin >> v[i];
		sumas += v[i];
		if (v[i] > max) max = v[i];
	}

	std::cout << cargaCamion(v, max, sumas, viajesMaximos) << "\n";

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