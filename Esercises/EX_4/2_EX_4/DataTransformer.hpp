#ifndef _DATATRANSFORMER_
#define _DATATRANSFORMER_

#include <iostream>
#include <vector>

class DataTransformer
{
 public:

  DataTransformer()= default;
  
  std::vector<float> data()
  {
    return _dataTransformed_;
  }
  
  // transform the vector in DataSource
  virtual void transform(DataSource& source) = 0;

 protected:
  std::vector<float> _dataTransformed_; //Transformed
  
};// end class DataTransf


class LinearScaler:
  public DataTransformer
{
  LinearScaler(const float& k):
    DataTransformer(),k_{k}
  {};
 
  void transform(DataSource& source) override
  {
    std::cout << "Applying a linear transformation \n"<<std::endl;
    for(auto& _ : source._data_)
      _*=k_;
  }
protected:
  float k_{1.0};
};

class LogTransformer:
  public DataTransformer
{
 public:
  void transform(DataSource& source) override
  {
    std::cout << "Applying a log-transformation\n"<<std::endl;
        for(auto& _ : source._data_)
	  ( _ >0 ? _ = log(_) : _ = 0.0);
  }
  
};

/*
class StandardScaler:
  public DataTransformer
{
 public:
    void transform(const DataSource& source) override
  {
  
  }
}
*/

#endif
