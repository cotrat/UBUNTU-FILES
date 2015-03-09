#include "Student.h"
#include <string>

using namespace std;

Student::Student(string sur, string maiden, string ID, string inst, string dep, string email, string prog)
{
	m_surname = sur;
	m_maiden = maiden;
	m_ID = ID;
	m_institution = inst;
	m_department = dep;
	m_email = email;
	m_program = prog;


}

Student::Student()
{

}

void Student::setDesign(int design)
{
	m_design = design;
}

void Student::setStyle(int style)
{
	m_style = style;
}

void Student::setFunc(int func)
{
	m_func = func;
}

int Student::getFunc()
{
	return m_func;
}

int Student::getStyle()
{
	return m_style;
}

int Student::getDesign()
{
	return m_design;
}



void Student::setMark(int mark)
{
	m_mark = mark;
}

void Student::setID(std::string ID)
{
	m_ID = ID;
}

void Student::setInstitution(std::string inst)
{
	m_institution = inst;
}

void Student::setDepartment(std::string dep)
{
	m_department = dep;
}

void Student::setMaiden(std::string maiden)
{
	m_maiden = maiden;
}


void Student::setEmail(std::string email)
{
	m_email = email;
}

void Student::setSurname(std::string sur)
{
	m_surname = sur;
}

void Student::setProgram(std::string prog)
{
	m_program = prog;
}

int Student::getMark()
{
	return m_mark;
}

std::string Student::getSurname()
{
	return m_surname;
}

std::string Student::getMaiden()
{
	return m_maiden;
}

std::string Student::getID()
{
	return m_ID;
}

std::string Student::getInstitution()
{
	return m_institution;
}

std::string Student::getDepartment()
{
	return m_department;
}

std::string Student::getEmail()
{
	return m_email;
}

std::string Student::getProgram()
{
	return m_program;
}

