#include "GerstnerWave.h"

GerstnerWave::GerstnerWave(const GerstnerWave& gw)
{
  this->amplitude = gw.amplitude;
  this->freq = gw.freq;
  this->phase = gw.phase;
  this->direction =Dvector(gw.direction);
}

GerstnerWave::~GerstnerWave()
{
  delete [] &direction;
}

double GerstnerWave::getAmplitude()
{
  return this->amplitude;
}

double GerstnerWave::getPhase()
{
  return this->phase;
}

double GerstnerWave::getFreq()
{
  return this->freq;
}

Dvector GerstnerWave::getDirection()
{
  return this->direction;
}

/*int getSeed()
{
  return this->seed;
}*/

double GerstnerWave::operator ()(double x, double y)
{
  assert(y != 0);
  return this->amplitude * x/y;
}
