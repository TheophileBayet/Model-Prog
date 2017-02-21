
#ifndef DVECTORH
#define DVECTORH
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cassert>
#include <fstream>
#include <string>
#include <cstring>

using namespace std ;

class Dvector
{
  private :
    int dim;
    double* vect;
  public :
      Dvector();
      Dvector(std::string);
      Dvector(int dim, double init=0.0);
      ~Dvector();
      double operator () (int i) const;
      void display(std::ostream& str);
      int size();
      void fillRandomly();
    Dvector& operator=(const Dvector &P);
    Dvector& operator +(int n);
    Dvector& operator -(int n);
    Dvector& operator *(int n);
    Dvector& operator /(int n);
    Dvector& operator +(const Dvector &vector);
    Dvector& operator -(const Dvector &vector);
    Dvector& operator -();
    void operator +=(Dvector &vector);
    void operator -=(Dvector &vector);
    void operator *=(int n);
    void operator /=(int n);
    Dvector& operator <<(int n);
    Dvector& operator >>(int n);
    bool operator ==(Dvector &vector);
    void resize (int taille, double val);
    /*
    Dvector operator =(Dvector vector)
    {
      Dvector *V = new Dvector(dim);
      for (int i=0; i< dim; i++)
      {
        V->vect[i] = vect[i];
      }
      return *V;
    }*/

};
#endif
