#include "LimitedMatrix.h"


LimitedMatrix::LimitedMatrix(std::size_t rows, std::size_t cols) : rows(rows), cols(cols) {
    data.resize(rows, std::vector<LimitedPrecision>(cols, 0));
}

LimitedMatrix::LimitedMatrix(const std::vector<std::vector<LimitedPrecision>>& data) {
    rows = data.size();
    cols = data[0].size();
    for (const auto& row : data) {
        if (row.size() != cols) {
            throw std::invalid_argument("All rows must have the same number of columns");
        }
    }
    this->data = data;
}

LimitedPrecision& LimitedMatrix::operator()(std::size_t row, std::size_t col) {
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Index out of range");
    }
    return data[row][col];
}

LimitedPrecision LimitedMatrix::operator()(std::size_t row, std::size_t col) const {
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Index out of range");
    }
    return data[row][col];
}

LimitedMatrix LimitedMatrix::operator+(const LimitedMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("LimitedMatrix dimensions must agree");
    }
    LimitedMatrix result(rows, cols);
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            result(i, j) = data[i][j] + other(i, j);
        }
    }
    return result;
}

LimitedMatrix LimitedMatrix::operator-(const LimitedMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("LimitedMatrix dimensions must agree");
    }
    LimitedMatrix result(rows, cols);
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            result(i, j) = data[i][j] - other(i, j);
        }
    }
    return result;
}

LimitedMatrix LimitedMatrix::operator*(const LimitedMatrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("LimitedMatrix dimensions are not suitable for multiplication");
    }
    LimitedMatrix result(rows, other.cols);
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < other.cols; ++j) {
            for (std::size_t k = 0; k < cols; ++k) {
                result(i, j) = result(i,j) + data[i][k] * other(k, j);
            }
        }
    }
    return result;
}

LimitedMatrix LimitedMatrix::operator*(LimitedPrecision scalar) const {
    LimitedMatrix result(rows, cols);
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            result(i, j) = data[i][j] * scalar;
        }
    }
    return result;
}

LimitedMatrix LimitedMatrix::transpose() const {
    LimitedMatrix result(cols, rows);
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            result(j, i) = data[i][j];
        }
    }
    return result;
}

LimitedMatrix LimitedMatrix::inverse() const {
    if (rows != cols) {
        throw std::invalid_argument("LimitedMatrix must be square for inversion");
    }

    LimitedMatrix augmented(rows, cols * 2);
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

        LimitedPrecision pivot = augmented(i, i);
        bool comparaçao = pivot == 0;
        if (pivot == 0) {
            throw std::runtime_error("LimitedMatrix is singular, cannot be inverted");
        }
        for (std::size_t j = 0; j < cols * 2; ++j) {
            augmented(i, j) = augmented(i, j) / pivot;
        }

        for (std::size_t j = 0; j < rows; ++j) {
            if (j != i) {
                LimitedPrecision factor = augmented(j, i);
                for (std::size_t k = 0; k < cols * 2; ++k) {
                    augmented(j, k) = augmented(j, k) - (factor * augmented(i, k));
                }
            }
        }
    }

    LimitedMatrix result(rows, cols);
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            result(i, j) = augmented(i, j + cols);
        }
    }

    return result;
}

LimitedPrecision LimitedMatrix::determinant() const {
    if (rows != cols) {
        throw std::invalid_argument("LimitedMatrix must be square to calculate determinant");
    }

    LimitedMatrix temp(*this); 
    LimitedPrecision det = 1.0;

    for (std::size_t i = 0; i < rows; ++i) {
        // Find pivot
        std::size_t pivotRow = i;
        for (std::size_t j = i + 1; j < rows; ++j) {
            if (std::abs(temp(j, i)) > std::abs(temp(pivotRow, i))) {
                pivotRow = j;
            }
        }

        if (pivotRow != i) {
            det = det * -1; 
            for (std::size_t j = 0; j < cols; ++j) {
                std::swap(temp(i, j), temp(pivotRow, j));
            }
        }

        for (std::size_t j = i + 1; j < rows; ++j) {
            LimitedPrecision ratio = temp(j, i) / temp(i, i);
            for (std::size_t k = i; k < cols; ++k) {
                temp(j, k) = temp(j, k) - (ratio * temp(i, k));
            }
        }

        det = det * temp(i, i);
    }

    return det;
}

void LimitedMatrix::printMatrix() const {
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

