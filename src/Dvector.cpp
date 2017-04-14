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
  this->im = new double[dim];
  for(int i=0;i<this->dim;i++){ 
    this->vect[i]=init;
    this->im[i]=init;
  }
}

Dvector::Dvector(const Dvector& v)
{
  this->dim = v.dim;
  this->vect = new double[v.dim];
  this->im = new double[v.dim];
  for (int i = 0; i < v.dim; i++){
    this->vect[i] = v.vect[i];
    this->im[i] = v.im[i];
  }
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
    this->im = new double[dim];
    for (int i = 0; i<dim; i++){
      im[i] = 0.0;
    }
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

double  Dvector::operator () (int i, bool return_im) const
{
  assert(i>=0 && i<dim);
  if (return_im == true){
    return im[i];
  }
  return vect[i];
}

double Dvector::operator () (int i, int j,int dimx) const{
  if(i*dimx+j>dim){
    std::cerr<<"ERR : Dvector::operator () :: indice out of bounds"<<std::endl;
  }
  return(this->vect[i*dimx+j]);
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
    im[i]=rand();
    // Si on divise par RAND_MAX, on obtient uniquement 0. Il faut ajouter un facteur supplémentaire.
  }
}

Dvector& Dvector::operator=(const Dvector &P)
{
  dim = P.dim;
  vect = new double[dim];
  im = new double[dim];
  memcpy(vect,P.vect,dim*sizeof(double));
  memcpy(im,P.im,dim*sizeof(double));
  return *this;
}

Dvector& Dvector::operator +(double f)
{
  static Dvector V(dim);
  for (int i=0; i< dim; i++)
  {
    V.vect[i] = vect[i] + f;
    V.im[i] = im[i] + f;
  }
  return V;
}

Dvector& Dvector::operator -(double f)
{
  static Dvector V(dim);
  for (int i=0; i< dim; i++)
  {
    V.vect[i] = vect[i] - f;
    V.im[i] = im[i] - f;
  }
  return V;
}

Dvector& Dvector::operator *(double f)
{
  static Dvector V(dim);;
  for (int i=0; i< dim; i++)
  {
    V.vect[i] = vect[i] * f;
    V.im[i] = im[i] * f;
  }
  return V;
}

Dvector& Dvector::operator /(double f)
{
  static Dvector V(dim) ;
  for (int i=0; i< dim; i++)
  {
    V.vect[i] = vect[i] / f;
    V.im[i] = im[i] / f;
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
    V.im[i] = im[i] + vector.im[i];
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
    V.im[i] = im[i] - vector.im[i];
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
    V.im[i] = - im[i];
  }
  return V;
}

void Dvector::operator +=(Dvector &vector)
{
  for (int i=0; i< dim; i++)
  {
    vect[i] += vector.vect[i];
    im[i] += vector.im[i];
  }
}

void Dvector::operator -=(Dvector &vector)
{
  for (int i=0; i< dim; i++)
  {
    vect[i] -= vector.vect[i];
    im[i] -= vector.im[i];
  }
}

void Dvector::operator *=(double f)
{
  for (int i=0; i< dim; i++)
  {
    vect[i] *= f;
    im[i] *= f;
  }
}

void Dvector::operator /=(double f)
{
  if (f!=0){
    for (int i=0; i< dim; i++)
    {
      vect[i] /= f;
      im[i] /= f;
    }
  }
  else {
    std::cout << "Division par 0" <<  std::endl;
  }
}

void Dvector::add(int i ,double f)
{
  if (i>=this->size()){
    std::cerr<<" Error : Dvector::add : indice out of bounds"<<std::endl;
  }else{
    this->vect[i]+=f;
  }

}

void Dvector::set(int const i , int const j ,int const dimx, double f){
  if(i*dimx+j>= dim){
    std::cerr<<"ERR : Dvector::set : indice out of bounds"<<std::endl;
  }
  this->vect[i*dimx+j]=f;

}

Dvector Dvector::conjugate(){
  for ( int i=0; i < dim; i++){
    this->im[i]=-this->im[i];
  }
  return *this;
}

Dvector& Dvector::operator <<(int n)
{
  static Dvector V(dim);
  V = *this;
  for (int j=0;j<n;j++){
    for (int i=0; i< dim; i++)
    {
      V.vect[i] = 2 * V.vect[i];
      V.im[i] = 2 * V.im[i];
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
      V.im[i] = V.im[i] / 2;
    }
  }
  return V;
}

bool Dvector::operator ==(Dvector &vector)
{
  bool res = true;
  for (int i=0; i< dim; i++)
  {
    res &= (vect[i] == vector.vect[i] && im[i] == vector.im[i]);
  }
  return res;
}

void Dvector::resize (int taille, double val)
{
  double* copie= NULL;
  double* im_copie = NULL;
  if (taille > dim){
    copie = (double*)malloc(taille*sizeof(double));
    im_copie = (double*)malloc(taille*sizeof(double));
    for (int i = 0; i < dim; i++)
    {
      copie[i] = vect[i];
      im_copie[i] = im[i];
    }
    for (int i = dim; i < taille; i++){
      copie[i] = val;
      im[i] = val;
    }
  } else {
    copie = (double*) malloc(taille*sizeof(double));
    im_copie = (double*) malloc(taille*sizeof(double));
    for (int i = 0; i < taille; i++){
      copie[i] = vect[i];
      im_copie[i] = im[i];
    }
  }
  vect=copie;
  im = im_copie;
  free(copie);
  free(im_copie);
  dim = taille;
}

Dvector::~Dvector()
{
  delete [] vect;
  delete [] im;
}
