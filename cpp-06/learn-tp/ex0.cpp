/*Challenge A: The "Truncator" (Mini Ex00)

Goal: Understand explicit value loss.

    Create a double variable with a large decimal (e.g., 1234.5678).

    Use static_cast to convert it to an int and display it.

    Use static_cast to convert it to a char and display it.

    Observation: What happens to the decimal part? What happens if the number is bigger than 127 (max char)?*/

#include <iostream>

int main(){

    double v = 1234.5678;
    int b = static_cast <int>(v);
    char c = static_cast <char>(v);
    std::cout << b << std::endl;
    std::cout << c << std::endl;
}