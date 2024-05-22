#include <iostream>
#include <cmath>
#include "Matrix.h"
#include "LimitedMatrix.h"
#include "LimitedPrecision.h"


int main() {
    double x = 1.764;
    double y = 2.895;
    double z = 3.967;
    double w = 4.789;
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


    LimitedPrecision sum = a + b;
    LimitedPrecision difference = a - b;
    LimitedPrecision product = a * b;
    LimitedPrecision quotient = a / b;

    std::cout << "a: " << static_cast<float>(a) << std::endl;
    std::cout << "b: " << static_cast<float>(b) << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Quotient: " << quotient << std::endl;
    

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
        {b_2,d_2}
    };
    LimitedMatrix lm_2 = LimitedMatrix(lmv_2);

    //Operations
    //Inversion
    // Matrix inv = m.inverse();
    // std::cout << "Original matrix:" << std::endl;
    // m.printMatrix();
    // std::cout << std::endl << "Inverse matrix:" << std::endl;
    // inv.printMatrix();

    // LimitedMatrix linv = lm.inverse();
    // std::cout << std::endl << "Original limited matrix:" << std::endl;
    // lm.printMatrix();
    // std::cout << std::endl << "Inverse limited matrix:" << std::endl;
    // linv.printMatrix();

    //Determinant
    // double det = m.determinant();
    // std::cout << "Original matrix:" << std::endl;
    // m.printMatrix();
    // std::cout << std::endl << "Determinant: " << det << std::endl;

    // LimitedPrecision lm_det = lm.determinant();
    // std::cout << std::endl << "Original limited matrix:" << std::endl;
    // lm.printMatrix();
    // std::cout << std::endl << "Determinant: " << lm_det << std::endl;

    //Properties
    //Associativity
    // std::cout << "Original matrixes:" << std::endl;
    // m.printMatrix();
    // std::cout << std::endl;
    // m_2.printMatrix();
    // std::cout << std::endl;
    // m_3.printMatrix();
    // std::cout << std::endl;

    // double u = 2.637;
    // double v = 3.719;
    // double product = u*v;

    // Matrix partial_product = m * u;
    // Matrix result = partial_product * v;
    // std::cout << "(m*u)*v:" << std::endl;
    // result.printMatrix();
    // result = m * product;
    // std::cout << std::endl << "(u*v)*m" << std::endl;
    // result.printMatrix();
    // std::cout << std::endl;

    // LimitedPrecision l_u = 2.637;
    // LimitedPrecision l_v = 3.719;
    // LimitedPrecision l_product = u*v;

    // LimitedMatrix l_partial_product = lm * l_u;
    // LimitedMatrix l_result = l_partial_product * l_v;
    // std::cout << "(lm*l_u)*l_v:" << std::endl;
    // l_result.printMatrix();
    // l_result = lm * l_product;
    // std::cout << std::endl << "(l_u*l_v)*lm" << std::endl;
    // l_result.printMatrix();
    // std::cout << std::endl;

    //M * M^-1 = I
    // Matrix inv = m.inverse();
    // Matrix result = m * inv;
    // result.printMatrix();
    // std::cout<< std::endl;

    
    // LimitedMatrix l_inv = lm.inverse();
    // LimitedMatrix l_result = lm * l_inv;
    // l_result.printMatrix();

    // (M^-1)^-1 = M
    // m.printMatrix();
    // Matrix identity = m.inverse().inverse();
    // identity.printMatrix();
    
    // LimitedMatrix l_identity = lm.inverse().inverse();
    // l_identity.printMatrix();

    //Distributive
    // u*(A+B)
    // uA + uB
    //
    // double u = 2.989;
    // Matrix sum = m + m_2;
    // Matrix product = sum * u;
    // Matrix pre_product = m*u + m_2*u;
    // product.printMatrix();
    // pre_product.printMatrix();

    // LimitedPrecision l_u = 2.989;
    // LimitedMatrix l_sum = lm + lm_2;
    // LimitedMatrix l_product = l_sum * l_u;
    // LimitedMatrix l_pre_product = lm*l_u + lm_2*l_u;
    // l_product.printMatrix();
    // l_pre_product.printMatrix();
    // return 0;

    //Comultativity
    // m.inverse().transpose().printMatrix();
    // m.transpose().inverse().printMatrix();
    // lm.inverse().transpose().printMatrix();
    // lm.transpose().inverse().printMatrix();
    

}
