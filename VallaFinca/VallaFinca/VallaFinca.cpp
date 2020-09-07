// Jose Ramon Prieto del Prado
// E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

/*
*	La funcion tiene coste lineal O(n) ya que todo lo que hay dentro de los bucles es de orden constante O(1)
*	-> O(m) * O(1) + O(n) * O(1) = O(m) + O(n) = O(n)
*/
void resolver(std::vector<int> const& datos, const int & franjaComprada, int & iniIntervalo) {
	int sumaCerosActual = 0; // O(1)
	for (int i = 0; i < franjaComprada; i++) { // m veces siendo m la franjaComprada
		if (datos[i] == 0) sumaCerosActual = datos[i]; // O(1)
	}
	int sumaCerosMax = sumaCerosActual;
	for (int i = franjaComprada; i < datos.size(); i++) { // n veces siendo n datos.size() - franjaComprada
		if (datos[i - franjaComprada] == 0) sumaCerosActual--; // O(1)
		if (datos[i] == 0) sumaCerosActual++; // O(1)
		if (sumaCerosActual >= sumaCerosMax) { // O(1)
			sumaCerosActual = sumaCerosMax; // O(1)
			iniIntervalo = i - franjaComprada + 1; // O(1)
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numDatos, franjaComprada, iniIntervalo = 0;
	bool llamar = false;
	std::cin >> numDatos;

	if (numDatos == 0) return false;

	std::cin >> franjaComprada;

	std::vector<int> datos(numDatos);

	for (int i = 0; i < numDatos; i++) {
		std::cin >> datos[i];
		if (datos[i] == 0) llamar = true;
	}

	if(llamar) resolver(datos, franjaComprada, iniIntervalo);

	if (llamar) std::cout << iniIntervalo << "\n";
	else std::cout << "No hace falta\n";
	
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