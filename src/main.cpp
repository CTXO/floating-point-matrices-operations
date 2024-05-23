#include <iostream>
#include <cmath>
#include "Matrix.h"
#include "LimitedMatrix.h"
#include "LimitedPrecision.h"


int main() {
    double x = 4.299;
    double y = 3.143;
    double z = 6.988;
    double w = 7.529;

    double x_2 = 5.928;
    double y_2 = 6.864;
    double z_2 = 3.787;
    double w_2 = 2.686;

    LimitedPrecision a = LimitedPrecision(x); 
    LimitedPrecision b = LimitedPrecision(y);
    LimitedPrecision c = LimitedPrecision(z);
    LimitedPrecision d = LimitedPrecision(w);
    LimitedPrecision a_2 = LimitedPrecision(x_2); 
    LimitedPrecision b_2 = LimitedPrecision(y_2);
    LimitedPrecision c_2 = LimitedPrecision(z_2);
    LimitedPrecision d_2 = LimitedPrecision(w_2);

    std::vector<std::vector<double>> mv = {
        {x, z},
        {y, w}
    };
    Matrix m = Matrix(mv);

    std::vector<std::vector<LimitedPrecision>> lmv = {
        {a,c},
        {b,d}
    };
    LimitedMatrix lm = LimitedMatrix(lmv);

    std::vector<std::vector<double>> mv_2 = {
        {x_2, z_2},
        {w_2, y_2}
    };
    Matrix m_2 = Matrix(mv_2);

    std::vector<std::vector<LimitedPrecision>> lmv_2 = {
        {a_2,c_2},
        {d_2,b_2}
    };
    LimitedMatrix lm_2 = LimitedMatrix(lmv_2);

    // Operations
    // Inversion
    
    // std::cout << "\n" << "Original matrix:" << std::endl;
    // m.printMatrix();
    // std::cout << std::endl << "Original limited matrix:" << std::endl;
    // lm.printMatrix();

    // Matrix inv = m.inverse();
    // std::cout << std::endl << "Inverse matrix:" << std::endl;
    // inv.printMatrix();
    // LimitedMatrix linv = lm.inverse();
    // std::cout << std::endl << "Inverse limited matrix:" << std::endl;
    // linv.printMatrix();
    // std::cout << "\n";

    //Determinant
    
    // std::cout << "\n" << "Original matrix:" << std::endl;
    // m.printMatrix();
    // std::cout << std::endl << "Original limited matrix:" << std::endl;
    // lm.printMatrix();

    // double det = m.determinant();
    // std::cout << std::endl << "Determinant: " << det;
    // LimitedPrecision lm_det = lm.determinant();
    // std::cout << std::endl << "LimitedPrecision Determinant: " << lm_det << "\n" << std::endl;

    //Properties
    //Associativity

    // double u = 2.637;
    // double v = 3.719;
    // LimitedPrecision l_u = u;
    // LimitedPrecision l_v = v;

    // std::cout << "\n" << "u: " << u << "\n" << "l_u: " << l_u << "\n" << std::endl;
    // std::cout << "v: " << v << "\n" << "l_v: " << l_v << std::endl;
    // std::cout << "\n" << "Matrix:" << std::endl;
    // m.printMatrix();
    // std::cout << "\n" << "Limited Matrix:" << std::endl;
    // lm.printMatrix();

    // Matrix partial_product = m * u;
    // Matrix result = partial_product * v;
    // std::cout << "\n" << "(m * u) * v:" << std::endl;
    // result.printMatrix();

    // double product = u*v;
    // result = m * product;
    // std::cout << std::endl << "(u * v) * m:" << std::endl;
    // result.printMatrix();
    // std::cout << std::endl;

    // LimitedMatrix l_partial_product = lm * l_u;
    // LimitedMatrix l_result = l_partial_product * l_v;
    // std::cout << "(lm * l_u) * l_v:" << std::endl;
    // l_result.printMatrix();

    // LimitedPrecision l_product = u*v;
    // l_result = lm * l_product;
    // std::cout << "\n" << "(l_u * l_v) * lm:" << std::endl;
    // l_result.printMatrix();
    // std::cout << std::endl;

    //M * M^-1 = I
    // std::cout<< "\n" << "Matrix:" << std::endl;
    // m.printMatrix();

    // Matrix inv = m.inverse();
    // Matrix result = m * inv;
    // std::cout << "\n" << "m * m.inverse():" << std::endl;
    // result.printMatrix();

    // std::cout<< "\n" << "Limited Matrix:" << std::endl;
    // lm.printMatrix();
    // LimitedMatrix l_inv = lm.inverse();
    // LimitedMatrix l_result = lm * l_inv;
    // std::cout << "\n" << "lm * lm.inverse():" << std::endl;
    // l_result.printMatrix();
    // std::cout << std::endl;

    // (M^-1)^-1 = M
    // std::cout<< "\n" << "Matrix:" << std::endl;
    // m.printMatrix();

    // Matrix identity = m.inverse().inverse();
    // std::cout<< "\n" << "m.inverse().inverse():" << std::endl;
    // identity.printMatrix();
    
    // std::cout<< "\n" << "Limited Matrix:" << std::endl;
    // lm.printMatrix();

    // LimitedMatrix l_identity = lm.inverse().inverse();
    // std::cout<< "\n" << "lm.inverse().inverse():" << std::endl;
    // l_identity.printMatrix();
    // std::cout<< std::endl;

    //Distributive
    // u*(A+B) = uA + uB
    // std::cout<< "\n" << "Matrices: " << std::endl;
    // m.printMatrix();
    // std::cout<< std::endl;
    // m_2.printMatrix();
    
    // std::cout<< "\n" << "Limited Matrices: " << std::endl;
    // lm.printMatrix();
    // std::cout<< std::endl;
    // lm_2.printMatrix();
    // std::cout<< std::endl;

    // double u = 2.989;
    // LimitedPrecision l_u = 2.989;
    // std::cout <<"u: " << u << "\n" << "l_u: " << l_u << "\n" << std::endl;

    // Matrix sum = m + m_2;
    // Matrix product = sum * u;
    // Matrix pre_product = m*u + m_2*u;

    // std::cout<< "(m + m_2) * u: " << std::endl;
    // product.printMatrix();
    // std::cout<< std::endl;
    // std::cout<< "(m * u) + (m_2 * u): " << std::endl;
    // pre_product.printMatrix();
    // std::cout<< std::endl;

    // LimitedMatrix l_sum = lm + lm_2;
    // LimitedMatrix l_product = l_sum * l_u;
    // LimitedMatrix l_pre_product = lm*l_u + lm_2*l_u;

    // std::cout<< "(lm + lm_2) * l_u: " << std::endl;
    // l_product.printMatrix();
    // std::cout<< std::endl;
    // std::cout<< "(lm * l_u) + (lm_2 * l_u): " << std::endl;
    // l_pre_product.printMatrix();
    // std::cout<< std::endl;

    //Commutative
    std::cout << "\n" << "Matrix:" << std::endl;
    m.printMatrix();
    std::cout << "\n" << "Limited Matrix:" << std::endl;
    lm.printMatrix();

    std::cout << "\n" << "m.inverse().transpose():" << std::endl;
    m.inverse().transpose().printMatrix();
    std::cout << "\n" << "m.transpose().inverse():" << std::endl;
    m.transpose().inverse().printMatrix();

    std::cout << "\n" << "lm.inverse().transpose():" << std::endl;
    lm.inverse().transpose().printMatrix();
    std::cout << "\n" << "lm.transpose().inverse():" << std::endl;
    lm.transpose().inverse().printMatrix();
    
    return 0;
}
