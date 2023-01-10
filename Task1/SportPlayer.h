#ifndef LABNUMBER8_SPORTPLAYER_H
#define LABNUMBER8_SPORTPLAYER_H
#include "iostream"
#include "string"
#include "Implementation.h"
struct SportPlayer{
    std::string fullname;
    std::string country;
    int gameNumber;
    int age;
    int weight;
    int height;
};
void ToNormal(std::string& str);
SportPlayer* FillStruct(int &size);
void ShowStruct(SportPlayer *element);
void ShowFields(SportPlayer* structure, int size);
SportPlayer* AddNewElements(SportPlayer* structures, int& size);
void FindElement(SportPlayer* structure, int size);
void DeleteOrChangeElementInArray(SportPlayer*& structures, int &size);
SportPlayer* SortFields(SportPlayer* structures, int size, int &new_size);
#endif //LABNUMBER8_SPORTPLAYER_H
