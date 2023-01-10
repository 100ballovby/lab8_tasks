#include "Books.h"
#include "Implementation.h"

void SortBooksByName(Books *books, int size, FILE* file, std::ofstream& out) {
    std::cout << "Введите год, по которому будем сортировать:\n";
    int year;
    std::cin >> year;
    Books *sorted = new Books[size];
    for(int d = size / 2; d > 0; d /= 2){
        for(int i = d, j; i < size; ++i){
            Books temp = sorted[i];
            for(j = i; j >= d ; j -= d){
                if(temp.name_ < books[j - d].name_)
                    sorted[j] = sorted[j - d];
                else
                    break;
            }
            sorted[j] = temp;
        }
    }
    for(int i = 0; i < size; ++i)
    {
        books[i].ShowFields(file, out);
    }
}

void Books::ShowFields(FILE* file, std::ofstream& out) {
    //fwrite(this, sizeof(this), sizeof(this), file)
    Books temp;
    fread(&reg_number_, sizeof(reg_number_), 1, file);
    fread(&author_, sizeof(author_), 1, file);
    fread(&name_, sizeof(name_), 1, file);
    fread(&year_, sizeof(year_), 1, file);
    fread(&publisher_, sizeof(publisher_), 1, file);
    fread(&pages_.page_count_, sizeof(pages_.page_count_), 1, file);
    temp = *this;
    std::cout << "\nРегистрационный номер книги\n";
    out << "\nРегистрационный номер книги\n";
    std::cout << temp.reg_number_;
    out << temp.reg_number_;
    std::cout << "\nАвтор книги\n";
    out << "\nАвтор книги\n";
    std::cout << temp.author_;
    out << temp.author_;
    std::cout << "\nНазвание книги\n";
    out << "\nНазвание книги\n";
    std::cout << temp.name_;
    out << temp.name_;
    std::cout << "\nГод издания книги\n";
    out << "\nГод издания книги\n";
    std::cout << temp.year_;
    out << temp.year_;
    std::cout << "\nИздательство книги\n";
    out << "\nИздательство книги\n";
    std::cout << temp.publisher_;
    out << temp.publisher_;
    std::cout << "\nКоличество страниц в книге\n";
    out << "\nКоличество страниц в книге\n";
    std::cout << temp.pages_.page_count_ << '\n';
    out << temp.pages_.page_count_;
}

