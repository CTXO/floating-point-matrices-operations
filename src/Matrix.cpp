#include "Matrix.h"


Matrix::Matrix(std::size_t rows, std::size_t cols) : rows(rows), cols(cols) {
    data.resize(rows, std::vector<double>(cols, 0));
}

Matrix::Matrix(const std::vector<std::vector<double>>& data) {
    rows = data.size();
    cols = data[0].size();
    for (const auto& row : data) {
        if (row.size() != cols) {
            throw std::invalid_argument("All rows must have the same number of columns");
        }
    }
    this->data = data;
}

double& Matrix::operator()(std::size_t row, std::size_t col) {
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Index out of range");
    }
    return data[row][col];
}

double Matrix::operator()(std::size_t row, std::size_t col) const {
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Index out of range");
    }
    return data[row][col];
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must agree");
    }
    Matrix result(rows, cols);
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            result(i, j) = data[i][j] + other(i, j);
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must agree");
    }
    Matrix result(rows, cols);
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            result(i, j) = data[i][j] - other(i, j);
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Matrix dimensions are not suitable for multiplication");
    }
    Matrix result(rows, other.cols);
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < other.cols; ++j) {
            for (std::size_t k = 0; k < cols; ++k) {
                result(i, j) += data[i][k] * other(k, j);
            }
        }
    }
    return result;
}

Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols);
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            result(i, j) = data[i][j] * scalar;
        }
    }
    return result;
}

Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            result(j, i) = data[i][j];
        }
    }
    return result;
}

Matrix Matrix::inverse() const {
    if (rows != cols) {
        throw std::invalid_argument("Matrix must be square for inversion");
    }

    Matrix augmented(rows, cols * 2);
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            augmented(i, j) = data[i][j];
            augmented(i, j + cols) = (i == j) ? 1 : 0;
        }
    }

    for (std::size_t i = 0; i < rows; ++i) {
        std::size_t pivotRow = i;
        for (std::size_t j = i + 1; j < rows; ++j) {
            if (std::abs(augmented(j, i)) > std::abs(augmented(pivotRow, i))) {
                pivotRow = j;
            }
        }
        if (pivotRow != i) {
            for (std::size_t j = 0; j < cols * 2; ++j) {
                std::swap(augmented(i, j), augmented(pivotRow, j));
            }
        }

        double pivot = augmented(i, i);
        if (pivot == 0) {
            throw std::runtime_error("Matrix is singular, cannot be inverted");
        }
        for (std::size_t j = 0; j < cols * 2; ++j) {
            augmented(i, j) /= pivot;
        }

        for (std::size_t j = 0; j < rows; ++j) {
            if (j != i) {
                double factor = augmented(j, i);
                for (std::size_t k = 0; k < cols * 2; ++k) {
                    augmented(j, k) -= factor * augmented(i, k);
                }
            }
        }
    }

    Matrix result(rows, cols);
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            result(i, j) = augmented(i, j + cols);
        }
    }

    return result;
}

double Matrix::determinant() const {
    if (rows != cols) {
        throw std::invalid_argument("Matrix must be square to calculate determinant");
    }

    Matrix temp(*this); 
    double det = 1.0;

    for (std::size_t i = 0; i < rows; ++i) {
        // Find pivot
        std::size_t pivotRow = i;
        for (std::size_t j = i + 1; j < rows; ++j) {
            if (std::abs(temp(j, i)) > std::abs(temp(pivotRow, i))) {
                pivotRow = j;
            }
        }

        if (pivotRow != i) {
            det *= -1; 
            for (std::size_t j = 0; j < cols; ++j) {
                std::swap(temp(i, j), temp(pivotRow, j));
            }
        }

        for (std::size_t j = i + 1; j < rows; ++j) {
            double ratio = temp(j, i) / temp(i, i);
            for (std::size_t k = i; k < cols; ++k) {
                temp(j, k) -= ratio * temp(i, k);
            }
        }

        det *= temp(i, i);
    }

    return det;
}

void Matrix::printMatrix() const {
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << "\n";
    }
}

