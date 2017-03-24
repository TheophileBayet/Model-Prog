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
  this->windDirection = new Dvector(wave.windDirection);
  this->wave = new Dvector(wave.wave);
}

WaveModel::~WaveModel()
{
  delete [] wave;
  delete [] windDirection;
}

Dvector getWindDirection()
{
  return this->windDirection;
}

Dvector getWave()
{
  return this->wave;
}

double getIntensity()
{
  return this->intensity;
}

double getWaveHeight()
{
  return this->waveHeight;
}

double getWaveLength()
{
  return this->waveLength;
}

double WaveModel::operator ()(double x, double y, time t)
{
  return (x/y)*sin(t);
}
