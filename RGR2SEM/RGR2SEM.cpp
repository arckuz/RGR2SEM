#include "Header.h"
enum instuction {
	Эль_Гамаля = 1,
	Вижинер,
	Скитал
};

void eng(string text) {
	int k = 0;
	while (k < text.length()) {
		if ((text[k] >= 'a') && (text[k] <= 'z') || (text[k] == ' '));
		else if ((text[k] >= 'A') && (text[k] <= 'Z') || (text[k] >= '0') && (text[k] <= '9'));
		else
			throw " Неправильный ввод, пожалуйста, используйте только буквы английского алфавита или цифры!\n";

		k++;
	}
}
void menu(const string& password) {
	cout << endl;
	string s, vibor, wish, n, text;
	ofstream fout("output.txt");
	ifstream in("message.txt");
	ifstream enc_m("encoded_message.txt");

	int k;

	bool is_Wish = true;

	cout << "Как вы хотите ввести текст?" << endl;
	cout << "1 - ввести вручную" << endl << "2 - использовать текст по умолчанию" << endl << "3 - получить текст из файла" << endl;
	cin >> n;
	if (n == "1") {
		cin.ignore();
		try {
			system("cls");
			cout << "Введите текст: ";
			getline(cin, text);
			eng(text);
		}
		catch (const char* err) {
			cout << err;
			text.clear();
			menu(password);
		}
	}
	else if (n == "2") {
		system("cls");
		text = "secret message";
	}
	else if (n == "3") {
		try {
			system("cls");
			getline(in, text);
			eng(text);
			in.close();
		}
		catch (const char* err) {
			cout << err;
			text.clear();
			menu(password);
		}
	}
	else {
		system("cls");
		cout << "Введите число от 1 до 3";
		text.clear();
		menu(password);
	}

	cout << "Что вы хотите сделать:" << endl << "1) только расшифровать текст" << endl << "2) только зашифровать текст" << endl << "3) зашифровать и расшифровать текст" << endl;
	cin >> wish;
	if (wish == "1" || wish == "2" || wish == "3") is_Wish = false;
	while (is_Wish) {
		system("cls");
		cout << "Введите 1, 2 или 3" << endl;
		cout << "1) только расшифровка" << endl << "2) только шифровка" << endl << "3) шифровка и расшифровка" << endl;
		cin >> wish;
		if (wish == "1" || wish == "2" || wish == "3") is_Wish = false;
	}


	cout << endl;
	cout << "Выберите шифр: " << endl;
	cout << "Нажмите <1> если выбрали  Эль Гамаля " << endl;
	cout << "Нажмите <2> если выбрали  Вижинер" << endl;
	cout << "Нажмите <3> если выбрали  Скитал " << endl;
	cout << "Нажмите <10> если выбрали  выход " << endl;

	cin >> vibor;
	if (vibor == "1" || vibor == "2" || vibor == "3" || vibor == "10") {
		k = stoi(vibor);
	}
	else {
		system("cls");
		cout << "";
		vibor.clear();
		menu(password);
	}
	switch (k) {

	case Эль_Гамаля:
		system("cls");
		cin.get();
		switch (stoi(wish))
		{
		case 1:
			el_gamal_dec(text);
			break;

		case 2:
			el_gamal_enc(text);
			getline(enc_m, text);
			fout << text;
			fout.close();
			break;

		case 3:
			el_gamal_enc(text);
			getline(enc_m, text);
			el_gamal_dec(text);;
			break;
		}
		enc_m.close();
		fout.close();
		system("notepad output.txt ");
		break;

	case Вижинер:
		system("cls");
		cin.get();
		switch (stoi(wish))
		{
		case 1:
			vij_dec(text);
			break;

		case 2:
			vij_enc(text);
			getline(enc_m, text);
			fout << text;
			fout.close();
			break;

		case 3:
			vij_enc(text);
			getline(enc_m, text);
			vij_dec(text);
			break;
		}
		enc_m.close();
		fout.close();
		system("notepad output.txt ");
		break;


	case Скитал:
		system("cls");
		cin.get();
		switch (stoi(wish))
		{
		case 1:
			skital_decode(text);
			break;

		case 2:
			skital_encode(text);
			getline(enc_m, text);
			fout << text;
			fout.close();
			break;

		case 3:
			skital_encode(text);
			getline(enc_m, text);
			skital_decode(text);
			break;	
		}
		enc_m.close();
		fout.close();
		system("notepad output.txt ");
		break;

	case 10:
		exit(0);
	}
	remove("output.txt");
	menu(password);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string s, password = "1111";

	cout << "Пароль: ";

	cin >> s;

	if (s == password) {
		remove("Output.txt");
		menu(password);
	}

	else {

		cout << "Неверный пароль " << endl;

	}

	system("pause");

	/*string message = "secret message";
	el_gamal_enc(message);
	ifstream enc_m("encoded_message.txt");
	getline(enc_m, message);
	el_gamal_dec(message);
	system("notepad output.txt ");*/
}

