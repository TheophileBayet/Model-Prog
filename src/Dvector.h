
#ifndef DVECTORH
#define DVECTORH
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std ;

class Dvector
{
  private :
    int dim;
    double* vect;
  public :
      Dvector();
      Dvector(int dim, double init=0.0);
      ~Dvector();
      Dvector(std::string &file);

      double operator () (int i)
      {
        if (i>=0 && i<dim){
          return vect[i];
        }
      }

      void display(std::ostream& str)
      {
        for(int i=0;i<dim;i++){
          std::cout << vect[i] << std::endl;
        }
      }

      int size()
      {
        return this->dim;
      }

      void fillRandomly()
      {
        srand(time(NULL));
        for(int i=0;i<dim;i++){
          vect[i]=rand()/RAND_MAX ;
        }
      }

    Dvector operator +(int n)
    {
      Dvector *V = new Dvector(dim);
      for (int i=0; i< dim; i++)
      {
        V->vect[i] = vect[i] + n;
      }
      return *V;
    }

    Dvector operator -(int n)
    {
      Dvector *V = new Dvector(dim);
      for (int i=0; i< dim; i++)
      {
        V->vect[i] = vect[i] - n;
      }
      return *V;
    }

    Dvector operator *(int n)
    {
      Dvector *V = new Dvector(dim);
      for (int i=0; i< dim; i++)
      {
        V->vect[i] = vect[i] * n;
      }
      return *V;
    }

    Dvector operator /(int n)
    {
      Dvector *V = new Dvector(dim);
      for (int i=0; i< dim; i++)
      {
        V->vect[i] = vect[i] / n;
      }
      return *V;
    }
};
#endif
