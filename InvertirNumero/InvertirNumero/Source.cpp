// Jose Ramon Prieto del Prado y Santiago Gabriel y Galan
// E58 y E24


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// Coste de la funcion -> O(log n) n numero de elementos
/*
		{ c0 si n < 10
T(n) =	{
		{ T(n/10) + c1 si n >= 10

		T(n) = T(n/10) + c1 = T(n/10^2) + 2c1 = .......... = T(n/10^k) + Kc1 = ... = T(1) + logn*c1 pertenece a O(log n)
		10^k = n => k = log n

*/

struct datos {
	int inverso;
	int potencia;
};

datos invertirNumero(int n) {
	if (n < 10)
		return { n, 10 };
	else {
		datos s = invertirNumero(n / 10);
		return { s.inverso + ((n % 10) * s.potencia), 10 * s.potencia };
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

	std::cout << invertirNumero(num).inverso << "\n";
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