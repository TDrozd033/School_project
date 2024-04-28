#include "SchoolGirl.h"

SchoolGirl::SchoolGirl( string name, int age, string className ) : Pupil( name, age, className )
{
  m_ID = " F_"+ m_ID;
}

void SchoolGirl::printOutfit()
{
  cout << "biala bluzka z krawatem, szkolna marynarka, granatowa / czarna spodniczka, plaskie obuwie\n";
}
