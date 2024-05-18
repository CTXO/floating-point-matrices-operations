#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include "LimitedPrecision.h"


class Matrix {
private:
    std::vector<std::vector<double>> data;
    std::size_t rows, cols;

public:
    // Constructor to initialize a matrix of given dimensions with all zeros
    Matrix(std::size_t rows, std::size_t cols);

    // Constructor to initialize a matrix from a 2D vector
    Matrix(const std::vector<std::vector<double>>& data);

    // Access element (l-value)
    double& operator()(std::size_t row, std::size_t col);

    // Access element (r-value)
    double operator()(std::size_t row, std::size_t col) const;

    // Matrix addition
    Matrix operator+(const Matrix& other) const;

    // Matrix subtraction
    Matrix operator-(const Matrix& other) const;

    // Matrix multiplication
    Matrix operator*(const Matrix& other) const;

    // Scalar multiplication
    Matrix operator*(double scalar) const;

    // Transpose the matrix
    Matrix transpose() const;

    // Invert the matrix
    Matrix inverse() const;

    //Calculate Determinant
    double determinant() const;

    //Print the Matrix
    void printMatrix() const;
};

#endif // MATRIX_H