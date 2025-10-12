#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange();
    ~BitcoinExchange();

    // Carga el CSV de historial de precios en un map (fecha -> precio).
    // Intenta primero "cpp_09/data.csv", luego "data.csv".
    void loadDatabase();

    // Procesa un archivo de entrada con líneas "YYYY-MM-DD | value"
    // e imprime los resultados/errores según el subject.
    void processInputFile(const std::string& filename) const;

private:
    std::map<std::string, double> _db; // fecha (YYYY-MM-DD) -> exchange_rate

    static std::string trim(const std::string& s);
    static bool isAllSpace(const std::string& s);

    // Validación de fecha (YYYY-MM-DD, mes/día correctos y años razonables)
    static bool isValidDateFormat(const std::string& date);
    static bool isLeap(int y);
    static bool isValidDateValues(int y, int m, int d);

    // Parseo de double seguro para C++98
    static bool parseDouble(const std::string& s, double& out);

    // Busca el precio: si la fecha no existe, usa la fecha inferior más cercana.
    // Devuelve true si pudo obtener un precio; false si no hay fecha <= date.
    bool getRateForDateOrLower(const std::string& date, double& rate) const;

    // Carga CSV desde ruta dada. Devuelve true si ha cargado algo.
    bool loadCSV(const std::string& path);

    // Helpers para imprimir errores del subject (en stdout, como el ejemplo)
    static void printBadInput(const std::string& line);
    static void printNotPositive();
    static void printTooLarge();
    static void printOpenFileError();
};

#endif
