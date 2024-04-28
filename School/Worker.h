#pragma once
#include "Person.h"
class Worker :  public Person
{
public:

  Worker( string name = "", int age = 0, double salary = 0, int YearsNo=0 );
  virtual ~Worker() { }
 
  void setSalary( double newSalary );
  double getSalary()const;
  void setYears( int YearsNo );
  double getYears()const;
 

  virtual void printWorker();

private:

  double m_Salary;
  int m_Years;
};

//INLINE FUNCTIONS:

inline double Worker::getSalary()const
{
  return m_Salary;
}
inline double Worker::getYears()const
{
  return m_Years;
}