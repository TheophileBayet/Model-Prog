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

void Ocean::compute()
{
  for (int i = 0; i < this->Nx; i++){
    for (int j = 0; j < this->Ny; j++){
      double val = this->Model(i,j,this->time);
      this->Hauteur.set(i,j,val);
    }
  }
}

int Ocean::get_lx(){
  return Length;
}


int Ocean::get_ly(){
  return Width;
}

int Ocean::getNx(){
  return Nx;
}

int Ocean::getNy(){
  return Ny;
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





void Ocean::init_gl_VertexArrayX(const int y, double* const vertices) const {
  for(int x=0 ; x<Nx ; x++) {
    vertices[3*x]   = (Length/Nx)*x;
    vertices[3*x+2] = (Width/Ny)*y;
  }
  vertices[3*Nx]   = Length;
  vertices[3*Nx+2] = (Width/Ny)*y;
}

void Ocean::init_gl_VertexArrayY(const int x, double* const vertices) const {
  for(int y=0 ; y<Ny ; y++) {
    vertices[3*y]   = (Length/Nx)*x;
    vertices[3*y+2] = (Width/Ny)*y;
  }
  vertices[3*Ny]   = (Length/Nx)*x;
  vertices[3*Ny+2] = Width;
}

void Ocean::gl_VertexArrayX(const int y, double* const vertices) const {
  for(int x=0 ; x<Nx ; x++) {
    vertices[3*x+1] = pow(-1, x+y)*Hauteur(y,x);
  }
  vertices[3*Nx+1] = pow(-1, Nx+y)*Hauteur(y,0);
}
void Ocean::gl_VertexArrayY(const int x, double* const vertices) const {
  for(int y=0 ; y<Ny ; y++) {
    vertices[3*y+1] = Hauteur(y,x);
  }
  vertices[3*Ny+1]  = Hauteur(0,x);
}
