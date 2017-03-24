

#ifndef HEIGHT
#define HEIGHT
#include"Dvector.h"
using namespace std;

class Height
{
  private :
    int dimx;
    int dimy;
    Dvector vect;
  public :
    Height();
    Height(int const dimx,int const  dimy, double init);
    Height(const Height& h);
    //TODO Height(std::string);
    ~Height();
    int getDimX();
    int getDimY();
    // Renvoie valeur hauteur du point;
    double operator () (int i, int j) const;
};
#endif
