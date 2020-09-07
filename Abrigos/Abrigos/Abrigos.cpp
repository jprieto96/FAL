// Jose Ramon Prieto del Prado
// E58

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>

struct datosEntrada {
	std::vector<int> precipitacionAbrigos;
	std::vector<int> probPrecipitacion;
};

struct solucion {
	std::vector<int> sol;
	int numSoluciones = 0;
};

struct marcas {
	std::vector<int> marcasAbrigos;
	int posMaxAbrigo = 0;
};

// Tiene un coste de O(1) -> Coste constante
bool esValida(int etapa, int i, datosEntrada const& d, solucion const& s, marcas const& m) {
	return !(d.precipitacionAbrigos[i] < d.probPrecipitacion[etapa]) &&
		!(etapa > 0 && (s.sol[etapa] == s.sol[etapa - 1])) &&
		!(m.marcasAbrigos[m.posMaxAbrigo] > etapa / 3 + 2);
}

// función que resuelve el problema
void resolver(datosEntrada const& d, solucion & solucion, marcas & m, int etapa) {
	for (int i = 0; i < d.precipitacionAbrigos.size(); i++) {
		solucion.sol[etapa] = i;
		++m.marcasAbrigos[i]; // marcamos
		int posMax = m.posMaxAbrigo;
		if (m.marcasAbrigos[m.posMaxAbrigo] < m.marcasAbrigos[i]) {
			m.posMaxAbrigo = i;
		}
		if (esValida(etapa, i, d, solucion, m)) {
			if (etapa == d.probPrecipitacion.size() - 1) {
				if (solucion.sol[0] != solucion.sol[etapa])
					++solucion.numSoluciones;
			}
			else 
				resolver(d, solucion, m, etapa + 1);
		}
		--m.marcasAbrigos[i]; // desmarcamos
		m.posMaxAbrigo = posMax;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int dias, abrigos;
	std::cin >> dias >> abrigos;
	if (dias == 0 && abrigos == 0) 
		return false;

	datosEntrada d;
	d.probPrecipitacion.resize(dias);
	d.precipitacionAbrigos.resize(abrigos);

	for (int i = 0; i < d.probPrecipitacion.size(); i++) {
		std::cin >> d.probPrecipitacion[i];
	} 
	
	for (int i = 0; i < d.precipitacionAbrigos.size(); i++) {
		std::cin >> d.precipitacionAbrigos[i];
	}

	int etapa = 0;
	solucion solucion;
	marcas m;
	solucion.sol.resize(dias);
	m.marcasAbrigos.resize(abrigos);
	resolver(d, solucion, m, etapa);

	// Imprimo solucion
	if (solucion.numSoluciones == 0) 
		std::cout << "Lo puedes comprar \n";
	else 
		std::cout << solucion.numSoluciones << '\n';

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