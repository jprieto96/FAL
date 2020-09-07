// Jose Ramon Prieto del Prado
// E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct datos {
	int numPartidos;
	std::vector<int> partidos;
};

struct sol {
	int maxPartidosGanados = 0, numVeces = 0, partidosDespuesRachaGanadora = 0;
};

/*
	P:{ datos.size() > 0 } datos -> D

		<int maxPartidosGanados, int numVeces, int partidosDespuesRachaGanadora> resolver(); int posIni
		positivos(v, k1, k2) : pt p : k1<=p<=k2 : v[p] > 0

	Q:{ pt k : posIni <= k < posIni + maxSeguidos : D[k] > 0 &&
		pt k1, k2 : 0 <= k1 <= k2 < D.size() && positivos(D, k1, k2) : k2 - k1 + 1 <= maxSeguidos }

*/

// función que resuelve el problema
// El coste del problema es de orden lineal 
// -> 1 + n * (max(coste de los que hay dentro del vector que es constante O(1) en cualquiera de los casos)) = > O(n)
void resolver(datos const& d, sol & sol) {
	int contActual = 0; // O(1)
	for (int i = 0; i < d.numPartidos; i++) { // n veces siendo n el numero de partidos
		if (d.partidos[i] > 0) { // O(1)
			contActual++; // O(1)
			if (contActual >= sol.maxPartidosGanados) { // O(1)
				if(contActual > sol.maxPartidosGanados) sol.numVeces = 0; // O(1)
				sol.numVeces++; // O(1)
				sol.partidosDespuesRachaGanadora = 0; // O(1)
				sol.maxPartidosGanados = contActual; // O(1)
			}
			else sol.partidosDespuesRachaGanadora++; // O(1)
		}
		else {
			contActual = 0; // O(1)
			sol.partidosDespuesRachaGanadora++; // O(1)
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	datos d;
	sol s;
	std::cin >> d.numPartidos;

	if (!std::cin) return false;

	d.partidos.resize(d.numPartidos);

	for (int i = 0; i < d.numPartidos; i++) std::cin >> d.partidos[i];

	resolver(d, s);

	std::cout << s.maxPartidosGanados << " " << s.numVeces << " " << s.partidosDespuesRachaGanadora << "\n";

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