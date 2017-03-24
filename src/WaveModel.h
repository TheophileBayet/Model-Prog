#ifndef WAVEMODEL
#define WAVEMODEL

#include "Dvector.h"

using namespace std;

class WaveModel
{
  private:
    Dvector windDirection;
    double intensity;
    Dvector wave;
    double waveLength;
    double waveHeight;
  public:
    //WaveModel();
    WaveModel(Dvector windDirection, double intensity, Dvector wave, double waveHeight, double waveLength);
    WaveModel(const WaveModel& w);
    ~WaveModel();
    //WaveModel(.....);
    Dvector getWindDirection();
    double getIntensity();
    Dvector getWave();
    double getWaveLength();
    double getWaveHeight();

    double operator () (const double x,const double y,const int t) const;
};
#endif
