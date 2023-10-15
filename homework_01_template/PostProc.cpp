#include <vector>


template<class type>
std::vector<type> printVector
(
 const std::vector<type>& vP
)
{
  for ( const type& elem : vP )
    std::cout << elem << " "; 
    
  std::cout  << std::endl;    
}
