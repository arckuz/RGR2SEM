#include "Header.h"


int findd(char str, vector<char>& alphabet) {
    for (int i = 0; i < alphabet.size(); i++) {
        if (str == alphabet[i]) {
            return i;
        }
    }
    return 0;
}
void letter_encryption(int i, int& cnt, int n, string str, string& str1, string key, vector<char> alphabet) {
    auto x = findd(str[i], alphabet);
    auto y = findd(key[(i - cnt) % key.length()], alphabet);
    str1 += alphabet[(x + y) % n];
}
void letter_decryption(int i, int& cnt, int n, string str1, string& str2, string key, vector<char> alphabet) {
    auto x = findd(str1[i], alphabet);
    auto y = findd(key[(i - cnt) % key.length()], alphabet);
    str2 += alphabet[(x - y + n) % n];
}
void vij() {
    string alf1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", alf2 = "abcdefghijklmnopqrstuvwxyz", str = "lol", key1 = "hellsdf", key2 = "", str1 = "", str2 = "";
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
        if (findd(str[i], alphabet1)) {
            if (findd(key1[(i - cnt) % key1.length()], alphabet1)) {
                letter_encryption(i, cnt, N, str, str1, key1, alphabet1);
            }
            else {
                letter_encryption(i, cnt, N, str, str1, key2, alphabet1);
            }
        }
        else if (findd(str[i], alphabet2)) {
            if (findd(key1[(i - cnt) % key1.length()], alphabet2)) {
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
        if (findd(str1[i], alphabet1)) {
            if (findd(key1[(i - cnt) % key1.length()], alphabet1)) {
                letter_decryption(i, cnt, N, str1, str2, key1, alphabet1);
            }
            else {
                letter_decryption(i, cnt, N, str1, str2, key2, alphabet1);
            }
        }
        else if (findd(str1[i], alphabet2)) {
            if (findd(key1[(i - cnt) % key1.length()], alphabet2)) {
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