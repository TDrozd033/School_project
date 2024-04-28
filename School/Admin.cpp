#include "Admin.h"


Admin:: Admin ( string name, int newAge, double newSalary, int YearsNo, Stanowisko sPosition) : Worker(name, newAge, newSalary, YearsNo )
{
  setPosition( sPosition );
}
// (kwota brutto - koszty uzysku) * 18% podatku - kwota wolna
// koszty uzyskania przychodu: 111.25 / miesiac
//kwota wolna 556.02 / 12 = 46.34
 
/*
dla admina podatek oblicza sie((kwota brutto - koszty uzysku) * 18 % podatku - kwota wolna),
(kwota netto to brutto minus obliczony podatek)
Jesli podatek wychodzi ujemny to go wyzerowac
kwoty ponizej
*/

 double Admin::CalcTax()
 {
   double kwota_brutto = getSalary();
   double koszty_uzysku = 111.25;

   double tax = 0.18;
   double kwota_wolna = 556.02 / 12;
   double podatek = ( kwota_brutto - koszty_uzysku ) * tax - kwota_wolna;
   if ( podatek < 0 )
   {
     podatek = 0;
   }
   return podatek;
 }



 double Admin::CalcSal()
 {
   double pensja_netto = getSalary() - CalcTax();
   return pensja_netto;
 }

 

void Admin::printWorker()
{
  cout << " Imie i Nazwisko: " << getName() <<endl<< " Wiek: " << getAge() << endl << " Pensja brutto: " << getSalary() << " zl" << ", Podatek: " << CalcTax() << " zl " << endl;
  cout<< " Pensja netto: " << CalcSal() << "zl" << endl << " Stanowisko: " << getPosition() << endl << " Staz pracy w latach: " << getYears() << endl;
 
}