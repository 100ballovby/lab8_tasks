#ifndef LABNUMBER8_RABOTYAGA_H
#define LABNUMBER8_RABOTYAGA_H
#include "iostream"
#include "Implementations.h"
#include "string"
struct Rabotyaga{
    std::string fullname;
    std::string position;
    std::string date_hiring;
    int dep_number;
    int age;
};
void ShowOutput(std::istream& file);
int CompareDates(Rabotyaga &element1, Rabotyaga &element2);
void ChangeStruct(Rabotyaga& element, std::istream& in, std::ostream& out);
void FillDate(Rabotyaga& element, std::istream& in, std::ostream& out, bool IsFromFile);
void FillElements(Rabotyaga* array, int start, int end, std::istream& in, std::ostream& out, bool IsFromFile);
void ShowStructure(Rabotyaga& element, std::ostream& out);
void ShowElements(Rabotyaga* array, int size, std::ostream& out);
void SortFields(Rabotyaga* structures, int size);
#endif //LABNUMBER8_RABOTYAGA_H
