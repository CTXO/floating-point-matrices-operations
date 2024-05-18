#include "LimitedPrecision.h"

const int PRECISION = 3;

// Scale factor for converting between integers and floats
const int SCALE_FACTOR = std::pow(10, PRECISION);

// Constructor to convert float to limited precision
LimitedPrecision::LimitedPrecision(float f) {
    float scaled = f * SCALE_FACTOR;
    float rounded = std::roundf(scaled);
    value = static_cast<int>(rounded);
}

// Conversion operator to convert limited precision to float
LimitedPrecision::operator float() const {
    return static_cast<float>(value) / SCALE_FACTOR;
}

// Example arithmetic operations
LimitedPrecision LimitedPrecision::operator+(const LimitedPrecision& other) const {
    return LimitedPrecision(static_cast<float>(*this) + static_cast<float>(other));
}

LimitedPrecision LimitedPrecision::operator-(const LimitedPrecision& other) const {
    return LimitedPrecision(static_cast<float>(*this) - static_cast<float>(other));
}

LimitedPrecision LimitedPrecision::operator*(const LimitedPrecision& other) const {
    return LimitedPrecision(static_cast<float>(*this) * static_cast<float>(other));
}

LimitedPrecision LimitedPrecision::operator*(const int other) const {
    return LimitedPrecision(static_cast<float>(*this) * static_cast<float>(other));
}

LimitedPrecision LimitedPrecision::operator/(const LimitedPrecision& other) const {
    return LimitedPrecision(static_cast<float>(*this) / static_cast<float>(other));
}

// Example comparison operators
bool LimitedPrecision::operator==(const LimitedPrecision& other) const {
    return value == other.value;
}

bool LimitedPrecision::operator==(const int other) const {
    return value == other;
}

bool LimitedPrecision::operator!=(const LimitedPrecision& other) const {
    return value != other.value;
}

// Example output operator
std::ostream& operator<<(std::ostream& os, const LimitedPrecision& lp) {
    os << static_cast<float>(lp);
    return os;
} 

 