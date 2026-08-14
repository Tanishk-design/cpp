#include <iostream>
#include <string>

class Rectangle {
private:
    double length;
    double width;
    std::string name;

public:
    // 1. Default Constructor (invoked when no arguments are provided)
    Rectangle() {
        name = "Default Rectangle";
        length = 1.0;
        width = 1.0;
        std::cout << "[Constructor] " << name << " created.\n";
    }

    // 2. Parameterized Constructor (invoked with specific values)
    Rectangle(std::string rName, double l, double w) {
        name = rName;
        length = l;
        width = w;
        std::cout << "[Constructor] " << name << " created.\n";
    }

    // Method to calculate area
    double getArea() {
        return length * width;
    }

    // 3. Destructor (automatically invoked when the object goes out of scope)
    ~Rectangle() {
        std::cout << "[Destructor] " << name << " destroyed.\n";
    }
};

int main() {
    std::cout << "--- Entering main function ---\n\n";

    // Calls the default constructor
    Rectangle r1;
    std::cout << "Area of r1: " << r1.getArea() << "\n\n";

    // Calls the parameterized constructor
    Rectangle r2("Custom Rectangle", 5.0, 3.0);
    std::cout << "Area of r2: " << r2.getArea() << "\n\n";

    {
        // Object inside a separate inner scope
        std::cout << "--- Entering inner block ---\n";
        Rectangle r3("Temporary Rectangle", 10.0, 2.0);
        std::cout << "Area of r3: " << r3.getArea() << "\n";
        std::cout << "--- Exiting inner block ---\n";
    } // r3's destructor is triggered right here

    std::cout << "\n--- Exiting main function ---\n";
    return 0;
} // r2 and r1 destructors are triggered here in reverse order of creation