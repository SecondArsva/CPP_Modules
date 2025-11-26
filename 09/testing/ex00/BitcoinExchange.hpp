#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void loadDatabase(const std::string &csvPath);
		void processInputFile(const std::string &inputPath) const;

	private:
		typedef std::map<std::string, double> PriceDB;
		PriceDB _db;

		static std::string trim(const std::string &s);
		static bool parseDate(const std::string &s, int &y, int &m, int &d);
		static bool isLeap(int y);
		static bool validDate(int y, int m, int d);
		static bool parseNumber(const std::string &s, double &out);
		bool getPriceForDateOrLower(const std::string &date, double &price) const;
		static bool splitInputLine(const std::string &line, std::string &date, std::string &value);
};

#endif
