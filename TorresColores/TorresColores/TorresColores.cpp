// Jose Ramon Prieto del Prado
// E58

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>

struct datosEntrada {
	int alturaTorre, azules, rojas, verdes;
	std::vector<std::string> colores;
};

struct marcas {
	bool torreValida;
	std::vector<int> piezasUsadas;
};

void escribirSol(std::vector<std::string> const& sol, marcas& m) {
	for (std::string s : sol) std::cout << s << " ";
	std::cout << "\n";
	m.torreValida = true;
}

// Tiene un coste de O(1) -> Coste constante
bool esValida(int k, datosEntrada const& d, marcas& m, std::vector<std::string>& sol) {
	// comprobar que no haya dos verdes seguidas
	if (k > 0 && sol[k] == "verde" && sol[k - 1] == "verde") return false;
	// comprobar siempre que el numero de verdes no supere al de azules
	if (m.piezasUsadas[2] > m.piezasUsadas[0]) return false; 
	// comprobar si te quedan piezas
	if ((sol[k] == "azul" && m.piezasUsadas[0] > d.azules) || 
		(sol[k] == "rojo" && m.piezasUsadas[1] > d.rojas) || 
		(sol[k] == "verde" && m.piezasUsadas[2] > d.verdes))
		return false;
	
	return true;
}

// función que resuelve el problema
void torreColores(datosEntrada const& d, marcas& m, std::vector<std::string> & sol, int k) {
	for (int i = 0; i < (int)d.colores.size(); i++) {
		sol[k] = d.colores[i];
		m.piezasUsadas[i]++;
		if (esValida(k, d, m, sol)) {
			if (k == d.alturaTorre - 1) {
				// comprobar que al final de la torre haya mas rojas que la suma de verdes y azules
				if (m.piezasUsadas[1] > (m.piezasUsadas[2] + m.piezasUsadas[0]))
					escribirSol(sol, m);
			}
			else
				torreColores(d, m, sol, k + 1);
		}
		m.piezasUsadas[i]--;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	datosEntrada datos; 
	marcas m;
	std::cin >> datos.alturaTorre;
	if (datos.alturaTorre == 0)
		return false;

	std::cin >> datos.azules >> datos.rojas >> datos.verdes;

	m.piezasUsadas.assign(3, 0);
	datos.colores.resize(3);
	m.torreValida = false;
	datos.colores[0] = "azul";
	datos.colores[1] = "rojo";
	datos.colores[2] = "verde";

	int k = 0;
	std::vector<std::string> sol(datos.alturaTorre);
	sol[0] = "rojo";
	m.piezasUsadas[1]++;

	if (k == datos.alturaTorre - 1)
		escribirSol(sol, m);

	else
		torreColores(datos, m, sol, k + 1);

	if (!m.torreValida) std::cout << "SIN SOLUCION \n";
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