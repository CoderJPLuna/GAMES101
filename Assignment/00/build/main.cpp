#include<cmath>
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Dense>
#include <eigen3/Eigen/src/Core/Matrix.h>
#include<iostream>

int main()
{
  float rad = 45.0f * 3.1415926f / 180.0f;
  Eigen::Vector3f P(2,1,1);
  Eigen::Matrix3f R;
  R <<  cos(rad),-sin(rad), 0,
        sin(rad), cos(rad), 0,
        0       , 0       , 1;
  Eigen::Matrix3f T;
  T <<  1, 0, 1,
        0, 1, 2,
        0, 0, 1;
  Eigen::Vector3f ret;
  ret = T * R * P;
  std::cout << ret << std::endl;
  return 0;
}
