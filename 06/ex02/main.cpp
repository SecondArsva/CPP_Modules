#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate() {
    std::srand(std::time(0));
    int r = std::rand() % 3;
    if (r == 0) {
        std::cout << "Generated: A\n";
        return new A;
    } else if (r == 1) {
        std::cout << "Generated: B\n";
        return new B;
    } else {
        std::cout << "Generated: C\n";
        return new C;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Identified by pointer: A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "Identified by pointer: B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "Identified by pointer: C\n";
    else
        std::cout << "Identified by pointer: Unknown\n";
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Identified by reference: A\n";
    } catch (...) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "Identified by reference: B\n";
        } catch (...) {
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << "Identified by reference: C\n";
            } catch (...) {
                std::cout << "Identified by reference: Unknown\n";
            }
        }
    }
}

int main() {
    Base* ptr = generate();
    identify(ptr);
    identify(*ptr);
    delete ptr;
    return 0;
}
