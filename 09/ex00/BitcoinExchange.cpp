#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib> // strtod
#include <climits>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

static bool splitOnce(const std::string& line, char sep, std::string& left, std::string& right) {
    std::string::size_type p = line.find(sep);
    if (p == std::string::npos) return false;
    left  = line.substr(0, p);
    right = line.substr(p + 1);
    return true;
}

std::string BitcoinExchange::trim(const std::string& s) {
    if (s.empty()) return s;
    std::string::size_type i = 0, j = s.size() - 1;
    while (i < s.size() && std::isspace(static_cast<unsigned char>(s[i]))) ++i;
    while (j != std::string::npos && std::isspace(static_cast<unsigned char>(s[j]))) {
        if (j == 0) break; // avoid wrap
        --j;
    }
    if (i > j) return "";
    return s.substr(i, j - i + 1);
}

bool BitcoinExchange::isAllSpace(const std::string& s) {
    for (std::string::size_type i = 0; i < s.size(); ++i)
        if (!std::isspace(static_cast<unsigned char>(s[i])))
            return false;
    return true;
}

bool BitcoinExchange::isLeap(int y) {
    return ( (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) );
}

bool BitcoinExchange::isValidDateValues(int y, int m, int d) {
    if (y < 1900 || y > 2100) return false; // rango razonable
    if (m < 1 || m > 12) return false;
    static const int daysInMonth[12] =
        {31,28,31,30,31,30,31,31,30,31,30,31};
    int dim = daysInMonth[m - 1];
    if (m == 2 && isLeap(y)) dim = 29;
    if (d < 1 || d > dim) return false;
    return true;
}

bool BitcoinExchange::isValidDateFormat(const std::string& date) {
    // Must be YYYY-MM-DD (length 10)
    if (date.size() != 10) return false;
    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) {
            if (date[i] != '-') return false;
        } else {
            if (!std::isdigit(static_cast<unsigned char>(date[i])))
                return false;
        }
    }
    int y = std::atoi(date.substr(0,4).c_str());
    int m = std::atoi(date.substr(5,2).c_str());
    int d = std::atoi(date.substr(8,2).c_str());
    return isValidDateValues(y,m,d);
}

bool BitcoinExchange::parseDouble(const std::string& s, double& out) {
    // C++98-friendly parsing using strtod; allow leading/trailing spaces already trimmed outside
    char* end = 0;
    const char* c = s.c_str();
    out = std::strtod(c, &end);
    if (end == c) return false;             // no conversion
    // Ensure the rest is only spaces
    while (*end) {
        if (!std::isspace(static_cast<unsigned char>(*end))) return false;
        ++end;
    }
    return true;
}

bool BitcoinExchange::loadCSV(const std::string& path) {
    std::ifstream in(path.c_str());
    if (!in) return false;

    std::string line;
    // Puede tener cabecera "date,exchange_rate"
    if (!std::getline(in, line)) return false;

    // Aceptamos cabecera o datos directos
    if (line.find("date") != std::string::npos && line.find("exchange_rate") != std::string::npos) {
        // OK, es cabecera: seguir leyendo
    } else {
        // Tal vez la primera línea ya es dato; procesarla
        std::string date = "", rateStr = line;
        std::string left, right;
        if (splitOnce(line, ',', left, right)) {
            date = trim(left);
            rateStr = trim(right);
            double rate;
            if (isValidDateFormat(date) && parseDouble(rateStr, rate)) {
                _db[date] = rate;
            }
        }
    }

    while (std::getline(in, line)) {
        if (isAllSpace(line)) continue;
        std::string left, right;
        if (!splitOnce(line, ',', left, right)) continue;
        std::string date = trim(left);
        std::string rateStr = trim(right);
        if (!isValidDateFormat(date)) continue;
        double rate;
        if (!parseDouble(rateStr, rate)) continue;
        _db[date] = rate;
    }
    return !_db.empty();
}

void BitcoinExchange::loadDatabase() {
    // Primero intentar dentro del paquete subido por ti
    if (loadCSV("cpp_09/data.csv")) return;
    // Luego en el cwd
    if (loadCSV("data.csv")) return;

    // Si aquí llegamos, no hay DB: lo dejamos vacío; el procesamiento avisará.
}

bool BitcoinExchange::getRateForDateOrLower(const std::string& date, double& rate) const {
    if (_db.empty()) return false;
    std::map<std::string,double>::const_iterator it = _db.lower_bound(date);
    if (it != _db.end() && it->first == date) {
        rate = it->second;
        return true;
    }
    if (it == _db.begin()) {
        // no hay fecha menor
        return false;
    }
    // ir al elemento anterior (fecha inferior más cercana)
    --it;
    rate = it->second;
    return true;
}

void BitcoinExchange::printBadInput(const std::string& line) {
    std::cout << "Error: bad input => " << line << std::endl;
}

void BitcoinExchange::printNotPositive() {
    std::cout << "Error: not a positive number." << std::endl;
}

void BitcoinExchange::printTooLarge() {
    std::cout << "Error: too large a number." << std::endl;
}

void BitcoinExchange::printOpenFileError() {
    std::cout << "Error: could not open file." << std::endl;
}

void BitcoinExchange::processInputFile(const std::string& filename) const {
    std::ifstream in(filename.c_str());
    if (!in) {
        printOpenFileError();
        return;
    }
    std::string line;
    // Cabecera opcional "date | value"
    if (std::getline(in, line)) {
        std::string hdr = trim(line);
        if (hdr != "date | value") {
            // No es cabecera clara; procesamos como dato también
            in.seekg(0); // volver al inicio
        }
    }

    while (std::getline(in, line)) {
        if (isAllSpace(line)) continue;

        // Intentar "date | value"
        std::string left, right;
        if (!splitOnce(line, '|', left, right)) {
            printBadInput(line);
            continue;
        }
        std::string date = trim(left);
        std::string valStr = trim(right);

        // Validar fecha
        if (!isValidDateFormat(date)) {
            printBadInput(line);
            continue;
        }

        // Validar número
        double value;
        if (!parseDouble(valStr, value)) {
            printBadInput(line);
            continue;
        }
        if (value < 0.0) {
            printNotPositive();
            continue;
        }
        if (value > 1000.0) {
            printTooLarge();
            continue;
        }

        // Obtener rate para fecha o inferior más cercana
        double rate;
        if (!getRateForDateOrLower(date, rate)) {
            // No hay fecha <= date en la DB
            printBadInput(line);
            continue;
        }

        // Calcular e imprimir
        // Mantener el valor como se leyó (string) en la salida, siguiendo el ejemplo
        double result = rate * value;
        std::cout << date << " => " << valStr << " = " << result << std::endl;
    }
}
