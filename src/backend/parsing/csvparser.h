#ifndef FT_PARSING_CSVPARSER_H
#define FT_PARSING_CSVPARSER_H

#include <string>
#include <vector>
#include <fstream>

namespace ftk {
namespace backend {
namespace parsing {

class CsvParser{
	public:
		CsvParser(const std::string& file_path);

		~CsvParser();

		CsvParser(const CsvParser&) = delete;
		CsvParser operator=(const CsvParser&) = delete;

		bool Parse();

		const std::vector<std::vector<std::string>>& GetData() const;
	private:
		std::vector<std::string> ParseLine(const std::string& line);

		std::string file_path_;
		
		std::vector<std::vector<std::string>> data_;


};

}

}

}

#endif
