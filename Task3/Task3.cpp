#include "Header.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    PrintInfo();
    FILE *file = fopen("..\\Task3\\test.bin", "wb+");
    if (file == nullptr) {
        std::cout << "Error opening file\n";
        return 1;
    }
    std::ifstream input("..\\Task3\\Input.txt", std::ifstream::in);
    std::ofstream out("..\\Task3\\Output.txt", std::fstream::out);
    int j = 0;
    int size = 3;
    Books *books = new Books[size];
    input >> j;
    for (int i = 0; i < size; ++i) {
        input >> books[i];
        fwrite(&books[i], sizeof(Books), 1, file);
    }
    while(true) {
        int choose;
        std::cout << "Введите команду:\n"
                     "1) Удаление структуры из массива(и из бинарного файла)\n"
                     "2) Изменение поля массива структуры(и в бинарном файле)\n"
                     "3) Просмотр записи файла\n"
                     "4) Вывести отсортированный массив\n"
                     "5) Добавить элемент в массив\n";
        choose = PrintNum(true, 5);
        int i;
        ShowArray(books, size, file, out);
        std::cout << '\n';
        switch (choose) {
            case 1: {
                std::cout << "Введите номер элемента, с которым проводить операцию:\n";
                i = PrintNum(true, size);
                books[i - 1].DeleteElement(file, i);

                decltype(auto) temp = books;
                books = new Books[size - 1];
                for (int j = 0, count = 0; j < size; ++j) {
                    if (j != i - 1) {
                        books[count] = temp[j];
                        ++count;
                    }
                }
                --size;
                ShowArray(books, size, file, out);
                break;
            }
            case 2: {
                std::cout << "Введите номер элемента, с которым проводить операцию:\n";
                i = PrintNum(true, size);
                books[i - 1].ChangeField(file, i);
                ShowArray(books, size, file, out);
                break;
            }
            case 3: {
                ShowArray(books, size, file, out);
                break;
            }
            case 4: {
                SortBooksByName(books, size, file, out);
                break;
            }
            case 5:
            {
                decltype(auto) temp = books;
                books = new Books[size + 1];
                for (int j = 0; j < size; ++j) {
                        books[j] = temp[j];
                }
                ++size;
                AppendArray(books, size, file);
                break;
            }
            default: {
                std::cout << "Неправильная команда, повторите ввод.\n";
                break;
            }
        }

        if(RestartProgram())
        {
            input.close();
            fclose(file);
            break;
        }else{
            continue;
        }
    }
    system("pause");
    return 0;
}
