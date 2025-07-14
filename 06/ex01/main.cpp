#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data;
    data.id = 42;
    data.name = "cpp_module_06";

    std::cout << "Original Data address: " << &data << std::endl;
    std::cout << "Original Data content: " << data.id << ", " << data.name << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Raw uintptr_t: " << raw << std::endl;
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Deserialized Data address: " << ptr << std::endl;
    std::cout << "Deserialized Data content: " << ptr->id << ", " << ptr->name << std::endl;

    return 0;
}
