// ex00/BitcoinExchange.cpp
#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

static bool is_all_space(const std::string& s) {
	for (size_t i = 0; i < s.size(); ++i) if (!std::isspace(static_cast<unsigned char>(s[i]))) return false;
	return true;
}

std::string BitcoinExchange::trim(const std::string& s) {
	if (s.empty()) return s;
	size_t i = 0, j = s.size();
	while (i < j && std::isspace(static_cast<unsigned char>(s[i]))) ++i;
	while (j > i && std::isspace(static_cast<unsigned char>(s[j-1]))) --j;
	return s.substr(i, j - i);
}

bool BitcoinExchange::isLeap(int y) {
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

bool BitcoinExchange::validDate(int y, int m, int d) {
	if (y < 0 || m < 1 || m > 12 || d < 1) return false;
	static const int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int maxd = mdays[m - 1];
	if (m == 2 && isLeap(y)) maxd = 29;
	return d <= maxd;
}

bool BitcoinExchange::parseDate(const std::string& s, int& y, int& m, int& d) {
	// Formato exacto YYYY-MM-DD
	if (s.size() != 10 || s[4] != '-' || s[7] != '-') return false;
	for (size_t i = 0; i < s.size(); ++i) {
		if (i == 4 || i == 7) continue;
		if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
	}
	std::istringstream ys(s.substr(0,4));
	std::istringstream ms(s.substr(5,2));
	std::istringstream ds(s.substr(8,2));
	if (!(ys >> y) || !(ms >> m) || !(ds >> d)) return false;
	return validDate(y, m, d);
}

bool BitcoinExchange::parseNumber(const std::string& s, double& out) {
	// Acepta enteros o floats positivos. Usa stringstream para validar consumiendo todo.
	std::string t = trim(s);
	if (t.empty()) return false;
	std::istringstream iss(t);
	iss >> out;
	if (iss.fail()) return false;
	// Asegurar que no queda basura
	char c;
	if (iss >> c) return false;
	return true;
}

bool BitcoinExchange::splitInputLine(const std::string& line, std::string& date, std::string& value) {
	// línea: "date | value"
	std::string raw = trim(line);
	if (raw.empty() || raw == "date | value") return false; // saltar cabecera u líneas vacías
	std::string::size_type p = raw.find('|');
	if (p == std::string::npos) return false;
	date  = trim(raw.substr(0, p));
	value = trim(raw.substr(p + 1));
	// El separador debe ser " | " (toleramos múltiples espacios)
	// Ya hemos hecho trim; comprobamos que hay algo en ambos lados
	if (date.empty() || value.empty()) return false;
	return true;
}

void BitcoinExchange::loadDatabase(const std::string& csvPath) {
	std::ifstream fin(csvPath.c_str());
	if (!fin) {
		throw std::runtime_error("Error: could not open database.");
	}
	std::string line;
	// Esperamos cabecera: "date,exchange_rate"
	if (!std::getline(fin, line)) {
		throw std::runtime_error("Error: empty database.");
	}
	// Procesar filas
	while (std::getline(fin, line)) {
		if (is_all_space(line)) continue;
		std::string t = trim(line);
		std::string::size_type c = t.find(',');
		if (c == std::string::npos) continue; // ignorar malformadas
		std::string d = trim(t.substr(0, c));
		std::string p = trim(t.substr(c + 1));
		int yy, mm, dd;
		if (!parseDate(d, yy, mm, dd)) continue; // ignorar fechas inválidas en DB
		double price;
		if (!parseNumber(p, price)) continue; // ignorar precios inválidos en DB
		_db[d] = price;
	}
	if (_db.empty()) {
		throw std::runtime_error("Error: database has no valid rows.");
	}
}

bool BitcoinExchange::getPriceForDateOrLower(const std::string& date, double& price) const {
	PriceDB::const_iterator it = _db.lower_bound(date);
	if (it != _db.end() && it->first == date) {
		price = it->second;
		return true;
	}
	if (it == _db.begin()) {
		// no hay fecha inferior
		return false;
	}
	--it; // fecha inmediatamente inferior
	price = it->second;
	return true;
}

void BitcoinExchange::processInputFile(const std::string& inputPath) const {
	std::ifstream fin(inputPath.c_str());
	if (!fin) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	std::string line;
	while (std::getline(fin, line)) {
		if (is_all_space(line)) continue;
		std::string date, valueStr;
		if (!splitInputLine(line, date, valueStr)) {
			// Si es exactamente la cabecera estándar, la saltamos silenciosamente.
			if (trim(line) == "date | value") continue;
			std::cerr << "Error: bad input => " << trim(line) << std::endl;
			continue;
		}
		// Validar fecha
		int y,m,d;
		if (!parseDate(date, y, m, d)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		// Validar número
		double amount;
		if (!parseNumber(valueStr, amount)) {
			std::cerr << "Error: bad input => " << date << " | " << valueStr << std::endl;
			continue;
		}
		if (amount < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (amount > 1000.0) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		// Buscar precio (fecha exacta o inferior)
		double price;
		if (!getPriceForDateOrLower(date, price)) {
			// Fecha válida pero anterior al primer registro en DB
			std::cerr << "Error: no price available for " << date << std::endl;
			continue;
		}
		// Calcular y mostrar
		double result = amount * price;
		// Mantener formato del subject
		std::cout << date << " => " << amount << " = " << result << std::endl;
	}
}
