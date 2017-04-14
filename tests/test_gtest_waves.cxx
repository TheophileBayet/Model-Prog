#include "gtest/gtest.h"
#include "../src/Dvector.h"
#include "../src/Height.h"
#include "../src/WaveModel.h"
#include "../src/GerstnerWave.h"
#include "../src/PhilipsWaveModel.h"
#include "../src/Ocean.h"


class WavesTest: public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(WavesTest,constructorsAndAccessors_Height){


  // TESTS HEIGHT

    Height *h1 = new Height();
    EXPECT_EQ(0,h1->getDimY());
    EXPECT_EQ(0,h1->getDimX());
    Height *h2 = new Height(2,2,10);
    EXPECT_EQ(2,h2->getDimX());
    EXPECT_EQ(2,h2->getDimY());
    EXPECT_EQ(10,(*h2)(1,1));
    Height h4(4,4,4);
    EXPECT_EQ(4,h4.getDimX());
    EXPECT_EQ(4,h4.getDimY());
    EXPECT_EQ(4,h4(3,3));
    Height h5(*h2);
    EXPECT_EQ(2,h5.getDimX());
    EXPECT_EQ(2,h5.getDimY());
    EXPECT_EQ(10,h5(1,1));

 // FIN TESTS HEIGHT
 }

TEST_F(WavesTest,constructorsAndAccessors_WaveModel){

 // TESTS WAVEMODEL
    Dvector vect1(3,2);
    Dvector vect2(3,3);
    WaveModel *wm1 = new WaveModel(vect1,10.0,vect2,10.0,10.0);
    EXPECT_EQ(10.0,wm1->getIntensity());
    EXPECT_EQ(10.0,wm1->getWaveHeight());
    EXPECT_EQ(10.0,wm1->getWaveLength());
    WaveModel *wm2 = new WaveModel(*wm1);
    EXPECT_EQ(10.0,wm2->getIntensity());
    EXPECT_EQ(10.0,wm2->getWaveHeight());
    EXPECT_EQ(10.0,wm2->getWaveLength());

 // FIN TESTS WAVEMODEL

}


TEST_F(WavesTest,constructorsAndAccessors_GerstnerWave){

  Dvector vect1(3,2);
  Dvector vect2(5,5);

  GerstnerWave *gw1 = new GerstnerWave(5.0,vect1,1.0,0.5);
  EXPECT_EQ(5.0,gw1->getAmplitude());
  EXPECT_EQ(1.0,gw1->getPhase());
  EXPECT_EQ(0.5,gw1->getFreq());
  GerstnerWave *gw2 = new GerstnerWave(*gw1);
  EXPECT_EQ(5.0,gw2->getAmplitude());
  EXPECT_EQ(1.0,gw2->getPhase());
  EXPECT_EQ(0.5,gw2->getFreq());

}


TEST_F(WavesTest,constructors_PhilipsWaveModel){
  // DEBUT DES TESTS PHILIPSWAVEMODEL

  Dvector wind(5,5);
  Dvector wave(6,6);

  PhilipsWaveModel *pw1 = new PhilipsWaveModel(wind,5.0,wave,10.0,15.0);


  PhilipsWaveModel *pw2 = new PhilipsWaveModel(*pw1);

  // FIN DES TESTS PHILIPSWAVEMODEL
}



TEST_F(WavesTest,constructorsAndAccessors_Ocean){
    // DEBUT DES TESTS OCEAN

    Dvector vect1(3,2);
    Dvector vect2(3,3);
    WaveModel *wm1 = new WaveModel(vect1,10.0,vect2,10.0,10.0);


    // FIN DES TESTS OCEAN
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
