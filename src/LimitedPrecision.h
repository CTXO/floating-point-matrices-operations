#ifndef LIMITEDPRECISION_H
#define LIMITEDPRECISION_H

#include <iostream>
#include <cmath>

class LimitedPrecision {
private:
    int value;

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

    // Example output operator
    friend std::ostream& operator<<(std::ostream& os, const LimitedPrecision& lp);
};

#endif // LIMITEDPRECISION_H