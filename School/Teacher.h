#pragma once
#include "Worker.h"
class Teacher : public Worker
{

public:

	Teacher( string name = "", int newAge = 0, double newSalary = 0, int YearsNo = 0, string newSubject = "",
		bool isTut = false, string newClass = "" );

	void setSubject( string newSubject );
	void setClassTut( bool isTut );
	void setClass( string newClass );
	
	string getSubject() const;
	bool getIsClassTutor() const;
	string getClass() const;

	double CalcSal();
  double CalcTax();

	double BruttoPlusBonuses();


	virtual void printWorker() final;


private:
	string m_Subject;
	bool isClassTutor;
	string m_Class;

};


//INLINE FUNCTIONS:


inline string Teacher:: getSubject() const
{
	return m_Subject;
}
inline bool Teacher::getIsClassTutor() const
{
	return isClassTutor;
}
inline string Teacher::getClass() const
{
	return m_Class;
}