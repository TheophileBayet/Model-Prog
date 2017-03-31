#include "Height.h"
#include <iostream>


Height::Height(){
  dimx = 0;
  dimy = 0;
}

Height::Height(int const nx, int const ny, double init)
{
  this->dimx = nx;
  this->dimy = ny;
  this->vect = Dvector(nx*ny,init);
}

Height::Height(const Height& h)
{
  this->dimx = h.dimx;
  this->dimy = h.dimy;
  this->vect = Dvector(dimx*dimy);
  for (int i = 0; i < h.dimx; i++){
    for (int j = 0; j < h.dimy; j++){
      this->vect.set(i,j,dimx,h(i,j));
    }
  }
}

//TODO
/*Height::Height(std::string file)
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
    this->dimy = i;
    this->vect = new double[dimx][dimy];
    i = 0;
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
}*/

Height::~Height()
{
  vect.~Dvector();
}

int Height::getDimX()
{
  return this->dimx;
}

int Height::getDimY()
{
  return this->dimy;
}

double Height::operator () (int i, int j) const
{
  return this->vect(i*dimx,j);
}

void Height::set (int i, int j, double val)
{
  this->vect.set(i,j,this->dimx,val);
}
