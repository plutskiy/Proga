#include <iostream>
#include <string>

int main() {
    std::string str;
    str = "1234567890AaBbCcDdEeFfGghhXxYyZz";
    for(size_t i = 0; i < 32; ++i){
        for(size_t j = 0; j < 32; ++j){
            for(size_t z = 0; z < 32; ++z){
                for(size_t g = 0; g < 32; ++g){
                    for(size_t s = 0; s < 32; ++s){
                        std::cout << str[i] << str[j] << str[z] << str[g] << str [s] << std::endl;
                    }
                }
            }
        }
    }
    return 0;
}
