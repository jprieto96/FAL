// Jose Ramon Prieto del Prado
// E58

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>

struct datosEntrada {
	std::vector<std::string> tipoJuguete;
	std::vector<std::vector<int>> satisfaccion;
	int m, n, minSatisfaccion;
};

struct sol {
	std::vector<int> solucion;
	bool valida;
};

void escribirSol(sol& sol) {
	for (int i : sol.solucion) std::cout << i << " ";
	std :: cout << '\n';
	sol.valida = true;
}

// Tiene un coste de O(1) -> Coste constante
bool esValida(int k, datosEntrada const& d, sol& sol, std::vector<int>& juguetesDisponibles) {
	// comprobar que cuando este dando el segundo juguete no sea del mismo tipo que el primero
	if (k % 2 == 1 && d.tipoJuguete[sol.solucion[k]] == d.tipoJuguete[sol.solucion[k - 1]]) return false;
	// comprobar el primer juguete que se le da al niño es el de menor identificador
	if (k % 2 == 1 && sol.solucion[k] < sol.solucion[k - 1]) return false;
	// comprobar que queden juguetes de ese tipo disponibles
	if (juguetesDisponibles[sol.solucion[k]] < 0) return false;
	// comprobar que los niños lleguen al minimo de satisfaccion establecido
	if (k % 2 == 1 && (d.satisfaccion[k/2][sol.solucion[k - 1]] + d.satisfaccion[k / 2][sol.solucion[k]]) < d.minSatisfaccion) return false;

	return true;
}

// función que resuelve el problema
void repartirRegalos(datosEntrada const& datos, sol& sol, std::vector<int>& juguetesDisponibles, int k) {
	for (int i = 0; i < datos.m; i++) {
		sol.solucion[k] = i;
		juguetesDisponibles[i]--;
		if (esValida(k, datos, sol, juguetesDisponibles)) {
			if (k == (2 * datos.n) - 1) {
				escribirSol(sol);
			}
			else
				repartirRegalos(datos, sol, juguetesDisponibles, k + 1);
		}
		juguetesDisponibles[i]++;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	datosEntrada datos;
	sol sol;
	int aux;
	std::cin >> datos.m >> datos.n >> datos.minSatisfaccion;
	if (!std::cin)
		return false;

	datos.tipoJuguete.resize(datos.m);
	std::vector<int> juguetesDisponibles(datos.m);
	datos.satisfaccion.resize(datos.n);

	for (int i = 0; i < datos.m; i++) {
		std::cin >> juguetesDisponibles[i];
	}

	for (int i = 0; i < datos.m; i++) {
		std::cin >> datos.tipoJuguete[i];
	}

	for (int i = 0; i < datos.n; i++) {
		for (int j = 0; j < datos.m; j++) {
			std::cin >> aux;
			datos.satisfaccion[i].push_back(aux);
		}
	}

	int k = 0;
	sol.solucion.resize(2 * datos.n);
	sol.valida = false;
	repartirRegalos(datos, sol, juguetesDisponibles, k);
	if(!sol.valida) std::cout << "SIN SOLUCION \n";
	std::cout << "\n";
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