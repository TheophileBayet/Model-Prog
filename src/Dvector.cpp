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

double  Dvector::operator () (int i) const
{
  assert(i>=0 && i<dim);
  return vect[i];
}

void Dvector::display(std::ostream& str)
{
  for(int i=0;i<dim;i++){
    str << fixed << setprecision(5) << vect[i] << std::endl;
  }
}

int Dvector::size()
{
  return this->dim;
}

void Dvector::fillRandomly()
{
  srand(time(NULL));
  for(int i=0;i<dim;i++){
    vect[i]=rand();
    // Si on divise par RAND_MAX, on obtient uniquement 0. Il faut ajouter un facteur supplémentaire.
  }
}

Dvector& Dvector::operator=(const Dvector &P)
{
  dim = P.dim;
  vect = new double[dim];
  memcpy(vect,P.vect,dim*sizeof(double));
  return *this;
}

Dvector& Dvector::operator +(int n)
{
  static Dvector V(dim);
  for (int i=0; i< dim; i++)
  {
    V.vect[i] = vect[i] + n;
  }
  return V;
}

Dvector& Dvector::operator -(int n)
{
  static Dvector V(dim);
  for (int i=0; i< dim; i++)
  {
    V.vect[i] = vect[i] - n;
  }
  return V;
}

Dvector& Dvector::operator *(int n)
{
  static Dvector V(dim);;
  for (int i=0; i< dim; i++)
  {
    V.vect[i] = vect[i] * n;
  }
  return V;
}

Dvector& Dvector::operator /(int n)
{
  static Dvector V(dim) ;
  for (int i=0; i< dim; i++)
  {
    V.vect[i] = vect[i] / n;
  }
  return V;
}

Dvector& Dvector::operator +(const Dvector &vector)
{
  static Dvector V(vector.dim);
  V = *this;
  for (int i=0; i< dim; i++)
  {
    V.vect[i] = vect[i] + vector.vect[i];
  }
  return V;
}

Dvector& Dvector::operator -(const Dvector &vector)
{
  static Dvector V(dim);
  V = *this;
  for (int i=0; i< dim; i++)
  {
    V.vect[i] = vect[i] - vector.vect[i];
  }
  return V;
}

Dvector& Dvector::operator -()
{
  static Dvector V(dim);
  V =*this;
  for (int i=0; i< dim; i++)
  {
    V.vect[i] = - vect[i];
  }
  return V;
}

void Dvector::operator +=(Dvector &vector)
{
  for (int i=0; i< dim; i++)
  {
    vect[i] += vector.vect[i];
  }
}

void Dvector::operator -=(Dvector &vector)
{
  for (int i=0; i< dim; i++)
  {
    vect[i] -= vector.vect[i];
  }
}

void Dvector::operator *=(int n)
{
  for (int i=0; i< dim; i++)
  {
    vect[i] *= n;
  }
}

void Dvector::operator /=(int n)
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

Dvector& Dvector::operator <<(int n)
{
  static Dvector V(dim);
  V = *this;
  for (int j=0;j<n;j++){
    for (int i=0; i< dim; i++)
    {
      V.vect[i] = 2 * V.vect[i];
    }
  }
  return V;
}

Dvector& Dvector::operator >>(int n)
{
  static Dvector V(dim);
  V = *this;
  for (int j=0;j<n;j++){
    for (int i=0; i< dim; i++)
    {
      V.vect[i] = V.vect[i] / 2;
    }
  }
  return V;
}

bool Dvector::operator ==(Dvector &vector)
{
  bool res = true;
  for (int i=0; i< dim; i++)
  {
    res &= (vect[i] == vector.vect[i]);
  }
  return res;
}

void Dvector::resize (int taille, double val)
{
  double* copie=NULL;
  if (taille > dim){
    copie = (double*) realloc(vect,taille*sizeof(double));
    for (int i = dim; i < taille; i++)
    {
      copie[i] = val;
    }
  }
  vect=copie;
  free(copie);
  dim = taille;
}

Dvector::~Dvector()
{
  delete [] vect;
}
