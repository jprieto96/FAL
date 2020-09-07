//
// 
//
//

//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno: Jose Ramon Prieto del Prado y Javier del Río lópez 
// Usuario del juez de clase: E58 y E60
// Usuario del juez de examen que has utilizado en la prueba de hoy: E21
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>


//*******************************
// Aqui especificación de la función que resuelve el problema. 
//	
//	P: { edificios.size()>0 && paratodo k1,k2 : 0<=k1<edificios.size() && 0<=k2<edificios.size() && k1!=k2 : edificios[k1].id != edificios[k2].id } 
//
//		vector<string> sol;
//
//	tieneVistas(v,i) = { paratodo p : 0<=p<i : v[p].altura < edificios[i].piso }
//	Q: {
//		sol-size() <= edificios.size()
//			&&
//		paratodo k : 0<=k<sol.edificios() && tieneVistas(edificios,k) : edificios[k].id in sol
//	}
//
// Aqui la justificación del coste de la función que resuelve el problema
//
//	Todas las operaciones dentro del bucle principal son de coste O(1) y el bucle se repite n veces (con n = número de edificios)
//		por lo que el coste es O(n) * O(1) = O(n)
// 
//*******************************

struct tDatos {
	std::string id;
	int altura;
	int piso;
};


// Aqui la función implementada por el alumno
// 
void resolver(std::vector<tDatos>const& edificios, std::vector<std::string>& sol) {
	int count = 0; // O(1)
	int maxi = -1; // O(1)
	for (int i = edificios.size() - 1; i >= 0; --i) { // n veces siendo n edificios.size()
		if (edificios[i].piso > maxi) { sol.push_back(edificios[i].id); ++count; }; // O(1)
		maxi = std::max(maxi, edificios[i].altura); // O(1)
	}

	sol.resize(count); //O(1) (aunque daría igual que fuese O(n), ya que O(n) + O(n) = O(2n) = O(n) )
}


bool resuelveCaso() {
	int numEdificios;
	std::cin >> numEdificios;
	if (numEdificios == 0) return false;
	std::vector<tDatos> edificios(numEdificios);
	for (int i = 0; i < numEdificios; ++i) {
		std::cin >> edificios[i].id >> edificios[i].altura >> edificios[i].piso;
	}
	std::vector<std::string> sol;

	// LLamada a la funcion que resuelve el problema

	resolver(edificios, sol);

	// Escribir el resultado

	if (sol.size() == 0)std::cout << "Ninguno\n";
	else {
		std::cout << sol.size() << '\n';
		for (int i = 0; i < sol.size(); ++i) std::cout << sol[i] << (i == sol.size() - 1 ? '\n' : ' ');
	}

	return true;
}


int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso())
		;

	// Para restablecer entrada. 
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}