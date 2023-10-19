template<class type>
class ADdouble
{
  
  public:

  ADdouble(type (*fToStore)(const type&)):
    _func_(fToStore)
  {}
  
  virtual type evaluate(){
    return type(0)};

  virtual type evaluate_derivative(){return type(0)};

 private:

  type *(_func_)(const type&)=nullptr; 
  //Pointer to a function:
  
}

template<class type>
class Scalar:
   public ADdouble<type>
{
 public:

  virtual type evaluate() override
  {
    // BHO
  }

  virtual type evaluate_derivative() = 0
  {
    // BHO
  }
  
}
 


