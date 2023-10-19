#ifndef CLASS_H
#define CLASS_H

template<class type>
class ADdouble
{
  
  public:

  ADdouble(type (*fToStore)(const type&)):
    _func_(fToStore)
  {}
  
  virtual type evaluate(const type& x) const = 0;

  virtual type evaluate_derivative(const type& x) const = 0;

  virtual ADdouble<type>& operator + (const ADdouble<type>& _tosum_) =  0;
  
  //virtual ADdouble operator -() =  0;
  //virtual ADdouble  operator *() = 0;
  


 protected:

  type (*_func_)(const type&); 
  //Pointer to a function:
  
};

template<class type>
class Scalar:
   public ADdouble<type>
{
 public:

  Scalar(type (*fToStore)(const type&)):
    ADdouble<type>(fToStore)
  {};

  virtual type evaluate(const type& x) const;
 
  virtual type evaluate_derivative(const type& x) const;

  virtual ADdouble<type>& operator + (const ADdouble<type>& _tosum_) =  0;
  
  
};

template<class type>
type Scalar<type>::evaluate(const type& x) const
{
  return (*this)._func_(x);
}

template<class type>
type Scalar<type>::evaluate_derivative(const type& x) const
{
  // Evaluate the derivative with forward difference:
  type f_x0 = (*this)._func_(x);
  type h    = type(0.001);
  type f_xh = (*this)._func_(x+h);
  
  return type((f_xh-f_x0)/h);
}
/*
template<class type>
ADdouble<type>& Scalar<type>::operator + (const ADdouble<type>& _tosum_) const
{
  (*this)
}
*/



#endif


