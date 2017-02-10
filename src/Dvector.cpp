#include "Dvector.h"
#include <iostream>

Dvector::Dvector()
{
  this->dim = 0;
}

Dvector::Dvector(int dim, double init)
{
  this->dim=dim;
  this->vect = new double[dim];
  for(int i=0;i<this->dim;i++) this->vect[i]=init;
}

Dvector::Dvector(std::string file)
{
  fstream fichier(file.c_str());
  if(fichier)
  {
    string ligne;
    long pos = fichier.tellg();
    int i =0;
        while(getline(fichier, ligne))
        {
          i++;
        }
    this->dim = i;
    this->vect = new double[dim];
    i =0;
    fichier.clear();
    fichier.seekg( pos,std::ios_base::beg ) ;
        while(getline(fichier, ligne))
        {
          double elt = atof(ligne.c_str());
          this->vect[i]=elt;
          i++;
        }
    fichier.close();
  }else{
    this->dim = 0;
  }
}

Dvector::~Dvector()
{
  delete [] vect;
}
