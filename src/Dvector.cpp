#include "Dvector.h"
#include <iostream>

Dvector::Dvector()
{
  this->dim = 0;
}

Dvector::Dvector(int dim, double init=0)
{
  this->dim=dim;
  this->vect = new double[dim];
  for(int i=0;i<this->dim;i++) this->vect[i]=init;
}

Dvector::Dvector(int dim)
{
  this->dim=dim;
  this->vect = new double[dim];
  for(int i=0;i<this->dim;i++) this->vect[i]=0;
}

Dvector::~Dvector()
{
  delete [] vect;
}

Dvector::Dvector(std::string)
{
  //TODO lecture dans un fichier
}
