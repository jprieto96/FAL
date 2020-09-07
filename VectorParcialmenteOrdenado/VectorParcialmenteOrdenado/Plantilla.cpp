// Jose Ramon Prieto del Prado y Santiago Gabriel y Galan
// E58 y E24

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol {
	bool correcto;
	int minimo;
	int maximo;
};

// función que resuelve el problema
// Tiene un coste de O(n) -> n número de elementos
tSol parcialmenteOrdenado(std::vector<int> const& v, int ini, int fin) {
	if (ini + 1 == fin) // Vector de un solo elemento
		return {true, v[ini], v[ini]};
	else {	//Vector de mas de 2 elementos;
		int mitad = (ini + fin) / 2;
		tSol izq = parcialmenteOrdenado(v, ini, mitad);
		tSol drcha = parcialmenteOrdenado(v, mitad, fin);

		return { izq.correcto && drcha.correcto && drcha.maximo >= izq.maximo && izq.minimo <= drcha.minimo, izq.minimo, drcha.maximo };
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num;
	std::cin >> num;

	if (num == 0)
		return false;

	std::vector<int> v;
	while (num != 0) {	// Mientras el numero no sea 0 lo guardamos en el vector
		v.push_back(num);
		std::cin >> num;
	}

	if (parcialmenteOrdenado(v, 0, v.size()).correcto)
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
