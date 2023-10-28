#include <string>
#include <iostream>
#include <vector>

struct Student
{
  std::string name;
  int age;
  float gAverage;
};


void StudentInfo(const Student& s)
{
  std::cout << "Name: " << s.name << std::endl;
  std::cout << "Age:  " << s.age << std::endl;
  std::cout << "gAverage:  " << s.gAverage << std::endl;
}

template <class Type>
void PrintStudents(std::vector<Type>& stds)
{ 
  for (typename std::vector<Type>::iterator it = stds.begin(); it != stds.end(); ++it){
    StudentInfo(*it);
  }
}

int main()
{
  
  Student Pippo;
  Pippo.name = "Pippo";
  Pippo.age = 23;
  Pippo.gAverage=29;
  
  std::vector<Student> Students(5);
   for (std::vector<Student>::iterator it = Students.begin(); it != Students.end(); ++it){
    *it = Pippo; // Copy the entire struct?
  }
  PrintStudents<Student>(Students);
  //StudentInfo(Pippo);

 return 0; 
}
