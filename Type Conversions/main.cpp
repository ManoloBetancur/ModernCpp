#include<iostream>

int main()
{
    int a = 7;
    int b = 2;

    float f = a/b; //Does not get the correct answer

    float f2 = (float)a/b; //C style converrsion, but is not recommended

    float f3 = static_cast<float>(a)/b; //Same result but C++ static converstion (casting)

    std::cout << f << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;

    //! Casting with pointers
    // char *p = &a; //?Not allowed because the pointer a points to an integer and not a char.
    char *p = (char *)&a; // * Compiles but is not very safe to use it widely
    // char *p = static_cast<char*>(&a);//?You cannot convert pointers types using static_cast
    char *p2 = reinterpret_cast<char*>(&a);//? With this C++ casting the convertion does not discard the qualifiers
    // * USE reinterpret cas to cast between pointer types.

    const int X = 10;
    int *ptr = const_cast<int*>(&X);

    std::cout << *ptr << std::endl;

}