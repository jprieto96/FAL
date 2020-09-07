// Jose Ramon Prieto del Prado
// E58

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>

struct datosEntrada {
	int longitud, numColores, consumoMax;
	std::vector<int> consumoLuces;
};

struct solucion{
	std::vector<int> sol;
	int cont = 0;
};

struct marcas {
	std::vector<int> lucesUsadas;
	int consumoTira = 0;
};

// Tiene un coste de O(1) -> Coste constante
bool esValida(int k, datosEntrada const& d, marcas& m, solucion & s) {
	// comprobar que no haya mas de dos luces seguidas del mismo color
	if (k > 1 && s.sol[k] == s.sol[k - 1] && s.sol[k - 1] == s.sol[k - 2]) return false;
	// Comprobamos que la suma de las luces un color no supere en mas de una unidad a la suma de las luces de los demas colores
	// Pongo k + 1 porque cuando k es 0 ya esta puesta una luz en la tira y asi sucesivamente
	if (2 * m.lucesUsadas[s.sol[k]] - (k + 1) > 1) return false;
	// comprobar que el consumo
	if (m.consumoTira > d.consumoMax) return false;
		
	return true;
}

// función que resuelve el problema
void resolver(datosEntrada const& d, marcas& m, solucion& s, int k) {
	for (int i = 0; i < d.numColores; i++) {
		s.sol[k] = i;
		// marcado
		m.lucesUsadas[i]++;
		m.consumoTira += d.consumoLuces[i];
		if (esValida(k, d, m, s)) {
			if (k == d.longitud - 1) { // esSolucion
				s.cont++;
			}
			else // noEsSolucion
				resolver(d, m, s, k + 1);
		}
		// desmarcado
		m.consumoTira -= d.consumoLuces[i];
		m.lucesUsadas[i]--;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	datosEntrada datos;
	marcas m;
	solucion s;
	std::cin >> datos.longitud;

	if (datos.longitud == 0)
		return false;

	std::cin >> datos.numColores >> datos.consumoMax;

	m.lucesUsadas.assign(datos.numColores, 0);
	datos.consumoLuces.resize(datos.numColores);

	for (int i = 0; i < datos.consumoLuces.size(); i++)
		std::cin >> datos.consumoLuces[i];

	s.sol.resize(datos.longitud);

	int k = 0;

	resolver(datos, m, s, k);
		
	std::cout << s.cont << "\n";
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