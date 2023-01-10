#include "Implementation.h"

void ShowArray(Books*& book, int size, FILE* file, std::ofstream& out){
    fclose(file);
    file = fopen("..\\Task3\\test.bin", "wb+");
    fseek(file, 0, SEEK_SET);
    if(size == 0)
    {
        std::cout << "Массив пуст.\n";
    }else{
        for(int i = 0; i < size; ++i)
        {
            std::cout << '\n' << i + 1 << ") элемент\n";
            book[i].ShowFields(file, out);
        }
    }
}

long double PrintNum(bool IsSizeInput = false, int overflow = 0)
{
    while (true) {
        int size = 0;
        long long PointIndex = -1;
        long long buff = 10132;
        long double output = 0;
        bool Sign = true;        // true = +, false = -
        bool WrongSign = false;
        char *input = new char[buff]{0};
        scanf("%[^\n]%*c", input);
        try{
            if(strlen(input) == 0) {
                throw EMPTY_STRING;
            }
            for (int i = 0; i < buff; ++i) {
                if (input[i] == 0) {
                    break;
                }
                if (input[i] == int('-') || input[i] == int('+')) {
                    if (i == 0 && input[i] == int('-')) {
                        Sign = false;
                        input[i] = '0';
                        ++size;
                        continue;
                    } else if(i == 0 && input[i] == int('+'))
                    {
                        if(Sign == false) {
                            throw WRONG_SIGN_POSITION;
                        }
                        Sign = true;
                        input[i] = '0';
                        WrongSign = true;
                        ++size;
                        continue;
                    }
                    else{
                        throw WRONG_SIGN_POSITION;
                    }
                }
                if(input[i] == int(' '))
                {
                    throw WRONG_SPACE_POSITION;
                }
                if ((input[i] < int('0') || input[i] > int('9')) && input[i] != int('.')) {
                    throw LETTER_INPUT;
                }
                if (input[i] == int('.')) {
                    for (int j = 0; j < i; ++j) {
                        if (input[j] == int('.')) {
                            throw WRONG_POINT_POSITION;
                        }
                    }
                }
                if (PointIndex == -1) {
                    for (int j = 0; j <= size; ++j) {
                        if (input[j] == int('.'))
                            PointIndex = j;
                    }
                }
                if (PointIndex != -1 && IsSizeInput) {
                    for (int j = PointIndex + 1; j <= size; ++j) {
                        if (input[j] != int('0')) {
                            throw WRONG_TYPE_INPUT;
                        }
                    }
                }
                ++size;
            }
            if (PointIndex != -1) {
                if((Sign == false || WrongSign) && size == 1){
                    throw WRONG_SIGN_POSITION;
                }
                for (long long i = PointIndex - 1; i >= 0; --i) {
                    output += (input[i] - '0') * powl(10, PointIndex - i - 1);
                }
                for (long long i = PointIndex + 1; i < size; ++i) {
                    output += (input[i] - '0') * powl(1 / 10.0, i - PointIndex);
                }
            } else {
                if((Sign == false || WrongSign) && size == 1){
                    throw WRONG_SIGN_POSITION;
                }
                for (long long i = size - 1; i >= 0; --i) {
                    output += (input[i] - '0') * powl(10, size - i - 1);
                }
            }
            if (Sign) {
                if (IsSizeInput) {
                    if (output < 1 || output > overflow) {
                        throw INCORRECT_DATA;
                    }
                }
                if (size < 300 || output < 1e300)
                    return output;
                else{
                    throw TOO_BIG_VALUE;
                }
            } else {
                if (IsSizeInput) {
                    if (-output < 1) {
                        throw INCORRECT_DATA;
                    }
                }
                if (size < 300 || output < 1e300)
                    return -output;
                else
                    throw TOO_BIG_VALUE;
            }
        }catch(Exceptions err)
        {
            char *wrongInput = new char[1000];
            char *temp = new char[1];
            switch (err){
                case (WRONG_TYPE_INPUT):
                    std::cerr << "Ожидался другой тип.\n";
                    std::cerr << "Повторите ввод.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case (INCORRECT_DATA):
                    std::cerr << "Неверный размер.\n";
                    std::cerr << "Повторите ввод.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case (WRONG_POINT_POSITION):
                    std::cerr << "Неверная позиция точки.\n";
                    std::cerr << "Повторите ввод.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case (WRONG_SIGN_POSITION):
                    std::cerr << "Неверная позиция знака.\n";
                    std::cerr << "Повторите ввод.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case (LETTER_INPUT):
                    std::cerr << "Ожидались числа, а не буковы.\n";
                    std::cerr << "Повторите ввод.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case (EMPTY_STRING):
                    std::cerr << "Пустая строка...\n";
                    std::cerr << "Повторите ввод.\n";
                    scanf("%*1[\n]", temp);
                    break;
                case (WRONG_SPACE_POSITION):
                    std::cerr << "Ввод без пробелов! Ожидалось одно число.\n";
                    std::cerr << "Повторите ввод.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case(TOO_BIG_VALUE):
                    std::cerr << "Слишком большое значение.\n";
                    std::cerr << "Повторите ввод.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                default:
                    break;
            }
            delete[] wrongInput;
        }
    }
}