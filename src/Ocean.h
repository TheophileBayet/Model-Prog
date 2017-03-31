#ifndef OCEAN
#define OCEAN

#include"Height.h"
#include "WaveModel.h"

class Ocean
{
  private :
    int Length;
    int Width;
    int Nx;
    int Ny;
    int time;
    Height Hauteur;
    WaveModel Model;
    double* vertices;
  public :
    Ocean(int Length, int Width,const int Nx,const int Ny, WaveModel Model);
    ~Ocean();
    void generateHeight(double h);
    void compute(int time);

    //TODO: à vérifier
    void gl_vertices();
};
#endif
