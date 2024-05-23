#include "LimitedPrecision.h"
// const int PRECISION = 3

// // Scale factor for converting between integers and floats
// const int SCALE_FACTOR = std::pow(10, PRECISION);

const int MANTISSA_SIZE = 5;
const int MIN_EXP = -5;
const int MAX_EXP = 5;


// Constructor to convert float to limited precision
LimitedPrecision::LimitedPrecision(float f) {
    
    negative = f < 0;
    float f_abs = std::fabs(f);
    
    if (f == 0) {
        mantissa = 0;
        exp = 0;
    }
    else {
        std::pair<double, int> m_exp = normalize(f, MANTISSA_SIZE);
        mantissa = m_exp.first;
        exp = m_exp.second;
    }
    if (!negative && exp > MAX_EXP)  {
        throw std::runtime_error("Overflow");
    }
    else if (negative && exp*-1 < MIN_EXP) {
        throw std::runtime_error("Underflow");
    }
    
    value = mantissa * std::pow(10, exp);
    
    // int int_count = integer_digit_count(static_cast<int>(f));
    // std::cout << "Int count is " << int_count << '\n';
    
    
    // exp = int_count;

    // f = std::fabs(f);
    
    // float digits_rounded = roundToSignificantDigits(f, MANTISSA_SIZE);
    // int decimalCount = MANTISSA_SIZE - int_count;
    // std::cout << "Digits rounded is " << digits_rounded << '\n';
    // std::cout << "Digits decimal count is " << decimalCount << '\n';
    // std::cout << "Multiply by:" << std::pow(10, decimalCount) << '\n';
    // mantissa = digits_rounded * std::pow(10, decimalCount); 
    // std::cout << "mantissa is " << mantissa << '\n';

    // in -12.3458
    // - 12345.8
    // - round (12345.8)
    // out - 12.346
    // 
}

std::pair<double, int> LimitedPrecision::normalize(double value, int digits) {
    int exponent = 0;

    if (value != 0.0) {
    
        while (fabs(value) >= 1.0) {
            value /= 10.0;
            exponent++;
        }
        while (fabs(value) < 0.1) {
            value *= 10.0;
            exponent--;
        }
    }

    double factor = pow(10, digits - static_cast<int>(floor(log10(fabs(value)))) - 1);
    value = round(value * factor) / factor;

    return std::make_pair(value, exponent);
}

double LimitedPrecision::roundToSignificantDigits(double value, int digits) {
    if (value == 0.0) {
        return 0.0;
    }

    double factor = pow(10, digits - static_cast<int>(floor(log10(fabs(value)))) - 1);
    return round(value * factor) / factor;
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

// int LimitedPrecision::decimal_digit_count(float f) {
//     float float_parsed = std::fabs(f);
//     float decimals = float_parsed - static_cast<int>(float_parsed);
//     std::cout << "DECIMALS " << decimals << " string: " << std::to_string(decimals) << " count: " << std::to_string(decimals).length() << '\n';
//     return std::to_string(decimals).length() - 2;
// }
int LimitedPrecision::decimal_digit_count(float num) {
    int count = 0;
    num = std::fabs(num);
    num = num - static_cast<int>(num);

    while (num > 0.001) {
        num *= 10;
        count++;
        num = num - static_cast<int>(num);
        // Avoid infinite loop by checking if num is stuck
        if (count > 10) {
            break;
        }
    }
    
    return count;
}


// Conversion operator to convert limited precision to float
LimitedPrecision::operator float() const {
    return value;
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

 