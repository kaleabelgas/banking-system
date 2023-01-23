#include <iostream>
#include "Auth.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	Users auth;

	string userInput = "";
	while (true) {
		cout << "Welcome! Login with your username and password, or register a new account." << endl << "login" << endl << "register" << endl;
		cin >> userInput;
	}
}