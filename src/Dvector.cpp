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

Dvector::~Dvector()
{
  delete [] vect;
}

Dvector::Dvector(string &file)
{
  fstream fichier(file.c_str());
  if(fichier)
  {
    string ligne;
    long pos = fichier.tellg();
    fichier.seekg( 0 , std::ios_base::end );
    long size = fichier.tellg() ;
    fichier.seekg( pos,  std::ios_base::beg ) ;
    Dvector((int) size);
    int i =0;
        while(getline(fichier, ligne))
        {
          double elt = atof(ligne.c_str());
          this->vect[i]=elt;
          i++;
        }


    fichier.close();
  }else{
    cerr << " Impossible d'ouvrir le fichier" << file << endl;
  }
}
