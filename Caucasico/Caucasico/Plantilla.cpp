//*****************
// IMPORTANTE
//
// Miguel robledo blanco, Jose Ramon Prieto 
// E01
//
//***************************************************
#include <iostream>
#include <fstream>
#include <vector>

//*******************************
/* Dividimos el vector recursivamente siempre por la mitad(parte izquierda y parte derecha) y
cuando llega al caso base de un elemento comprueba si es par o no y si es par aumenta el contador en uno.
Cada vez que termina en el lado izquierdo y derecho suma ambos contadores */
// Complejidad O(n) n número de elementos

/*

			  {c1           si n=1
Recursividad: {
			  {2T(n/2) + c1 si n>=2


*/
//*******************
struct sol {
	bool ok;
	int cont;
};
// Aqui la funcion recursiva que resuelve el problema
sol caucasico(std::vector<int> const& v, int ini, int fin) {
	if (ini + 1 == fin) {
		int par = 0;
		if (v[ini] % 2 == 0)
			par++;
		return { true, par };
	}
	else {
		int mitad = (ini + fin) / 2;
		sol ladoIzq = caucasico(v, ini, mitad);
		sol ladodrcha = caucasico(v, mitad, fin);

		return { ladoIzq.ok && ladodrcha.ok && std::abs(ladoIzq.cont - ladodrcha.cont) <= 2, ladoIzq.cont + ladodrcha.cont };
	}
}


// Tratar cada caso
bool resuelveCaso() {
	// Lectura de los datos
	int num;
	std::cin >> num;
	if (num == 0) return false;
	std::vector<int> v(num);
	for (int i = 0; i < num; ++i) {
		std::cin >> v[i];
	}

	// resolver

	// Escribir los resultados
	if (caucasico(v, 0, v.size()).ok) std::cout << "SI" << '\n';
	else std::cout << "NO\n";
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
