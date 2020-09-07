// Jose Ramon Prieto del Prado
// E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/*
*	La funcion tiene coste lineal O(n) ya que todo lo que hay dentro del bucle es de orden constante O(1)
*	y como el bucle se repite n veces siendo n el tamaño del vector datos -> O(n) * O(1) = O(n)
*/
void buscaLlanos(std::vector<int> const& datos, const int& cantidadValoresIguales, std::vector<int> & sol,
	int & contSecuencias, int & secMasLarga) {
	int contActual = 1, max = datos[(int)datos.size() - 1]; // O(1)
	for (int i = (int)datos.size() - 1; i >= 0; i--) { // n veces siendo n el tamaño del vector datos
		if (i != 0 && datos[i] == datos[i - 1]) contActual++; // O(1)
		else {
			if (contActual >= cantidadValoresIguales && datos[i] >= max) { // O(1)
				if (contActual >= secMasLarga) { secMasLarga = contActual; contSecuencias++; sol.push_back(i + secMasLarga - 1); max = datos[i]; } // O(1)
			}
			else if (max < datos[i]) max = datos[i]; // O(1)
			contActual = 1; // O(1)
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numDatos, contSecuencias = 0, secMasLarga = 0;
	int cantidadValoresIguales;
	std::vector<int> sol;
	std::cin >> numDatos >> cantidadValoresIguales;

	if (!std::cin) return false;

	std::vector<int> datos(numDatos);

	for (int i = 0; i < numDatos; i++) std::cin >> datos[i];

	buscaLlanos(datos, cantidadValoresIguales, sol, contSecuencias, secMasLarga);

	std::cout << secMasLarga << " " << contSecuencias << " ";
	for (int i = 0; i < (int)sol.size(); i++) std::cout << sol[i] << " ";
	std::cout << "\n";
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