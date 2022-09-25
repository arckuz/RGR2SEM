#include "Header.h"


int step(int a, int x, int p) {
    int y;
    //cin >> a >> x >> p;
    y = x % (p - 1);
    int t, t0;
    t = 0;
    t0 = a % p;
    for (int k = 0; k < y; ++k) {
        t = a % p;
        a = t * t0;
    }
    //cout << t << endl;
    return t;
}
int step_with_numb(int Y, int k, int M, int p) {
    int q, q0;
    q = Y % p;
    q0 = q;
    for (int i = 1; i < k; i++) {
        q = (q * q0) % p;
    }
    q = (q * M) % p;
    return q;
}
int nod(int a, int b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}
int vzaim_prost(int p) {
    for (int k = 2; p - 1; k++) {
        if (nod(k, p - 1) == 1) {
            return k;
        }
    }
}