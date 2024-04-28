#pragma once

#include<string>
#include<iostream>
using namespace std;
class Person
{
public:
  Person( string name = "", int age = 0 )noexcept;
  // explicit - nie moze byc niejawnej konwersji przy pomocy konstruktora z jednym parametrem 
  // noexcept - nie moze rzucac wyjatkami 

  virtual ~Person() { }
  Person& operator = ( const Person& p ) = default;
  // default - podstaw defaultwe dostarczone przez kompilator, nie wolno go implementowac

  void setPerson( string newName, int newAge );
  void setName( string newName );
  string getName()const;
  void setAge( int newAge );
  int getAge()const;
  



private:

  string m_Name;
  int m_Age;

};


// INLINE FUNCTIONS:

inline int Person::getAge()const
{
  return m_Age;
}

inline string Person::getName()const
{
  return m_Name;

}

