#include "Header.h"


int main()
{
    int p = 43, g = 24, x = 30, M = 36, M1, Y, k, A, B;


    Y = step(g, x, p);
    k = vzaim_prost(p);
    A = step(g, k, p);
    B = step_with_numb(Y, k, M, p);



    M1 = step_with_numb(A, p - 1 - x, B, p);
}

