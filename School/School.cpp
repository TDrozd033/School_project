
#include <iostream>
#include "Person.h"
#include "Pupil.h"
#include"SchoolBoy.h"
#include "Worker.h"
#include"Teacher.h"
#include"Admin.h"
#include"SchoolGirl.h"

#define NUMBER_OF_PUPILS 8
#define NUMBER_OF_TEACHERS 6
#define NUMERS_OF_ADMINS 3

using namespace std;
void PrintPupil( Pupil** tab, int nPupil );
void sortPupil( Pupil** tab, int nPupil);
void PrintAdmin( Admin** tab, int nAdmin );
void PrintTeacher( Teacher** tab, int nTeacher );


int main()
{
  Teacher* teacher[NUMBER_OF_TEACHERS] = { NULL };
  Admin* admin[NUMERS_OF_ADMINS] = { NULL };
  Pupil* pupils[NUMBER_OF_PUPILS] = { NULL };


  //- w programie glownym stowrzyc 6-miu nauczycieli oraz 3 pracownikow administr.


  teacher[ 0 ] = new Teacher("Jacek Placek", 60, 7000, 12, "Informatyka", false);
  teacher[ 1 ] = new Teacher("Rafal Szczota", 44, 6500, 15, "Matematyka", true,  "4A");
  teacher[ 2 ] = new Teacher("Renata Wcislo", 69, 8500, 22, "Polski", true, "6B");
  teacher[ 3 ] = new Teacher("Donald Duda", 34, 6000, 11, "Chemia", true, "8C");
  teacher[ 4 ] = new Teacher("Jaroslaw Giertych", 75, 11100, 30, "Niemiecki", false);
  teacher[ 5 ] = new Teacher("Adam Nowak", 32, 5500, 4, "Fizyka", true, "2A");


  admin[ 0 ] = new Admin("Abdul Babdul", 30, 7000, 5, MLODSZY_SPECJALISTA);
  admin[ 1 ] = new Admin("Jan Lato", 56, 15000, 18, STARSZY_SPECJALISTA);
  admin[ 2 ] = new Admin("Romuald Slowak", 43, 9000, 12, SPECJALISTA);


  pupils[ 0 ] = new SchoolGirl("Maja Wielka", 16, "8A");
  pupils[ 1 ] = new SchoolBoy("Arnold Boczek", 22, "3B");
  pupils[ 2 ] = new SchoolGirl("Jola Lojalna", 18, "2C");
  pupils[ 3 ] = new SchoolBoy("Marian Pazdzioch", 15, "7B");
  pupils[ 4 ] = new SchoolGirl("Anna Nowak", 15, "6A");
  pupils[ 5 ] = new SchoolBoy("Lopata Maciej", 14, "5A");
  pupils[ 6 ] = new SchoolGirl("Wiktoria Beblo", 17, "8A");
  pupils[ 7 ] = new SchoolBoy("Pampers Pampers", 20, "2B");


  pupils[ 0 ]->setNode(POLSKI, 5.0);
  pupils[ 0 ]->setNode(MATEMATYKA, 5.0);
  pupils[ 0 ]->setNode(ANGIELSKI, 4.5);
  pupils[ 0 ]->setNode(FIZYKA, 3.5);
  pupils[ 0 ]->setNode(NIEMIECKI, 3.0);


  pupils[ 1 ]->setNode(INFORMATYKA, 3.5);
  pupils[ 1 ]->setNode(POLSKI, 3.0);
  pupils[ 1 ]->setNode(MATEMATYKA, 3.5);
  pupils[ 1 ]->setNode(NIEMIECKI, 5.0);
  pupils[ 1 ]->setNode(CHEMIA, 4.5);
  pupils[ 1 ]->setNode(FIZYKA, 2.5);


  pupils[ 2 ]->setNode(POLSKI, 5.0);
  pupils[ 2 ]->setNode(CHEMIA, 3.5);
  pupils[ 2 ]->setNode(MATEMATYKA, 4.5);
  pupils[ 2 ]->setNode(NIEMIECKI, 2.5);


  pupils[ 3 ]->setNode(ANGIELSKI, 5.0);
  pupils[ 3 ]->setNode(POLSKI, 3.0);
  pupils[ 3 ]->setNode(NIEMIECKI, 2.5);
  pupils[ 3 ]->setNode(INFORMATYKA, 5.0);
  pupils[ 3 ]->setNode(FIZYKA, 4.0);


  pupils[ 4 ]->setNode(POLSKI, 3.5);
  pupils[ 4 ]->setNode(ANGIELSKI, 2.5);
  pupils[ 4 ]->setNode(NIEMIECKI, 3.5);
  pupils[ 4 ]->setNode(CHEMIA, 5.0);
  pupils[ 4 ]->setNode(MATEMATYKA, 4.0);


  pupils[ 5 ]->setNode(POLSKI, 2.5);
  pupils[ 5 ]->setNode(MATEMATYKA, 3.5);
  pupils[ 5 ]->setNode(ANGIELSKI, 4.5);
  pupils[ 5 ]->setNode(CHEMIA, 4.0);
  pupils[ 5 ]->setNode(INFORMATYKA, 3.5);
  pupils[ 5 ]->setNode(NIEMIECKI, 5.0);
  pupils[ 5 ]->setNode(FIZYKA, 3.5);


  pupils[ 6 ]->setNode(MATEMATYKA, 5.0);
  pupils[ 6 ]->setNode(INFORMATYKA, 4.5);
  pupils[ 6 ]->setNode(ANGIELSKI, 5.0);
  pupils[ 6 ]->setNode(POLSKI, 3.0);
  

  pupils[ 7 ]->setNode(INFORMATYKA, 3.5);
  pupils[ 7 ]->setNode(MATEMATYKA, 2);
  pupils[ 7 ]->setNode(POLSKI, 4.0);
  pupils[ 7 ]->setNode(ANGIELSKI, 2.5);
  


  cout<< " UCZNIOWIE: " << endl<<endl; 
  PrintPupil(pupils, NUMBER_OF_PUPILS);

  sortPupil(pupils, NUMBER_OF_PUPILS);
  cout << endl << " POSORTOWANI UCZNIOWIE:" << endl<<endl;
  PrintPupil(pupils, NUMBER_OF_PUPILS);

  cout << endl << " PRACOWNICY ADMINISTRACJI: "<<endl<<endl;
  PrintAdmin(admin, NUMERS_OF_ADMINS);

  cout << endl<<" NAUCZYCIELE: "<< endl<<endl;
  PrintTeacher(teacher, NUMBER_OF_TEACHERS);
 

  return 0;
}

void PrintPupil( Pupil** tab, int nPupil )
{
  for( int i = 0; i < nPupil; i++ )
  {
    cout << " Uczen nr " << i + 1 << ":" << endl;
    tab[i]->printPupil();
    cout << endl;
  }
  cout << endl;
}
  
void sortPupil( Pupil** tab, int nPupil)
{
  for( int i = 0; i < nPupil; i++ )
  {
    int j = i - 1;
  Pupil* temp = tab[ i ];
  while( j >= 0 && tab[ j ]->getName() > temp->getName() )
  {
      tab[ j + 1 ] = tab[ j-- ];
    }
    tab[ j + 1 ] = temp;	
  }
      
}


void PrintTeacher( Teacher** tab, int nTeacher )
{
  for( int i = 0; i < nTeacher; i++ )
  {
    cout << " Nauczyciel nr " << i + 1 << ":" << endl;
    tab[i]->printWorker();
    cout << endl;
  }
  cout << endl;
}

void PrintAdmin( Admin** tab, int nAdmin )
{
  for( int i = 0; i < nAdmin; i++ )
  {
    cout << " Pracownik administracji nr " << i + 1 << ":" << endl;
    tab[i]->printWorker();
    cout << endl;
  }
  cout << endl;
}

