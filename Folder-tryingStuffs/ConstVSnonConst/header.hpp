#ifndef _header_H
#define  _ header_H

#include <stdexcept>

template <class T>
class array
{
public:
  array(const std::vector<T>& v2):v1(v2) {};

  T& getNum(unsigned int idx);
private:
  std::vector<T> v1;
};

// I have included the header:
#include "header.tpl.hpp"
#endif
