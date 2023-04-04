#include "Header.h"

bool check_vzaim_prost(int p, int g) {
    if (nod(p, g) == 1) {
        return true;
    }
    else return false;
}
bool chec_pros(int p) {
    int i;
    for (i = 2; i < p / 2; i++) {
        if (p % i == 0) {
            return false;
        }
    }
    if (i == p / 2) {
        return true;
    }
}
int nod(int a, int b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}
int step(int a, int x, int p) {
    int y;
    y = x % (p - 1);
    int t, t0;
    t = 0;
    t0 = a % p;
    for (int k = 0; k < y; ++k) {
        t = a % p;
        a = t * t0;
    }
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
    cout << "«ашифрованное сообщение: ";
    ofstream out{ "encoded_message.txt" };
    for (auto i : message) {
        int M = int(i);
        int k = vzaim_prost(p);
        int A = step(g, k, p);
        int B = step_with_numb(Y, k, M, p);
        cout << A << " " << B << "|";
        encoded_message.push_back(make_pair(A, B));
        out << A << " " << B << " ";
    }
    out.close();
    cout << endl;
}
void decryption(int p, int x, vector<pair<int, int>> encoded_message, string& decoded_message) {
    for (auto i : encoded_message) {
        int A = i.first;
        int B = i.second;
        int M1 = step_with_numb(A, p - 1 - x, B, p);
        decoded_message+=char(M1);
    }
    cout << "–асшифрованное сообщение: " << decoded_message;
    ofstream out{ "output.txt" };
    out << decoded_message;
    out.close();
}

void el_gamal_enc(string message) {
    int Y;
    string p, g, x;
    while (true) {
        cout << "¬ведите простое число p => 1000: ";
        getline(cin, p);
        try {
            stoi(p);
        }
        catch (const std::out_of_range& e) {
            cout << "¬веденное число не входит в диопазон значений типа int!" << endl;
            continue;
        }
        catch (const std::invalid_argument& e) {
            cout << "¬веденное значение содержит не подход€щие символы!" << endl;
            continue;
        }
        if (chec_pros(stoi(p)) && stoi(p) >=1000) {
            break;
        }
        else {
            cout << "¬веденное число не простое или оно меньше 1000\n";
        }
    }
    while (true) {
        cout << "¬ведите число 0 < g < p, взаимно простое с p: ";
        getline(cin, g);
        try {
            stoi(g);
        }
        catch (const std::out_of_range& e) {
            cout << "¬веденное число не входит в диопазон значений типа int!" << endl;
            continue;
        }
        catch (const std::invalid_argument& e) {
            cout << "¬веденное значение содержит не подход€щие символы!" << endl;
            continue;
        }
        if (check_vzaim_prost(stoi(p), stoi(g)) && stoi(g) > 0 && stoi(g) < stoi(p)) {
            break;
        }
        else {
            cout << "¬веденное число не подходит под условие\n";
        }
    }
    while (true) {
        cout << "¬ведите число 2 < X < p - 1: ";
        getline(cin, x);
        try {
            stoi(x);
        }
        catch (const std::out_of_range& e) {
            cout << "¬веденное число не входит в диопазон значений типа int!" << endl;
            continue;
        }
        catch (const std::invalid_argument& e) {
            cout << "¬веденное значение содержит не подход€щие символы!" << endl;
            continue;
        }
        if (stoi(x) > 2 && stoi(x) < (stoi(p) - 1)) {
            break;
        }
        else {
            cout << "¬веденное число не не подходит под условие\n";
        }
    }
    
    
   /* int p = 3571, g = 1785, x = 698, Y;*/
    vector<pair<int, int>> encoded_message;

    Y = step(stoi(g), stoi(x), stoi(p));

    encryption(stoi(p), stoi(g), Y, message, encoded_message);
}

void el_gamal_dec(string message) {
    //int p = 3571, g = 1785, x = 698, Y;
    int Y;
    string p, g, x;
    while (true) {
        cout << "¬ведите число p: ";
        getline(cin, p);
        try {
            stoi(p);
        }
        catch (const std::out_of_range& e) {
            cout << "¬веденное число не входит в диопазон значений типа int!" << endl;
            continue;
        }
        catch (const std::invalid_argument& e) {
            cout << "¬веденное значение содержит не подход€щие символы!" << endl;
            continue;
        }
        if (stoi(p) > 0) {
            break;
        }
        else cout << "¬веденное значение не подходит под ксловие";
    }
    while (true) {
        cout << "¬ведите число g: ";
        getline(cin, g);
        try {
            stoi(g);
        }
        catch (const std::out_of_range& e) {
            cout << "¬веденное число не входит в диопазон значений типа int!" << endl;
            continue;
        }
        catch (const std::invalid_argument& e) {
            cout << "¬веденное значение содержит не подход€щие символы!" << endl;
            continue;
        }
        if (stoi(g) > 0) {
            break;
        }
        else cout << "¬веденное значение не подходит под ксловие";
    }
    while (true) {
        cout << "¬ведите число x: ";
        getline(cin, x);
        try {
            stoi(x);
        }
        catch (const std::out_of_range& e) {
            cout << "¬веденное число не входит в диопазон значений типа int!" << endl;
            continue;
        }
        catch (const std::invalid_argument& e) {
            cout << "¬веденное значение содержит не подход€щие символы!" << endl;
            continue;
        }
        if (stoi(x) > 0) {
            break;
        }
        else cout << "¬веденное значение не подходит под ксловие";
    }
    
    string decoded_message = "";
    vector<pair<int, int>> encoded_message;
    string str_a = "", str_b = "";

    bool first_space = false;
    for (auto i : message) {
        if ((i >= 'A') && (i <= 'Z') || (i >= 'a') && (i <= 'z')) {
            cout << "ќшибка в зашифрованном сообщении!";
            exit(0);
        }
        if (i != ' ' && !first_space) {
            str_a += i;
        }
        else if (i != ' ' && first_space) {
            str_b += i;
        }
        else if ((i == ' '|| i == '\0') && first_space) {
            encoded_message.push_back(make_pair(stoi(str_a), stoi(str_b)));
            str_a = str_b = "";
            first_space = false;
        }
        else if (i == ' ' && !first_space) {
            first_space = true;
        }
    } 

    Y = step(stoi(g), stoi(x), stoi(p));

    decryption(stoi(p), stoi(x), encoded_message, decoded_message);
}
