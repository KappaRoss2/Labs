#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "equatation.h"


void diff_u(vector& u, vector& du)
{
    for (size_t i = 1; i < u.size() - 2; ++i)
        du[i] = u[i + 1] + u[i - 1] - 2 * u[i];
}

void diff_T(vector& T, vector& dT)
{
    for (size_t i = 1; i < T.size() - 2; ++i)
        dT[i] = T[i + 1] + T[i - 1] - 2 * T[i];
}
void init_consts(double*& consts)
{
    srand(time(0));
    consts = new double[4];
    consts[0] = (double)(rand()) / 999;
    consts[1] = (double)(rand()) / 999;
    consts[2] = (double)(rand()) / 999;
    consts[3] = (double)(rand()) / 999;
}
/*vector diff(vector& T)
{
    vector tmp(0.0, T.size());
    for (size_t i = 1; i < T.size() - 2; i++)
    {
        tmp[i] = T[i + 1] + T[i - 1] - 2 * T[i];
    }
    return tmp;
}*/

equatation::equatation(int N, double L)
{
    init_consts(consts);
    Lx = L;
    NumPoint = N;
    h = L / N;
    dt = h * h / 4.0;
    T = vector(0.0, NumPoint);
    dT = vector(0.0, NumPoint);
    u = vector(0.0, NumPoint);
    du = vector(0.0, NumPoint);
};
void equatation::step()
{
    double _Nu = consts[0] / (h * h);
    double _Hi = consts[1] / (h * h);
    double dth = dt * h;
    double _param = consts[2] / consts[3];
    diff_v(u, du);
    u = u + dt * (du * _Nu - _param);
    diff_T(T, dT);
    T = T + dt * (_Hi * dT + u * (T.shift(-1) - T.shift(1)) / (2 * h));

}
void equatation::setInitial(vector T_in, vector u_in)
{
    T = T_in;
    u = u_in;
};
void equatation::write(std::string name)
{
    std::ofstream out;
    out.open(name);

    out << std::setw(5) << "x";
    out << std::setw(15) << "v";
    out << std::setw(15) << "T";
    out << std::endl;
    for (int i = 0; i < NumPoint; i++)
    {
        out << std::setw(5) << i * h;
        out << std::setw(15) << v[i];
        out << std::setw(15) << T[i];
        out << std::endl;
    }
    out.close();
}
Case::~Case() { delete[] consts; }
