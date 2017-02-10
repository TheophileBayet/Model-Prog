#include "../src/Dvector.h"
#include <iostream>
#include <assert.h>
using namespace std;

int main()
{
  std::cout<<"#### TESTS DES FONCTIONS DE BASE (TP 1)  ####"<<std::endl;
  std::cout<<std::endl;

  Dvector *lolilol1 = new Dvector();
  assert(lolilol1->size() == 0);
  std::cout<< "     Default Constructor : OK      "<<std::endl;
  std::cout<<std::endl;

  Dvector *lolilol = new Dvector(3,2.00);
  Dvector *noInit = new Dvector(5);
  assert(lolilol->size() == 3);
  assert(noInit->size()==5);
  std::cout<< "     Second Constructor : OK      "<<std::endl;
  std::cout<<std::endl;
  /*
  std::stringstream test_str;
  lolilol->display(test_str);
  assert(test_str.str() == "2.0000\n2.00000\n2.00000\n");
  std::cout <<"     DISPLAY : OK      "<<std::endl;*/



  lolilol->fillRandomly();
  assert(lolilol->size()==3);


  return 0;
}
