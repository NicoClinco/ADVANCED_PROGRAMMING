#include <math.h>
#include <stdio.h>
#include <iostream>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_sf_gamma.h>
#include <memory>
#include <cassert>
#include <vector>

int main(){
  

  // just allocate:
  std::unique_ptr<gsl_integration_glfixed_table> gslft(gsl_integration_glfixed_table_alloc(10));

  size_t N2 = 10;

  std::vector<double> pnts(N2);
  std::vector<double> weights(N2);

  double xSTART,xEND;
  xSTART = 0;
  xEND = 2.0;
  for (size_t i=0;i<N2;i++)
    {
      gsl_integration_glfixed_point(xSTART,xEND,i,&pnts[i],&weights[i],gslft.get());
      std::cout << pnts[i] << "\n" << weights[i] << "\n";
    }
   
  gsl_integration_glfixed_table_free(gslft.release());

  assert(gslft == nullptr);
  
  
  
  return 0;
}
