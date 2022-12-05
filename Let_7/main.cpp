#include <iostream>
#include <sstream>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <cctype>

std::string read_file_from_path(const std::string &path) {
    std::ifstream f(path);
    std::string result;
    if (f) {
        std::ostringstream ss;
        ss << f.rdbuf();
        return ss.str();
    } else {
        return {};
    }
}

bool is_palindrome(const std::string &palindrom) {
    for (size_t i = 0; i != (palindrom.length() / 2); ++i) {
        if (std::tolower(palindrom[i]) != std::tolower(palindrom[palindrom.length() - i - 1])) {
            return false;
        }
    }
    return true;
}

//Этот метод выделяет из одной строки, в которой есть несколько строк, разделённых \n и записать каждую строку в другую,
//после чего, из источника данная строка удаляется
std::string videlenie_stroki(std::string &otkuda, std::string &kuda) {
    size_t i = 0;
    while (otkuda[i] != '\n') {
        kuda.push_back(otkuda[i]);
        i++;
    }
    otkuda.erase(0, i + 1);
    return kuda;
}


void polindrombI(std::string file) {
    size_t size_of_palindromes = 0;
    size_t quantity = std::count(file.begin(), file.end(), '\n'); //Подсчёт кол-ва строк в файле
    std::string *arr = new std::string[quantity];//Выделение массива строк для разделения полученного файла на строки

    for (size_t i = 0; i != quantity; ++i) {
        arr[i] = videlenie_stroki(file, arr[i]); //Заполнение этого массива
    }

    for (size_t s = 0; s != quantity; ++s) {
        if (is_palindrome(arr[s]) == true) { //Подсчёт кол-ва полиндромов
            size_of_palindromes++;
        }
    }

    size_t i = 0;
    std::string *palindromes = new std::string[size_of_palindromes]; //Выделение массива для строк палиндромов
    for (size_t s = 0; s != quantity; ++s) {
        if (is_palindrome(arr[s]) == true) {
            palindromes[i] = arr[s];
            ++i;
        }
    }

//Вывод массива строк-плаиндромов
    std::cout  << "\"count_palindromes\": "<< size_of_palindromes << ',' << std::endl << "palindromes\": [";
    for (size_t s = 0; s != size_of_palindromes; ++s) {
        if (s == size_of_palindromes - 1){
            std::cout << '\"' << palindromes[s] << '\"';
        } else {
            std::cout << '\"' << palindromes[s] << '\"' << ',' << " ";
        }
    }
    std::cout << ']';
    delete[] arr;
    delete[] palindromes;
}


int main(int argc, char **argv) {
    std::string file = read_file_from_path(argv[1]);
    polindrombI(file);
    return 0;
}