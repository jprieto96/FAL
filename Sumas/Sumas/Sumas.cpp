// Jose Ramon Prieto del Prado
// E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// Coste de la funcion -> O(2^(a - b))  a y b elementos de entrada del algoritmo
/*
		{ c0 si a == b || b == 1
T(a, b) =	{
		{ T(a-1, b-1) + T(a-1, b) + c1 si a != b && b != 1

		T(a, b) = T(a-1, b-1) + T(a-1, b) + c1 = 2T(a - 1, b) + c1 = 2(2T(2a - 2, 2b) + c1) + c1 = 2^2T(2a - 2, 2b) + 2c1 + c1 =
		= 2^2(2T(3a - 3, 3b) + c1) + 2c1 + c1 = 2^3T(3a - 3, 3b) + 2^2c1 + 2c1 + c1 = .......... = 2^kT(ka - k, kb) +
		sum(2^j desde j == 0 hasta j == k - 1) = ..... => pertenece O(2^(a - b))  a y b elementos de entrada del algoritmo

*/
int calcularNumSumas(int suma, int i, std::vector<int> const& v,  std::vector<std::vector<int>>& tabla) {
	if (suma == 0)
		return tabla[i][0] = 1;
	else if (i == 0)
		return tabla[0][suma] = 0;
	else {
		if (tabla[i - 1][suma] == -1)
			tabla[i - 1][suma] = calcularNumSumas(suma, i - 1, v, tabla);
		if (suma >= v[i]) {
			if (tabla[i - 1][suma - v[i]] == -1)
				tabla[i - 1][suma - v[i]] = calcularNumSumas(suma - v[i], i - 1, v, tabla);
			return tabla[i][suma] = tabla[i - 1][suma] + tabla[i - 1][suma - v[i]];

		}
		else return tabla[i][suma] =  tabla[i - 1][suma];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numValores, s;
	std::cin >> numValores >> s;
	if (!std::cin)
		return false;
	std::vector<int> v(numValores);
	std::vector<std::vector<int>> tabla(numValores + 1, std::vector<int>(s + 1, -1));

	for (int i = 0; i < numValores; i++) {
		std::cin >> v[i];
	}

	std::cout << calcularNumSumas(s, numValores, v, tabla) << "\n";

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