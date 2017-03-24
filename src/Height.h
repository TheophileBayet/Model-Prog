  using namesapce std;

class Height
{
  private :
    int dimx;
    int dimy;
    double** vect;
  public :
    Height();
    Height(int dimx, int dimy, double init);
    Height(const Height& h);
    //TODO Height(std::string);
    ~Height();
    int getDimX();
    int getDimY();
    // Renvoie valeur hauteur du point;
    double operator () (int i, int j) const;
}