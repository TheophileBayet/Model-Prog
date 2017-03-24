#include"PhilipsWaveModel.h"


    PhilipsWaveModel::PhilipsWaveModel(Dvector windDirection, double intensity, Dvector wave, double waveHeight, double waveLength):WaveModel(windDirection,intensity,wave,waveHeight,waveLength){

    }
    PhilipsWaveModel::PhilipsWaveModel(const PhilipsWaveModel& pw):WaveModel(pw){

    }
    PhilipsWaveModel::~PhilipsWaveModel(){
        this->~WaveModel();
    }
