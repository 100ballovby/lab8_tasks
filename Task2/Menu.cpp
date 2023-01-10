#include "Menu.h"
void PrintInfo(std::ostream& out)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    std::cout << "Лабораторная работа номер 8:\n"
                 "Задание 2:\n"
                 "--------------------------------------------------------------------------------------------\n"
                 "Задание: Информация о сотрудниках предприятия содержит: Ф.И.О., номер отдела,\n"
                 "должность, дату начала работы. Вывести списки сотрудников по отделам\n"
                 "в порядке убывания стажа.\n"
                 "Информация, обрабатываемая программой, должна храниться\n"
                 "в текстовом файле, результат работы занести в другой файл и отобразить\n"
                 "на экране.\n"
                 "Работу подготовил:\n";
    std::cout << "Гулис Антон\n";
    std::cout << "Чтобы запустить решение, нажмите ";
    out << "Лабораторная работа номер 8:\n"
                 "Задание 2:\n"
                 "--------------------------------------------------------------------------------------------\n"
                 "Задание: Информация о сотрудниках предприятия содержит: Ф.И.О., номер отдела,\n"
                 "должность, дату начала работы. Вывести списки сотрудников по отделам\n"
                 "в порядке убывания стажа.\n"
                 "Информация, обрабатываемая программой, должна храниться\n"
                 "в текстовом файле, результат работы занести в другой файл и отобразить\n"
                 "на экране.\n"
                 "Работу подготовил:\n";
    out << "Гулис Антон\n";
    out << "Чтобы запустить решение, нажмите ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    std::cout << "Enter.\n";
    out << "Enter.\n";
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

bool RestartProgram(std::ostream& out){
    char* temp = new char[1];
    std::cout << "Чтобы повторить выполнение программы, нажмите ";
    out << "Чтобы повторить выполнение программы, нажмите ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    std::cout << " Y(y):\n" ;
    out << " Y(y):\n" ;
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
