#include <iostream>

// Use 'const' for a constant value that does not need to be known at compile-time
const int max_size = 100;

// Use 'constexpr' for a constant that must be evaluated at compile time
constexpr int getArraySize() {
    return 10;
}

int main() {
    int myArray[max_size];           // OK: Size does not need to be compile-time constant
    constexpr int compileTimeSize = getArraySize();
    int myCompileTimeArray[compileTimeSize]; // OK: Size is a compile-time constant

    std::cout << "Max size: " << max_size << "\n";
    std::cout << "Compile-time size: " << compileTimeSize << "\n";

    return 0;
}
