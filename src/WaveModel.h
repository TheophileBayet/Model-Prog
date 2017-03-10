#include "Dvector.h";

using namespace std;

class WaveModel
{
  private :
    Dvector winddirection;
    double intensity;
    Dvector wave;
    double wavelength;
    double waveheight;
  public :
    WaveModel();
    WaveModel(const WaveModel& w);
    //WaveModel(.....);

}
