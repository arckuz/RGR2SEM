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
    random_device rd;
    ranlux24_base gen(rd());
    uniform_int_distribution<> dist(2, p-1);
    while(true){
        int k = dist(gen);
        if (nod(k, p - 1) == 1) {
            return k;
        }
    }
}
void encryption(int p, int g, int Y, string message, vector<pair<int, int>>& encoded_message) {
    for (auto i : message) {
        int M = int(i);
        int k = vzaim_prost(p);//случайное взаимно простое
        int A = step(g, k, p);
        int B = step_with_numb(Y, k, M, p);
        cout << A << " " << B << " ";
        encoded_message.push_back(make_pair(A, B));
    }
    cout << endl;
}
void decryption(int p, int x, vector<pair<int, int>> encoded_message) {
    for (auto i : encoded_message) {
        int A = i.first;
        int B = i.second;
        int M1 = step_with_numb(A, p - 1 - x, B, p);
        cout << char(M1);
    }
}
void El_Gamal() {
    int p = 3571, g = 1785, x = 698, Y;
    string message = "Secret message", decoded_message;
    vector<pair<int, int>> encoded_message;

    Y = step(g, x, p); //открытый ключ

    encryption(p, g, Y, message, encoded_message);
    decryption(p, x, encoded_message);
}
//хуй