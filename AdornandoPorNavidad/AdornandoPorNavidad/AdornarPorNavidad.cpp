// Jose Ramon Prieto del Prado
// E58

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>

struct producto {
	int coste, superficie;
}; 

struct datosEntrada {
	int numObjetos, presupuesto;
	std::vector <std::pair <int, int >> producto;
};

struct sol {
	std::vector<bool> solucion;
	std::vector<bool> solucionMejor;
};

// función que resuelve el problema
void VA(datosEntrada const& datos, sol& sol, int k, int& costeActual, int& supActual, int& superficieMejor, std::vector<int> & acum) {
	// añade el objeto
	sol.solucion[k] = true;
	costeActual += datos.producto[k].first;
	supActual += datos.producto[k].second;
	if (costeActual <= datos.presupuesto) {
		if (k == datos.numObjetos - 1) {
			if (supActual > superficieMejor) superficieMejor = supActual;
		}
		else {
			if(supActual + acum[k + 1] > superficieMejor) 
				VA(datos, sol, k + 1, costeActual, supActual, superficieMejor, acum);
		}
	}
	costeActual -= datos.producto[k].first;
	supActual -= datos.producto[k].second;

	// No añade el objeto
	sol.solucion[k] = false;
	// No hay condiciones porque no compramos el objeto
	if (k == datos.numObjetos - 1) {
		if (supActual > superficieMejor) superficieMejor = supActual;
	}
	else {
		VA(datos, sol, k + 1, costeActual, supActual, superficieMejor, acum);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	datosEntrada datos;
	sol sol;
	std::cin >> datos.numObjetos;
	if (!std::cin)
		return false;

	std::cin >> datos.presupuesto;
	datos.producto.resize(datos.numObjetos);
	sol.solucion.resize(datos.numObjetos);
	sol.solucionMejor.resize(datos.numObjetos);
	std::vector<int> acum(datos.numObjetos);

	for (int i = 0; i < datos.numObjetos; i++) {
		std::cin >> datos.producto[i].first >> datos.producto[i].second;
		acum[i] = datos.producto[i].second;
	}
	 // Calculo el vector de acumulados
	for (int i = datos.numObjetos - 1; i > 0; i--) {
		acum[i - 1] += acum[i];
	}

	int costeActual = 0;
	int supActual = 0;
	int superficieMejor = datos.producto[0].second;

	VA(datos, sol, 0, costeActual, supActual, superficieMejor, acum);

	std::cout << superficieMejor << "\n";
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