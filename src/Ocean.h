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
    void gl_initY(int x);
    void gl_initX(int y);
    void gl_X(int y);
    void gl_Y(int x);
  public :
    Ocean(int Length, int Width,const int Nx,const int Ny, WaveModel Model);
    ~Ocean();
    void generateHeight(double h);
    void compute(int time);

    //TODO: à vérifier
    void gl_vertices();
};
#endif
