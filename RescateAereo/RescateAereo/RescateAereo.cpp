// Jose Ramon Prieto del Prado
// E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct sol {
	int ini = 0;
	int fin = 0;
};

// función que resuelve el problema
// El coste del algoritmo es lineal -> O(n) = > 1 + n * (peor caso dentro del bucle(1+1+1+1+1+1)) = 1 + 6n = > O(n)
void resolver(std::vector<int> const& datos, const int & altura, sol &sol) {
	int contMejor = 0, contActual = 0; // O(1)
	for (int i = 0; i < (int) datos.size(); i++) { // n veces siendo n el tamaño del vector datos
		if (datos[i] > altura) { // O(1)
			contActual++; // O(1)
			if (contActual > contMejor) { // O(1)
				contMejor = contActual; // O(1)
				sol.ini = i - contMejor + 1; // O(1)
				sol.fin = i; // O(1)
			}
		}
		else contActual = 0; // O(1)
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numEdificios;
	int altura;
	sol s;
	std::cin >> numEdificios >> altura;

	std::vector<int> datos(numEdificios);

	for (int i = 0; i < numEdificios; i++) std::cin >> datos[i];

	resolver(datos, altura, s);

	std::cout << s.ini << " " << s.fin << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}