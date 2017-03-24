
#ifndef PHILIPSWAVEMODEL
#define PHILIPSWAVEMODEL
#include"WaveModel.h"

class PhilipsWaveModel:public WaveModel
{
private:

  public:
    PhilipsWaveModel(Dvector windDirection, double intensity, Dvector wave, double waveHeight, double waveLength);
    PhilipsWaveModel(const WaveModel& w);
    ~PhilipsWaveModel();





};

#endif