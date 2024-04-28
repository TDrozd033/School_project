#include "Person.h"

Person::Person( string name, int age )noexcept
{
  setName( name );
  setAge( age );
}

 void Person::setPerson( string newName, int newAge )
{
  setName( newName );
  setAge( newAge );
}
void Person::setName( string newName )
{
  m_Name = newName;
}


 void Person::setAge( int newAge )
{
  m_Age = newAge;
}
