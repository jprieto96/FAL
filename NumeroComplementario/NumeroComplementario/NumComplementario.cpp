// Jose Ramon Prieto del Prado
// E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct sol {
	int num;
	int potencia;
};


// Coste de la funcion -> O(log n) n numero de elementos
/*
		{ c0 si n < 10
T(n) =	{
		{ T(n/10) + c1 si n >= 10

		T(n) = T(n/10) + c1 = T(n/10^2) + 2c1 = .......... = T(n/10^k) + Kc1 = ... = T(1) + logn*c1 pertenece a O(log n)
		10^k = n => k = log n

*/
sol numComplementarioInvertido(int n) {
	if (n < 10) return { 9 - n, 10 };
	else {
		sol s = numComplementarioInvertido(n / 10);
		return { s.num + ((9 - (n % 10)) * s.potencia), 10 * s.potencia };
	}
}

// Coste de la funcion -> O(log n) n numero de elementos
/*
		{ c0 si n < 10
T(n) =	{
		{ T(n/10) + c1 si n >= 10

		T(n) = T(n/10) + c1 = T(n/10^2) + 2c1 = .......... = T(n/10^k) + Kc1 = ... = T(1) + logn*c1 pertenece a O(log n)
		10^k = n => k = log n

*/
int numComplementario(int n) {
	if (n < 10) return 9 - n;
	else return (numComplementario(n / 10) * 10) + (9 - (n % 10));
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;
	std::cout << numComplementario(n) << " " << numComplementarioInvertido(n).num << "\n";
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