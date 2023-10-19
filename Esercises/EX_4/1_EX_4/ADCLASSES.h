#ifndef CLASSAD_H
#define CLASSAD_H


template<class type>
class ADexpression
{
 public:

  ADexpression() = default;

  virtual type evaluate() const = 0;

  virtual type evaluate_der() const = 0;

  
};

template<class type>
class Var:
  public ADexpression<type>
{
 public:
  
 Var(const type& value):
   value_(value){};

  virtual type evaluate() const
  {
    return value_;
  }

  virtual type evaluate_der() const
  {
    return type(1.0);
  }

 private:
  type value_;
  
};


/*----------------------*/
template<class type>
class Sum:
  public ADexpression<type>
{
 public:

  Sum(const ADexpression<type>& a,
      const ADexpression<type>& b):a(a),b(b)
  {};

    virtual type evaluate() const
    {
      return a.evaluate()+b.evaluate();
    }

    virtual type evaluate_der() const
    {
      return a.evaluate_der() + b.evaluate_der();
    }
 private:
  const ADexpression<type>& a;
  const ADexpression<type>& b;
};

/*-----------------------*/

template<class type>
class Product:
  public ADexpression<type>
{
 public:

  Product(const ADexpression<type>& a,
	  const ADexpression<type>& b):a(a),b(b)
  {};

  virtual type evaluate() const
  {
    return a.evaluate()*b.evaluate();
  }

  virtual type evaluate_der() const
  {
    return a.evaluate_der()*b.evaluate()+a.evaluate()*b.evaluate_der();
  }
   
 private:
  const ADexpression<type>& a;
  const ADexpression<type>& b;
  
};




#endif
