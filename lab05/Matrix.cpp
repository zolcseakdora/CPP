#include "Matrix.h"
#include<ctime>
#include<cstdlib>
#include <climits>
#include <iomanip>
using namespace std;
Matrix::Matrix(int rows, int cols):mRows(rows),mCols(cols),mElements(mRows*mCols,0){
}

Matrix::Matrix(const Matrix &other):mRows(other.mRows),mCols(other.mCols),mElements(other.mElements){
}

Matrix::Matrix(Matrix &&other) noexcept:mRows(other.mRows),mCols(other.mCols),mElements(move(other.mElements)){
}

Matrix &Matrix::operator=(const Matrix &other){
    // TODO: insert return statement here
    if (this != &other) {
        if (mRows != other.mRows || mCols != other.mCols) {
            throw out_of_range("nem egyenlok");
        }
        copy(other.mElements.begin(), other.mElements.end(), mElements.begin());
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&other) noexcept{
    // TODO: insert return statement here
    if (this != &other) {
        if (mRows != other.mRows || mCols != other.mCols) {
            cout<<"nem egyenlok";
        }
        mElements = move(other.mElements); 
    }
    return *this; 
}

void Matrix::fillMatrix(double value) {
    fill(mElements.begin(), mElements.end(), value);
}


void Matrix::randomMatrix(int a, int b){
    srand(time(0));
    for(int i=0; i<mRows*mCols;++i){
        double d=rand();
        cout<<d<<endl;
        d=d/RAND_MAX;
        mElements[i]=a+d*(b-a);
    }

}

void Matrix::printMatrix(std::ostream &os) const
{
    for(int i=0; i< this->mRows; ++i){
        for(int j=0; j< this->mCols; ++j){
            os<<setw(8)<<mElements[i*mCols+j]<<" ";
        }
        os<<endl;
    }
}

double *Matrix::operator[](int row){
    return &mElements[row*mCols];
}

const double *Matrix::operator[](int row) const{
    return  &mElements[row*mCols];
}

double &Matrix::operator()(int row, int col) {
    if (row < 0 || row >= mRows || col < 0 || col >= mCols) {
        throw std::out_of_range("Matrix indices out of range");
    }
    return mElements[row * mCols + col];
}

const double &Matrix::operator()(int row, int col) const {
    if (row < 0 || row >= mRows || col < 0 || col >= mCols) {
        throw std::out_of_range("Matrix indices out of range");
    }
    return mElements[row * mCols + col];
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if (x.getRows() != y.getRows() || x.getCols() != y.getCols()) {
        throw std::out_of_range("Matrix sizes are not equal");
    }

    Matrix result(x.getRows(), x.getCols());

    for (int i = 0; i < x.getRows(); ++i) {
        for (int j = 0; j < x.getCols(); ++j) {
            result(i, j) = x(i, j) + y(i, j);
        }
    }

    return result;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if (x.getCols() != y.getRows()) {
        throw std::out_of_range("Matrix dimensions do not allow multiplication");
    }

    Matrix result(x.getRows(), y.getCols());

    for (int i = 0; i < x.getRows(); ++i) {
        for (int j = 0; j < y.getCols(); ++j) {
            double sum = 0.0;
            for (int k = 0; k < x.getCols(); ++k) {
                sum += x(i, k) * y(k, j);
            }
            result(i, j) = sum;
        }
    }

    return result;
}

std::istream &operator>>(std::istream &is, Matrix &mat)
{
    // TODO: insert return statement here
    for(int i=0; i<mat.mElements.size(); ++i){
        is>>mat.mElements[i];
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Matrix &mat){
    // TODO: insert return statement here
    mat.printMatrix(os);
    return os;
}
