#include "Header.h"
void skital_encode(string message) {
    int inp_key;
    string key;
    while (true) {
        cout << "Введите цифровой ключ: ";
        getline(cin, key);
        try {
            stoi(key);
        }
        catch (const std::out_of_range& e) {
            cout << "Введенное число не входит в диапазон значений типа int!" << endl;
            continue;
        }
        catch (const std::invalid_argument& e) {
            cout << "Введенное значение содержит не подходящие символы!" << endl;
            continue;
        }
        if (stoi(key) > 0) {
            break;
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

    ofstream out{ "encoded_message.txt" };
    out << enc_message;
    out.close();
    cout << "Зашифрованное сообщение: " << enc_message << endl;
}

void skital_decode(string message) {

    string key;
    int inp_key;
    while (true) {
        cout << "Введите ключ: ";
        getline(cin, key);
        try {
            stoi(key);
        }
        catch(const std::out_of_range& e) {
            cout << "Введенное число не входит в диопазон значений типа int!" << endl;
            continue;
        }
        catch (const std::invalid_argument& e) {
            cout << "Введенное значение содержит не подходящие символы!" << endl;
            continue;
        }
        if (stoi(key) > 0) {
            break;
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
 
    cout <<"Decoded message: " << dec_message;
    ofstream out{ "output.txt" };
    out << dec_message;
    out.close();
}
