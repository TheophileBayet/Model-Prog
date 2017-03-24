#include "WaveModel.h"
#include "math.h"

WaveModel::WaveModel(Dvector windDirection, double intensity, Dvector wave, double waveHeight, double waveLength)
{
  this->windDirection = windDirection;
  this->intensity = intensity;
  this->wave = wave;
  this->waveHeight = waveHeight;
  this->waveLength = waveLength;
}

WaveModel::WaveModel(const WaveModel& wave)
{
  this->intensity = wave.intensity;
  this->waveLength = wave.waveLength;
  this->waveHeight = wave.waveHeight;
  this->windDirection = Dvector(wave.windDirection);
  this->wave = Dvector(wave.wave);
}

WaveModel::~WaveModel()
{
  delete [] &wave;
  delete [] &windDirection;
}

Dvector WaveModel::getWindDirection()
{
  return this->windDirection;
}

Dvector WaveModel::getWave()
{
  return this->wave;
}

double WaveModel::getIntensity()
{
  return this->intensity;
}

double WaveModel::getWaveHeight()
{
  return this->waveHeight;
}

double WaveModel::getWaveLength()
{
  return this->waveLength;
}

double WaveModel::operator ()(const double x,const double y,const int t) const
{
  return (x/y)*sin(t);
}
