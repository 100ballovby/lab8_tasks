#include "Header.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    PrintInfo();
    int size;
    auto players = FillStruct(size);
    while(true)
    {
        printf("Выберите функцию, которую хотите применить к заданному массиву структур:\n"
               "1) Показать элементы массива структур\n"
               "2) Добавить в массив структур новый элемент\n"
               "3) Найти в массиве структур определенную\n"
               "4) Удалить или изменить элемент из массива структур\n"
               "5) Отсортировать массив структур по убыванию роста\n");
        int choose;
        choose = PrintNum(true, 5);
        int new_size = 0;
        switch (choose) {
            case 1: {
                ShowFields(players, size);
                if(RestartProgram())
                {
                    delete[] players;
                    return 0;
                }
                break;
            }
            case 2: {
                players = AddNewElements(players, size);
                ShowFields(players, size);
                if(RestartProgram())
                {
                    delete[] players;
                    return 0;
                }
                break;
            }
            case 3: {
                FindElement(players, size);
                if(RestartProgram())
                {
                    delete[] players;
                    return 0;
                }
                break;
            }
            case 4: {
                DeleteOrChangeElementInArray(players, size);
                ShowFields(players, size);
                if(RestartProgram())
                {
                    delete[] players;
                    return 0;
                }
                break;
            }
            case 5: {
                auto sorted_array = SortFields(players, size, new_size);
                ShowFields(sorted_array, new_size);
                if(RestartProgram())
                {
                    delete[] players;
                    return 0;
                }
                break;
            }
            default:
            {
                printf("Введенное значение не принадлежит отрезку [1; 5], введите заново\n");
                break;
            }
        }
    }
    return 0;
}