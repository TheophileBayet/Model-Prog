#include "WaveModel.h"

class GerstnerWave
{
/*  protected :
    int seed*/
  private:
    double amplitude;
    double phase;
    Dvector direction;
    double freq;
  public:
    GerstnerWave(double amplitude, Dvector direction, double phase, double freq);
    GerstnerWave(const GerstnerWave& gw);
    ~GerstnerWave();
    double getAmplitude();
    double getPhase();
    double getFreq();
    Dvector getDirection();
    //int getSeed();

    double operator ()(double x, double y);

}
