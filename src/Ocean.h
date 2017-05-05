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
    void compute();
    int get_ly();
    int get_lx();
    int getNx();
    int getNy();
    //TODO: à vérifier
    void gl_vertices();


    // importé de ocean.hxx :
    /** Initialise la grille dans la direction x
 *  param[in]   y        abscisse de la colonne à parcourir
 *  param[out]  vertices buffer contenant les coordonnées des noeuds
 */
void init_gl_VertexArrayX(const int y, double* const vertices) const ;
/** Initialise la grille dans la direction y
 *  param[in]   x        abscisse de la ligne à parcourir
 *  param[out]  vertices buffer contenant les coordonnées des noeuds
 */
void init_gl_VertexArrayY(const int x, double* const vertices) const ;

/** Convertit le champs de hauteur en tabeau directement utilisable
 *  par OpenGL pour un y donné
 *  param[in]   y        abscisse de la colonne à parcourir
 *  param[out]  vertices buffer contenant les valeurs aux noeuds
 */
void gl_VertexArrayX(const int y, double* const vertices) const ;

/** Convertit le champs de hauteur en tabeau directement utilisable
 *  par OpenGL pour un x donné
 *  param[in]   x        abscisse de la ligne à parcourir
 *  param[out]  vertices buffer contenant les valeurs aux noeuds
 */
void gl_VertexArrayY(const int x, double* const vertices) const ;


};
#endif
