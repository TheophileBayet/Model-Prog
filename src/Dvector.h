
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

      double operator () (int i) const
      {
        assert(i>=0 && i<dim);
        return vect[i];
      }

      void display(std::ostream& str)
      {
        for(int i=0;i<dim;i++){
          str << fixed << setprecision(5) << vect[i] << std::endl;
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
          vect[i]=rand();
          // Si on divise par RAND_MAX, on obtient uniquement 0. Il faut ajouter un facteur supplémentaire.
        }
      }

    Dvector& operator=(const Dvector &P)
    {
      dim = P.dim;
      vect = new double[dim];
      memcpy(vect,P.vect,dim*sizeof(double));
      return *this;
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

    Dvector& operator +(const Dvector &vector)
    {
      static Dvector V = *this;
      for (int i=0; i< dim; i++)
      {
        V.vect[i] = vect[i] + vector.vect[i];
      }
      return V;
    }

    Dvector operator -(Dvector vector)
    {
      Dvector *V = new Dvector(dim);
      for (int i=0; i< dim; i++)
      {
        V->vect[i] = vect[i] - vector.vect[i];
      }
      return *V;
    }

    Dvector operator -()
    {
      Dvector *V = new Dvector(dim);
      for (int i=0; i< dim; i++)
      {
        V->vect[i] = - vect[i];
      }
      return *V;
    }

    void operator +=(Dvector vector)
    {
      for (int i=0; i< dim; i++)
      {
        vect[i] += vector.vect[i];
      }
    }

    void operator -=(Dvector vector)
    {
      for (int i=0; i< dim; i++)
      {
        vect[i] -= vector.vect[i];
      }
    }

    void operator *=(int n)
    {
      for (int i=0; i< dim; i++)
      {
        vect[i] *= n;
      }
    }

    void operator /=(int n)
    {
      if (n!=0){
        for (int i=0; i< dim; i++)
        {
          vect[i] /= n;
        }
      }
      else {
        std::cout << "Division par 0" <<  std::endl;
      }
    }

    Dvector operator << (int n)
    {
      Dvector *V = new Dvector(dim);
      for (int i=0; i< n; i++)
      {
        V->vect[i] = 2 * vect[i];
      }
      return *V;
    }

    Dvector operator >> (int n)
    {
      Dvector *V = new Dvector(dim);
      for (int i=0; i< n; i++)
      {
        V->vect[i] = vect[i] / 2;
      }
      return *V;
    }
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
