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
void vij_enc(string message, string key) {
    string alf1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", alf2 = "abcdefghijklmnopqrstuvwxyz", key1 = "", key2 = "", enc_message= "";
    key1 = key;

    vector<char> alphabet1;
    vector<char> alphabet2;
    for (auto i : key1) {
        if (int(i) >= 65 && int(i) <= 106) {
            key2 += char(int(i) + 32);
        }
        else if (int(i) >= 97 && int(i) <= 122) {
            key2 += char(int(i) - 32);
        }
    }
    for (auto i : alf1) {
        alphabet1.push_back(i);
    }
    for (auto i : alf2) {
        alphabet2.push_back(i);
    }
    int N = alphabet1.size(), n = alphabet2.size();


    for (int i = 0, cnt = 0; i < message.length(); i++) {
        if (findd(message[i], alphabet1)) {
            if (findd(key1[(i - cnt) % key1.length()], alphabet1)) {
                letter_encryption(i, cnt, N, message, enc_message, key1, alphabet1);
            }
            else {
                letter_encryption(i, cnt, N, message, enc_message, key2, alphabet1);
            }
        }
        else if (findd(message[i], alphabet2)) {
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
    cout << "Encoded message: " << enc_message;

}
void vij_dec(string key) {
    string message;
    ifstream in;
    cout << endl;
    in.open("encoded_message.txt");
    if (in.is_open())
    {
        getline(in, message);
    }
    else {
        cout << "File not found";
    }
    in.close();

    string alf1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", alf2 = "abcdefghijklmnopqrstuvwxyz", key1 = "", key2 = "", dec_message = "";
    key1 = key;

    vector<char> alphabet1;
    vector<char> alphabet2;
    for (auto i : key1) {
        if (int(i) >= 65 && int(i) <= 106) {
            key2 += char(int(i) + 32);
        }
        else if (int(i) >= 97 && int(i) <= 122) {
            key2 += char(int(i) - 32);
        }
    }
    for (auto i : alf1) {
        alphabet1.push_back(i);
    }
    for (auto i : alf2) {
        alphabet2.push_back(i);
    }
    int N = alphabet1.size(), n = alphabet2.size();
    for (int i = 0, cnt = 0; i < message.length(); i++) {
        if (findd(message[i], alphabet1)) {
            if (findd(key1[(i - cnt) % key1.length()], alphabet1)) {
                letter_decryption(i, cnt, N, message, dec_message, key1, alphabet1);
            }
            else {
                letter_decryption(i, cnt, N, message, dec_message, key2, alphabet1);
            }
        }
        else if (findd(message[i], alphabet2)) {
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

    cout << "Decoded message: " << dec_message;
}

void vij() {
    string alf1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", alf2 = "abcdefghijklmnopqrstuvwxyz", str = "abcdefghijklmnopqrstuvwxyz", key1 = "ooo", key2 = "", str1 = "", str2 = "";
    vector<char> alphabet1;
    vector<char> alphabet2;
    for (auto i : key1) {
        if (int(i) >= 65 && int(i) <= 106) {
            key2 += char(int(i) + 32);
        }
        else if (int(i) >= 97 && int(i) <= 122) {
            key2 += char(int(i) - 32);
        }
    }
    for (auto i : alf1) {
        alphabet1.push_back(i);
    }
    for (auto i : alf2) {
        alphabet2.push_back(i);
    }
    int N = alphabet1.size(), n = alphabet2.size();
    for (int i = 0, cnt = 0; i < str.length(); i++) {
        if (findd(str[i], alphabet1)>=0) {
            if (findd(key1[(i - cnt) % key1.length()], alphabet1) >= 0) {
                letter_encryption(i, cnt, N, str, str1, key1, alphabet1);
            }
            else {
                letter_encryption(i, cnt, N, str, str1, key2, alphabet1);
            }
        }
        else if (findd(str[i], alphabet2)>=0) {
            if (findd(key1[(i - cnt) % key1.length()], alphabet2) >= 0) {
                letter_encryption(i, cnt, N, str, str1, key1, alphabet2);
            }
            else {
                letter_encryption(i, cnt, N, str, str1, key2, alphabet2);
            }
        }
        else {
            str1 += str[i];
            cnt += 1;
        }
        cout << str1[i];
    }
    cout << endl;
    for (int i = 0, cnt = 0; i < str1.length(); i++) {
        if (findd(str1[i], alphabet1) >= 0) {
            if (findd(key1[(i - cnt) % key1.length()], alphabet1) >= 0) {
                letter_decryption(i, cnt, N, str1, str2, key1, alphabet1);
            }
            else {
                letter_decryption(i, cnt, N, str1, str2, key2, alphabet1);
            }
        }
        else if (findd(str1[i], alphabet2) >= 0) {
            if (findd(key1[(i - cnt) % key1.length()], alphabet2) >= 0) {
                letter_decryption(i, cnt, N, str1, str2, key1, alphabet2);
            }
            else {
                letter_decryption(i, cnt, N, str1, str2, key2, alphabet2);
            }
        }
        else {
            str2 += str1[i];
            cnt += 1;
        }
        cout << str2[i];
    }
}