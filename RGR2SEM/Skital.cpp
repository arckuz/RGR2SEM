#include "Header.h"
string encode(string str0, int key) {
    vector <vector <char>> vec;
    string str = str0, str1;

    int n = key;

    vec.resize(n);

    int letters_in_a_row = str.length() / n;
    if (str.length() % n != 0) letters_in_a_row++;

    for (int i = 0; i < n; i++) {
        vec[i].resize(letters_in_a_row);
    }

    int k = 0;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            if (k < str.length()) {
                vec[i][j] = str[k];
            }
            else vec[i][j] = ' ';
            k++;
        }
    }

    k = 0;
    for (int i = 0; i < letters_in_a_row; i++) {
        while (k != n) {
            str1 += vec[k][i];
            k++;
        }
        k = 0;
    }

    for (auto x : vec) {
        for (auto y : x) {
            cout << y;
        }
        cout << endl;
    }

    cout << endl;

    return str1;
}

string decode(string str0, int key) {
    vector <vector <char>> vec;
    string str = str0, str1;

    int n = key;

    vec.resize(n);

    int letters_in_a_row = str.length() / n;

    for (int i = 0; i < n; i++) {
        vec[i].resize(letters_in_a_row);
    }

    int k = 0, k0 = 0;
    for (int i = 0; i < letters_in_a_row; i++) {
        while (k != n) {
            vec[k][i] = str[k0];
            k++;
            k0++;
        }
        k = 0;
    }

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < letters_in_a_row; j++) {
            str1 += vec[i][j];
        }
    }

    for (auto x : vec) {
        for (auto y : x) {
            cout << y;
        }
        cout << endl;
    }

    cout << endl;

    return str1;
}
void skital() {
    string str, encoded_str, decoded_str;
    str = "NASTUPAITE pojalysta, dorogie koi dryzia", encoded_str = encode(str, 3), decoded_str = decode(encoded_str, 3);
    cout << encoded_str << endl;
    cout << decoded_str;
}