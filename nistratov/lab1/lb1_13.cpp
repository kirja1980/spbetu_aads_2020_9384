#include <iostream>
#include <fstream>
#include <array>

bool bracket(std::string line, int& current_pos);
void solver(char read_type);

bool brackets(std::string line, int& current_pos)
{
    std::cout << "<Скобки>" << std::endl;
    switch (line[current_pos])
    {
    case 'A':
        return true;
    case '(':
    {
        current_pos++;
        if (bracket(line, current_pos) == true)
            if (brackets(line, current_pos) == true)
                return true;
    }
return false;
    }
}

bool bracket(std::string line, int& current_pos)
{
    std::cout << "<Скобка>" << std::endl;
    if (line[current_pos] == 'B')
    {
        current_pos++;
        if (brackets(line, current_pos) == true)
        {
            current_pos++;
            if (line[current_pos] == ')')
            {
                current_pos++;
                return true;
            }
        }
    }
    return false;
}

char read_type()
{
 std::cout << "Введите 1 для считывания из файла\nВведите 2 для считывания из консоли" << std::endl;
 char key = getchar();
 return key;
}

bool synt_checker(std::string line)
{
    // Syntaxis checker { A, B, (, ) }

    for(size_t i = 0; i < line.length()-1; i++)
        if (line[i] != 'A' && line[i] != 'B' && line[i] != '(' && line[i] != ')')
        {
            return false;
        }
    return true;
}

void solver(char read_type)
{
    switch (read_type)
    {
    case '1':
        {
            //Считывание с файла

            std::ifstream in_file("input.txt");
            std::ofstream out_file("output.txt");
            std::string line;
            int i = 0;
            int line_number = 1;
            while (std::getline(in_file, line))
            {
                if (!synt_checker(line))
                {
                    out_file << "Ошибка синтаксиса" << std::endl;
                }
                else
                {
                    i = 0;
                    if (line[line.length()-1] != 'A' || line[line.length()-1] != 'B' || line[line.length()-1] != '(' || line[line.length()-1] != ')') line.pop_back();
                    if (brackets(line, i) && (i == line.length()-1)) out_file << "Выражение " << line << " - скобки" << std::endl;
                    else out_file << "Выражение " << line << " - не скобки" << std::endl;
                }
            }
            out_file.close();
            break;
        }
    case '2':
        {
            // Считывание с консоли

            std::string text;
            int i = 0;
            std::cout << "Введите значение" << std::endl;
            std::cin >> text;
            if (!synt_checker(text)){
                std::cout << "Ошибка синтаксиса" << std::endl;
                return;
            }
            if (brackets(text, i) && (i == text.length()-1)) std::cout << "Выражение " << text << " - скобки" << std::endl;
            else std::cout << "Выражение " << text << " - не скобки" << std::endl;
            break;
        }
    default:
        std::cout<<"Числа нет в списке команд" << std::endl;
        break;
    }
}

int main()
{
    std::string text;
    solver(read_type());
}