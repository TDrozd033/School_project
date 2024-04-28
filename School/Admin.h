#pragma once
#include "Worker.h"

/*Dla kazdego pracownika pamietac : nawisko i imie, wiek oraz pensja brutto, sta¿ pracy w latach.
Dla pracownika administracyjnego pamietac na jakim stanowisku pracuje(mozliwosci : mlodszy specjalista,
	specjalista, starszy specjalista)*/

enum Stanowisko {MLODSZY_SPECJALISTA, SPECJALISTA, STARSZY_SPECJALISTA };

const string nazwa[] = { " Mlodszy Specjalista ", " Specjalista ", " Starszy Specjalista " };
class Admin : public Worker
{

public:
	Admin( string name = "", int newAge = 0, double newSalary = 0, int YearsNo = 0, Stanowisko sPosition = MLODSZY_SPECJALISTA );

	void setPosition( Stanowisko newPosition );

	string getPosition() const;

	 double CalcSal();
	 double CalcTax();
	 


	virtual void printWorker() final;

private:

  string m_Position;
};

//INLINE FUNCTIONS:

inline string Admin::getPosition() const
{
	return m_Position;
}

inline void Admin::setPosition( Stanowisko newPosition )
{
	m_Position = nazwa[newPosition];
}