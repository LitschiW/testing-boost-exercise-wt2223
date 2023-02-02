#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <Eigen/Dense>
#include "matrixIO.hpp"
#include <fstream>

using namespace Eigen;

BOOST_AUTO_TEST_SUITE(MatrixIOTests)

BOOST_AUTO_TEST_CASE(TestSaveData)
{
  MatrixXd matrix(3, 3);
  matrix << 1, 2, 3,
      4, 5, 6,
      7, 8, 9;
  matrixIO::saveData("test.csv", matrix);

  std::ifstream f("test.csv");
  bool          file_exists = f.good();

  BOOST_TEST(file_exists);
}

BOOST_AUTO_TEST_CASE(TestOpenData)
{
  MatrixXd matrix(3, 3);
  matrix << 1, 2, 3,
      4, 5, 6,
      7, 8, 9;
  matrixIO::saveData("test.csv", matrix);

  MatrixXd matrix2 = matrixIO::openData("test.csv", 3);
  BOOST_TEST(matrix == matrix2);
}

BOOST_AUTO_TEST_SUITE_END()