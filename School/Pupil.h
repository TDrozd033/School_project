#pragma once
#include "Person.h"
//w C:
//typedef enum { POLSKI, MATEMATYKA, FIZYKA, CHEMIA, INFORMATYKA, ANGIELSKI, NIEMIECKI} Subjects;

// w C++:
enum Subjects { POLSKI, MATEMATYKA, FIZYKA, CHEMIA, INFORMATYKA, ANGIELSKI, NIEMIECKI };
#define MAXSUBJECTS NIEMIECKI+1


class Pupil :  public Person
{


public:
  Pupil( string name = "", int age=0, string className = "" )noexcept;
  virtual ~Pupil(){ }

  string getID()const;
  string getClassName()const;
  void setClassName( string newClassName );
  void setNode( Subjects subject, double note );
  double calcAve();
  double getAve()const;
  void printPupil();
  virtual void printOutfit() { cerr << "Error\n"; }
  void clearNotes();


protected:
  string m_ID;

private:

  string m_ClassName;
  double m_Ave;
  double m_Notes[MAXSUBJECTS];
  static int m_baseID;

};

// INLINE FUNCTIONS:

inline string Pupil::getID()const
{
  return m_ID;
}
inline string Pupil::getClassName()const
{
  return m_ClassName;
}



inline double Pupil::getAve()const
{
  return m_Ave;
}

