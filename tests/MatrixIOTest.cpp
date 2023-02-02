#define BOOST_TEST_DYN_LINK

#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "Configuration.hpp"
#include "MatrixIO.hpp"

using namespace Eigen;

BOOST_AUTO_TEST_SUITE(MatrixIOTests)
{
  BOOST_AUTO_TEST_CASE(TestSaveData)
  {
    MatrixXd matrix(3, 3);
    matrix << 1, 2, 3,
        4, 5, 6,
        7, 8, 9;
    matrixIO::saveData("test.csv", matrix);

    struct stat buffer;
    bool        file_exists = (stat(name.c_str(), &buffer) == 0);

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
}