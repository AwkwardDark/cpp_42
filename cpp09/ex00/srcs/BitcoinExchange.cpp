#include "BitcoinExchange.hpp"

// ==========================CANONICAL FORM==============================

BitcoinExchange::BitcoinExchange(void) : _inFile("input.txt")
{
	parseDB();
	_sInfile.open(_inFile.c_str(), std::ios::in);
	if (_sInfile.is_open())
		parseInfile();
	else
		throw std::runtime_error("Error: could not open input file.");
}

BitcoinExchange::BitcoinExchange(std::string inFile) : _inFile(inFile)
{
	parseDB();
	_sInfile.open(_inFile.c_str(), std::ios::in);
	if (_sInfile.is_open())
		parseInfile();
	else
		throw std::runtime_error("Error: could not open input file.");
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this != &src)
	{
		this->_inFile = src._inFile;
		this->_database = src._database;
	}
	return (*this);
}

// ===================PRIVATE METHODS (PARSING STRATEGY)===================

// Creates the map and then parse the pair of inputs (date and value)
void BitcoinExchange::parseDB(void)
{
	std::ifstream db;

	db.open("data.csv", std::ios::in);
	if (db.is_open())
	{
		std::string line;
		std::getline(db, line);
		if (line.compare("date,exchange_rate") != 0)
			throw std::runtime_error("Error: bad format for data.csv.");
		while (std::getline(db, line))
		{
			std::size_t sep = line.find(',');
			if (sep == std::string::npos)
				throw std::runtime_error("Error: bad input on data.csv.");
			_database.insert(std::pair<std::string, std::string>(line.substr(0, sep), line.substr(sep + 1))); // creating the map with date -> value
		}
		checkDB();
	}
	else
		throw std::runtime_error("Error: could not open data.csv.");
}

