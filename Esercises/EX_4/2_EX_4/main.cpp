
#include "DataSource.hpp"

int main()
{

  ConsoleDataSource CD("Console");
  CD.read_data();
  CD.display_info();

  FileDataSource FD("File","data.txt");
  FD.read_data();
  FD.display_info();
  return 0;
}
