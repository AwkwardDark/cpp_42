#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <exception>

# define RED     "\033[31m"
# define RESET   "\033[0m"

class	BitcoinExchange
{
	private:
		std::string							_inFile; // (input.txt for ex)
		std::ifstream						_sInfile; // to open the infile
		std::map<std::string, std::string>	_database; // data.csv
		void	parseDB(void);
		void	parseInfile(void);

	public:
		BitcoinExchange(void);
		BitcoinExchange(std::string inFile);
		~BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &src);
		// Parsing
		void	checkDB(void);
		int		is_digit(std::string str);
		int		check_calendar(std::string year, std::string month, std::string day);
		int		check_float(std::string value);
		void	check_find_input(std::string input);
		float	calculate_exchange(std::string date, std::string value);

};

#endif
