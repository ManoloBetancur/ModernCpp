#include<iostream>

using namespace std::string_literals;

int main()
{
    auto str = "HELLO"s;

    size_t pos = str.find("LL");

    std::cout << pos << std::endl;

}