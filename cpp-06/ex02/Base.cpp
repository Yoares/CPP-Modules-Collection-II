#include "Base.hpp"

Base::~Base () {}

Base* generate(void) {
    // Generate a number between 0 and 2
    int randomChoice = std::rand() % 3;

    switch (randomChoice) {
        case 0:
            std::cout << "Generated A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated C" << std::endl;
            return new C();
        default:
            return NULL; 
    }
}

void identify(Base* p){
    Base *wich_one = dynamic_cast<A *>(p);
    if (wich_one != NULL)
        std::cout << "my type is A" << std::endl;
    Base *wich_two = dynamic_cast<B *>(p);
    if (wich_two != NULL)
        std::cout << "my type is B"  << std::endl;
    Base *wich_tree = dynamic_cast<C *>(p);
    if (wich_tree != NULL)
        std::cout << "my type is C"  << std::endl;
}

void identify(Base& p){
    try {
        Base &one = dynamic_cast<A&>(p);
        (void)one;
        std::cout << "my type is A"  << std::endl;
        
    }
    catch(std::exception &e){
        try
        {
            Base &two = dynamic_cast<B&>(p);
            (void)two;
            std::cout << "my type is B"  << std::endl;
        }
        catch(const std::exception& e)
        {
           try
           {
                Base &tree = dynamic_cast<C&>(p);
                (void)tree;
                 std::cout << "my type is C"  << std::endl;
           }
           catch(const std::exception& e)
           {
                std::cerr << e.what() << std::endl;
           }
           
        }
        
    }
}