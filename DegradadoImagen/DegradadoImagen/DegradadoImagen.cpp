// Jose Ramon Prieto y Santiago Gabriel y Galan
// E58 y E24


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol {
	bool ok;
	int suma;
};

// Funcion que resuelve el problema
// Coste de O(n) siendo n el numero de elementos del vector
tSol esUnDegradado(std::vector <int> const& v, int ini, int fin) {
	if (ini + 1 == fin)
		return {true, v[ini]}; // Un elemento
	else { // 2 o mas elementos
		int mitad = (ini + fin) / 2;
		tSol sumaIzq = esUnDegradado(v, ini, mitad);
		tSol sumaDrcha = esUnDegradado(v, mitad, fin);
		return {sumaIzq.ok && sumaDrcha.ok && sumaIzq.suma < sumaDrcha.suma, sumaIzq.suma + sumaDrcha.suma};
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	bool correcto = true;
	int n, aux;
	std::cin >> n;
	if (!std::cin)
		return false;
	int m;
	std::cin >> m;
	std::vector<std::vector<int>> v(n);

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> aux;
			v[i].push_back(aux);
		}
		if (!esUnDegradado(v[i], 0, v[i].size()).ok) // Si cualquier fila de la matriz no es un degradado, ya la matriz no es un degradado.
			correcto = false;
	}

	if (correcto)
		std::cout << "SI\n";
	else
		std::cout << "NO\n";
	
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}