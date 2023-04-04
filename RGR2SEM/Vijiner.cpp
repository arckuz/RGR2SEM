#include "Header.h"


int findd(char str, vector<char>& alphabet) {
    for (int i = 0; i < alphabet.size(); i++) {
        if (str == alphabet[i]) {
            return i;
        }
    }
    return -1;
}
void letter_encryption(int i, int& cnt, int n, string str, string& str1, string key, vector<char> alphabet) {
    int x = findd(str[i], alphabet);
    int y = findd(key[(i - cnt) % key.length()], alphabet);
    str1 += alphabet[(x + y) % n];
}
void letter_decryption(int i, int& cnt, int n, string str1, string& str2, string key, vector<char> alphabet) {
    auto x = findd(str1[i], alphabet);
    auto y = findd(key[(i - cnt) % key.length()], alphabet);
    str2 += alphabet[(x - y + n) % n];
}

void vij_enc(string message) {
    string key;
    string alf1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", alf2 = "abcdefghijklmnopqrstuvwxyz", key1 = "", key2 = "", enc_message = "";
    vector<char> alphabet1;
    vector<char> alphabet2;

    for (auto i : alf1) {
        alphabet1.push_back(i);
    }
    for (auto i : alf2) {
        alphabet2.push_back(i);
    }
    size_t N = alphabet1.size(), n = alphabet2.size();

    bool flag = true;

    while (flag) {
        cout << "Введите ключ: ";
        getline(cin, key);
        for (auto i : key) {
            flag = false;
            if (findd(i, alphabet1) < 0 && findd(i, alphabet2) < 0) {
                flag = true;
                cout << "Введенный ключ не подходит под условие!\n";
                break;
            }
        }
    };
    key1 = key;

    for (auto i : key1) {
        if (int(i) >= 65 && int(i) <= 106) {
            key2 += char(int(i) + 32);
        }
        else if (int(i) >= 97 && int(i) <= 122) {
            key2 += char(int(i) - 32);
        }
    }


    for (int i = 0, cnt = 0; i < message.length(); i++) {
        if (findd(message[i], alphabet1) >= 0) {
            if (findd(key1[(i - cnt) % key1.length()], alphabet1)) {
                letter_encryption(i, cnt, N, message, enc_message, key1, alphabet1);
            }
            else {
                letter_encryption(i, cnt, N, message, enc_message, key2, alphabet1);
            }
        }
        else if (findd(message[i], alphabet2) >= 0) {
            if (findd(key1[(i - cnt) % key1.length()], alphabet2)) {
                letter_encryption(i, cnt, N, message, enc_message, key1, alphabet2);
            }
            else {
                letter_encryption(i, cnt, N, message, enc_message, key2, alphabet2);
            }
        }
        else {
            enc_message += message[i];
            cnt += 1;
        }
    }

    ofstream out{ "encoded_message.txt" };
    out << enc_message;
    out.close();
    cout << "Зашифрованное сообщение: " << enc_message << endl;

}
void vij_dec(string message) {
    string key;
    string alf1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", alf2 = "abcdefghijklmnopqrstuvwxyz", key1 = "", key2 = "", dec_message = "";
    vector<char> alphabet1;
    vector<char> alphabet2;

    for (auto i : alf1) {
        alphabet1.push_back(i);
    }
    for (auto i : alf2) {
        alphabet2.push_back(i);
    }
    int N = alphabet1.size(), n = alphabet2.size();

    bool flag = true;

    while (flag) {
        cout << "Введите ключ: ";
        getline(cin, key);
        for (auto i : key) {
            flag = false;
            if (findd(i, alphabet1) < 0 && findd(i, alphabet2) < 0) {
                flag = true;
                cout << "Введенный ключ не подходит под условие!\n";
                break;
            }
        }
    }

    key1 = key;

    for (auto i : key1) {
        if (int(i) >= 65 && int(i) <= 106) {
            key2 += char(int(i) + 32);
        }
        else if (int(i) >= 97 && int(i) <= 122) {
            key2 += char(int(i) - 32);
        }
    }
    for (int i = 0, cnt = 0; i < message.length(); i++) {
        if (findd(message[i], alphabet1) >= 0) {
            if (findd(key1[(i - cnt) % key1.length()], alphabet1)) {
                letter_decryption(i, cnt, N, message, dec_message, key1, alphabet1);
            }
            else {
                letter_decryption(i, cnt, N, message, dec_message, key2, alphabet1);
            }
        }
        else if (findd(message[i], alphabet2) >= 0) {
            if (findd(key1[(i - cnt) % key1.length()], alphabet2)) {
                letter_decryption(i, cnt, N, message, dec_message, key1, alphabet2);
            }
            else {
                letter_decryption(i, cnt, N, message, dec_message, key2, alphabet2);
            }
        }
        else {
            dec_message += message[i];
            cnt += 1;
        }
    }

    cout << "Расшифрованное сообщение: " << dec_message;
    ofstream out{ "output.txt" };
    out << dec_message;
    out.close();
}
