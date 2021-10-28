#include <iostream>
#include <fstream>
#include "gtest/gtest.h"
#include "Grid.h"
#include "string"

using std::string;
using std::ifstream, std::ofstream;

const string inFolder = "in/";
const string outFolder = "sols/";

TEST(solveTest, 1Solution_nums1) {
   ifstream fin;
   ofstream fout;
   string file = "nums1.txt";
   fin.open(inFolder + file);
   ASSERT_TRUE(fin);
   fout.open(outFolder + file);
   ASSERT_TRUE(fout);
   Grid grid;
   fin >> grid;
   fin.close();
   grid.solve(fout);
   fout.close();
   EXPECT_EQ(1, grid.numberOfSolutions());
}
TEST(solveTest, 1Solution_nums2) {
   ifstream fin;
   ofstream fout;
   string file = "nums2.txt";
   fin.open(inFolder + file);
   ASSERT_TRUE(fin);
   fout.open(outFolder + file);
   ASSERT_TRUE(fout);
   Grid grid;
   fin >> grid;
   fin.close();
   grid.solve(fout);
   fout.close();
   EXPECT_EQ(1, grid.numberOfSolutions());
}
TEST(solveTest, 2Solution_nums3) {
   ifstream fin;
   ofstream fout;
   string file = "nums3.txt";
   fin.open(inFolder + file);
   ASSERT_TRUE(fin);
   fout.open(outFolder + file);
   ASSERT_TRUE(fout);
   Grid grid;
   fin >> grid;
   fin.close();
   grid.solve(fout);
   fout.close();
   EXPECT_EQ(2, grid.numberOfSolutions());
}
TEST(solveTest, 3Solution_nums4) {
   ifstream fin;
   ofstream fout;
   string file = "nums4.txt";
   fin.open(inFolder + file);
   ASSERT_TRUE(fin);
   fout.open(outFolder + file);
   ASSERT_TRUE(fout);
   Grid grid;
   fin >> grid;
   fin.close();
   grid.solve(fout);
   fout.close();
   EXPECT_EQ(3, grid.numberOfSolutions());
}
TEST(solveTest, 18Solution_nums5) {
   ifstream fin;
   ofstream fout;
   string file = "nums5.txt";
   fin.open(inFolder + file);
   ASSERT_TRUE(fin);
   fout.open(outFolder + file);
   ASSERT_TRUE(fout);
   Grid grid;
   fin >> grid;
   fin.close();
   grid.solve(fout);
   fout.close();
   EXPECT_EQ(18, grid.numberOfSolutions());
}
TEST(solveTest, 12Solution_nums6) {
   ifstream fin;
   ofstream fout;
   string file = "nums6.txt";
   fin.open(inFolder + file);
   ASSERT_TRUE(fin);
   fout.open(outFolder + file);
   ASSERT_TRUE(fout);
   Grid grid;
   fin >> grid;
   fin.close();
   grid.solve(fout);
   fout.close();
   EXPECT_EQ(12, grid.numberOfSolutions());
}
