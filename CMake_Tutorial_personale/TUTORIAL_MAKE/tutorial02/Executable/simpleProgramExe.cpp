#include <iostream>
#include <cmath>

#include "TutorialConfig.h"
#include "Header.h"

#ifdef USE_LIBS_EXE
#include "SquareRoot.cpp"
#include "Square.cpp"
#endif



int main()
{

  std::cout << Tutorial_VERSION_MAJOR << std::endl;
  std::cout << Tutorial_VERSION_MINOR << std::endl;
	
  std::cout << "Included: " << DeclaredVariable << std::endl;

  std::cout << "Variable: " << boolean_var << std::endl;
//  float squareC = MyMath::Square(0.55,2);
 //std::cout << squareC << std::endl;
 #ifdef USE_LIBS_EXE
   float sqrtc = MyMath::SquareRoot(0.55);
   float sqrc = MyMath::Square(0.55,2);
   std::cout << "The library is present\n"<< std::endl;
 #else
   float sqrtc = sqrt(0.55);
   float sqrc = pow(0.55,2);
   std::cout << "The library is not present\n"<< std::endl;

 #endif
 std::cout << " sqrtC is " << sqrtc << std::endl;
 std::cout << " sqrC is " << sqrc << std::endl;
}
