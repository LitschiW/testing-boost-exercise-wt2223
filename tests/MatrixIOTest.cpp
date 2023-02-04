#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include <fstream>
#include "matrixIO.hpp"

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

  for (int i = 0; i < matrix.rows(); i++) {
    for (int j = 0; j < matrix.cols(); j++) {
      BOOST_TEST(matrix(i, j) == matrix2(i, j));
    }
  }
}

BOOST_AUTO_TEST_SUITE_END()