#include"PhilipsWaveModel.h"
#include"math.h"


    PhilipsWaveModel::PhilipsWaveModel(Dvector windDirection, double intensity, Dvector wave, double waveHeight, double waveLength):WaveModel(windDirection,intensity,wave,waveHeight,waveLength){

    }
    PhilipsWaveModel::PhilipsWaveModel(const PhilipsWaveModel& pw):WaveModel(pw){

    }
    PhilipsWaveModel::~PhilipsWaveModel(){
        this->~WaveModel();
    }

    Dvector PhilipsWaveModel::fft(Dvector x){
      // Implémentation de la fft
    int n = x.size();
    if(x.size()<=1){
        return Dvector(x);
      }
    Dvector even = Dvector(n/2);
    Dvector odd = Dvector(n/2);
    Dvector y =Dvector(n,0);
    fft(even);
    fft(odd);

    for(int i = 0 ; i <n/2; i++){
      double t = odd(i)*exp(-2*M_PI*i/n);
      y.add(i,even(i)+t);
      y.add((i+n/2),even(i)-t);
    }
    return y;
    }


    Dvector PhilipsWaveModel::ifft(Dvector x){
      // Implémentation de la fft
    int n = x.size();
    if(x.size()<=1){
        return Dvector(x);
      }
    Dvector y =Dvector(n,0);
    x.conjugate();
    fft(x);
    y = x.conjugate()/n;
    return y;
    }
