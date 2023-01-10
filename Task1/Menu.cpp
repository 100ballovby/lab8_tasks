//
// Created by Gilsson on 12/14/2022.
//

#include "Menu.h"
void PrintInfo()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    std::cout << "Лабораторная работа номер 8:\n"
                 "Задание 1:\n"
                 "--------------------------------------------------------------------------------------------\n"
                 "Задание: Информация об участниках спортивных соревнований содержит\n"
                 "название страны, название команды, ФИО игрока, игровой номер, возраст, рост и\n"
                 "вес. Вывести фамилии спортсменов, возраст которых больше 20 лет (сортировка\n"
                 "Шелла по убыванию).\n"
                 "Предусмотреть возможность\n"
                 "заполнения одного поля структуры, используя известные значения других полей\n"
                 "структуры\n"
                 "Работу подготовил:\n";
    std::cout << "Гулис Антон\n";
    std::cout << "Чтобы запустить решение, нажмите ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    std::cout << "Enter.\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    while(true)
    {
        char *temp = new char[1]{0};
        scanf("%[^\n]%*c", temp);
        if(strlen(temp) == 0) {
            char* temp2 = new char[1];
            scanf("%*1[\n]", temp2);
            return;
        }
    }
}

bool RestartProgram(){
    char* temp = new char[1];
    std::cout << "Чтобы повторить выполнение программы, нажмите ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    std::cout << " Y(y):\n" ;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    std::cin >> temp;
    char* temp2 = new char[1];
    scanf("%*1[\n]", temp2);
    if(*temp != 'y' && *temp != 'Y')
    {
        system("cls");
        return true;
    }
    system("cls");
    return false;
}