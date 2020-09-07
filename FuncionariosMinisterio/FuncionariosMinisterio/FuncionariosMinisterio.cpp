// Jose Ramon Prieto del Prado
// E58

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>

struct datosEntrada {
	std::vector<std::vector<int>> tiempos;
	int numFuncionarios, numTareas;
};

struct sol {
	std::vector<int> solucion;
	int sumaTiempos = 0;
};

// función que resuelve el problema
void calcularSolMejor(datosEntrada const& datos, sol & sol, int k, std::vector<bool> & marcas, int & solMejor, std::vector<int> & acum) {
	for (int i = 0; i < datos.numTareas; i++) {
		sol.solucion[k] = i;
		sol.sumaTiempos += datos.tiempos[k][i];
		if (!marcas[i]) { //esValida
			marcas[i] = true; // marcado
			if (k == datos.numFuncionarios - 1) { // esSolucion
				if (sol.sumaTiempos < solMejor) solMejor = sol.sumaTiempos; // solucion Mejor (la suma de tiempos minima de cada funcionario)
			}
			else { // noEsSolucion
				if(sol.sumaTiempos + acum[k + 1] < solMejor) // estimacion
					calcularSolMejor(datos, sol, k + 1, marcas, solMejor, acum);
			}
			marcas[i] = false; // desmarcado
		}
		sol.sumaTiempos -= datos.tiempos[k][i];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	datosEntrada datos;
	sol sol;
	int aux = 0;
	int solMejor = 0;
	std::cin >> datos.numFuncionarios;
	if (datos.numFuncionarios == 0)
		return false;
	datos.numTareas = datos.numFuncionarios;
	sol.solucion.resize(datos.numFuncionarios);
	datos.tiempos.resize(datos.numFuncionarios);
	std::vector<bool> marcas(datos.numFuncionarios);

	for (int i = 0; i < datos.numFuncionarios; i++) {
		for (int j = 0; j < datos.numTareas; j++) {
			std::cin >> aux;
			datos.tiempos[i].push_back(aux);
		}
	}

	// vector de minimos en el que meto en acum el minimo de tiempo de cada funcionario
	std::vector<int> acum(datos.numFuncionarios);
	for (int i = 0; i < datos.numFuncionarios; i++){
		int auxMin = datos.tiempos[i][0];
		for (int j = 1; j < datos.numTareas; j++){
			if (auxMin > datos.tiempos[i][j]) auxMin = datos.tiempos[i][j];
		}
		acum[i] = auxMin;
	}

	// Vector acumulados
	for (int i = (int)acum.size() - 1; i > 0; --i) {
		acum[i - 1] += acum[i];
	}

	// Calculo una de las posibles soluciones
	for (int i = 0; i < datos.numTareas; i++) {
		solMejor += datos.tiempos[i][i];
	}

	int k = 0;
	calcularSolMejor(datos, sol, k, marcas, solMejor, acum);
	std::cout << solMejor << "\n";
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