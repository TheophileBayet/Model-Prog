#include"PhilipsWaveModel.h"


    PhilipsWaveModel::PhilipsWaveModel(Dvector windDirection, double intensity, Dvector wave, double waveHeight, double waveLength):WaveModel(windDirection,intensity,wave,waveHeight){

    }
    PhilipsWaveModel::PhilipsWaveModel(const PhilipsWaveModel& w):WaveModel(pw){

    }
    PhilipsWaveModel::~PhilipsWaveModel():~WaveModel(){
      
    }
