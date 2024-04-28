#include "Pupil.h"

int Pupil::m_baseID = 10000; //


Pupil:: Pupil( string name, int age, string className )noexcept : Person( name,age )
{
   
  setClassName( className );
  m_ID = to_string( m_baseID++ );
  clearNotes();

  
}

void Pupil::setClassName( string newClassName )
{
  m_ClassName = newClassName;
}

void Pupil::setNode( Subjects subject, double note )
{
  if ( note >= 2 && note <= 5 && subject >= POLSKI && subject <= NIEMIECKI )
  {
    m_Notes[subject] = note;
  }

}

double Pupil::calcAve()
{
  double srednia = 0;
  int licznik = 0;
  for( int i = POLSKI; i < MAXSUBJECTS; i++ )
  {
    if (m_Notes[i] > 1)
    {
      licznik++;
      srednia += m_Notes[i];
    }
  }

  return m_Ave = (licznik) ? srednia / licznik : 0;
}


void Pupil::clearNotes()
{
  memset( m_Notes, 0, MAXSUBJECTS * sizeof(double) );
  m_Ave = 0;
}

void Pupil::printPupil()
{
  cout << getID() << ", " << getName() << " (" << getClassName()
    << ") " << getAge() << "lat " << " srednia " <<calcAve() << endl;
  cout << '\t';
  printOutfit();
}
