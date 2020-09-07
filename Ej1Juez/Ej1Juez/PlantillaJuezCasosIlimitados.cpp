// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// Funcion que resuelve el problema
// v. size () siempre es potencia de dos
bool sufDisperso(std::vector <int > const& v, int const& ini, int const& fin, int const& K) {
	if (ini + 1 == fin)
		return true; // Un elemento
	else { // Vector de 2 o mas elementos
		int m = (ini + fin) / 2;
		bool sIz = sufDisperso(v, ini, m, K);
		bool sDr = sufDisperso(v, m, fin, K);
		return sIz && sDr && K  std::abs(v[ini] - v[fin - 1]);
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
	int k;
	std::cin >> k;
	std::vector<int> v(num);
	for (int& n : v)
		std::cin >> v[n];
	if (sufDisperso(v, 0, num, k))
		std::cout << "SI\n";
	else
		std::cout << "NO\n";
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