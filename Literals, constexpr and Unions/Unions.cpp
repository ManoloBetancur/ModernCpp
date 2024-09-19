#include <iostream>
#include <cstdint>  // for uint8_t

// Define a struct to hold person information
struct Person {
    char name[50];
    int age;
    float salary;
};

// Define a union to view an integer as bytes
union IntViewer {
    int intValue;
    uint8_t bytes[sizeof(int)];  // uint8_t ensures that we look at individual bytes
};

int main() {
    // Example using struct
    Person john = {"John Doe", 30, 60000.0f};
    std::cout << "Name: " << john.name << "\n";
    std::cout << "Age: " << john.age << "\n";
    std::cout << "Salary: " << john.salary << "\n";

    // Example using union
    IntViewer viewer;
    viewer.intValue = 0x12345678; // Assuming a 32-bit int and a little-endian machine

    std::cout << "Integer: " << viewer.intValue << "\n";
    std::cout << "Bytes: ";
    for (size_t i = 0; i < sizeof(viewer.bytes); ++i) {
        std::cout << std::hex << static_cast<int>(viewer.bytes[i]) << " ";
    }
    std::cout << std::dec << "\n";  // Switch back to decimal for any further output

    return 0;
}
