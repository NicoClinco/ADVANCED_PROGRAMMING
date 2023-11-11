#include <random>
#include <stdio>
#include <iostream>
#include <cmath>


int main()
{
  //std::random_device rd;
  unsigned int counter = 0;
  unsigned int nPoints = 100;
  std::default_random_engine rd3{1};
  std::uniform_real_distribution<double> dist(0,1);

  for(unsigned int i=0;i<nPoints;++i)
    {
  const double x = dist(rd3);
  const double y = dist(rd3);

  double dist_ = pow(pow(x,2)+pow(y,2),0.5);
  if (dist_<1.0)
    {
      counter++;
    }
  }
  
  return 0;
}
