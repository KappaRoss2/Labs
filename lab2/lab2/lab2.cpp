#include "case.h"
#include <time.h>
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    Case A(10000, 2);
    Vec T_init(0.0, 10000);
    T_init[50] = 0.1;
    A.setInitial(T_init);
    // весь расчет тут 
    clock_t start = clock();

    for (int i = 0; i < 1000000; i++) 
    {
        A.step();
    }

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    printf("The time: %f seconds\n", seconds);

    A.write("D:\\ООП\\lab2.txt");
    return 0;
}