void Books::ChangeField(FILE *&file, int position) {
    std::cout << "Введите поле, которое необходимо изменить:\n"
                 "1) Регистрационный номер:\n"
                 "2) Автор\n"
                 "3) Название книги\n"
                 "4) Год издания\n"
                 "5) Издатель книги\n"
                 "6) Количество страниц\n";
    int flag;
    flag = PrintNum(true, 6);
    fclose(file);
    *&file = fopen("..\\Task3\\test.bin", "wb+");
    fseek(file, 0, SEEK_SET);
    --position;
    //fseek(file, sizeof(std::string), SEEK_SET);
    switch (flag) {
        case 1:{
            std::cout << "Текущее значение поля:" << reg_number_ <<'\n';
            std::cout << "Введите новое значение: \n";
            int new_val;
            new_val = PrintNum(true, 12345678);
            int temp;
            fseek(file, 0, SEEK_SET);
            while(position != 0) {
                fseek(file, offsetof(Books, pages_), SEEK_CUR);
                fread(&temp, sizeof(int), 1, file);
                //fread(&temp, sizeof(int), 1, file);
                --position;
            }
            fseek(file, offsetof(Books, reg_number_), SEEK_CUR);
            int a = 0;
            //fread(&a, sizeof(int), 1, file);
            long pos = ftell(file);
            fread(&a, sizeof(int), 1, file);
            //std::cout << a << '\n';
            fclose(file);
            *&file = fopen("..\\Task3\\test.bin", "wb+");
            fseek(file, pos, SEEK_SET);
            fwrite(&new_val, sizeof(reg_number_), 1, file);
            fseek(file, pos, SEEK_SET);
            fread(&reg_number_, sizeof(int), 1, file);
            std::cout << reg_number_;
            break;
        }
        case 2:{
            std::cout << "Текущее значение поля:" << author_ <<'\n';
            std::cout << "Введите новое значение: \n";
            std::string new_val;
            //std::getline(std::wcin, new_val);
            std::getline(std::cin, new_val);
            fseek(file, 0, SEEK_SET);
            int temp = 0;
            while(position != 0) {
                fseek(file, offsetof(Books, pages_), SEEK_CUR);
                fread(&temp, sizeof(int), 1, file);
                //fread(&temp, sizeof(int), 1, file);
                --position;
            }
            fseek(file, offsetof(Books, author_), SEEK_CUR);
            std::string a;
            //fseek(file, 1, SEEK_CUR);
            //fread(&a, name_.size(), 1, file);
            //std::cout << a;
            long pos = ftell(file);
            std::string temp_val = new_val;
            fclose(file);
            *&file = fopen("..\\Task3\\test.bin", "wb+");
            //fread(&a, author_.size(), 1, file);
            //std::cout << a << '\n';
            fseek(file, pos, SEEK_SET);
            int size = new_val.size();
            fwrite(&new_val, sizeof(new_val), 1, file);
            fseek(file, pos, SEEK_SET);
            if(author_.size() < temp_val.size())
            author_.resize(temp_val.size() + 1);
            fread(&author_, sizeof(temp_val), 1, file);
            std::cout << author_;
            break;
        }
        case 3:{
            std::cout << "Текущее значение поля:" << name_ <<'\n';
            std::cout << "Введите новое значение: \n";
            std::string new_val;
            std::getline(std::cin, new_val);
            //std::getline(std::wcin, new_val);

            fseek(file, 0, SEEK_SET);
            int temp = 0;
            while(position != 0) {
                fseek(file, offsetof(Books, pages_.page_count_), SEEK_CUR);
                fseek(file, sizeof(int), SEEK_CUR);
                //fread(&temp, sizeof(int), 1, file);
                --position;
            }
            long pos = ftell(file);
            fseek(file, offsetof(Books, name_), SEEK_CUR);
            std::string a;
            //fread(&a, name_.size(), 1, file);
            //std::cout << a;
            pos = ftell(file);
            //fread(&a, name_.size(), 1, file);
            //std::cout << a << '\n';
            fclose(file);
            *&file = fopen("..\\Task3\\test.bin", "wb+");
            fseek(file, 0, SEEK_SET);
            fseek(file, pos, SEEK_SET);
            fwrite(&new_val, sizeof(new_val), 1, file);

            fseek(file, pos, SEEK_SET);
            if(name_.size() < new_val.size())
            name_.resize(new_val.size());
            fread(&name_, sizeof(new_val), 1, file);
            std::cout << name_;
            break;
        }
        case 4:{
            std::cout << "Текущее значение поля:" << year_ <<'\n';
            std::cout << "Введите новое значение: \n";
            int new_val;
            new_val = PrintNum(true, 2023);
            int temp;
            fseek(file, 0, SEEK_SET);
            while(position != 0) {
                fseek(file, offsetof(Books, pages_), SEEK_CUR);
                fread(&temp, sizeof(int), 1, file);
                //fread(&temp, sizeof(int), 1, file);
                --position;
            }
            fseek(file, offsetof(Books, year_), SEEK_CUR);
            int a = 0;
            //fread(&a, sizeof(int), 1, file);
            long pos = ftell(file);
            fclose(file);
            *&file = fopen("..\\Task3\\test.bin", "wb+");
            //fread(&a, sizeof(int), 1, file);
            //std::cout << a << '\n';
            fseek(file, pos, SEEK_SET);
            fwrite(&new_val, sizeof(year_), 1, file);
            fseek(file, pos, SEEK_SET);
            fread(&year_, sizeof(int), 1, file);
            std::cout << year_;
            break;
        }
        case 5:
        {
            std::cout << "Текущее значение поля:" << publisher_ <<'\n';
            std::cout << "Введите новое значение: \n";
            std::string new_val;
            //std::getline(std::wcin, new_val);
            std::getline(std::cin, new_val);
            fseek(file, 0, SEEK_SET);
            int temp = 0;
            while(position != 0) {
                fseek(file, offsetof(Books, pages_), SEEK_CUR);
                fread(&temp, sizeof(int), 1, file);
                //fread(&temp, sizeof(int), 1, file);
                --position;
            }
            fseek(file, offsetof(Books, publisher_), SEEK_CUR);
            std::string a;
            //fread(&a, name_.size(), 1, file);
            //std::cout << a;
            long pos = ftell(file);
            fclose(file);
            *&file = fopen("..\\Task3\\test.bin", "wb+");
            //fread(&a, publisher_.size(), 1, file);
            //std::cout << a << '\n';
            fseek(file, pos, SEEK_SET);
            fwrite(&new_val, sizeof(new_val), 1, file);
            fseek(file, pos, SEEK_SET);
            if(publisher_.size() < new_val.size())
            publisher_.resize(new_val.size());
            fread(&publisher_, sizeof(new_val), 1, file);
            std::cout << publisher_;
            break;
        }
        case 6:{
            std::cout << "Текущее значение поля:" << pages_.page_count_ <<'\n';
            std::cout << "Введите новое значение: \n";
            int new_val;
            new_val = PrintNum(true, 35000);
            int temp;
            fseek(file, 0, SEEK_SET);
            while(position != 0) {
                fseek(file, offsetof(Books, pages_), SEEK_CUR);
                fread(&temp, sizeof(int), 1, file);
                //fread(&temp, sizeof(int), 1, file);
                --position;
            }
            fseek(file, offsetof(Books, pages_.page_count_), SEEK_CUR);
            int a = 0;
            //fread(&a, sizeof(int), 1, file);
            long pos = ftell(file);
            fclose(file);
            *&file = fopen("..\\Task3\\test.bin", "wb+");
            //fread(&a, sizeof(int), 1, file);
            //std::cout << a << '\n';
            fseek(file, pos, SEEK_SET);
            fwrite(&new_val, sizeof(pages_.page_count_), 1, file);
            fseek(file, pos, SEEK_SET);
            fread(&pages_.page_count_, sizeof(int), 1, file);
            std::cout << pages_.page_count_;
            break;
        }
        default:{
            std::cout << "Введите корректное число, пожалуйста \n";
            break;
        }
    }

}

