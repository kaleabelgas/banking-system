#include <iostream>
#include "Auth.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

UserSystem auth;
void errorMessage(string error) {
	cout << "Error: " << error << endl;
}

void registerStep() {
	string username, password;
	while (true) {
		cout << "Please input your username." << endl;
		cin >> username;
		if (!auth.checkUser(username)) break;
		errorMessage("User already exists!");
	}
	cout << "Please input your password." << endl;
	cin >> password;
	cout << "Registration successful!" << endl;
}


int main(){

	cout << "Welcome! Login with your username and password, or register a new account." << endl << "login" << endl << "register" << endl;
	
	while (true) {
		string userInput, username, password;
		cin >> userInput;
		if (userInput == "login") {
			cout << "Please input your username." << endl;
			cin >> username;
			if (!auth.checkUser(username)) {
				cout << "User does not exist. Proceeding to register step..." << endl;
				registerStep();
			}
			else {
				while (true) {
					cout << "Please input your password." << endl;
					cin >> password;
					if (auth.checkPassword(username, password)) {
						cout << "Login successful!" << endl;
						break;
					}
					else {
						cout << "Wrong password..." << endl;
						continue;
					}

				}
			}
			break;
		}
		else if (userInput == "register") {
			registerStep();
			break;
		}
		else {
			errorMessage("Invalid input!");
			continue;
		}
	}

		
}