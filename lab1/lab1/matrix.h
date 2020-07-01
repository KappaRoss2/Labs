#pragma once
#include <iostream>

class MATRIX {
	public:
	double** M;
	int n;
	int m;
	MATRIX(int _n, int _m);
	MATRIX(const MATRIX& _M);
	double GetMij(int i, int j);
	void SetMij(int i, int j, double value);
	MATRIX operator=(const MATRIX& _M);
	friend MATRIX operator+(const MATRIX& A, const MATRIX& B);
	friend MATRIX operator-(const MATRIX& A, const MATRIX& B);
	friend MATRIX operator+=(MATRIX& A, const double digit);
	friend MATRIX operator-=(MATRIX& A, const double digit);
	friend MATRIX operator/=(MATRIX& A, const double digit);
	friend MATRIX operator*=(MATRIX& A, const double digit);
	friend MATRIX operator*(MATRIX& A, const double digit);
	friend MATRIX operator* (const double digit, MATRIX& A);
	friend MATRIX operator/ (const double digit, MATRIX& A);
	friend MATRIX operator/ (MATRIX& A, const double digit);
	friend MATRIX operator+ (MATRIX& A, const double digit);
	friend MATRIX operator+ (const double digit, MATRIX& A);
	friend MATRIX operator- (const double digit, MATRIX& A);
	friend MATRIX operator- (MATRIX& A, const double digit);
	friend MATRIX operator*(MATRIX& A, MATRIX& B);
	friend MATRIX operator/(const MATRIX& A, const MATRIX& B);
	friend std::ostream& operator<< (std::ostream& out, const MATRIX& M);
	~MATRIX();
};