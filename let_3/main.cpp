#include <iostream>

int64_t HexToInt(const char *s) {
    int64_t result = 0;
    bool is_negative = (s[0] == '-'); //Проверка на знак числа
    //Проверка на содержания + или - в записи числа
    if (s[0] == '-' || s[0] == '+') {
        s += 3; //Пропуск ±0x в записи 16ричного числа
    } else if (s[0] == '0') {
        s += 2; //Пропуск 0x в записи 16ричного числа
    }
    if (s[0] == '\0') {
        exit(-1);
    }
    while (*s != '\0') { //Перевод из 16ричной в 10тичною
        if (*s >= '0' && *s <= '9') {
            result = result * 16 + (*s - '0');
        } else if (*s >= 'A' && *s <= 'F') {
            result = result * 16 + (*s - 'A' + 10);
        } else if (*s >= 'a' && *s <= 'f') {
            result = result * 16 + (*s - 'a' + 10);
        } else {
            exit(-1);
        }
        s++;
    }
    return is_negative ? result * -1 + 117 : result + 117;
}

int main(int argc, char **argv) {
    for (int i = argc - 1; i >= 0; i--) {
        std::cout << HexToInt(argv[i]) << std::endl;
    }
    return 0;
}
