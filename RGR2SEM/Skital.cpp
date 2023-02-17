#include "Header.h"
void skital_encode() {
    string str0;
    int inp_key;
    ifstream in;

    cout << endl;
    in.open("message.txt");
    if (in.is_open())
    {
        getline(in, str0);
    }
    else {
        cout << "File not found";
    }
    in.close();

    cout << "Your message: ";
    cout << str0 << endl;
    cout << "Input key: ";
    cin >> inp_key;



    vector <vector <char>> vec;
    string str = str0, str1;

    int n = inp_key;

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
        }
    }

   // cout << endl;
    ofstream out{ "encoded_message.txt" };
    out << str1;
    out.close();
    cout << "Encoded message: " << str1;
}

void skital_decode() {

    string str0;
    ifstream in;   
    cout << endl;
    in.open("encoded_message.txt");
    if (in.is_open())
    {
        getline(in, str0);
    }
    else {
        cout << "File not found";
    }
    in.close();

    int inp_key;

    cout << "Your message: ";
    cout << str0 << endl;
    cout << "Input key: ";
    cin >> inp_key;



    vector <vector <char>> vec;
    string str = str0, str1;

    size_t n = inp_key;

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
            //cout << y;
        }
        //cout << endl;
    }

   // cout << endl;
    
    cout <<"Decoded message: " << str1;
    ofstream out{ "decoded_message.txt" };
    out << str1;
    out.close();
}
