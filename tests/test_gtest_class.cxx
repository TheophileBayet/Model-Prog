#include "gtest/gtest.h"
#include "../src/Dvector.h"


class DvectorTest: public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(DvectorTest,constructors){
    Dvector *nul = new Dvector();
    Dvector *vec2 = new Dvector(2);
    Dvector *vec4 = new Dvector(4,3.0);
    Dvector vec3(3,1);
    Dvector vec5(5);
    //string test_name = "/user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep/tests/test1.txt";
    //Dvector *name = new Dvector(test_name);

    EXPECT_EQ(0,nul->size());
    EXPECT_EQ(4,vec4->size());
    EXPECT_EQ(2,vec2->size());

    EXPECT_EQ(5,vec5.size());
    EXPECT_EQ(0,vec5(4));
    EXPECT_EQ(3,vec3.size());
    EXPECT_EQ(1,vec3(2));

    //EXPECT_EQ(10,name->size());

}

TEST_F(DvectorTest,internalFunctions){
    //Test display
    Dvector vect(3,2);
    stringstream disp;
    vect.display(disp);
    EXPECT_EQ(disp.str(),"2.00000\n2.00000\n2.00000\n");

    // Test fill random
    vect.fillRandomly();
    EXPECT_EQ(3,vect.size());

    // Test resize
    /*
    vect.resize(5,10.0);
    EXPECT_EQ(5,vect.size());
    EXPECT_EQ(10,vect(4));*/
}


TEST_F(DvectorTest,operators){
    Dvector vect1(3,2);
    Dvector vect2(3,3);
    Dvector vect3(3,0);
    Dvector vect4(4,7);
    Dvector *vect5 = new Dvector(5,1);

    vect1 = vect1 + 4;
    EXPECT_EQ(6,vect1(2));
    vect1 = vect1 - 3;
    EXPECT_EQ(3,vect1(1));
    vect1 = vect1 * 2;
    EXPECT_EQ(6,vect1(0));
    vect1 = vect1 / 6;
    EXPECT_EQ(1,vect1(2));

    vect3 = vect1 + vect2 ;
    EXPECT_EQ(4,vect3(2));
    EXPECT_EQ(3,vect2(0));
    EXPECT_EQ(1,vect1(1));

    vect3 = vect1 - vect2 ;
    EXPECT_EQ(-2,vect3(2));
    EXPECT_EQ(3,vect2(0));
    EXPECT_EQ(1,vect1(1));

    //vect3-();
    //EXPECT_EQ(2,vect3(2));

    vect4 += vect4;
    EXPECT_EQ(14,vect4(3));
    vect4 -= vect4;
    EXPECT_EQ(0,vect4(2));
    vect1 *= 3 ;
    EXPECT_EQ(3,vect1(2));
    vect2 /= 3 ;
    EXPECT_EQ(1,vect2(0));

    *vect5 = *vect5 << 3;
    EXPECT_EQ(8,(*vect5)(1));
    *vect5 = *vect5 >>1;
    EXPECT_EQ(4,(*vect5)(2));

    bool eq = vect1==vect2;
    bool fa = false;
    bool tr = true;
    EXPECT_EQ(fa,eq);
    eq = vect1==vect1;
    EXPECT_EQ(tr,eq);

}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
