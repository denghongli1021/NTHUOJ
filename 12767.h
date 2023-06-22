#include "function.h"

Matrix::~Matrix(){

}

Matrix::Matrix(int n) : n(n){
    matrix = new long long*[n];
    for (int i = 0 ;i<n;i++) {
        matrix[i] = new long long [n];
    }
    toZero();
}

Matrix::Matrix(const Matrix& ref){
    n = ref.n;
    matrix = new long long *[n];
    for (int i=0;i<n;i++) {
        matrix[i] = new long long [n];
    }
    matrix = ref.matrix;
}

Matrix& Matrix::operator=(const Matrix& ref){
    n = ref.n;
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<n;j++) {
            matrix[i][j] = ref.matrix[i][j];
        }
    }
    return *this;
}

long long& Matrix::operator()(const int& row, const int& column) const{
    return matrix[row][column];
}

void Matrix::toIdentity(){
    for (int i = 0 ;i < n ;i++) {
        matrix[i][i+1] = 1;
        matrix[n-1][i] = 1;
    }
}

Matrix Matrix::operator*(const Matrix& rhs) const{
    Matrix result(n);
    result.toZero();
    for (int i = 0 ;i<n;i++) {
        for (int j = 0 ; j<n;j++) {
            for (int k = 0 ;k <n;k++) {
                result.matrix[i][j] += ((*this)(i,k) * rhs(k,j) );
                result.matrix[i][j] %= mod;
            }
        }
    }
    return result;
}
/*
const int MAX = 100;
void matrix_multiply(int A[][MAX], int B[][MAX], int C[][MAX], int m, int n, int p)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
*/

Matrix Matrix::power(int k) const{
    Matrix tmp(n);
    tmp = *this;
    if (k == 1) {
        return tmp;
    }
    if (k % 2 == 1) {
        tmp = power ((k-1)/2);
        return tmp*tmp*(*this);
    }
    else {
        tmp = power(k/2);
        return tmp*tmp;
    }
}

Matrix constructMatrix(int n){
    Matrix temp(n);
    temp.toZero();
    temp.toIdentity();
    return result;
}
