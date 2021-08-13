#include <iostream>

#include "subdir/sayhello.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    sayHello();
    return 0;
}