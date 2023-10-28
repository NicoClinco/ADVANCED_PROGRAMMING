template<class T>
T& array<T>::getNum(unsigned int idx)
{
  if (idx<0 && idx>v1.size())
    std::cerr << "---ERROR---\n"<<std::endl;
  
  return v1[idx];
 
}
