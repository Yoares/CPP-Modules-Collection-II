/*Challenge B: The "Secret Message" (Mini Ex01)

Goal: Understand that data is just bytes.

    Create a struct Data { int id; char code; };.

    Instantiate it: id = 42, code = '*'.

    Create a void* rawPtr.

    Use reinterpret_cast to store the address of your struct in rawPtr.

    Pass rawPtr to a function that casts it back to Data* and prints the values.

        Tip: This simulates sending generic data packets.*/
#include <iostream>

struct Data{
    public:
    int id;
    char code;
};

int main(){
    Data it;
    it.id = 42;
    it.code = '*';
    void* rawptr = reinterpret_cast<void*>(&it);//mask
    std::cout << "Add" <<rawptr << std::endl;

    Data* retrieved = reinterpret_cast<Data*>(rawptr);//unmask
    std::cout << "ID: " << retrieved->id << std::endl;     // Prints 42
    std::cout << "Code: " << retrieved->code << std::endl; // Prints *
}