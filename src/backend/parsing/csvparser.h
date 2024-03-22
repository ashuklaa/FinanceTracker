#ifndef FT_PARSING_CSVPARSER_H
#define FT_PARSING_CSVPARSER_H

#include <string>
#include <vector>

/**
 *\file csvparser.h 
 * \brief CSV parse tool to parse statements into database
 *
 * Allows loading of data found within csv files using robust structural analysis
 * */

namespace ftk {
namespace backend {
namespace parsing {

/**
 * \class CsvParser
 * \brief Class for parsing CSV files.
 *
 * This class provides methods to load a CSV file, parse it,
 * and retrieve the data. The parser assumes that the first
 * row of the CSV contains the headers.
 */

class CsvParser{
	public:
	/**
	 * \brief Constructor for parse tool
	 * \param delimiter - character used in csv 
	*/
	explicit CsvParser(char delimiter = ',');

	/**
	 * \brief loads and parses csv file
	 * \param filename - path to csv file
	 * \return True if file successfully parsed, else false
	*/
	bool load(const std::string& filename);

	/**
	 * \brief Retrieves CSV headers
	 * \return Vector of strings with headers in contents
	*/
	std::vector<std::string> getHeaders() const;

	/**
	 * \brief Retrieves data from specific column
	 * \param colName - Name of column to retrieve data from
	 * \return A vector of strings containing column data
	*/

	std::vector<std::string> getColData(const std::string& colName);

	/**
	 * \brief Retrieves data from specific row
	 * \param rowIndex - Index of a row to retrieve data from.
	 * \return A vector of strings containing row data
	*/
	std::vector<std::string> getRowData(size_t rowIndex) const;
	private:
		char m_delimiter;				///< Delimiter character from csv
		std::vector<std::string> m_headers;		///< Headers froM CSV
		std::vector<std::vector<std::string>> m_data;	///< Data from CSV file
	/**
	* \brief Parses single line of csv
	* \param line The line to parse
	* \return a vector of strings representing parsed data from line
	*/

	std::vector<std::string> parseLine(const std::string& line);


};

}

}

}

#endif
