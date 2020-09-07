// Jose Ramon Prieto del Prado y Santiago Gabriel y Galan
// E58 y E24

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct sol {
	std::string nombre;
	int numCanicas;
};

// función que resuelve el problema
// Tiene un coste de O(n) -> n número de elementos
/*
		{c0 si n == 2
T(n) =	{
		{2T(n/2) + c1

		Haciendo el despliegue nos da orden de complejidad n
*/
sol ganadorJuegoDeCanicas(std::vector<sol> const& v, int ini, int fin) {
	if (ini + 2 == fin) // 2 elementos
		if (v[ini].numCanicas >= v[ini + 1].numCanicas)
			return { v[ini].nombre , v[ini].numCanicas + (v[ini + 1].numCanicas / 2) };
		else
			return { v[ini + 1].nombre , v[ini + 1].numCanicas + (v[ini].numCanicas / 2) };
	else {	// Mas de 2 elementos;
		int mitad = (ini + fin) / 2;
		sol izq = ganadorJuegoDeCanicas(v, ini, mitad);
		sol drcha = ganadorJuegoDeCanicas(v, mitad, fin);

		return { (izq.numCanicas >= drcha.numCanicas) ? izq.nombre : drcha.nombre , (izq.numCanicas >= drcha.numCanicas) ? izq.numCanicas + (drcha.numCanicas / 2) 
			: drcha.numCanicas + (izq.numCanicas / 2) };
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num;
	std::cin >> num;

	if (!std::cin)
		return false;

	std::vector<sol> v(num);
	for (int i = 0; i < v.size(); i++) {
		std::cin >> v[i].nombre >> v[i].numCanicas;
	}

	std::cout << ganadorJuegoDeCanicas(v, 0, v.size()).nombre << " " << ganadorJuegoDeCanicas(v, 0, v.size()).numCanicas << "\n";

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
