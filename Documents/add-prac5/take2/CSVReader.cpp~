#include "Student.h"
#include "CSVReader.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
using namespace std;

CSVReader::CSVReader()
{

}

CSVReader::~CSVReader()
{

}

void CSVReader::compare(vector<Student> moodle,vector<Student> official)
{
	unsigned int i,j,l;
	bool check = 0;
	bool written = 0;
	vector<int> outputs;
	for(i = 0; i < official.size(); i++)
	{
		for(j = 0; j < moodle.size(); j++)
		{
			
			if(moodle[j].getID().substr(1) == official[i].getID())
			{
				check = 1;
			} 
		}
		if(!check)
		{	
			
			outputs.push_back(atoi(official[i].getID().c_str()));
		}
		check = 0;	
	}
		
		sort(outputs.begin(), outputs.end());

	for(l = 0; l < outputs.size(); l++)
	{
		if(l>0)
		{
			cout << ",a" <<outputs[l];
			written = 1;
		}
		else
		{
			cout << "a" <<outputs[l];
			written = 1;
		}
	}

	//Second Part Checking if they are in moodle but not official
	check = 0;
	outputs.clear();

	for(i = 0; i < moodle.size(); i++)
	{
		for(j = 0; j < official.size(); j++)
		{
			
			if(official[j].getID() == moodle[i].getID().substr(1))
			{
				check = 1;
			} 
		}
		if(!check)
		{	
			
			outputs.push_back(atoi(moodle[i].getID().substr(1).c_str()));
		}
		check = 0;	
	}

	sort(outputs.begin(), outputs.end());
	for(l = 0; l < outputs.size(); l++)
	{
		if(written)
		{
			cout << " ";
		}
		if(l>0)
		{
			cout << ",a" <<outputs[l];
			written = 1;
		}
		else
		{
			cout << "a" <<outputs[l];
			written = 1;
		}
	}
	

}

void CSVReader::parsePracmarkFormat()
{
	unsigned int itr;
	double sum = 0;
	
	
	unsigned int x1;
	unsigned int x2;
	

	vector<string> line_storage;
	vector<string> split_entries;
	vector<Student> classmems;
	std::ifstream  classFile("pracmarker.csv");
	string line;
	getline(classFile, line);

	while(getline(classFile, line))
		{
        		line_storage.push_back(line);
		}
        
	for(unsigned int i = 0; i < line_storage.size(); i++)
	{
		istringstream ss(line_storage[i]);
		string token;
		while(!ss.eof()) 
		{
			std::getline(ss, token, ',');
    			split_entries.push_back(token);
			
			
		}
	}

	vector<int> spots; 
	int pos;
	string curr_id;
	
	itr =0;
	
	while(itr < line_storage.size())
	{
		pos = -10;
		/* Check if already in our vector of students */ 
	 	curr_id = split_entries[0+(4*itr)];

		if(classmems.size() >= 1)
		{
			for(x1 = 0; x1 < classmems.size(); x1++)
			{
				if(curr_id == classmems[x1].getID())
				{
					pos = x1;
			
					if( atoi(split_entries[1+(4*itr)].c_str()) > classmems[pos].getDesign() )
					{
						classmems[pos].setDesign(atoi(split_entries[1+(4*itr)].c_str()));
					}
					if( atoi(split_entries[2+(4*itr)].c_str()) > classmems[pos].getStyle() )
					{
						classmems[pos].setStyle(atoi(split_entries[2+(4*itr)].c_str()));
					}
					if( atoi(split_entries[3+(4*itr)].c_str()) > classmems[pos].getFunc() )
					{
						classmems[pos].setFunc(atoi(split_entries[3+(4*itr)].c_str()));
					}
				}
				
			}
		}


				if(pos < 0)
				{
					
					Student newStud;
					newStud.setID(split_entries[0+(4*itr)]);
					mark = atoi(split_entries[1+(4*itr)].c_str()) + atoi(split_entries[2+(4*itr)].c_str()) + atoi(split_entries[3+(4*itr)].c_str());
					newStud.setDesign(atoi(split_entries[1+(4*itr)].c_str()));
					newStud.setStyle(atoi(split_entries[2+(4*itr)].c_str()));
					newStud.setFunc(atoi(split_entries[3+(4*itr)].c_str()));
					classmems.push_back(newStud);
				}
				
		itr++;
		
	}
	
	
	for(x2 = 0; x2 < classmems.size(); x2++)
	{

			sum = sum + (classmems[x2].getStyle() + classmems[x2].getFunc() + classmems[x2].getDesign());	
	}
	
	
	sum = sum/classmems.size();
	printf("%.2f", sum);

	
}

vector<Student> CSVReader::parseOfficialFormat()
{
	vector<string> line_storage;
	vector<string> split_entries;
	vector<Student> classmems;
	std::ifstream  classFile("officiallist.csv");
	string line;
	getline(classFile, line);

	while(getline(classFile, line))
		{
        		line_storage.push_back(line);
		}
        


	for(unsigned int i = 0; i < line_storage.size(); i++)
	{
		istringstream ss(line_storage[i]);
		string token;
		while(std::getline(ss, token, ',')) 
		{
    			split_entries.push_back(token);
		}
	}

	unsigned int itr = 0;
	while(itr < line_storage.size())
	{
		Student newStud;
		newStud.setID(split_entries[0+(4*itr)]);
		newStud.setSurname(split_entries[1+(4*itr)]);
		newStud.setMaiden(split_entries[2+(4*itr)]);
		newStud.setDepartment(split_entries[3+(4*itr)]);
		

		

		classmems.push_back(newStud);
		itr++;
	}

	return classmems;

}

vector<Student> CSVReader::parseMoodleFormat()
{

	vector<string> line_storage;
	vector<string> split_entries;
	
	vector<Student> classmems;
	std::ifstream  classFile("moodlelist.csv");
	string line;
	getline(classFile, line);

	while(getline(classFile, line))
		{
        		line_storage.push_back(line);
		}
        
	for(unsigned int i = 0; i < line_storage.size(); i++)
	{
		istringstream ss(line_storage[i]);
		string token;
		while(std::getline(ss, token, ',')) 
		{
    			split_entries.push_back(token);
			
		}
	}
	
	unsigned int itr = 0;
	while(itr < line_storage.size())
	{
		Student newStud;
		newStud.setMaiden(split_entries[0+(6*itr)]);
		newStud.setSurname(split_entries[1+(6*itr)]);
		newStud.setID(split_entries[2+(6*itr)]);
		newStud.setInstitution(split_entries[3+(6*itr)]);
		newStud.setDepartment(split_entries[4+(6*itr)]);
		newStud.setEmail(split_entries[5+(6*itr)]);

		

		classmems.push_back(newStud);
		itr++;
	}

	return classmems;
}
