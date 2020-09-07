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
int numCombinatorio(int a, int b, std::vector<std::vector<int>>& tabla) {
	if (b == a) return tabla[a][b] = 1;
	else if(b == 1) return tabla[a][b] = a;
	else {
		if (tabla[a - 1][b - 1] == -1) tabla[a - 1][b - 1] = numCombinatorio(a - 1, b - 1, tabla);
		if (tabla[a - 1][b] == -1) tabla[a - 1][b] = numCombinatorio(a - 1, b, tabla);
		return tabla[a][b] = tabla[a - 1][b - 1] + tabla[a - 1][b];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int a, b;
	std::cin >> a >> b;
	if (!std::cin)
		return false;
	
	std::vector<std::vector<int>> tabla(a + 1, std::vector<int>(b + 1, -1));

	std::cout << numCombinatorio(a, b, tabla) << "\n";

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