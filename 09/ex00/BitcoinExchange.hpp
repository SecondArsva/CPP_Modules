// ex00/BitcoinExchange.hpp
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
	BitcoinExchange();
	~BitcoinExchange();

	// Carga la base de datos "date,price" (con cabecera)
	void loadDatabase(const std::string& csvPath);

	// Procesa el fichero de entrada "date | value" y escribe resultados/errores a stdout/stderr
	void processInputFile(const std::string& inputPath) const;

private:
	typedef std::map<std::string, double> PriceDB;
	PriceDB _db;

	static std::string trim(const std::string& s);
	static bool parseDate(const std::string& s, int& y, int& m, int& d);
	static bool isLeap(int y);
	static bool validDate(int y, int m, int d);
	static bool parseNumber(const std::string& s, double& out);

	// Devuelve true y price si hay fecha exacta o la fecha inferior más cercana.
	// Si no existe inferior, devuelve false.
	bool getPriceForDateOrLower(const std::string& date, double& price) const;

	// Valida línea "date | value". Devuelve false si formato incorrecto.
	static bool splitInputLine(const std::string& line, std::string& date, std::string& value);
};

#endif
