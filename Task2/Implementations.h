#ifndef LABNUMBER8_IMPLEMENTATIONS_H
#define LABNUMBER8_IMPLEMENTATIONS_H
#include "Rabotyaga.h"
enum Exceptions
{
    LETTER_INPUT,
    WRONG_TYPE_INPUT,
    WRONG_SIGN_POSITION,
    WRONG_POINT_POSITION,
    INCORRECT_DATA,
    EMPTY_STRING,
    WRONG_SPACE_POSITION,
    TOO_BIG_VALUE,
};
void ToDateType(std::string& str, int num);
long long PrintNum(bool IsSizeInput, int overflow);
void ShowOutput(std::istream& file);
//int CompareDates(Rabotyaga &element1, Rabotyaga &element2);
#endif //LABNUMBER8_IMPLEMENTATIONS_H
