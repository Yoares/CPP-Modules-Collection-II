#include <iostream>

int main() {
    float   myFloat = 42.5f;

    // 1. static_cast: "Convert the value"
    // The compiler does math to turn floating point bits into integer bits.
    int     valueCast = static_cast<int>(myFloat);

    // 2. reinterpret_cast: "Re-label the bits"
    // We treat the address of the float as if it were an address of an int.
    // We are looking at the raw IEEE 754 bits of 42.5 as an integer.
    int* bitCastPtr = reinterpret_cast<int*>(&myFloat);
    int     rawBits = *bitCastPtr;

    std::cout << "Original Float: " << myFloat << std::endl;
    std::cout << "static_cast (Value): " << valueCast << std::endl;       // Output: 42
    std::cout << "reinterpret_cast (Bits): " << rawBits << std::endl;     // Output: 1110006912 (Garage? No, it's the raw bits!)
    return 0;
}