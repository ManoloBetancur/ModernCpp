#include<iostream>

using namespace std::string_literals;

std::string toUpper(std::string s)
{
    for(char &c: s)
    {
        c = toupper(c);
    }
    return s;
};

std::string toLower(std::string s)
{
    for(char &c: s)
    {
        c = tolower(c);
    }
    return s;
};

int main()
{
    auto str = "manolo"s;
    std::cout << toUpper(str) << std::endl;
    auto str2 = "MANOLO"s;
    std::cout << toLower(str2) << std::endl;

}