#include "Worker.h"


Worker:: Worker( string name, int age, double salary, int YearsNo ) : Person( name, age )
{
  setSalary( salary );
  setYears( YearsNo );
}

void Worker:: setSalary( double newSalary )
{
  m_Salary = newSalary;
}
void Worker::setYears( int YearsNo )
{
  m_Years = YearsNo;  
}

 void Worker::printWorker()
{
   cout << " Imie i Nazwisko: " << getName() <<endl<< " Wiek: " << getAge() << " lat " <<endl<< " Pensja: " << getSalary() << " zl " << endl<<" Staz pracy w latach: " << getYears() << endl;
}

