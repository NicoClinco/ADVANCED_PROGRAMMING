#include <iostream>
 #include <vector>


int main()
{
 
 std::vector<float> a{1,3,4,31,92.1};

 for (float num : a)
   num = 1.0;
 
 for (float num : a)
  std::cout << num << std::endl; 
 
 return 0;
}
