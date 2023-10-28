
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>

class Book {
public:
  std::string title;
  std::string author;
  std::string genre;
  unsigned int publication_year;
};

// class to overload the call operator:
class Compare{
public:
  bool operator()(const Book& a, const Book& b) const {return b.author>a.author;}
};

bool sort_by_asc_order(const Book& a, const Book& b)
{
  return a.publication_year < b.publication_year;
}


void print(const std::vector<Book> &books) {
  for (const Book &book : books) {
    std::cout << "  Title: " << book.title << " | Author: " << book.author
              << " | Genre: " << book.genre
              << " | Year: " << book.publication_year << std::endl;
  }
}

int main() {
  // Define a list of books.
  std::vector<Book> books = {
      {"Go set a watchman", "Harper Lee", "Fiction", 2015},
      {"Animal farm", "George Orwell", "Satire", 1945},
      {"To kill a mockingbird", "Harper Lee", "Fiction", 1960},
      {"1984", "George Orwell", "Science fiction", 1949},
      {"Pride and prejudice", "Jane Austen", "Romance", 1813},
      {"Sense and sensibility", "Jane Austen", "Romance", 1811}};

  std::cout << "Original list of books:" << std::endl;
  print(books);
 
  // Pointer to function as comparator:
  // Sort in ascending order by year.

  std::sort(books.begin(),books.end(),sort_by_asc_order);
  std::cout << "\nSorted books by year with function-ptr"<< std::endl;
  print(books);
  
  // Lambda function comparator:
  // Sort in descending order by year.
  std::sort(books.begin(),books.end(), [](Book a,Book b) {return (a.publication_year>b.publication_year);} );

  std::cout << "\nSorted books by year with lambda function"<< std::endl;
  print(books);
  // Sort in ascending order by author name.
  // ...
  std::sort(books.begin(),books.end(),Compare());
  std::cout << "\nSorted books by author name with a functor"<< std::endl;
  print(books);
  // Filter books by author.

  // USING std::copy_if
  const std::string chosen_autor = "George Orwell";
  std::vector<Book> filtered_books;
  std::copy_if(books.begin(),books.end(),std::back_inserter(filtered_books),
	               [chosen_autor] (const Book& b){return b.author==chosen_autor;});
  print(filtered_books);

  return 0;
}
