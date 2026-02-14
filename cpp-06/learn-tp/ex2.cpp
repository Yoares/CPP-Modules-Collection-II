/*Challenge C: The "Identify" Game (Mini Ex02)

Goal: Detect types without knowing them.

    Create a class Animal (with virtual destructor!).

    Create classes Cat and Dog inheriting from Animal.

    Write a function void checkType(Animal* a) that uses dynamic_cast to print "Meow" if it's a Cat, or "Woof" if it's a Dog.

    In main, create a new Dog, pass it to the function, and verify it barks.*/

#include <iostream>
class Animal{
    public :
        virtual ~Animal(){};
};

class Dog : public Animal {

};

class Cat : public Animal {
    
};

void checkType(Animal* a){
    Dog *dog = dynamic_cast <Dog *>(a);
    if (dog == nullptr)
        std::cout << "meow" << std::endl;
    else
        std::cout << "Woof" << std::endl;

}

void checkTypeRef(Animal& a){
    try {
        Dog& dog = dynamic_cast <Dog &>(a);
        (void)dog;
         std::cout << "Woof" << std::endl;
    }
    catch(std::exception &e){
        try {
            Cat& cat = dynamic_cast <Cat &>(a);
            (void)cat;
            std::cout << "meow" << std::endl;
        }
        catch(std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
}

int main(){
    Animal *d = new Dog();
    checkType(d);
    Animal c = Cat();
    checkTypeRef(c);
}


/**
     * Animal -> Cat
     * Animal -> Wolf
     * Animal = new Cat ===> Animal.DoSomething() ===> d-c(Aniaml) -> Cat if True 'Adresse' , False 'Null', if animal is a ref it will throw an exept()
     * 
     */
    
