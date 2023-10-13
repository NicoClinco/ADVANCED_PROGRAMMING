#ifndef POWERCLASS_H 
#define POWERCLASS_H

#include<iostream>
#include<cmath>

namespace My_Math{
  class powersMath;
}

class My_Math::powersMath{
      public:
	float num_;
	powersMath(const float& num):
		num_(num)
	{};
	float ReturnSquare();
	float ReturnPower();
};

#endif
