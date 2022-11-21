#include <iostream>

struct MobilePhone {
    double weight;
    bool is_broken;
    double price;
};

int main() {
    int n;
    std::cin >> n;
    MobilePhone *phone_list = new MobilePhone[n];
    for (int i = 0; i < n; i++) {
        std::cin >> phone_list[i].weight >> phone_list[i].is_broken >>
                 phone_list[i].price;
    }
    std::cout << "<Mobile Phone>" << std::endl;
    for (int s = 0; s < n; s++) {
        std::cout << "\t" << "<MobliePhone id=" << '"' << s << '"' << " weight=" << '"' << phone_list[s].weight
                  << '"' << " is_broken=" << '"' << std::boolalpha << phone_list[s].is_broken << '"'
                  << " price=" << '"' << phone_list[s].price << "\"/>" << std::endl;
    }
    cout << "<Mobile Phone>";
    std::cout << "<Mobile Phone>";
    delete[] phone_list;
    return 0;
}
