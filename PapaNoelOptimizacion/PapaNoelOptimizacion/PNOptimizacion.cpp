// Jose Ramon Prieto del Prado
// E58

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>

struct datosEntrada {
	std::vector<std::vector<int>> satisfaccion;
	int m, n;
};

struct sol {
	std::vector<int> solucion;
	int sumaSatis = 0;
};

// función que resuelve el problema
void repartirRegalos(datosEntrada const& datos, sol& sol, std::vector<bool> & marcas, int k, int & satisMejor) {
	for (int i = 0; i < datos.m; i++) {
		sol.solucion[k] = i;
		if (!marcas[i]) { // esValida
			sol.sumaSatis += datos.satisfaccion[k][i];
			marcas[i] = true;
			if (k == datos.n - 1) {
				if (sol.sumaSatis > satisMejor) satisMejor = sol.sumaSatis; // solucion Mejor
			}
			else
				repartirRegalos(datos, sol, marcas, k + 1, satisMejor);
			marcas[i] = false;
			sol.sumaSatis -= datos.satisfaccion[k][i];
		}
		
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	datosEntrada datos;
	sol sol;
	int aux, satisMejor = 0;
	std::cin >> datos.m >> datos.n;
	if (!std::cin)
		return false;

	datos.satisfaccion.resize(datos.n);

	for (int i = 0; i < datos.n; i++) {
		for (int j = 0; j < datos.m; j++) {
			std::cin >> aux;
			datos.satisfaccion[i].push_back(aux);
		}
	}

	for (int i = 0; i < datos.n; i++) {
		satisMejor += datos.satisfaccion[i][i];
	}

	int k = 0;
	std::vector<bool> marcas(datos.m);
	sol.solucion.assign(datos.n, 0);
	repartirRegalos(datos, sol, marcas, k, satisMejor);
	std::cout << satisMejor << "\n";
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