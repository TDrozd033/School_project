#include "Teacher.h"


Teacher::Teacher( string name, int newAge, double newSalary, int YearsNo, string newSubject,
	bool isTut, string newClass) : Worker(name, newAge, newSalary, YearsNo )
{
	setSubject( newSubject );
	setClassTut( isTut );
	setClass( newClass );
	
}

void Teacher::setSubject( string newSubject )
{
	m_Subject = newSubject;
}
void Teacher::setClassTut( bool isTut )
{
	isClassTutor = isTut;

}
void Teacher::setClass( string newClass )
{
	m_Class = newClass;
}

// ma byc printowanie pensji ( pensja netto, pensja brutto, podatek )
/*dla nauczycieli od 80 % pensji naliczac 50 % koszty uzysku a od reszty tak jak dla admina przy czym
uwzglednic w kwocie brutto wysluge lat(w zakresie od 5 do 20 lat pracy doliczac do kwoty brutto
	odpowiednio od 5 do 20 % kwoty brutto) oraz jesli jest wychowawca
	dodac dodatek 400 zl
	np dla 10 stazu pracy od 5000 brutto doliczyc 500 czyli lacznie jest 5500 brutto(bez wychowacy).
	Powyzej 20 lat stazowe sie nie zwieksza)*/

double Teacher::BruttoPlusBonuses()
{
	double kwota_brutto = getSalary();
	double koszty_uzysku = 111.25;
	double tax = 0.18;
	double kwota_wolna = 556.02 / 12;
	if( getIsClassTutor() )
	{
		kwota_brutto += 400;
	}


	if( getYears() >= 5 && getYears() <= 20 )
	{
		kwota_brutto += kwota_brutto * ( getYears() / 100 );
	}
	else if( getYears() > 20 )
	{
		kwota_brutto += kwota_brutto * 0.2;
	}
	return kwota_brutto;

}

double Teacher::CalcTax()
{
	double kwota_brutto = BruttoPlusBonuses();	
	double koszty_uzysku = 111.25;
	double tax = 0.18;
	double kwota_wolna = 556.02 / 12;
	double podatek = ( (0.8 * kwota_brutto - 0.5 * koszty_uzysku) + (0.2 * kwota_brutto - koszty_uzysku) ) * tax - kwota_wolna;
	if( podatek < 0 )
	{
		podatek = 0;
	}
	return podatek;
}
double Teacher:: CalcSal() 
{
	double pensja_netto = BruttoPlusBonuses() - CalcTax();
	return pensja_netto;

}

void Teacher::printWorker() 
{
	cout << " Imie i Nazwisko: " << getName() << endl<<" Wiek: " << getAge() << endl;
	if( getIsClassTutor() )
	{
		cout << " Wychowawca: " << getClass() << endl;
	}
	else
	{
		cout << " Nie jest wychowawca " << endl;
	}
	cout << " Pensja brutto: " << BruttoPlusBonuses() << " zl" << ", Podatek: " << CalcTax() << " zl " << endl;
	cout << " Pensja netto: " << CalcSal() << " zl " << endl <<" Przedmiot: " << getSubject() << endl;
	cout << " Staz pracy w latach: " << getYears() << endl;
}


