#include "Rabotyaga.h"
void FillDate(Rabotyaga& element, std::istream& in, std::ostream& out, bool IsFromFile = true)
{
    std::cout << "Формат даты: 16/12/2022(день/месяц/год)\n";
    out << "Введите число\n";
    std::cout << "Введите число\n";
    std::string day;
    if(!IsFromFile) {
        ToDateType(day, PrintNum(true,31));
    }
    else
        std::getline(in, day);
    out << day;
    std::cout << day;
    out << "\nВведите месяц\n";
    std::cout << "\nВведите месяц\n";
    std::string month;
    if(!IsFromFile) {
        ToDateType(month, PrintNum(true,12));
    }
    else
        std::getline(in, month);
    out << month;
    std::cout << month;
    out << "\nВведите год\n";
    std::cout << "\nВведите год\n";
    std::string year;
    if(!IsFromFile) {
        ToDateType(year, PrintNum(true, 2023));
    }
    else
        std::getline(in, year);
    out << year << '\n';
    std::cout << year << '\n';
    element.date_hiring = day;
    element.date_hiring += "/";
    element.date_hiring += month;
    element.date_hiring += "/";
    element.date_hiring += year;
    out << element.date_hiring << '\n';
    std::cout << element.date_hiring << '\n';
}

void FillElements(Rabotyaga* array, int start, int end, std::istream& in, std::ostream& out, bool IsFromFile = true)
{
    for(int i = start; i < end; ++i){
        out << "\nВведите номер департамента сотрудника\n";
        std::cout << "\nВведите номер департамента сотрудника\n";
        if(!IsFromFile)
            array[i].dep_number = PrintNum(true, 123456);
        else
            in >> array[i].dep_number;
        out << array[i].dep_number;
        std::cout << array[i].dep_number;
        out << "\nВведите возраст сотрудника\n";
        std::cout << "\nВведите возраст сотрудника\n";
        if(!IsFromFile)
            array[i].age = PrintNum(true, 130);
        else
            in >> array[i].age;
        out << array[i].age;
        out << "\nВведите полное имя сотрудника\n";
        std::cout << "\nВведите полное имя сотрудника\n";
        if(!IsFromFile)
            std::getline(std::cin, array[i].fullname);
        else
            std::getline(in, array[i].fullname);
        out << array[i].fullname;
        out << "\nВведите должность сотрудника\n";
        std::cout << "\nВведите должность сотрудника\n";
        if(!IsFromFile)
            std::getline(std::cin, array[i].position);
        else
            std::getline(in, array[i].position);
        out << array[i].position;
        out << "\nВведите дату начала работы сотрудника\n";
        std::cout << "\nВведите дату начала работы сотрудника\n";
        FillDate(array[i], in, out, IsFromFile);
    }
}

void ShowStructure(Rabotyaga& element, std::ostream& out)
{
    out << "Номер департамента сотрудника " << element.dep_number << '\n';
    std::cout << "Номер департамента сотрудника " << element.dep_number << '\n';
    out << "Возраст сотрудника " << element.age << '\n';
    std::cout << "Возраст сотрудника " << element.age << '\n';
    out << "Полное имя сотрудника" << element.fullname.c_str() << '\n';
    std::cout << "Полное имя сотрудника " << element.fullname.c_str() << '\n';
    out << "Должность сотрудника " << element.position.c_str() << '\n';
    std::cout << "Должность сотрудника " << element.position.c_str() << '\n';
    out << "Дата начала работы сотрудника " << element.date_hiring.c_str() << '\n';
    std::cout << "Дата начала работы сотрудника " << element.date_hiring.c_str() << '\n';
}

void ShowElements(Rabotyaga* array, int size, std::ostream& out)
{
    std::cout << "\nЭлементы массива:\n\n";
    out << "\nЭлементы массива:\n\n";
    for(int i = 0; i < size; ++i){
        ShowStructure(array[i], out);
    }
}

void SortFields(Rabotyaga* structures, int size)
{
    for(int d = size / 2; d > 0; d /= 2){
        for(int i = d, j; i < size; ++i){
            Rabotyaga temp = structures[i];
            for(j = i; j >= d ; j -= d){
                if(CompareDates(temp, structures[j - d]) == -1)
                    structures[j] = structures[j - d];
                else
                    break;
            }
            structures[j] = temp;
        }
    }
}

void ChangeStruct(Rabotyaga& element, std::istream& in, std::ostream& out)
{
    std::cout << "\nВыберите поле, которое необходимо изменить:\n"
                 "1)Номер департамента сотрудника\n"
                 "2)Возраст сотрудника\n"
                 "3)Полное имя сотрудника\n"
                 "4)Должность сотрудника\n"
                 "5)Дата начала работы сотрудника\n";
    while(true) {
        int flag;
        flag = PrintNum(true, 5);
        switch (flag) {
            case 1:
            {
                std::cout << "Текущее значение поля:" << element.dep_number <<'\n';
                out << "Текущее значение поля:" << element.dep_number <<'\n';
                std::cout << "Введите новое значение: \n";
                out << "Введите новое значение: \n";
                element.dep_number = PrintNum(true, 12345678);
                out << element.dep_number;
                std::cout << element.dep_number;
                break;
            }
            case 2:
            {
                std::cout << "Текущее значение поля:" << element.age <<'\n';
                out << "Текущее значение поля:" << element.age <<'\n';
                std::cout << "Введите новое значение: \n";
                out << "Введите новое значение: \n";
                element.age = PrintNum(true, 130);
                out << element.age;
                std::cout << element.age;
                break;
            }
            case 3:
            {
                std::cout << "Текущее значение поля:" << element.fullname <<'\n';
                out << "Текущее значение поля:" << element.fullname <<'\n';
                std::cout << "Введите новое значение: \n";
                out << "Введите новое значение: \n";
                std::getline(std::cin, element.fullname);
                out << element.fullname;
                std::cout << element.fullname;
                break;
            }
            case 4:
            {
                std::cout << "Текущее значение поля:" << element.position <<'\n';
                out << "Текущее значение поля:" << element.position <<'\n';
                std::cout << "Введите новое значение: \n";
                out << "Введите новое значение: \n";
                std::getline(std::cin, element.position);
                out << element.position;
                std::cout << element.position;
                break;
            }
            case 5: {
                std::cout << "Текущее значение поля:" << element.date_hiring << '\n';
                out << "Текущее значение поля:" << element.date_hiring << '\n';
                std::cout << "Введите новое значение: \n";
                out << "Введите новое значение: \n";
                FillDate(element, in, out, false);
                std::cout << element.date_hiring;
                out << element.date_hiring;
                break;
            }
            default:
            {
                std::cout << "Неправильная команда, повторите ввод\n";
                continue;
                break;
            }
        }
        return;
    }
}