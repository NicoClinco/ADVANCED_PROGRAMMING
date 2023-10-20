#include "DataSource.hpp"
#include "DataTransformer.hpp"
int main()
{

  /*
  ConsoleDataSource CD("Console");
  CD.read_data();
  CD.display_info();
  */
  
  FileDataSource FD("File","data.txt");
  FD.read_data();
  FD.display_info();

  DataTransformer* pLogScaler =
    new LogTransformer();
    
  pLogScaler->transform(FD);

  FD.display_info();
  
}
