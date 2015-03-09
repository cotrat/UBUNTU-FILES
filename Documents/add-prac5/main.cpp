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
	
	vector<Student> classmems;
	vector<Student> classmems2;
	CSVReader myCSV;
	classmems = myCSV.parseMoodleFormat();
	classmems2 = myCSV.parseOfficialFormat();

	/*for(int l = 0; l < classmems.size(); l++)
	{
	
		cout << classmems[l].getMaiden();
		cout << classmems[l].getSurname();
		cout << classmems[l].getID();
		cout << classmems[l].getInstitution();
		cout << classmems[l].getDepartment();
		cout << classmems[l].getEmail() << endl;
		
	}

		cout << endl;
		cout << endl;
		cout << endl;

	for(int x = 0; x < classmems2.size(); x++)
	{
		cout << classmems2[x].getID();
		cout << classmems2[x].getSurname();
		cout << classmems2[x].getMaiden();
		cout << classmems2[x].getDepartment();
		cout << endl;
	}*/

	myCSV.compare(classmems,classmems2);
	cout << " ";
	myCSV.parsePracmarkFormat();
	
}
