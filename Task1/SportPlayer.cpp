#include "SportPlayer.h"
void ToNormal(std::string& str)
{
    for(auto it = str.begin(); it != str.end(); ++it)
    {
        if(*it == 0)
        {
            str.erase(it, str.end());
            break;
        }
    }
}

SportPlayer* FillStruct(int &size)
{
    printf("Выберите опцию заполнения массива структур:\n"
           "1) Ввод размера массива структур\n"
           "2) Ввод структур, пока не появится структура с заданным признаком\n");
    int n = 0;
    n = PrintNum(true, 2);
    char* fix = new char[1];
    //scanf("%*1[\n]", fix);
    switch (n) {
        case 1: {
            int f = 0;
            printf("Введите количество элементов массива структур\n");
            f = PrintNum(true, 1000);
            size = f;
            char *fix = new char[1];
            //scanf("%*1[\n]", fix);
            auto structures = new SportPlayer[f];
            for (int i = 0; i < f; ++i) {
                printf("Введите игровой номер игрока\n");
                structures[i].gameNumber = PrintNum(true, 100);
                printf("Введите возраст игрока\n");
                structures[i].age = PrintNum(true, 117);
                structures[i].fullname.resize(100);
                printf("Введите полное имя игрока\n");
                scanf("%[^\n]%*c", structures[i].fullname.c_str());
                ToNormal(structures[i].fullname);
                printf("Введите вес игрока\n");
                structures[i].weight = PrintNum(true, 300);
                printf("Введите рост игрока\n");
                structures[i].height = PrintNum(true, 400);
                structures[i].country.resize(100);
                printf("Введите страну игрока\n");
                scanf("%[^\n]%*c", structures[i].country.c_str());
                ToNormal(structures[i].country);
            }
            delete[] fix;
            return structures;
            break;
        }
        case 2: {
            printf("Выберите поля структуры, значения которых хотите задать заранее:\n"
                   "1) Игровой номер\n"
                   "2) Возраст\n"
                   "3) Полное имя\n"
                   "4) Вес\n"
                   "5) Рост\n"
                   "6) Страна\n");
            auto controlstruct = new std::string[6];
            size = 0;
            std::string fields;
            char exit = 0;
            char* fix = new char[1];
            int counter = 0;
            while (exit != 'N' && exit != 'n' && counter != 6) {
                int choose = PrintNum(true, 6);
                if (fields.find(choose + '0') == std::string::npos) {
                    fields.push_back(choose + '0');
                    ++counter;
                } else {
                    printf("Данное поле уже было введено\n");
                }
                printf("Желаете выбрать еще поле?(y / n)\n");
                scanf("%c", &exit);
                scanf("%*1[\n]", fix);
            }
            int size_str = fields.size();
            for(int i = 0; i < 6; ++i)
            {
                controlstruct[i] = "0";
            }
            for(auto i: fields) {
                if (i == '1') {
                    printf("Введите игровой номер игрока\n");
                    scanf("%[^\n]%*c", controlstruct[0].c_str());
                }
                else if (i == '2')
                {
                    printf("Введите возраст игрока\n");
                    scanf("%[^\n]%*c", controlstruct[1].c_str());
                }
                else if(i == '3') {
                    printf("Введите полное имя игрока\n");
                    controlstruct[2].resize(100);

                    scanf("%[^\n]%*c", controlstruct[2].c_str());
                }
                else if(i == '4'){
                    printf("Введите вес игрока\n");

                    scanf("%[^\n]%*c", controlstruct[3].c_str());
                }
                else if(i == '5'){
                    printf("Введите рост игрока\n");

                    scanf("%[^\n]%*c", controlstruct[4].c_str());
                }
                else if(i == '6'){
                    controlstruct[5].resize(100);
                    printf("Введите страну игрока\n");
                    scanf("%[^\n]%*c", controlstruct[5].c_str());
                }
            }
            auto structures = new SportPlayer[100];
            int count = 0;
            for(int i = 0; ; ++i)
            {
                printf("Введите игровой номер игрока\n");
                scanf("%i", &structures[i].gameNumber);
                scanf("%*1[\n]", fix);
                if(structures[i].gameNumber == std::stoi(controlstruct[0]))
                {
                    ++count;
                }
                printf("Введите возраст игрока\n");
                scanf("%i", &structures[i].age);
                scanf("%*1[\n]", fix);
                if(structures[i].age == std::stoi(controlstruct[1]))
                {
                    ++count;
                }
                structures[i].fullname.resize(100);
                printf("Введите полное имя игрока\n");
                scanf("%[^\n]%*c", structures[i].fullname.c_str());
                if(structures[i].fullname == controlstruct[2])
                {
                    ++count;
                }
                printf("Введите вес игрока\n");
                scanf("%i", &structures[i].weight);
                scanf("%*1[\n]", fix);
                if(structures[i].weight == std::stoi(controlstruct[3]))
                {
                    ++count;
                }
                printf("Введите рост игрока\n");
                scanf("%i", &structures[i].height);
                scanf("%*1[\n]", fix);
                if(structures[i].height == std::stoi(controlstruct[4]))
                {
                    ++count;
                }
                structures[i].country.resize(100);
                printf("Введите страну игрока\n");
                scanf("%[^\n]%*c", structures[i].country.c_str());
                if(structures[i].country == controlstruct[5])
                {
                    ++count;
                }
                ++size;
                if(count == size_str)
                {
                    break;
                }else{
                    count = 0;
                }
            }
            delete[] fix;
            return structures;
            break;
        }
        default:
            return nullptr;
            break;
    }
}

