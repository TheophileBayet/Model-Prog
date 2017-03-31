#include "gtest/gtest.h"
#include "../src/Dvector.h"
#include "../src/Height.h"
#include "../src/WaveModel.h"


class WavesTest: public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(WavesTest,constructorsAndAccessors){


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
    WaveModel wm3(vect1,5.0,vect2,5.0,5.0);
    EXPECT_EQ(5.0,wm3.getIntensity());
    EXPECT_EQ(5.0,wm3.getWaveHeight());
    EXPECT_EQ(5.0,wm3.getWaveLength());
    /*WaveModel wm4(wm3);
    EXPECT_EQ(5.0,wm4.getIntensity());
    EXPECT_EQ(5.0,wm4.getWaveHeight());
    EXPECT_EQ(5.0,wm4.getWaveLength());
    /*WaveModel wm5(*wm1);
    EXPECT_EQ(10.0,wm5.getIntensity());
    EXPECT_EQ(10.0,wm5.getWaveHeight());
    EXPECT_EQ(10.0,wm5.getWaveLength());
  */
 // FIN TESTS WAVEMODEL

}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
