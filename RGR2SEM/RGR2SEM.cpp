#include "Header.h"



int main()
{
	
	string message;
	cout << "enter your message: ";
	getline(cin, message);
	ofstream out{ "message.txt" };
	out << message;
	out.close();
	//string str = "nastupaite pojalysta, dorogie koi dryzia";
	skital_encode();
	skital_decode();
}

