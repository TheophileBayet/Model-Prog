#include <cstdlib>
#include <ctime>
#include <iostream>

/** @todo Inclure les fichiers de définition du problème */

#include "window.hxx"
  int mainwindow;
  Ocean* ocean ;

int main(int argc, char** argv) {
  /** @todo Initialiser des paramètres de simulation */
  int Lx = WIDTH;
  int Ly = HEIGHT1;
  int Nx = 30;
  int Ny = 30 ;
   // TESTS WAVEMODEL
    Dvector *vect1= new Dvector(10,10);
    Dvector *vect2= new Dvector(12,10);
    WaveModel *wm1 = new WaveModel(*vect1,50.0,*vect2,Ly,Lx);
    ocean = new Ocean(Lx,Ly,Nx,Ny,*wm1);
  /** @todo Initialiser du modèle*/

  /** @todo Initialiser du champ de hauteur */
  ocean->generateHeight(HEIGHT1);
  /** @todo Initialiser de l'océan */
  ocean->gl_vertices();
  /* Initialisation de la fenêtre d'affichage */
  Window::init(WIDTH, HEIGHT1, "Houle", argc, argv, "AZERTY", 50, 1);

  /* Execute la simulation */
  Window::launch();

  /* Libère la mémoire */
  Window::quit();
  delete ocean;

  return 0;

}
