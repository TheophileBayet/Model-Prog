#include "Ocean.h"
#include "WaveModel.h"
#include <tgmath.h>

Ocean::Ocean(const int Length,const int Width,const int Nx,const int Ny, WaveModel Model)
{
  this->Length = Length;
  this->Width = Width;
  this->Nx = Nx;
  this->Ny = Ny;
  assert(Nx != 0); assert(Ny != 0);
  this->Hauteur = Height(Nx, Ny, 0.0);
  this->Model = Model;

  this->vertices = new double[3*(Ny+Nx)];
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


//TODO : NO Sé ... A revoir
void Ocean::gl_vertices()
{
  for (int x=0 ; x<this->Nx ; x++){
    gl_initY(x);
    for (int y=0 ; y<this->Ny ; y++){
      gl_initX(y);
    }
  }
  for (int x=0 ; x<this->Nx ; x++){
    gl_Y(x);
    for (int y=0 ; y<this->Ny ; y++){
      gl_X(y);
    }
  }
}

void Ocean::gl_initX(int y)
{
  for (int x=0 ; x<this->Nx ; x++){
    this->vertices[3*x] = (this->Length / this->Nx)*x;
    this->vertices[3*x +2] = (this->Width / this->Ny)*y;
  }
  this->vertices[3*this->Nx] = this->Length;
  this->vertices[3*this->Nx +2] = (this->Width / this->Ny)*y;
}

void Ocean::gl_initY(int x)
{
  for (int y=0 ; y<this->Ny ; y++){
    this->vertices[3*y] = (this->Length / this->Nx)*x;
    this->vertices[3*y +2] = (this->Width / this->Ny)*y;
  }
  this->vertices[3*this->Ny] = (this->Length / this->Nx)*x;
  this->vertices[3*this->Ny +2] = this->Width;
}

void Ocean::gl_X(int y)
{
  for (int x=0 ; x<this->Nx ; x++){
    this->vertices[3*x +1] = pow(-1,x+y)*this->Hauteur(y,x); //TODO
  }
  this->vertices[3*this->Nx +1] = pow(-1,this->Nx +y)*this->Hauteur(y,0); //TODO
}

void Ocean::gl_Y(int x)
{
  for (int y=0 ; y<this->Ny ; y++){
    this->vertices[3*y +1] = this->Hauteur(y,x);
  }
  this->vertices[3*this->Ny +1] = this->Hauteur(0,x);
}
