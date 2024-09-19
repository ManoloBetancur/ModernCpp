#include<iostream>


//?Convert Farenheit to celsius
long double operator"" _F(long double t)
{
    return (5.0/9.0) * (t-32);
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

int main()

{

    double temperature1 = 25;

    //! Literal knows the data type so auto can be used here
    auto temperature2 = 102.0_F;

    std::cout << temperature1 << std::endl;
    std::cout << temperature2 << std::endl;

    //!Checks if it is a valid binary
    auto bin_str = "1010"_b;
    std::cout << bin_str << std::endl;

    //! Invalid intended binary string
    auto bin_String = "1012"_b;
    std::cout << bin_String << std::endl;

    std::cout << "End of program" << std::endl;
    return 0;
}