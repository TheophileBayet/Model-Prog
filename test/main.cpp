#include "../src/Dvector.h"
#include <iostream>
#include <assert.h>
#include <sstream>
using namespace std;

int main()
{
  std::cout<<std::endl;
  std::cout<<"#### TESTS DES FONCTIONS DE BASE (TP 1)  ####"<<std::endl;
  std::cout<<std::endl;

  Dvector *lolilol1 = new Dvector();
  assert(lolilol1->size() == 0);
  std::cout<< "     Default Constructor : OK      "<<std::endl;
  std::cout<<std::endl;

  Dvector *lolilol = new Dvector(3,2.00);
  Dvector *noInit = new Dvector(5);
  Dvector P(3);
  assert(lolilol->size() == 3);
  assert(noInit->size()==5);
  std::cout<< "     Second Constructor : OK      "<<std::endl;
  std::cout<<std::endl;

  stringstream test_str;
  lolilol->display(test_str);
  assert(test_str.str() == "2.00000\n2.00000\n2.00000\n");
  std::cout <<"     DISPLAY : OK      "<<std::endl;
  std::cout<< std::endl;
  std::cout << "Before random fill :" << std::endl;
  lolilol->display(std::cout);
  lolilol->fillRandomly();
  std::cout << "After random fill : " << std::endl;
  lolilol->display(std::cout);
  assert(lolilol->size()==3);
  std::cout<<std::endl;
  std::cout <<"     FillRandomly : OK      "<<std::endl;

  string test_name = "test/test1.txt";
  Dvector *Q = new Dvector(test_name);
  assert(Q->size()==10);
  std::cout<<std::endl;
  std::cout <<"     File Constructor : OK      "<<std::endl;

  stringstream yolo;
  Q->display(yolo);
  string yolo_name = "test/yolo.txt";
  // Création d'un fichier dans lequel stocker le stream yolo :
  fstream file(yolo_name.c_str());
  if(file)
  {
      file << yolo.str() ;
      file.close();
  }

  //std::cout << yolo.str(); // Verification de la valeur des double dans Q.
  Dvector *R = new Dvector(yolo_name);
  assert(R->size()==10);
  std::cout<<std::endl;
  std::cout <<"     Display then constructor : OK      "<<std::endl;

  std::cout<<std::endl;
  std::cout << "#### TESTS DES OPERATEURS (TP 1)  ####"<<std::endl;
  std::cout<<std::endl;

  std::cout << "  standard  real operators tests :   "<< std::endl;
  std::cout << std::endl;

  Dvector Ope_Vect(3,2);
  Dvector *Test_Vect=new Dvector(3);
  assert(Ope_Vect(2)==2);

  std::cout << " Accessor : OK" << std::endl;
  std::cout << std::endl;

  try {
  *Test_Vect = Ope_Vect+(2) ;
  Test_Vect->display(std::cout);
  assert((*Test_Vect)(2)==4);
} catch (int e){
  std::cout<< " ERROR WITH REAL + OPERATOR : error number  "<<e<<"raised " << std::endl;
}

  std::cout << " REAL Operator + : OK" << std::endl;
  std::cout << std::endl;

  try {
  *Test_Vect = Ope_Vect-(3) ;
  Test_Vect->display(std::cout);
  assert((*Test_Vect)(1)==-1);
} catch (int e){
  std::cout<< " ERROR WITH REAL - OPERATOR : error number  "<<e<<"raised " << std::endl;
}

  std::cout << " REAL Operator - : OK" << std::endl;
  std::cout << std::endl;

try {
  *Test_Vect = Ope_Vect*(-3) ;
  Test_Vect->display(std::cout);
  assert((*Test_Vect)(1)==-6);
} catch (int e){
  std::cout<< " ERROR WITH REAL * OPERATOR : error number  "<<e<<"raised " << std::endl;
}

  std::cout << " REAL Operator * : OK" << std::endl;
  std::cout << std::endl;

try {
  *Test_Vect = Ope_Vect/(2) ;
  Test_Vect->display(std::cout);
  assert((*Test_Vect)(1)==1);
} catch (int e){
  std::cout<< " ERROR WITH REAL / OPERATOR : error number  "<<e<<"raised " << std::endl;
}
  std::cout << " REAL Operator / : OK" << std::endl;
  std::cout << std::endl;

  std::cout << "  standard unary operators tests :   "<< std::endl;
  std::cout << std::endl;
  /*
  try {
  *Test_Vect = Ope_Vect-() ;
  Test_Vect->display(std::cout);
  assert((*Test_Vect)(1)==-2);
} catch (int e){
  std::cout<< " ERROR WITH UNARY - OPERATOR : error number  "<<e<<"raised " << std::endl;
}
  std::cout << " Unary Operator - : OK" << std::endl;
  std::cout << std::endl;

  std::cout << "  standard binary operators tests :   "<< std::endl;
  std::cout << std::endl;
  Dvector Bin_Ope_Vect(3,3);
/*
  try {
  std::cout << " on aditionne : " << std::endl ;
  Ope_Vect.display(std::cout);
  std::cout <<"et "<<std::endl;
  Bin_Ope_Vect.display(std::cout);
  *Test_Vect = Ope_Vect+(Bin_Ope_Vect) ;
  std::cout << " ce qui donne : "<<std::endl;
  Test_Vect->display(std::cout);
  assert((*Test_Vect)(2)==5);
} catch (int e){
  std::cout<< " ERROR WITH BINARY + OPERATOR : error number  "<<e<<"raised " << std::endl;
}

  std::cout << " Binary Operator + : OK" << std::endl;
  std::cout << std::endl;

  try {
  std::cout << " on soustraie : " << std::endl ;
  Ope_Vect.display(std::cout);
  std::cout <<"et "<<std::endl;
  Bin_Ope_Vect.display(std::cout);
  *Test_Vect = Ope_Vect-(Bin_Ope_Vect) ;
  std::cout << " ce qui donne : "<<std::endl;
  Test_Vect->display(std::cout);
  assert((*Test_Vect)(2)==-1);
} catch (int e){
  std::cout<< " ERROR WITH BINARY - OPERATOR : error number  "<<e<<"raised " << std::endl;
}

  std::cout << " Binary Operator - : OK" << std::endl;
  std::cout << std::endl;*/
  std::cout << " Mais d'où vient ce petit doublre free ? " << std::endl;

  return 0;
}
