// Jose Ramón Prieto del Prado y Santiago Gabriel y Galán Puelles
// E58 y E24


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct sol {
	int cont;
	bool sePresenta;
};

// función que resuelve el problema
// Tiene un coste de O(n) -> n número de elementos
/*
		{c0 si n == 2
T(n) =	{
		{2T(n/2) + c1

		Haciendo el despliegue nos da orden de complejidad n
*/
sol numPartidosJugados(std::vector<std::string> const& v, int ini, int fin, int rondaLimitada, int & rondaActual) {
	rondaActual = 1;
	if (ini + 2 == fin) { // Caso base con dos elementos
		if (v[ini] == "NP" && v[ini + 1] == "NP")
			return { 0 , false };
		else if (v[ini] == "NP" || v[ini + 1] == "NP")
			return { 0 , true };
		else
			return { 1, true };
	}
	else { // Mas de dos elemntos
		int mitad = (ini + fin) / 2;
		sol izq = numPartidosJugados(v, ini, mitad, rondaLimitada, rondaActual);
		sol drcha = numPartidosJugados(v, mitad, fin, rondaLimitada, rondaActual);

		if ((rondaActual < rondaLimitada) && izq.sePresenta && drcha.sePresenta) {
			rondaActual++;
			return { izq.cont + drcha.cont + 1, true };
		}
		else if (izq.sePresenta || drcha.sePresenta) {
			rondaActual++;
			return { izq.cont + drcha.cont, true };
		}
		else {
			rondaActual++;
			return { izq.cont + drcha.cont, false  };
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, rondaLimitada, rondaActual;
	std::cin >> n >> rondaLimitada;
	if (!std::cin)
		return false;
	std::vector<std::string> v(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	sol solucion = numPartidosJugados(v, 0, n, rondaLimitada, rondaActual);
	std::cout << solucion.cont << "\n";

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




