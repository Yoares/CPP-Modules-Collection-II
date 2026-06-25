#include "Serialize.hpp"

int main(){

    Data My_data = {42, "yasser"};

    Data *ptr = &My_data;

    std::cout << ptr << std::endl;
    uintptr_t raw = Serialize::serialize(ptr);
    std::cout << raw << std::endl;
    Data *de_raw = Serialize::deserialize(raw);
    std::cout << de_raw << std::endl;
}