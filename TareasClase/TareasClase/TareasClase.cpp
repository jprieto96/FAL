// Jose Ramon Prieto del Prado
// E58

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>

struct datosEntrada {
	int alumnos, tareas, maximoTareas;
};

struct marcas {
	std::vector<int> tareasAsignadas;
	std::vector<std::vector<int>> preferencias;
};

void escribirSol(std::vector<int> const& sol) {
	for (int s : sol) std::cout << s << " ";
	std::cout << "\n";
}

// Tiene un coste de O(1) -> Coste constante
bool esValida(std::vector<int>& sol, int k, marcas& m, datosEntrada const& d) {
	// comprobar que un alumno no realice mas de t tareas
	if (m.tareasAsignadas[sol[k]] > d.maximoTareas) return false;
	// comprobar que no haga dos veces la misma tarea
	if (k % 2 != 0 && sol[k] == sol[k - 1]) return false;

	return true;
}

// función que resuelve el problema
void VA(datosEntrada const& d, marcas& m, std::vector<int>& sol, int k, int & solMejor, int & sumaPreferencias) {
	for (int i = 0; i < d.alumnos; i++) {
		sol[k] = i;
		m.tareasAsignadas[i]++;
		sumaPreferencias += m.preferencias[i][k/2];
		if (esValida(sol, k, m, d)) {
			if (k == (2 * d.tareas) - 1) {
				if (sumaPreferencias > solMejor) solMejor = sumaPreferencias;
			}
			else {
				VA(d, m, sol, k + 1, solMejor, sumaPreferencias);
			}
		}
		m.tareasAsignadas[i]--;
		sumaPreferencias -= m.preferencias[i][k/2];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	datosEntrada datos;
	marcas m;
	int aux;
	std::cin >> datos.tareas >> datos.alumnos >> datos.maximoTareas;
	if (datos.tareas == 0)
		return false;

	m.preferencias.resize(datos.alumnos);
	m.tareasAsignadas.resize(datos.alumnos);

	for (int i = 0; i < datos.alumnos; i++) {
		for (int j = 0; j < datos.tareas; j++) {
			std::cin >> aux;
			m.preferencias[i].push_back(aux);
		}
	}

	int k = 0;
	int solMejor = -1;
	int sumaPreferencias = 0;

	std::vector<int> sol(2 * datos.tareas);

	VA(datos, m, sol, k, solMejor, sumaPreferencias);

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