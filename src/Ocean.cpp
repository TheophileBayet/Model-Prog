#include "Ocean.h"
#include "WaveModel.h"

Ocean::Ocean(const int Length,const int Width,const int Nx,const int Ny, WaveModel Model)
{
  this->Length = Length;
  this->Width = Width;
  this->Nx = Nx;
  this->Ny = Ny;
  assert(Nx != 0); assert(Ny != 0);
  this->Hauteur = Height(Nx, Ny, 0.0);
  this->Model = Model;
  this->vertices = new double[Nx*Ny];
}

Ocean::~Ocean()
{
  delete [] vertices;
}

void Ocean::generateHeight(double h)
{
  this->Hauteur = Height(this->Length, this->Width, h);
}

void Ocean::compute(int time)
{
  for (int i = 0; i < this->Nx; i++){
    for (int j = 0; j < this->Ny; j++){
      double val = this->Model(i,j,time);
      this->Hauteur.set(i,j,val);
    }
  }
}


//TODO : à revoir
void Ocean::gl_vertices()
{
  // Pour y
  for (int x=0 ; x<this->Nx ; x++){
    for(int y=0 ; y<this->Ny ; y++) {
      this->vertices[3*y+1] = this->Hauteur(y,x);
    }
    this->vertices[3*this->Ny+1]  = this->Hauteur(0,x);
  }
  // Pour x
  for (int y=0 ; y<this->Ny ; y++){
    for(int x=0 ; y<this->Nx ; x++) {
      this->vertices[3*x] = this->Hauteur(y,x);
    }
    this->vertices[3*this->Nx]  = this->Hauteur(y,0);
  }
}
