#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Product {
public:
  std::string name;
  double price;
};

void print(const std::vector<Product> &products) {
  for (const Product &product : products) {
    std::cout << product.name << ":\t$" << product.price << std::endl;
  }
}

int main() {
  // Define a list of products.
  const std::vector<Product> products = {{"Smartphone", 799.99},
                                                                        {"Laptop", 1299.99},
                                                                        {"Tablet", 349.99},
                                                                        {"Headphones", 99.99},
                                                                        {"Smartwatch", 249.99}};

  std::cout << "List of products:" << std::endl;
  // print(products);

  // Compute total cost.
  
  auto bin_sum = [] (const double& init,const Product&  b)->double{std::cout << init+b.price<<std::endl;return init+b.price;};
  double TOT_SUM  = std::accumulate(products.begin(),products.end(),0.0,bin_sum);
  std::cout << TOT_SUM << std::endl;

  return 0;
}
