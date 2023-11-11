#include <stdio.h>
#include <iostream>
#include <stdexcept>


class Vector
{
public:

  Vector(double* data,unsigned int size):
    size_{size}
  {
    // Remember to assert the size
    data_ = new double[size_];
    for(unsigned int i=0;i<size_;i++)
    {
      data_[i] = data[i];
    }
  }
  //Copy-constructor
  
  Vector(const Vector& rhs)
  {
    std::cout << "COPY-CONSTRUCTOR CALLED\n"<<std::endl;
    data_ = new double [rhs.size_];
    size_ = rhs.size_;
    for(unsigned int i=0;i<rhs.size_;i++)
    {
      data_[i] = rhs.data_[i];
    }
  }
  
  Vector& operator=(const Vector& rhs)
  {
    std::cout<< "COPY-ASSIGNMENT CALLED\n"<<std::endl;

    if(size_ != rhs.size_)
      throw std::invalid_argument( "received a different size" );

    
    for(unsigned int i=0;i<rhs.size_;i++)
    {
      data_[i] = rhs.data_[i];
    }
    return *this;
  }

  Vector(Vector&& rhs):
    size_{rhs.size_}
  {
    std::cout << " MOVE CONSTRUCTOR CALLED \n";
    delete[] data_;
    data_ = rhs.data_;
    rhs.data_ = nullptr; // 
  }

  ~Vector()
  {
    delete[] data_;
    data_ = nullptr; 
  }
  double* data_=nullptr;
  unsigned int size_;
};

  
  
int main()
{
  unsigned int size = 10;
  double* array = new double[size];

  for (int i=0;i<size;i++)
    array[i] = i/10.0;
  
  Vector v1(array,size);
  //Vector v2(v1);
  Vector v2(array,size);
  v2 = v1;

  Vector v3(std::move(v2));

  for (int i=0;i<size;i++)
    {
    std::cout << v3.data_[i] << " ";
    }
  return 0;
}
