#include "Header.h"
void skital_encode(string message) {
    int inp_key;
    string key;
    cout << "���� ���������: ";
    cout << message << endl;
    while (true) {
        cout << "������� ����: ";
        getline(cin, key);
        if (is_it_number(key) && stoi(key)>0) {
            break;
        }
        else {
            cout << "��������� ��������� �� �������� ��� �������";
        }
    }
    inp_key = stoi(key);


    vector <vector <char>> vec;
    string enc_message;

    int n = inp_key;

    vec.resize(n);

    int letters_in_a_row = message.length() / n;
    if (message.length() % n != 0) letters_in_a_row++;

    for (int i = 0; i < n; i++) {
        vec[i].resize(letters_in_a_row);
    }

    int k = 0;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            if (k < message.length()) {
                vec[i][j] = message[k];
            }
            else vec[i][j] = ' ';
            k++;
        }
    }

    k = 0;
    for (int i = 0; i < letters_in_a_row; i++) {
        while (k != n) {
            enc_message += vec[k][i];
            k++;
        }
        k = 0;
    }

    for (auto x : vec) {
        for (auto y : x) {
        }
    }

    ofstream out{ "encoded_message.txt" };
    out << enc_message;
    out.close();
    cout << "������������� ���������: " << enc_message << endl;
}

void skital_decode(string message) {

    string key;
    int inp_key;
    while (true) {
        cout << "������� ����: ";
        getline(cin, key);
        if (is_it_number(key) && stoi(key) > 0) {
            break;
        }
        else {
            cout << "��������� ��������� �� �������� ��� �������";
        }
    }
    inp_key = stoi(key);



    vector <vector <char>> vec;
    string dec_message;

    size_t n = inp_key;

    vec.resize(n);

    int letters_in_a_row = message.length() / n;

    for (int i = 0; i < n; i++) {
        vec[i].resize(letters_in_a_row);
    }

    int k = 0, k0 = 0;
    for (int i = 0; i < letters_in_a_row; i++) {
        while (k != n) {
            vec[k][i] = message[k0];
            k++;
            k0++;
        }
        k = 0;
    }

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < letters_in_a_row; j++) {
            dec_message += vec[i][j];
        }
    }

    for (auto x : vec) {
        for (auto y : x) {
        }
    }

    
    cout <<"Decoded message: " << dec_message;
    ofstream out{ "output.txt" };
    out << dec_message;
    out.close();
}
