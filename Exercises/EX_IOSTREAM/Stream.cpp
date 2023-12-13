/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <sstream>

class Month
{
    public:
    Month():
      days_(32,0){};
        
    friend std::istream &operator>>(std::istream &input,Month& m)
    {
        std::string name_month;
        int day;
        bool save = true;
        //Read:
        if(input>>name_month>>day)
        {
            try{
                if(m.monthsName.find(name_month) == m.monthsName.end())
                    throw std::invalid_argument("month not found");
                    
                 if(day<1 || day>31)  
                    throw std::invalid_argument("The day is not right!");
            }
            catch(const std::invalid_argument& e)
            {
                std::cout << e.what() << '\n';
                save = false; // avoid to save the month and day
            }// end catch
            
            if(save){
                m.name_month_=name_month;
                m.days_[day]++;
            }
        }
        if(input.fail())
          throw std::invalid_argument("Bad read for the month");
        return input;
    }
    std::set<std::string> monthsName = {"jan","feb","march","april","may","june"};
    std::vector<int> days_; //0 is discarded
    std::string name_month_;
};

class Year
{
    public:
  Year():months_{{"jan",Month()},
                 {"feb",Month()},
		 {"march",Month()},
		 {"april",Month()},
		 {"may",Month()},
		 {"june",Month()}
    }
  {};
        
    friend std::istream &operator>>(std::istream &input,Year& y)
    {
        char c;
        std::string year;
        int yearVal;
        if(input>>c>>year>>yearVal)
        {
            if(c=='{' && year=="year" && yearVal>1900)
            {
                Month m;
                input>>m;
                y.months_[m.name_month_]=m;
                //if(input>>m){
                //   y.months_[m.name_month_]=m;
                //   }
            }
        }
        input>>c;
        //std::cout << y.months_["jan"].days_[11] <<std::endl;
        if(c!='}')
            throw std::invalid_argument("Expected to close the year, obtained other stuffs.");
        return input;
    }
    std::map<std::string,Month> months_;
    int year_;
    std::set<std::string> monthsName = {"jan","feb","march","april","may","june"};
};

int main()
{
    std::stringstream ss;
    ss<<"{ year 1995 jan 11 }";
    Year firstYear;
    ss>> firstYear;
    
    return 0;
}
