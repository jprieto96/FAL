// Jose Ramon Prieto del Prado
// E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct sol {
	int vagonIniAsalto = 0;
	int gananciaObtenida = 0;
};

struct datos {
	int numVagones;
	int numVagonesParaAtracar;
	std::vector<int> vagones;
};

// función que resuelve el problema
// El coste del algoritmo es lineal -> O(n) = > n + n = 2n => O(n)
void resolver(datos const& d, sol& sol) {
	int gananciaActual = 0; // O(1)
	// Cuento la ganancia del primer intervalo
	for (int i = 0; i < d.numVagonesParaAtracar; i++) { // n veces siendo n el intervalo
		gananciaActual += d.vagones[i];  // O(1)
	}
	// asigno la ganancia actual del primer intervalo a la mejor Obtenida
	sol.gananciaObtenida = gananciaActual; // O(1)
	// asigno la pos0 ya que seria el inicio si el primer intervalo es el correcto
	sol.vagonIniAsalto = 0; // O(1)
	for (int i = d.numVagonesParaAtracar; i < (int) d.vagones.size(); i++) { // n veces siendo n el resto del vector que no es el intervalo
		// resto de la gananciaActual  el valor de la izquierda del intervalo y sumo el de la derecha al lado del intervalo
		gananciaActual = gananciaActual - d.vagones[i - d.numVagonesParaAtracar] + d.vagones[i]; // O(1)
		if (gananciaActual >= sol.gananciaObtenida) { // O(1)
			sol.gananciaObtenida = gananciaActual; // O(1)
			// el inicio del intervalo es la posicion actual - numCifras del intervalo + 1
			sol.vagonIniAsalto = i - d.numVagonesParaAtracar + 1; // O(1)
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	datos d;
	sol s;
	std::cin >> d.numVagones >> d.numVagonesParaAtracar;
	d.vagones.resize(d.numVagones);
	for (int i = 0; i < d.numVagones; i++) std::cin >> d.vagones[i];
	resolver(d, s);
	std::cout << s.vagonIniAsalto << " " << s.gananciaObtenida << "\n";
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