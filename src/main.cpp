#include "Dvector.h"
#include <iostream>
#include <assert.h>
using namespace std;

int main()
{
  cout<<"#### TESTS DES FONCTIONS DE BASE (TP 1)  ####"<<endl;
  cout<<endl;

  Dvector *lolilol1 = new Dvector();
  assert(lolilol1->size() == 0);
  cout<< "     Default Constructor : OK      "<<endl;
  cout<<endl;

  Dvector *lolilol = new Dvector(3,2.00);
  Dvector *noInit = new Dvector(5);
  assert(lolilol->size() == 3);
  assert(noInit->size()==5);
  cout<< "     Second Constructor : OK      "<<endl;
  cout<<endl;
  /*
  stringstream test_str;
  lolilol->display(test_str);
  assert(test_str.str() == "2.0000\n2.00000\n2.00000\n");
  cout <<"     DISPLAY : OK      "<<endl;*/



  lolilol->fillRandomly();
  assert(lolilol->size()==3);


  return 0;
}