void BitcoinExchange::parseInfile(void)
{
	std::string line;
	std::getline(_sInfile, line);
	if (line.empty())
		throw std::runtime_error("Error: input file is empty.");
	if (line.compare("date | value"))
		throw std::runtime_error("Error: input file has the wrong header.");
	while (std::getline(_sInfile, line))
	{
		try
		{
			check_find_input(line);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
}

// =======================PUBLIC METHODS (PARSING)============================

void BitcoinExchange::checkDB(void)
{
	std::string day;
	std::string month;
	std::string year;
	std::size_t sep1;
	std::size_t sep2;

	if (_database.empty())
		throw std::runtime_error("Error: database is empty");
	for (std::map<std::string, std::string>::iterator it = _database.begin(); it != _database.end(); it++)
	{
		std::string date = it->first;
		std::string value = it->second;
		std::stringstream svalue;
		double fvalue;

		// Extract the 3 dates
		sep1 = date.find('-');
		if (sep1 == std::string::npos)
			throw std::runtime_error("Error: bad input => " + date);
		year = date.substr(0, sep1);
		sep2 = date.substr(sep1 + 1).find('-');
		if (sep2 == std::string::npos)
			throw std::runtime_error("Error: bad input => " + date);
		month = date.substr(sep1 + 1, sep2);
		day = date.substr(sep1 + sep2 + 2);

		// Check the format of each date
		if (day.length() != 2 || month.length() != 2 || !is_digit(year) || !is_digit(month) || !is_digit(day) || !check_calendar(year, month, day))
			throw std::runtime_error("Error: bad input => " + date);

		// Check the value associated to the date
		if (!check_float(value))
			throw std::runtime_error("Error: bad input => " + value);
		svalue << value;
		svalue >> fvalue;
		if (fvalue > 2147483647)
			throw std::runtime_error("Error: too big number (overflow) => " + value);
		if (fvalue < 0.0)
			throw std::runtime_error("Error: number is negative => " + value);
	}
}

void BitcoinExchange::check_find_input(std::string input)
{
	std::string date;
	std::string day;
	std::string month;
	std::string year;
	std::string value;
	std::stringstream svalue;
	float fvalue;
	std::size_t sep1;
	std::size_t sep2;
	std::size_t sep3;
	std::size_t pipe;

	pipe = input.find('|');
	if (pipe == std::string::npos)
		throw std::runtime_error("Error: bad input => " + input);
	date = input.substr(0, pipe);
	// Extract the 3 dates
	sep1 = date.find('-');
	if (sep1 == std::string::npos)
		throw std::runtime_error("Error: bad input => " + input);
	year = date.substr(0, sep1);
	sep2 = date.substr(sep1 + 1).find('-');
	if (sep2 == std::string::npos)
		throw std::runtime_error("Error: bad input => " + input);
	month = date.substr(sep1 + 1, sep2);
	sep3 = date.substr(sep1 + sep2 + 2).find(' ');
	if (sep3 == std::string::npos)
		throw std::runtime_error("Error: bad input => " + input);
	day = date.substr(sep1 + sep2 + 2, sep3);

	// Check the format of each date
	if (day.length() != 2 || month.length() != 2 || !is_digit(year) || !is_digit(month) || !is_digit(day) || !check_calendar(year, month, day))
		throw std::runtime_error("Error: bad input => " + input);

	// Checking the input value
	value = input.substr(pipe + 2);
	if (!check_float(value))
		throw std::runtime_error("Error: bad input, the value is not correct.");
	svalue << value;
	svalue >> fvalue;
	if (fvalue < 0)
		throw std::runtime_error("Error: number is negative.");
	if (fvalue > 1000)
		throw std::runtime_error("Error: number is bigger than 1000.");
	std::cout << year << "-" << month << "-" << day << " => " << value << " = " << calculate_exchange(date, value) << std::endl;
}

float BitcoinExchange::calculate_exchange(std::string date, std::string input_value)
{
	std::map<std::string, std::string>::iterator it = _database.begin();
	std::map<std::string, std::string>::iterator next;
	std::string exchange;
	std::stringstream sexchange;
	std::stringstream svalue;
	float finput_value;
	float fexchange;
	float result;

	if (date.compare(it->first) < 0)
		throw std::runtime_error("Error: no date on the database smaller than " + date);
	for (; it != _database.end(); it++)
	{
		if (!it->first.compare(date))
		{
			exchange = it->second;
			break;
		}
		next = it;
		next++;
		// checks that the value returned is always the date lower
		if (next == _database.end() || next->first > date)
		{
			exchange = it->second;
			break;
		}
	}

	svalue << input_value;
	svalue >> finput_value;
	sexchange << exchange;
	sexchange >> fexchange;
	result = fexchange * finput_value;

	return (result);
}

// ============================UTILS=================================

int BitcoinExchange::is_digit(std::string str)
{
	for (std::size_t i = 0; i < str.length(); i++)
	{
		if (str.at(i) < '0' || str.at(i) > '9')
			return (0);
	}
	return (1);
}

int BitcoinExchange::check_calendar(std::string year, std::string month, std::string day)
{
	std::stringstream syear;
	std::stringstream smonth;
	std::stringstream sday;
	int iyear;
	int imonth;
	int iday;

	syear << year;
	syear >> iyear;
	smonth << month;
	smonth >> imonth;
	sday << day;
	sday >> iday;

	if (iday == 0 || imonth == 0 || imonth > 12)
		return (0);
	// checking bisextil year
	if ((iyear % 4 == 0 && (iyear % 100 != 0 || iyear % 400 == 0)) && imonth == 2 && iday > 29)
		return (0);
	if (!(iyear % 4 == 0 && (iyear % 100 != 0 || iyear % 400 == 0)) && imonth == 2 && iday > 28)
		return (0);
	if ((imonth == 4 || imonth == 6 || imonth == 9 || imonth == 11) && iday > 30)
		return (0);
	else if (iday > 31)
		return (0);
	return (1);
}

int BitcoinExchange::check_float(std::string value)
{
	std::size_t i = 0;

	if (value.at(0) == '-')
		i++;
	for (; i < value.length(); i++)
	{
		if (value.at(i) == '.')
			break ;
		if (value.at(i) < '0' || value.at(i) > '9')
			return (0);
	}
	if (i == value.length())
		return (1);
	i++;
	for (; i < value.length(); i++)
	{
		if (value.at(i) < '0' || value.at(i) > '9')
			return (0);
	}
	return (1);
}
