#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
	public:
		Student(std::string sur, std::string maiden, std::string ID, std::string inst, std::string dep, std::string email, std::string prog);
		Student();

		std::string getSurname();
		void setSurname(std::string);

		std::string getMaiden();
		void setMaiden(std::string);

		std::string getID();
		void setID(std::string);

		std::string getInstitution();
		void setInstitution(std::string);

		std::string getDepartment();
		void setDepartment(std::string);

		std::string getEmail();
		void setEmail(std::string);
		
		std::string getProgram();
		void setProgram(std::string);

		int getMark();
		void setMark(int);

		int getStyle();
		void setStyle(int);

		int getDesign();
		void setDesign(int);

		int getFunc();
		void setFunc(int);
	private:
		std::string m_surname;
		std::string m_maiden;
		std::string m_ID;
		std::string m_institution;
		std::string m_department;
		std::string m_email;
		std::string m_program;
		int m_mark;
		int m_style;
		int m_func;
		int m_design;
		
};

#endif
