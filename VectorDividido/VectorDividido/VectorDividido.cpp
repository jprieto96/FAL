// Jose Ramon Prieto del Prado
// E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/*
	P:{ datos.size() > 0 }

		<bool cierto> resolver(vector <int> datos, int mitad);
		
	Q:{  }

*/

// función que resuelve el problema
// El coste del problema es de orden lineal -> 1 + 1 + 1 + n/2 * (1) + n/2 * (1) + 1 -> O(n)
bool resolver(std::vector<int> const& datos, int mitad) {
	if (mitad == (int) datos.size() - 1) return true; // O(1)
	int max = datos[0]; // O(1)
	int min = datos[mitad + 1]; // O(1)
	for (int i = 0; i <= mitad; i++) { // n/2 veces, considerando a n como el tamaño del vector datos
		if (max < datos[i]) max = datos[i]; // O(1)
	}
	for (int i = mitad + 1; i < (int)datos.size(); i++) { // n/2 veces, considerando a n como el tamaño del vector datos
		if (min > datos[i]) min = datos[i]; // O(1)
	}

	return max < min; // O(1)
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int sizeVector;
	int mitad;
	std::cin >> sizeVector >> mitad;

	std::vector<int> datos(sizeVector);

	for (int i = 0; i < sizeVector; i++) std::cin >> datos[i];

	if(resolver(datos, mitad)) std::cout << "SI\n";
	else std::cout << "NO\n";
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