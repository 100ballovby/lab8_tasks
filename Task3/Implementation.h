//
// Created by Gilsson on 12/13/2022.
//

#ifndef LABNUMBER8_IMPLEMENTATION_H
#define LABNUMBER8_IMPLEMENTATION_H
#include <windows.h>
#include "iostream"
#include "Books.h"
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

long double PrintNum(bool IsSizeInput, int overflow);
void ShowArray(Books*& book, int size, FILE* file, std::ofstream& out);
#endif //LABNUMBER8_IMPLEMENTATION_H
