// Author: justin0u0<dancinglinkxalgorithm@gmail.com>
#include <iostream>
using namespace std;
const int mod = 1000000009;

class Matrix {
private:
  int n;
  long long **matrix;
public:
  // The Default Constructor
  Matrix() {
    n = 0;
    matrix = nullptr;
  }
  // TODO: The Destructor
  ~Matrix();

  // TODO: The Customize Constructor
  Matrix(int n);

  // TODO: Copy contructor
  // Will be trigger when the following condition:
  // Matrix m = ref; -> Call copy contructor to copy from 'ref' to 'm'
  Matrix(const Matrix& ref);

  // TODO: copy assignment,
  // Will be trigger when the following condition:
  // Matrix a;
  // a = ref; -> Call copy assignment to copy from 'ref' to 'a'
  Matrix& operator=(const Matrix& ref);

  // TODO: Overload operator()
  // This operator allow the following code
  // This operator can help you access the data easily
  // 1. cout << m(1, 2) << endl; -> Shorthand of `cout << m.matrix[1, 2] << endl;`
  // 2. m(1, 2) = 100; -> Shorthand of `m.matrix[1, 2] = 100`
  long long& operator()(const int& row, const int& column) const;

  // Utilities functions
  // TODO: Make the matrix identity matrix
  void toIdentity();
  void toZero() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        matrix[i][j] = 0;
    }
  }

  // TODO: Overload operator *
  Matrix operator*(const Matrix& rhs) const;

  // TODO: Return the matrix power of 'k'
  Matrix power(int k) const;

  friend ostream& operator<<(ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.n; i++) {
      for (int j = 0; j < matrix.n; j++)
        os << matrix(i, j) << ' ';
      os << endl;
    }
    return os;
  }
};
Matrix::~Matrix(){

}

Matrix::Matrix(int n) : n(n){
    matrix = new long long* [n];
    for(int i=0; i<n; i++)
        matrix[i] = new long long[n];
    toZero();
}

Matrix::Matrix(const Matrix& ref){
    n = ref.n;
    matrix = new long long*[n];
    for(int i=0; i<n; i++)
        matrix[i] = new long long[n];
    matrix = ref.matrix;
}

Matrix& Matrix::operator=(const Matrix& ref){
    n = ref.n;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        matrix[i][j] = ref.matrix[i][j];
    return *this;
}

long long& Matrix::operator()(const int& row, const int& column) const{
    //printf("%d\n",matrix[row][column]);
    return matrix[row][column];
}

void Matrix::toIdentity(){
    for (int i = 0; i < n-1; i++)
        matrix[i][i+1] = 1;
    for (int i = 0; i < n; i++)
        matrix[n-1][i] = 1;

}

Matrix Matrix::operator*(const Matrix& rhs) const{
    Matrix result(n);
    result.toZero();
    for(int row = 0; row < n; row++){
        for(int sft_r = 0; sft_r < n; sft_r++){
            for(int col = 0; col < n; col++){
                result(row, sft_r) += ( (*this)(row, col) * rhs(col, sft_r) ) % mod;
                result(row, sft_r) %= mod;
            }
        }
    }
    return result;
}

Matrix Matrix::power(int k) const{
    Matrix tmp(n);
    tmp = *this;
    if(k == 1) return tmp;
    if(k%2 == 1){
        tmp = power( (k-1)/2 );
        return tmp*tmp*(*this);
    }
    else{
        tmp = power(k/2);
        return tmp*tmp;
    }
}

// porno
Matrix constructMatrix(int n){
    Matrix result(n);
    result.toIdentity();
    return result;
}

// by ryona
int main() {
  int n, m;
  cin >> n >> m;
  if (m <= n) {
    cout << 1 << endl;
  } else {
    Matrix base = constructMatrix(n);
    base = base.power(m - n);
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans = (ans + base(n - 1, i)) % mod;
    cout << ans << endl;
  }
  return 0;
}
