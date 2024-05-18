#ifndef LIMITED_MATRIX_H
#define LIMITED_MATRIX_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include "LimitedPrecision.h"


class LimitedMatrix {
private:
    std::vector<std::vector<LimitedPrecision>> data;
    std::size_t rows, cols;

public:
    // Constructor to initialize a matrix of given dimensions with all zeros
    LimitedMatrix(std::size_t rows, std::size_t cols);

    // Constructor to initialize a matrix from a 2D vector
    LimitedMatrix(const std::vector<std::vector<LimitedPrecision>>& data);

    // Access element (l-value)
    LimitedPrecision& operator()(std::size_t row, std::size_t col);

    // Access element (r-value)
    LimitedPrecision operator()(std::size_t row, std::size_t col) const;

    // Limited_Matrix addition
    LimitedMatrix operator+(const LimitedMatrix& other) const;

    // Limited_Matrix subtraction
    LimitedMatrix operator-(const LimitedMatrix& other) const;

    // Limited_Matrix multiplication
    LimitedMatrix operator*(const LimitedMatrix& other) const;

    // Scalar multiplication
    LimitedMatrix operator*(LimitedPrecision scalar) const;

    // Transpose the matrix
    LimitedMatrix transpose() const;

    // Invert the matrix
    LimitedMatrix inverse() const;

    //Calculate Determinant
    LimitedPrecision determinant() const;

    //Print the Limited_Matrix
    void printMatrix() const;
};

#endif // LIMITED_MATRIX_H