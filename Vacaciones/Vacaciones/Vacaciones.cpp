// Jose Ramon Prieto del Prado
// E58

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>

struct datosEntrada {
	int numCiudades;
	std::vector<std::vector<int>> costes;
};

struct sol {
	std::vector<int> sol;
	int solMejor;
};

int minimo(datosEntrada const& d) {
	//cogemos la primera posicion valida
	int min = d.costes[0][1];
	for (int i = 0; i < d.numCiudades; i++) {
		for (int j = 0; j < d.numCiudades; j++) {
			if (d.costes[i][j] < min && d.costes[i][j] != 0)
				min = d.costes[i][j];
		}
	}
	return min;
}

// función que resuelve el problema
void VA(datosEntrada const& d, std::vector<bool> & marcas, sol & s, int k, int& costeActual, int & minCiudad) {
	for (int i = 1; i < d.numCiudades; i++) {
		s.sol[k] = i;
		costeActual += d.costes[s.sol[k - 1]][i];
		if (!marcas[i]) { // esValida
			marcas[i] = true; // marcado
			if (k == d.numCiudades - 1) { // esSolucion
				// calculamos el coste que llevamos hasta ahora + el viaje de vuelta a la ciudad origen
				if (costeActual + d.costes[i][0] < s.solMejor) s.solMejor = costeActual + d.costes[i][0];
			}
			else { // noEsSolucion
				// estimacion
				if((d.numCiudades - 1 - k) * minCiudad + costeActual < s.solMejor)
					VA(d, marcas, s, k + 1, costeActual, minCiudad);
			}
			marcas[i] = false; // desmarcado
		}
		costeActual -= d.costes[s.sol[k - 1]][i];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	datosEntrada datos;
	sol s;
	int aux;
	std::cin >> datos.numCiudades;
	if (datos.numCiudades == 0)
		return false;

	std::vector<bool> marcas(datos.numCiudades);
	datos.costes.resize(datos.numCiudades);
	for (int i = 0; i < datos.numCiudades; i++) {
		for (int j = 0; j < datos.numCiudades; j++) {
			std::cin >> aux;
			datos.costes[i].push_back(aux);
		}
	}

	s.sol.resize(datos.numCiudades);

	s.solMejor = 1000000000;
	int costeActual = 0;
	int minCiudad = minimo(datos);
	s.sol[0] = 0;
	marcas[0] = true;

	VA(datos, marcas, s, 1, costeActual, minCiudad);

	std::cout << s.solMejor << "\n";

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