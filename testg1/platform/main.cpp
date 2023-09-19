#include <iostream>
#include "system.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    unsigned long now = PITime();
    int id = GetDayID();
    std::cout << "id:"<<id << std::endl;
    std::cout << "now:"<<now << std::endl;
    return 0;
}
