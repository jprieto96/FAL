//
// 
//
//

//*****************
// IMPORTANTE
// Jose Ramon Prieto del Prado
// E58
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>


//*******************************
// Aqui especificación de la función que resuelve el problema. 
//	
//	P: { v.size() > 0 }  vector de entrada = V
//
//	consecutivos(secuencia,ini, fin) = { paratodo k : ini<=k<=fin : secuencia[k] + 1 == secuencia[k + 1] }
//	secuenciaMax(secuencia,longitud) = { secuencia.size() == longitud }
//	
//	Q: {
//		longitud > 0 && ini <= V.size() - 1 && ini >= 0
//	}
//
// Aqui el invariante.
//
// 
//
//
// Aqui la justificación del coste de la función que resuelve el problema
//
//	El coste del algoritmo es lineal -> O(n) ya que la primera instruccion es de coste constante y luego
//	tenemos un bucle que se repite n veces siendo n el tamaño del vector v, en el que todo lo lo que hay dentro
//  es de coste constante por lo que -> O(1) + O(n) * O(1) = O(n)
// 
//*******************************


// Aqui la función implementada por el alumno
// 
void resolver(std::vector<int>const& v, int & iniIntervalo, int & longitudIntervalo) {
	int longActual = 1, contMejor = 1; // O(1)
	for (int i = 1; i < (int) v.size(); i++) { // n veces siendo n v.size()
		if (v[i - 1] + 1 == v[i]) longActual++; // O(1)
		else longActual = 1; // O(1)
		if (longActual > contMejor) { contMejor = longActual; iniIntervalo = i - contMejor + 1; longitudIntervalo = contMejor; } // O(1)
	}
}


bool resuelveCaso() {
	int numDatos, iniIntervalo = 0, longitudIntervalo = 1;
	std::cin >> numDatos;
	if (numDatos == 0) return false;
	std::vector<int> v(numDatos);
	for (int i = 0; i < numDatos; ++i) std::cin >> v[i];

	// LLamada a la funcion que resuelve el problema
	resolver(v, iniIntervalo, longitudIntervalo);

	// Escribir el resultado
	std::cout << iniIntervalo << " " << longitudIntervalo << "\n";

	return true;
}


int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// Para restablecer entrada. 
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}