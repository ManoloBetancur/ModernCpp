#include <iostream>
#include <string>
#include <sstream>

//*USING STRING LITERALS
using namespace std::string_literals;

int main() {
    // ----- std::string Example -----
    
    // Creating and initializing a string
    std::string str = "Hello, World!";

    //!String could also be created as follows
    std::string s1("HOLA");
    std::string s2{"MUNDO"};
    //!Using string literals "using namespace std::string_literals;"
    auto s3 = "Hola Mundo!"s;

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;

    
    // Accessing and modifying characters
    std::cout << "Original string: " << str << std::endl;
    str[7] = 'C';  // Modify a specific character
    std::cout << "Modified string: " << str << std::endl;
    
    // String length
    std::cout << "String length: " << str.size() << std::endl;

    // Substring
    std::string sub = str.substr(0, 5);  // Get "Hello"
    std::cout << "Substring: " << sub << std::endl;
    
    // Concatenation
    std::string str2 = " Welcome to C++!";
    std::string combined = str + str2;  // Concatenation
    std::cout << "Concatenated string: " << combined << std::endl;

    // Find a substring
    size_t pos = str.find("World");
    if (pos != std::string::npos) {
        std::cout << "\"World\" found at position: " << pos << std::endl;
    } else {
        std::cout << "\"World\" not found" << std::endl;
    }

    // Replace a part of the string
    str.replace(7, 5, "Everyone");  // Replace "World" with "Everyone"
    std::cout << "Replaced string: " << str << std::endl;

    //? ----- std::stringstream Example -----
    
    // Creating a string stream
    std::stringstream ss;
    
    // Inserting data into string stream
    int number = 2024;
    std::string text = "The year is ";
    ss << text << number;
    
    // Extracting data from string stream
    std::string output = ss.str();  // Extract the full stream content as a string
    std::cout << "String stream output: " << output << std::endl;

    // Clearing and reusing the string stream
    ss.str("");  // Clear the string inside the stream
    ss.clear();  // Clear any error flags
    
    // String stream is also useful for converting between types
    std::string numberStr = "12345";
    int num;
    ss << numberStr;    // Insert string
    ss >> num;          // Extract as int
    std::cout << "Converted number from string: " << num << std::endl;

    // Output multiple types into a string stream
    double pi = 3.14159;
    ss.str(""); // Reset stream
    ss.clear();
    ss << "Pi value is approximately " << pi;
    std::cout << ss.str() << std::endl;

    //?Example for std::ostringstream (Output string string)
        
    std::ostringstream oss;  // Output string stream
    
    // Writing formatted data into the string stream
    int year = 2024;
    std::string event = "Olympics";
    oss << "The " << event << " will be held in " << year << ".";
    
    // Extract the final string from the output stream
    std::string outputString = oss.str();
    std::cout << "Output string: " << outputString << std::endl;
    // Output: The Olympics will be held in 2024.
    
    //? ---- std::istringstream Example (Input String Stream) ----
    
    std::string inputString = "123 45.67 Hello";
    std::istringstream iss(inputString);  // Input string stream
    
    int integer;
    double floatingPoint;
    std::string word;
    
    // Reading (parsing) data from the string
    iss >> integer >> floatingPoint >> word;
    
    std::cout << "Parsed integer: " << integer << std::endl;
    std::cout << "Parsed floating-point: " << floatingPoint << std::endl;
    std::cout << "Parsed word: " << word << std::endl;





    return 0;
}
