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
    string test_name = "/user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep/tests/test1.txt";
    Dvector *name = new Dvector(test_name);

    EXPECT_EQ(0,nul->size());
    EXPECT_EQ(4,vec4->size());
    EXPECT_EQ(2,vec2->size());

    EXPECT_EQ(5,vec5.size());
    EXPECT_EQ(0,vec5(4));
    EXPECT_EQ(3,vec3.size());
    EXPECT_EQ(1,vec3(2));

    EXPECT_EQ(10,name->size());


}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
