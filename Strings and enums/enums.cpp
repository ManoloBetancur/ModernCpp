#include <iostream>

// Traditional enum
enum Direction {
    North,  // Implicitly assigned value 0
    East,   // Implicitly assigned value 1
    South,  // Implicitly assigned value 2
    West    // Implicitly assigned value 3
};

// Scoped enum (enum class)
enum class Color {
    Red,    // Implicitly assigned value 0
    Green,  // Implicitly assigned value 1
    Blue    // Implicitly assigned value 2
};

//? enum with other data type
enum class Keys : char{
    key_c = 'c',
    key_d,
    key_e
};

int main() {
    // Using traditional enum
    Direction direction = North;
    std::cout << "Direction: " << direction << std::endl; // Prints the integer value (0)

    // Using scoped enum (enum class)
    Color color = Color::Red;

    // You can't directly output scoped enum to console, you must cast it to an integer
    std::cout << "Color: " << static_cast<int>(color) << std::endl; // Prints the integer value (0)

    // You can directly compare enum class values
    if (color == Color::Red) {
        std::cout << "The color is Red" << std::endl;
    }

    auto key_pressed = Keys::key_c;

    if(key_pressed == Keys::key_c)
    {
        std::cout << "You press key c" << std::endl;
    }

    auto key_pressed2 = Keys::key_d;
    if(key_pressed2 == static_cast<Keys>('d'))
    {
        std::cout << "You press key d" << std::endl;
    }
    

    return 0;
}
