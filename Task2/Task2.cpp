#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"
#include "Rabotyaga.h"
#include "Menu.h"
#include "Implementations.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    std::fstream file("..\\Task2\\Input.txt", std::fstream::in | std::fstream::out);
    std::ofstream out("..\\Task2\\Output.txt");
    int size = 0;
    std::cout << "Введите размер массива структур:\n";
    file >> size;
    std::cout << size << '\n';
    auto array_struct = new Rabotyaga[size];
    std::cout << "Введите количество элементов, которые хотите добавить в массив\n";
    int amount;
    file >> amount;
    std::cout << amount << '\n';
    FillElements(array_struct, 0, amount, file, out, true);
    ShowElements(array_struct, amount, out);
    SortFields(array_struct, amount);
    out << "\nОтсортированные элементы:\n";
    std::cout << "\nОтсортированные элементы:\n";
    ShowElements(array_struct, amount, out);
    int count = 0;
    while(true) {
        PrintInfo(out);
        std::cout << "\n\nВыберите действие, которое хотите произвести над файлом:\n"
                     "1) Добавление записи в файл\n"
                     "2) Удаление записи из файла\n"
                     "3) Корректировка записи файла\n"
                     "4) Сортировка массива структур\n";
        int num;
        std::fstream commands;
        commands.open("..\\Task2\\Commands.txt", std::fstream::in);
        //ShowOutput(file);
        num = PrintNum(true, 4);
        switch (num) {
            case 1: {
                if (amount + 1 >= size) {
                    Rabotyaga *temp_struct = new Rabotyaga[size];
                    for (int i = 0; i < amount; ++i) {
                        temp_struct[i] = array_struct[i];
                    }
                    size *= 2;
                    array_struct = new Rabotyaga[size];
                    for (int i = 0; i < amount; ++i) {
                        array_struct[i] = temp_struct[i];
                    }
                }
                FillElements(array_struct, amount, amount + 1, commands, out, false);
                ++amount;
                ShowElements(array_struct, amount, out);
                if (RestartProgram(out)) {
                    delete[] array_struct;
                    file.close();
                    out.close();
                    commands.close();
                    return 0;
                }
                break;
            }
            case 2: {
                for (int i = 0; i < amount; ++i) {
                    std::cout << i + 1 << ") ";
                    ShowStructure(array_struct[i], out);
                    std::cout << '\n';
                }
                int element;
                std::cout << "Введите номер структуры, которую хотите удалить: \n";
                element = PrintNum(true, size);
                auto *temp_structs = new Rabotyaga[size - 1];
                for (int i = 0, count = 0; i < size; ++i) {
                    if (i != element - 1) {
                        temp_structs[count] = array_struct[i];
                        ++count;
                    }
                }
                delete[] array_struct;
                array_struct = new Rabotyaga[--size];
                --amount;
                for (int i = 0; i < amount; ++i) {
                    array_struct[i] = temp_structs[i];
                }
                for (int i = 0; i < amount; ++i) {
                    std::cout << i + 1 << ") ";
                    ShowStructure(array_struct[i], out);
                    std::cout << '\n';
                }
                if (RestartProgram(out)) {
                    delete[] array_struct;
                    file.close();
                    out.close();
                    commands.close();
                    return 0;
                }
                break;
            }
            case 3: {
                for (int i = 0; i < amount; ++i) {
                    std::cout << i + 1 << ") ";
                    ShowStructure(array_struct[i], out);
                    std::cout << '\n';
                }
                std::cout << "Введите номер структуры, которую хотите изменить: \n";
                int element;
                element = PrintNum(true, size);
                ChangeStruct(array_struct[element - 1], commands, out);
                ShowElements(array_struct, amount, out);
                if (RestartProgram(out)) {
                    delete[] array_struct;
                    file.close();
                    out.close();
                    commands.close();
                    return 0;
                }
                break;
            }
            case 4:
            {
                SortFields(array_struct, size);
                ShowElements(array_struct, size, out);
                if (RestartProgram(out)) {
                    delete[] array_struct;
                    file.close();
                    out.close();
                    commands.close();
                    return 0;
                }
            }
        }
    }
    system("pause");
    return 0;
}