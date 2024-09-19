#include <iostream>
#include <string>

// User-defined literal for kilometers
constexpr long double operator"" _km(long double x) {
    return x * 1000.0;  // Convert to meters
}

// User-defined literal for binary strings
std::string operator"" _b(const char* str, size_t len) {
    std::string result;
    for (size_t i = 0; i < len; ++i) {
        if (str[i] == '0') result += '0';
        else if (str[i] == '1') result += '1';
        else throw std::invalid_argument("Invalid binary string");
    }
    return result;
}

int main() {
    // Integer literals
    int decimal = 42;
    int octal = 052;
    int hexadecimal = 0x2A;
    int binary = 0b101010;

    // Floating-point literals
    double d1 = 3.14;
    double d2 = 3.14e-10;

    // Character and string literals
    char c = 'A';
    const char* str = "Hello";
    std::string cpp_str = "C++ string";

    // Boolean literals
    bool t = true;
    bool f = false;

    // Null pointer literal
    int* ptr = nullptr;

    // User-defined literals
    auto distance = 5.5_km;
    auto bin_str = "1010"_b;

    std::cout << "Distance: " << distance << " meters" << std::endl;
    std::cout << "Binary string: " << bin_str << std::endl;

    return 0;
}