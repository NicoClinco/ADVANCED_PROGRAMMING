
#include <iostream>
#include <vector>

class Array
{
 public:
  Array(const std::vector<float> &data) : data(data) {}

  // Writing operator:
   const float& operator() (unsigned int idx) const
  {
    
    std::cout<< "const version\n"<<std::endl;
    return data[idx];
  }
  // Reading operator:
  float& operator () (unsigned int idx)
  {
    std::cout<< "non-const version\n"<<std::endl;
    return data[idx];
  }

private:
  std::vector<float> data;
};

int main()
{
  std::vector<float> d1{1.1,2.2,3.3,4.4};
  Array a(d1);

  const Array& a_const = a;
  
  const float& x = a_const(2);
  

  std::cout<<x<<std::endl;
 
 return 0;
}
