#include <set>
#include <stdio.h>

class Access
{
public:
void activate(unsigned int code)
  {
    s.insert(code);
  }
void deactivate(unsigned int code)
  {
    //If it is present:
    s.erase(code);
  }
bool is_active(unsigned int code) const
  {
    auto it = s.find(code);
    if (it == s.end())
      return false;
    return true;
  }
  // The keys are unique, thus we must
  // use the map.
std::set<unsigned int> s;
};

int main()
{
  Access AccessPoint;
 


  for(auto _ : AccessPoint.s)
    std::cout<< _ << "\n";
  return 0;
}
