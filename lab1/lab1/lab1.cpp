#include <iostream>
#include "matrix.h"
using namespace std;

MATRIX::MATRIX(int _n, int _m)
{
    n = _n;
    m = _m;

    M = (double**) new double* [n];


    for (int i = 0; i < n; i++)
        M[i] = (double*)new double[m];


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            M[i][j] = 0;
};

MATRIX::MATRIX(const MATRIX& _M)
{

    n = _M.n;
    m = _M.m;

    // Выделить память для M
    M = (double**) new double* [n]; // количество строк, количество указателей

    for (int i = 0; i < n; i++)
        M[i] = (double*) new double[m];

    // заполнить значениями
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            M[i][j] = _M.M[i][j];
};

double MATRIX::GetMij(int i, int j)
{
    if ((n > 0) && (m > 0))
        return M[i][j];
    else
        return 0;
};

void MATRIX::SetMij(int i, int j, double value)
{
    if ((i < 0) || (i >= n))
        return;
    if ((j < 0) || (j >= m))
        return;
    M[i][j] = value;
};


MATRIX MATRIX::operator=(const MATRIX& _M)
{
    if (m > 0)
    {
        for (int i = 0; i < n; i++)
            delete[] M[i];
    }

    if (m > 0)
    {
        delete[] M;
    }

    n = _M.n;
    m = _M.m;

    M = (double**) new double* [n];
    for (int i = 0; i < n; i++)
        M[i] = (double*) new double[m];


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            M[i][j] = _M.M[i][j];
    return *this;
};

MATRIX operator+(const MATRIX& A, const MATRIX& B)
{
    MATRIX C(A.n, A.m);
    if ((A.n == B.n) && (A.m == B.m))
    {
        for (int i = 0; i < A.n; i++)
            for (int j = 0; j < A.m; j++)
            {
                C.M[i][j] = A.M[i][j] + B.M[i][j];
            }
        return C;
    }
    else
    {
        return C;
    }
};

MATRIX operator-(const MATRIX& A, const MATRIX& B)
{
    MATRIX C(A.n, A.m);
    if ((A.n == B.n) && (A.m == B.m))
    {
        for (int i = 0; i < A.n; i++)
            for (int j = 0; j < A.m; j++)
            {
                C.M[i][j] = A.M[i][j] - B.M[i][j];
            }
        return C;
    }
    else
    {
        return C;
    }
};

MATRIX operator+=(MATRIX& A, const double digit)
{
    for (int i = 0; i < A.n; i++)
        for (int j = 0; j < A.m; j++)
        {
            A.M[i][j] += digit;
        }
    return A;
};

MATRIX operator-=(MATRIX& A, const double digit)
{
    for (int i = 0; i < A.n; i++)
        for (int j = 0; j < A.m; j++)
        {
            A.M[i][j] -= digit;
        }
    return A;
};

MATRIX operator/=(MATRIX& A, const double digit)
{
    for (int i = 0; i < A.n; i++)
        for (int j = 0; j < A.m; j++)
        {
            A.M[i][j] /= digit;
        }
    return A;
};

MATRIX operator*=(MATRIX& A, const double digit)
{
    for (int i = 0; i < A.n; i++)
        for (int j = 0; j < A.m; j++)
        {
            A.M[i][j] *= digit;
        }
    return A;
};

MATRIX operator*(MATRIX& A, const double digit)
{
    MATRIX C(A.n, A.m);;
    for (int i = 0; i < A.n; i++)
        for (int j = 0; j < A.m; j++)
        {
            C.M[i][j] = A.M[i][j] * digit;
        }
    return C;
};

MATRIX operator* (const double digit, MATRIX& A)
{
    MATRIX C(A.n, A.m);
    for (int i = 0; i < A.n; i++)
        for (int j = 0; j < A.m; j++)
        {
            C.M[i][j] = digit * A.M[i][j];
        }
    return C;
};

MATRIX operator/ (const double digit, MATRIX& A)
{
    MATRIX C(A.n, A.m);
    for (int i = 0; i < A.n; i++)
        for (int j = 0; j < A.m; j++)
        {
            C.M[i][j] = digit / A.M[i][j];
        }
    return C;
};

MATRIX operator/ (MATRIX& A, const double digit)
{
    MATRIX C(A.n, A.m);
    for (int i = 0; i < A.n; i++)
        for (int j = 0; j < A.m; j++)
        {
            C.M[i][j] = A.M[i][j] / digit;
        }
    return C;
};

MATRIX operator+ (MATRIX& A, const double digit)
{
    MATRIX C(A.n, A.m);
    for (int i = 0; i < A.n; i++)
        for (int j = 0; j < A.m; j++)
        {
            C.M[i][j] = A.M[i][j] + digit;
        }
    return C;
};

MATRIX operator+ (const double digit, MATRIX& A)
{
    MATRIX C(A.n, A.m);
    for (int i = 0; i < A.n; i++)
        for (int j = 0; j < A.m; j++)
        {
            C.M[i][j] = digit + A.M[i][j];
        }
    return C;
};

MATRIX operator- (const double digit, MATRIX& A)
{
    MATRIX C(A.n, A.m);
    for (int i = 0; i < A.n; i++)
        for (int j = 0; j < A.m; j++)
        {
            C.M[i][j] = digit - A.M[i][j];
        }
    return C;
};

MATRIX operator- (MATRIX& A, const double digit)
{
    MATRIX C(A.n, A.m);
    for (int i = 0; i < A.n; i++)
        for (int j = 0; j < A.m; j++)
        {
            C.M[i][j] = A.M[i][j] - digit;
        }
    return C;
};

MATRIX operator*(MATRIX& A, MATRIX& B)
{
    MATRIX C(A.n, A.m);
    if ((A.n == B.n) && (A.m == B.m))
    {
        for (int i = 0; i < A.n; i++)
            for (int j = 0; j < A.m; j++)
            {
                C.M[i][j] = A.M[i][j] * B.M[i][j];
            }
        return C;
    }
    else
    {
        return C;
    }
};

MATRIX operator/(const MATRIX& A, const MATRIX& B)
{
    MATRIX C(A.n, A.m);
    if ((A.n == B.n) && (A.m == B.m))
    {
        for (int i = 0; i < A.n; i++)
            for (int j = 0; j < A.m; j++)
            {
                C.M[i][j] = A.M[i][j] / B.M[i][j];
            }
        return C;
    }
    else
    {
        return C;
    }
};

ostream& operator<< (ostream& out, const MATRIX& M)
{
    for (int i = 0; i < M.n; i++)
    {
        for (int j = 0; j < M.m; j++)
            out << M.M[i][j] << "\t";
        out << endl;
    }
    out << endl << endl;
    return out;
};

MATRIX::~MATRIX()
{
    if (n > 0)
    {

        for (int i = 0; i < n; i++)
            delete[] M[i];
    }

    if (m > 0)
        delete[] M;
};