void ShowStruct(SportPlayer *element)
{
    printf("Игровой номер игрока: %i\n", element->gameNumber);
    printf("Возраст игрока: %i\n", element->age);
    printf("Полное имя игрока: %s\n", element->fullname.c_str());
    printf("Вес игрока: %i\n", element->weight);
    printf("Рост игрока: %i\n", element->height);
    printf("Страна игрока: %s\n", element->country.c_str());
}

void ShowFields(SportPlayer* structure, int size)
{
    for(int i = 0; i < size; ++i) {
        printf("%i-й элемент массива: \n", i + 1);
        ShowStruct(&structure[i]);
        printf("\n \n");
    }
}

SportPlayer* AddNewElements(SportPlayer* structures, int& size)
{
    printf("Выберите способ добавления нового элемента массива:\n"
           "1) Ввод заданного количества структур с клавиатуры\n"
           "2) Ввод заданного количества структур при помощи полей других структур в массиве:\n");
    int flag = PrintNum(true, 2);
    switch (flag) {
        case 1:
        {
            printf("Введите количество структур, которые хотите добавить: \n");
            int add_size;
            char* fix = new char[1];
            scanf("%i", &add_size);
            scanf("%*1[\n]", fix);
            SportPlayer* temp_st = new SportPlayer[size + add_size];
            for(int i = 0; i < size; ++i)
            {
                temp_st[i] = structures[i];
            }
            for(int i = size; i < size + add_size; ++i)
            {
                printf("Введите игровой номер игрока\n");
                scanf("%i", &temp_st[i].gameNumber);
                scanf("%*1[\n]", fix);
                printf("Введите возраст игрока\n");
                scanf("%i", &temp_st[i].age);
                scanf("%*1[\n]", fix);
                temp_st[i].fullname.resize(100);
                printf("Введите полное имя игрока\n");
                scanf("%[^\n]%*c", temp_st[i].fullname.c_str());
                ToNormal(temp_st[i].fullname);
                printf("Введите вес игрока\n");
                scanf("%i", &temp_st[i].weight);
                scanf("%*1[\n]", fix);
                printf("Введите рост игрока\n");
                scanf("%i", &temp_st[i].height);
                scanf("%*1[\n]", fix);
                temp_st[i].country.resize(100);
                printf("Введите страну игрока\n");
                scanf("%[^\n]%*c", temp_st[i].country.c_str());
                ToNormal(temp_st[i].country);
            }
            size += add_size;
            delete[] fix;
            return temp_st;
            break;
        }
        case 2: {
            ShowFields(structures, size);
            printf("Введите номер структуры, у которой будем брать значения:\n");
            int number = PrintNum(true, size);
            SportPlayer *temp_st = new SportPlayer[size + 1];
            for (int i = 0; i < size; ++i) {
                temp_st[i] = structures[i];
            }
            temp_st[size].height = 0;
            temp_st[size].fullname = "";
            temp_st[size].age = 0;
            temp_st[size].gameNumber = 0;
            temp_st[size].weight = 0;
            temp_st[size].country = "";
            ShowStruct(&structures[number - 1]);
            ShowStruct(&temp_st[size]);
            printf("Выберите поля структуры, значения которых хотите задать заранее:\n"
                   "1) Игровой номер\n"
                   "2) Возраст\n"
                   "3) Полное имя\n"
                   "4) Вес\n"
                   "5) Рост\n"
                   "6) Страна\n");
            std::string fields;
            char exit = 0;
            int count = 0;
            char* fix = new char[1];
            while (exit != 'N' && exit != 'n' && count != 6) {
                int choose = PrintNum(true, 6);
                if (fields.find(choose + '0') == std::string::npos) {
                    fields.push_back(choose + '0');
                    ++count;
                } else {
                    printf("Данное поле уже было введено\n");
                }
                printf("Желаете выбрать еще поле?(y / n)\n");
                scanf("%c", &exit);
                scanf("%*1[\n]", fix);
            }
            int size_str = fields.size();
            for (auto i: fields) {
                switch (i) {
                    case '1': {
                        temp_st[size].gameNumber = structures[number - 1].gameNumber;
                        break;
                    }
                    case '2': {
                        temp_st[size].age = structures[number - 1].age;
                        break;
                    }
                    case '3': {
                        temp_st[size].fullname = structures[number - 1].fullname;
                        break;
                    }
                    case '4': {
                        temp_st[size].weight = structures[number - 1].weight;
                        break;
                    }
                    case '5': {
                        temp_st[size].height = structures[number - 1].height;
                        break;
                    }
                    case '6': {
                        temp_st[size].country = structures[number - 1].country;
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
            ShowStruct(&temp_st[size]);
            if (temp_st[size].gameNumber == 0) {
                printf("Введите игровой номер игрока\n");
                temp_st[size].gameNumber = PrintNum(true, 100);
            }
            if (temp_st[size].age == 0) {
                printf("Введите возраст игрока\n");
                temp_st[size].age = PrintNum(true, 117);
            }
            if (temp_st[size].fullname == "") {
                temp_st[size].fullname.resize(100);
                printf("Введите полное имя игрока\n");
                scanf("%[^\n]%*c", temp_st[size].fullname.c_str());
                ToNormal(temp_st[size].fullname);
            }
            if (temp_st[size].weight == 0) {
                printf("Введите вес игрока\n");
                temp_st[size].weight = PrintNum(true, 150);
            }
            if (temp_st[size].height == 0) {
                printf("Введите рост игрока\n");
                temp_st[size].height = PrintNum(true, 300);
            }
            if(temp_st[size].country == "") {
                temp_st[size].country.resize(100);
                printf("Введите страну игрока\n");
                scanf("%[^\n]%*c", temp_st[size].country.c_str());
                ToNormal(temp_st[size].country);
            }
            delete[] fix;
            ++size;
            return temp_st;
        }
        default:
        {
            printf("Неправильный ввод.\n");
            return nullptr;
            break;
        }
    }
}

void FindElement(SportPlayer* structure, int size)
{
    char* fix = new char[1];
    printf("Поиск структур с заданным значением элемента\n");
    printf("Выберите поля структуры, значения которых хотите задать заранее:\n"
           "1) Игровой номер\n"
           "2) Возраст\n"
           "3) Полное имя\n"
           "4) Вес\n"
           "5) Рост\n"
           "6) Страна\n");
    auto controlstruct = new std::string[6];
    std::string fields;
    int counter = 0;
    char exit = 0;
    while (exit != 'N' && exit != 'n' && counter != 6) {
        int choose = PrintNum(true, 6);
        if (fields.find(choose + '0') == std::string::npos) {
            fields.push_back(choose + '0');
            ++counter;
        } else {
            printf("Данное поле уже было введено\n");
        }
        printf("Желаете выбрать еще поле?(y / n)\n");
        scanf("%c", &exit);
        scanf("%*1[\n]", fix);
    }
    int size_str = fields.size();
    for(int i = 0; i < 6; ++i)
    {
        controlstruct[i] = "-10";
    }
    int temp;
    for(auto i: fields) {
        if (i == '1') {
            printf("Введите игровой номер игрока\n");
            temp = PrintNum(true, 100);
            controlstruct[0] = std::to_string(temp);
        }
        else if (i == '2')
        {
            printf("Введите возраст игрока\n");
            temp = PrintNum(true, 117);
            controlstruct[1] = std::to_string(temp);
        }
        else if(i == '3') {
            printf("Введите полное имя игрока\n");
            controlstruct[2].resize(100);

            scanf("%[^\n]%*c", controlstruct[2].c_str());
            ToNormal(controlstruct[2]);
        }
        else if(i == '4'){
            printf("Введите вес игрока\n");
            temp = PrintNum(true, 500);
            controlstruct[3] = std::to_string(temp);
        }
        else if(i == '5'){
            printf("Введите рост игрока\n");
            temp = PrintNum(true, 500);
            controlstruct[4] = std::to_string(temp);
        }
        else if(i == '6'){
            controlstruct[5].resize(100);
            printf("Введите страну игрока\n");
            scanf("%[^\n]%*c", controlstruct[5].c_str());
        }
    }
    int count = 0;
    for(int i = 0; i < size; ++i)
    {
        if(std::stoi(controlstruct[0]) == structure[i].gameNumber)
            ++count;
        if(std::stoi(controlstruct[1]) == structure[i].age)
            ++count;
        if(controlstruct[2] == structure[i].fullname)
            ++count;
        if(std::stoi(controlstruct[3]) == structure[i].weight)
            ++count;
        if(structure[i].height == std::stoi(controlstruct[4]))
        {
            ++count;
        }
        if(structure[i].country.c_str() == controlstruct[5])
        {
            ++count;
        }
        if(count == size_str){
            printf("Мы нашли этот элемент под номером: %i \n", i + 1);
            ShowStruct(&structure[i]);
            return;
        }else{
            count = 0;
        }
    }
    printf("Структура не найдена!\n");
    delete[] fix;
}

void DeleteOrChangeElementInArray(SportPlayer*& structures, int &size)
{
    printf("Выберите поля структуры, по значениям которых определим:\n"
           "1) Игровой номер\n"
           "2) Возраст\n"
           "3) Полное имя\n"
           "4) Вес\n"
           "5) Рост\n"
           "6) Страна\n");
    auto controlstruct = new std::string[6];
    std::string fields;
    char exit = 0;
    char* fix = new char[1];
    int counter = 0;
    while (exit != 'N' && exit != 'n' && counter != 6) {
        int choose = PrintNum(true, 6);
        if (fields.find(choose + '0') == std::string::npos) {
            fields.push_back(choose + '0');
            ++counter;
        } else {
            printf("Данное поле уже было введено\n");
        }
        printf("Желаете выбрать еще поле?(y / n)\n");
        scanf("%c", &exit);
        scanf("%*1[\n]", fix);
    }
    int size_str = fields.size();
    for(int i = 0; i < 6; ++i)
    {
        controlstruct[i] = "0";
    }
    for(auto i: fields) {
        if (i == '1') {
            printf("Введите игровой номер игрока\n");
            scanf("%[^\n]%*c", controlstruct[0].c_str());
        }
        else if (i == '2')
        {
            printf("Введите возраст игрока\n");
            scanf("%[^\n]%*c", controlstruct[1].c_str());
        }
        else if(i == '3') {
            printf("Введите полное имя игрока\n");
            controlstruct[2].resize(100);

            scanf("%[^\n]%*c", controlstruct[2].c_str());
            ToNormal(controlstruct[2]);
        }
        else if(i == '4'){
            printf("Введите вес игрока\n");

            scanf("%[^\n]%*c", controlstruct[3].c_str());
        }
        else if(i == '5'){
            printf("Введите рост игрока\n");

            scanf("%[^\n]%*c", controlstruct[4].c_str());
        }
        else if(i == '6'){
            controlstruct[5].resize(100);
            printf("Введите страну игрока\n");
            scanf("%[^\n]%*c", controlstruct[5].c_str());
            ToNormal(controlstruct[5]);
        }
    }
    int count = 0;
    for(int i = 0; i < size ; ++i)
    {
        if(structures[i].gameNumber == std::stoi(controlstruct[0]))
        {
            ++count;
        }
        if(structures[i].age == std::stoi(controlstruct[1]))
        {
            ++count;
        }
        if(structures[i].fullname == controlstruct[2])
        {
            ++count;
        }
        if(structures[i].weight == std::stoi(controlstruct[3]))
        {
            ++count;
        }
        if(structures[i].height == std::stoi(controlstruct[4]))
        {
            ++count;
        }
        if(structures[i].country == controlstruct[5])
        {
            ++count;
        }
        if(count == size_str)
        {
            int flag;
            printf("Выберите, что хотите сделать с данным элементом массива:\n"
                   "1) Изменить\n"
                   "2) Удалить\n");
            flag = PrintNum(true, 2);
            switch (flag) {
                case 1:
                {
                    printf("Выберите поля структуры, значения которых хотим изменить:\n"
                           "1) Игровой номер\n"
                           "2) Возраст\n"
                           "3) Полное имя\n"
                           "4) Вес\n"
                           "5) Рост\n"
                           "6) Страна\n");
                    auto controlstruct1 = new std::string[6];
                    std::string fields1;
                    char exit = 0;
                    char* fix = new char[1];
                    int counter = 0;
                    while (exit != 'N' && exit != 'n' && counter != 6) {
                        int choose = PrintNum(true, 6);
                        if (fields1.find(choose + '0') == std::string::npos) {
                            fields1.push_back(choose + '0');
                            ++counter;
                        } else {
                            printf("Данное поле уже было введено\n");
                        }
                        printf("Желаете выбрать еще поле?(y / n)\n");
                        scanf("%c", &exit);
                        scanf("%*1[\n]", fix);
                    }
                    int size_str1 = fields1.size();
                    for(int f = 0; f < 6; ++f)
                    {
                        controlstruct1[f] = "-10";
                    }
                    for(auto it: fields1) {
                        if (it == '1') {
                            printf("Введите игровой номер игрока\n");
                            scanf("%[^\n]%*c", controlstruct1[0].c_str());
                        }
                        else if (it == '2')
                        {
                            printf("Введите возраст игрока\n");
                            scanf("%[^\n]%*c", controlstruct1[1].c_str());
                        }
                        else if(it == '3') {
                            printf("Введите полное имя игрока\n");
                            controlstruct1[2].resize(100);

                            scanf("%[^\n]%*c", controlstruct1[2].c_str());
                            ToNormal(controlstruct1[2]);
                        }
                        else if(it == '4'){
                            printf("Введите вес игрока\n");

                            scanf("%[^\n]%*c", controlstruct1[3].c_str());
                        }
                        else if(it == '5'){
                            printf("Введите рост игрока\n");

                            scanf("%[^\n]%*c", controlstruct1[4].c_str());
                        }
                        else if(it == '6'){
                            controlstruct1[5].resize(100);
                            printf("Введите страну игрока\n");
                            scanf("%[^\n]%*c", controlstruct1[5].c_str());
                            ToNormal(controlstruct1[2]);
                        }else{
                            --size_str1;
                        }
                    }
                    if(controlstruct1[0] != "-10")
                    {
                        structures[i].gameNumber = std::stoi(controlstruct1[0]);
                    }
                    if(controlstruct1[1] != "-10")
                    {
                        structures[i].age = std::stoi(controlstruct1[1]);
                    }if(controlstruct1[2] != "-10")
                    {
                        structures[i].fullname = controlstruct1[2];
                    }if(controlstruct1[3] != "-10")
                    {
                        structures[i].weight = std::stoi(controlstruct1[3]);
                    }if(controlstruct1[4] != "-10")
                    {
                        structures[i].height = std::stoi(controlstruct1[4]);
                    }if(controlstruct1[5] != "-10")
                    {
                        structures[i].country = controlstruct1[5];
                    }
                    break;
                }
                case 2:
                {
                    SportPlayer* temp_elements = new SportPlayer[size - 1];
                    for(int j = 0, counter = 0; counter < size; ++counter)
                    {
                        if(counter != i)
                        {
                            temp_elements[j] = structures[counter];
                            ++j;
                        }
                    }
                    --size;
                    structures = temp_elements;
                    break;
                }
            }
            count = 0;
        }
    }
    delete[] fix;
}

SportPlayer* SortFields(SportPlayer* structures, int size, int &new_size)
{
    auto sorted = new SportPlayer[size];
    int count = 0;
    for(int i = 0; i < size; ++i) {
        if (structures[i].age > 20) {
            sorted[count] = structures[i];
            ++count;
        }
    }
    new_size = count;
    for(int d = new_size / 2; d > 0; d /= 2){
        for(int i = d, j; i < new_size; ++i){
            SportPlayer temp = sorted[i];
            for(j = i; j >= d ; j -= d){
                if(temp.height > structures[j - d].height)
                    sorted[j] = sorted[j - d];
                else
                    break;
            }
            sorted[j] = temp;
        }
    }
    return sorted;
}
