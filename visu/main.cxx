#include <cstdlib>
#include <ctime>
#include <iostream>

/** @todo Inclure les fichiers de définition du problème */

#include "window.hxx"
  int mainwindow;
  Ocean* ocean;

int main(int argc, char** argv) {
  /** @todo Initialiser des paramètres de simulation */

  /** @todo Initialiser du modèle*/

  /** @todo Initialiser du champ de hauteur */

  /** @todo Initialiser de l'océan */

  /* Initialisation de la fenêtre d'affichage */
  Window::init(WIDTH, HEIGHT1, "Houle", argc, argv, "AZERTY", 50, 1);

  /* Execute la simulation */
  Window::launch();

  /* Libère la mémoire */
  Window::quit();
  delete ocean;

  return 0;

}
