#ifndef LIMITEDPRECISION_H
#define LIMITEDPRECISION_H

#include <iostream>
#include <cmath>


class LimitedPrecision {
private:
    double mantissa;
    int exp;
    float value;
    bool negative;



public:
    // Constructor to convert float to limited precision
    LimitedPrecision(float f);

    // Conversion operator to convert limited precision to float
    operator float() const;

    // Example arithmetic operations
    LimitedPrecision operator+(const LimitedPrecision& other) const;
    LimitedPrecision operator-(const LimitedPrecision& other) const;
    LimitedPrecision operator*(const LimitedPrecision& other) const;
    LimitedPrecision operator*(const int other) const;
    LimitedPrecision operator/(const LimitedPrecision& other) const;

    // Example comparison operators
    bool operator==(const LimitedPrecision& other) const;
    bool operator==(const int other) const;
    bool operator!=(const LimitedPrecision& other) const;
    
    int integer_digit_count(int f);
    int decimal_digit_count(float f);
    double roundToSignificantDigits(double value, int digits);
    std::pair<double, int> normalize(double value, int digits);

    // Example output operator
    friend std::ostream& operator<<(std::ostream& os, const LimitedPrecision& lp);
};

#endif // LIMITEDPRECISION_H