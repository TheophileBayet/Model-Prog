#include "GerstnerWave.h"

GerstnerWave::GerstnerWave(const GerstnerWave& gw)
{
  this->amplitude = gw.amplitude;
  this->freq = gw.freq;
  this->phase = gw.phase;
  this->direction = new Dvector(gw.direction);
}

GerstnerWave::~GerstnerWave()
{
  delete [] direction;
}

double getAmplitude()
{
  return this->amplitude;
}

double getPhase()
{
  return this->phase;
}

double getFreq()
{
  return this->freq;
}

Dvector getDirection()
{
  return this->direction;
}

/*int getSeed()
{
  return this->seed;
}*/

double GerstnerWave::operator ()(double x, double y)
{
  double z = 0.0;
  
  return z;
}
