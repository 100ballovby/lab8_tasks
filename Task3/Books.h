#ifndef LABNUMBER8_BOOKS_H
#define LABNUMBER8_BOOKS_H

#include <string>
#include "iostream"
#include "fstream"
#include "utility"

long double PrintNum(bool IsSizeInput , int overflow);
union pages{
    int page_count_;
    pages(int page_count) : page_count_(page_count){};
};

class Books {
    int reg_number_ = 0;
    std::string author_ = "";
    std::string name_ = "";
    int year_ = 0;
    std::string publisher_ = "";
    pages pages_ = 0;
public:
    Books(){};
    Books(Books& books): reg_number_(books.reg_number_), author_(books.author_), name_(books.name_), year_(books.year_), publisher_(books.publisher_),
                         pages_(books.pages_){};
private:void CreateElement();
public: friend std::istream &operator>>(std::istream &in, Books &books) {
        std::cout << "Введите регистрационный номер книги\n";
        in >> books.reg_number_;
        std::cout << books.reg_number_ << '\n';
        std::cout << "Введите автора книги\n";
        std::getline(in, books.author_);
        std::cout << books.author_ << '\n';
        std::cout << "Введите название книги\n";
        std::getline(in, books.name_);
        std::cout << books.name_ << '\n';
        std::cout << "Введите год издания книги\n";
        in >> books.year_;
        std::cout << books.year_ << '\n';
        std::cout << "Введите издательство книги\n";
        std::getline(in, books.publisher_);
        std::cout << books.publisher_ << '\n';
        std::cout << "Введите количество страниц в книге\n";
        in >> books.pages_.page_count_;
        std::cout << books.pages_.page_count_;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, Books &books) {
        out << "\nРегистрационный номер книги: " << books.reg_number_ << std::endl;
        out << "\nАвтор книги: " << books.author_ << std::endl;
        out << "\nНазвание книги: " << books.name_ << std::endl;
        out << "\nГод издания книги: " << books.year_ << std::endl;
        out << "\nИздательство книги: " << books.publisher_ << std::endl;
        out << "\nКоличество страниц в книге: " << books.pages_.page_count_ << std::endl;
        return out;
    }
    friend void SortBooksByName(Books *books, int size, FILE* file, std::ofstream& out);
    friend void AppendArray(Books* books, int size, FILE* file);
    //void SortBooksByName(Books* books, int size, std::fstream& out);
    //friend void ChangeField(Books*& book, FILE *file, int position);
    void DeleteElement(FILE*& file, int position);
    void ChangeField(FILE*& file, int position);
    friend void ShowArray(Books*& book, int size, FILE* file, std::ofstream& out);
private:
    void ShowFields(FILE* file, std::ofstream& out);
};
void AppendArray(Books* books, int size, FILE* file);
void ShowArray(Books*& book, int size, FILE* file, std::ofstream& out);
#endif //LABNUMBER8_BOOKS_H