void Books::DeleteElement(FILE *&file, int position) {
    std::string temp_buf;
    int temp;
    long last_pose;
    long _pos = 0;
    fseek(file, 0, SEEK_END);
    last_pose = ftell(file);
    fseek(file, 0, SEEK_SET);
    int temp_pos = position;
    --position;
    while(temp_pos > 0){
        fseek(file, offsetof(Books, pages_), SEEK_CUR);
        fread(&temp, sizeof(int), 1, file);
        //fread(&temp, sizeof(int), 1, file);
        --temp_pos;
    }
    fseek(file, offsetof(Books, reg_number_), SEEK_CUR);
    char c = '0';
    _pos = ftell(file);
    char buff[sizeof(Books) + 1];
    for(int i = _pos; i < last_pose;)
    {
        fread(&buff, sizeof(Books), 1, file);
        _pos = ftell(file);
        i = _pos;
        temp_buf.append(buff, sizeof(Books));
        buff[0] = '0';
    }
    std::cout << temp_buf;
    fseek(file, 0, SEEK_SET);
    int count = position;
    while(position != 0) {
        fseek(file, offsetof(Books, pages_), SEEK_CUR);
        fread(&temp, sizeof(int), 1, file);
        //fread(&temp, sizeof(int), 1, file);
        --position;
    }
    if(count != 0)
    fseek(file, offsetof(Books, reg_number_), SEEK_CUR);
    //fread(&temp_buf, sizeof(temp_buf), 1, file);
    int reg;
    _pos = ftell(file);
    fread(&reg, sizeof(int), 1, file);
    fclose(file);
    file = fopen("..\\Task3\\test.bin", "wb+");
    //last_pose = ftell(file);
    fseek(file, _pos, SEEK_SET);
    count = temp_buf.size();
    while(count != 0) {
        fwrite(&temp_buf, sizeof(Books), 1, file);
        temp_buf.erase(0, sizeof(Books));
        count -= sizeof(Books);
    }
    //_pos = ftell(file);
    c = EOF;
    fwrite(&c, sizeof(char), 1, file);
    fclose(file);
    file = fopen("..\\Task3\\test.bin", "wb+");
}

void AppendArray(Books* books, int size, FILE* file)
{
    fseek(file, 0, SEEK_END);
    books[size - 1].CreateElement();
    fwrite(&books[size - 1], sizeof(Books), 1, file);
    fseek(file, 0, SEEK_SET);
}

void Books::CreateElement() {
    std::cout << "Введите регистрационный номер книги\n";
    reg_number_ = PrintNum(true, 1234567);
    std::cout << reg_number_ << '\n';
    std::cout << "Введите автора книги\n";
    std::getline(std::cin, author_);
    std::cout << author_ << '\n';
    std::cout << "Введите название книги\n";
    std::getline(std::cin, name_);
    std::cout << name_ << '\n';
    std::cout << "Введите год издания книги\n";
    year_ = PrintNum(true, 2023);
    std::cout << year_ << '\n';
    std::cout << "Введите издательство книги\n";
    std::getline(std::cin, publisher_);
    std::cout << publisher_ << '\n';
    std::cout << "Введите количество страниц в книге\n";
    pages_.page_count_ = PrintNum(true, 23675);
    std::cout << pages_.page_count_;
}
/*void ChangeField(Books*& book, FILE *file, int position) {
    book[position - 1].DeleteElement(file, position);
}*/

