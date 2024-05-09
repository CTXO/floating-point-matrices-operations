#include <iostream>
#include <cmath>

// Define the number of digits of precision
const int PRECISION = 3;

// Scale factor for converting between integers and floats
const int SCALE_FACTOR = pow(10, PRECISION);

// Custom type to represent the limited precision numbers
struct LimitedPrecision {
    int value;

    // Constructor to convert float to limited precision
    LimitedPrecision(float f) {
        float scaled = f * SCALE_FACTOR;
        float rounded = roundf(scaled);
        value = static_cast<int>(rounded);
    }

    // Conversion operator to convert limited precision to float
    operator float() const {
        return static_cast<float>(value) / SCALE_FACTOR;
    }

    // Example arithmetic operations
    LimitedPrecision operator+(const LimitedPrecision& other) const {
        return LimitedPrecision(static_cast<float>(*this) + static_cast<float>(other));
    }

    LimitedPrecision operator-(const LimitedPrecision& other) const {
        return LimitedPrecision(static_cast<float>(*this) - static_cast<float>(other));
    }

    LimitedPrecision operator*(const LimitedPrecision& other) const {
        return LimitedPrecision(static_cast<float>(*this) * static_cast<float>(other));
    }

    LimitedPrecision operator/(const LimitedPrecision& other) const {
        return LimitedPrecision(static_cast<float>(*this) / static_cast<float>(other));
    }

    // Example comparison operators
    bool operator==(const LimitedPrecision& other) const {
        return value == other.value;
    }

    bool operator!=(const LimitedPrecision& other) const {
        return value != other.value;
    }

    // Example output operator
    friend std::ostream& operator<<(std::ostream& os, const LimitedPrecision& lp) {
        os << static_cast<float>(lp);
        return os;
    }
};

int main() {
    LimitedPrecision a = 1.2349; // Initialize with a float
    LimitedPrecision b = 2.3456;

    LimitedPrecision sum = a + b;
    LimitedPrecision difference = a - b;
    LimitedPrecision product = a * b;
    LimitedPrecision quotient = a / b;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Quotient: " << quotient << std::endl;

    return 0;
}
