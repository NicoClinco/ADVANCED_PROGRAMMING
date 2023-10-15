/*

 File that contains many functions for post-processing

*/

// Print a vector:
template<class type>
void printVector
(
 const std::vector<type>& vP
)
{
  for ( const type& elem : vP )
    std::cout << elem << " "; 
    
  std::cout  << "\n"<< std::endl;    
}



