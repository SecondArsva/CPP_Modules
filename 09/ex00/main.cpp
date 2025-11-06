// ex00/main.cpp
#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	try {
		BitcoinExchange btc;
		// Ruta de la DB oficial (ajústala a donde tengas el CSV del tarball)
		// Por ejemplo: "../cpp_09/cpp_09/data.csv" si llamas desde el repo raíz.
		// Para corregir sin líos, puedes copiar data.csv a ex00/ y usar "data.csv".
		btc.loadDatabase("data.csv");
		btc.processInputFile(argv[1]);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
