#ifndef CSVReader_H
#define CSVReader_H

#include <string>
#include <vector>
#include "Student.h"

class CSVReader {
	public:
		CSVReader();
		~CSVReader();
		std::vector<Student> parseMoodleFormat();
		std::vector<Student> parseOfficialFormat();
		void parsePracmarkFormat();
		void compare(std::vector<Student>, std::vector<Student>);
	private:
		
		
};

#endif
