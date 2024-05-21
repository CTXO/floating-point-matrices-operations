#include "LimitedPrecision.h"

const int PRECISION = 3;

// Scale factor for converting between integers and floats
const int SCALE_FACTOR = std::pow(10, PRECISION);

const int MANTISSA_SIZE = 5;
const int MIN_EXP = -10;
const int MAX_EXP = 10;


// Constructor to convert float to limited precision
LimitedPrecision::LimitedPrecision(float f) {
    int int_count = integer_digit_count(static_cast<int>(f));
    int decimal_count = decimal_digit_count(f);
    if (f > 0) {
        exp = int_count;
    }
    else {
        exp = int_count * -1;
    }

    if (exp > MAX_EXP)  {
        throw std::runtime_error("Overflow");
    }
    else if (exp < MIN_EXP) {
        throw std::runtime_error("Underflow");
    }

    float scaled = std::pow(10, exp) * f;
    float rounded = std::roundf(scaled);

    if (int_count >= MANTISSA_SIZE) {
        mantissa = static_cast<int>(rounded / std::pow(10, int_count - MANTISSA_SIZE));
    } 
    else {
        int mantissa_factor = MANTISSA_SIZE - int_count;
        mantissa = static_cast<int>(rounded * std::pow(10, mantissa_factor));
    }
    
    if (integer_digit_count(mantissa) != MANTISSA_SIZE) {
        throw std::runtime_error("Mantissa size is wrong");
    }
    
    value = static_cast<float>(*this);
}

int LimitedPrecision::integer_digit_count(int f) {
    if (f > 0 && f < 1) {
        return 0;
    }
    if (f < 0) {
        return std::to_string(f).length() - 1;
    }
    return std::to_string(f).length();
}

int LimitedPrecision::decimal_digit_count(float f) {
    float float_parsed = std::abs(f);
    float decimals = float_parsed - static_cast<int>(float_parsed);
    return std::to_string(decimals).length() - 2;
}

// Conversion operator to convert limited precision to float
LimitedPrecision::operator float() const {
    return static_cast<float>(mantissa / std::pow(10, MANTISSA_SIZE - exp));
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

 