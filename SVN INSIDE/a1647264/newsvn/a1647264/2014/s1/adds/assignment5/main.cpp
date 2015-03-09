// Design Began 24/04/2014
// Coding Began 24/04/2014

#include "Student.h"
#include "CSVReader.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	// Create vectors to store classmembers, then compare then find the average
	vector<Student> classmems;
	vector<Student> classmems2;
	CSVReader myCSV;
	classmems = myCSV.parseMoodleFormat();
	classmems2 = myCSV.parseOfficialFormat();
	myCSV.compare(classmems,classmems2);
	myCSV.parsePracmarkFormat();
	
}
