// Jose Ramon Prieto del Prado
// E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct sol {
	int sumaMaxSubsecuencia = 0;
	int diaInicio = 0;
	int longSubsecuencia = 0;
};

// función que resuelve el problema
// Todas las operaciones pasan por un bucle que se repite n veces por lo que tiene coste O(n) y como lo que hay dentro del bucle es de coste O(1),
// podemos decir que el coste del problema es = > O(n) * O(1) = O(n) - El problema tiene un coste lineal
void resolver(std::vector<int> const& datos, sol & s) {
	int sumaActual = 0, contSecuencia = 0; // O(1)
	for (int i = 0; i < (int) datos.size(); i++) { // n veces siendo n datos.size()
		sumaActual += datos[i]; // O(1)
		contSecuencia++; // O(1)
		if (sumaActual <= datos[i]) { sumaActual = datos[i]; contSecuencia = 1; } // O(1)
		if (sumaActual > s.sumaMaxSubsecuencia) { // O(1)
			s.longSubsecuencia = contSecuencia; // O(1)
			s.diaInicio = i - s.longSubsecuencia + 1; // O(1)
			s.sumaMaxSubsecuencia = sumaActual; // O(1)
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int sizeVector;
	sol s;
	std::cin >> sizeVector;
	if (!std::cin) return false;
	std::vector<int> datos(sizeVector);
	for (int i = 0; i < sizeVector; i++) std::cin >> datos[i];
	s.sumaMaxSubsecuencia = - 1000000000;
	resolver(datos, s);
	std::cout << s.sumaMaxSubsecuencia << " " << s.diaInicio << " " << s.longSubsecuencia << "\n";
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

		while(resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}