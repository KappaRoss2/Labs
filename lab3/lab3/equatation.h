#pragma once
#include <valarray>
#include <string>

using vector = std::valarray<double>;

class equatation
{
public:
	int NumPoint;
	double* consts;
	double Lx;
	double dt;
	double h;
	vector u;
	vector du;
	vector T;
	vector dT;
	equatation(int NumPoint, double L);
	void setInitial(vector T, vector u);
	void step();
	void write(std::string); 
	~Case();
};