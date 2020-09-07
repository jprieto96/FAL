// Jose Ramon Prieto del Prado
// E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct datos {
	bool correcto;
	int num1, num2;
};

// función que resuelve el problema
// Coste de la funcion -> O(log n) n numero de elementos
/*
		{ c0 si n == 1
T(n) =	{
		{ T(n/2) + c1 si n > 1

		T(n) = T(n/2) + c1 = T(n/2^2) + 2c1 = .......... = T(n/2^k) + Kc1 = ... = T(1) + logn*c1 pertenece a O(log n)
		2^k = n => k = log n

*/
datos resolver(std::vector<int> const& v1, std::vector<int> const& v2, int ini, int fin) {
	if (ini + 1 == fin) {
		if (v1[ini] > v2[ini]) return { false, ini - 1, ini };
		else if (v1[ini] < v2[ini])  return { false, ini, ini + 1 };
		else return { true, ini, ini };
	}
	else {
		int mitad = (ini + fin) / 2;
		if (v1[mitad] > v2[mitad]) return resolver(v1, v2, ini, mitad);
		else if (v1[mitad] < v2[mitad]) return resolver(v1, v2, mitad, fin);
		else return { true, mitad, mitad };
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num;
	std::cin >> num;
	if (num == 0)
		return false;

	std::vector<int> v1(num);
	std::vector<int> v2(num);

	for (int i = 0; i < num; ++i) {
		std::cin >> v1[i];
	}

	for (int i = 0; i < num; ++i) {
		std::cin >> v2[i];
	}

	datos sol = resolver(v1, v2, 0, num);

	if(sol.correcto) std::cout << "SI " << sol.num1 << "\n";
	else std::cout << "NO " << sol.num1 << " " << sol.num2 << "\n";
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