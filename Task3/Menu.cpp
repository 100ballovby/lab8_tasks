#include "Menu.h"
void PrintInfo()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    std::cout << "Лабораторная работа номер 8:\n"
                 "Задание 3:\n"
                 "--------------------------------------------------------------------------------------------\n"
                 "Задание: реализовать одну из 30 задач, используя классы, одно поле - union.\n"
                 "Реализовать корректировку записей внутри двоичного файла без полной перезаписи файла,"
                 "а только перезаписи скорректированного элемента\n"
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
    return false;
}