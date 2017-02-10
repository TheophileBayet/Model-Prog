
#ifndef DVECTORH
#define DVECTORH
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
using namespace std ;

class Dvector
{
  private :
    int dim;
    double* vect;
  public :
      Dvector();
      Dvector(int dim);
      Dvector(int dim, double init);
      ~Dvector();

      void display(std::ostream& str)
      {
        for(int i=0;i<dim;i++) str<<fixed<<setprecision(5)<<vect[i]<<endl;
        str.flush();
      }

      int size()
      {
        return this->dim;
      }

      void fillRandomly()
      {
        for(int i=0;i<dim;i++) vect[i]=rand() ;
      }
};
#endif
