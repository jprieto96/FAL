// Jose Ramon Prieto del Prado
// E58

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>

struct cancion {
	int duracion, satisfaccion;
};

struct datosEntrada {
	int numCanciones, t1, t2;
	std::vector <std::pair <int, int >> cancion;
};

struct sol {
	std::vector<int> solucion;
};

// función que resuelve el problema
// 0 -> No reproducir cancion
// 1 -> Reproducir cancion en el trayecto de ida
// 2 -> Reproducir cancion en el trayecto de vuelta
void VA(datosEntrada const& datos, sol& sol, int k, int& duracionIda, int& duracionVuelta, int& satisActual, int& satisMejor) {
	// trayecto de ida
	sol.solucion[k] = 1;
	duracionIda += datos.cancion[k].first;
	satisActual += datos.cancion[k].second;
	if (duracionIda <= datos.t1) {
		if (k == datos.numCanciones - 1) { 
			if (duracionIda == datos.t1 && duracionVuelta == datos.t2 && satisActual > satisMejor)
				satisMejor = satisActual;
		}
		else {
			VA(datos, sol, k + 1, duracionIda, duracionVuelta, satisActual, satisMejor);
		}
	}
	duracionIda-= datos.cancion[k].first;
	satisActual -= datos.cancion[k].second;

	// trayecto de vuelta
	sol.solucion[k] = 2;
	duracionVuelta += datos.cancion[k].first;
	satisActual += datos.cancion[k].second;
	if (duracionVuelta <= datos.t2) {
		if (k == datos.numCanciones - 1) {
			if (duracionIda == datos.t1 && duracionVuelta == datos.t2 && satisActual > satisMejor)
				satisMejor = satisActual;
		}
		else {
			VA(datos, sol, k + 1, duracionIda, duracionVuelta, satisActual, satisMejor);
		}
	}
	duracionVuelta -= datos.cancion[k].first;
	satisActual -= datos.cancion[k].second;

	// no reproducir
	sol.solucion[k] = 0;
	// No hay condiciones porque no reproducimos la cancion
	if (k == datos.numCanciones - 1) {
		if (duracionIda == datos.t1 && duracionVuelta == datos.t2 && satisActual > satisMejor)
			satisMejor = satisActual;
	}
	else {
		VA(datos, sol, k + 1, duracionIda, duracionVuelta, satisActual, satisMejor);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	datosEntrada datos;
	sol sol;
	std::cin >> datos.numCanciones >> datos.t1 >> datos.t2;
	if (datos.numCanciones == 0)
		return false;

	datos.cancion.resize(datos.numCanciones);
	sol.solucion.resize(datos.numCanciones);

	 // Recoger duracion y satisfaccion de cada cancion
	for (int i = 0; i < datos.numCanciones; i++) {
		std::cin >> datos.cancion[i].first >> datos.cancion[i].second;
	}

	int duracionIda = 0;
	int duracionVuelta = 0;
	int satisActual = 0;
	int satisMejor = -1;

	VA(datos, sol, 0, duracionIda, duracionVuelta, satisActual, satisMejor);
	if (satisMejor != -1) std::cout << satisMejor << "\n";
	else std::cout << "IMPOSIBLE" << "\n";
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