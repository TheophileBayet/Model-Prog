#ifndef GERSTNERWAVE
#define GERSTNERWAVE
#include "WaveModel.h"

class GerstnerWave
{
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

    double operator ()(double x, double y, int time);

};
#endif
