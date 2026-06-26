#include "Base.hpp"

int main(){
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    Base *p = generate();
    identify(p);
    Base *a = generate();
    identify(*a);
}