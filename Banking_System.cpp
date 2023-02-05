#include <iostream>
#include "UserSystem.h"
#define NOMINMAX
#include <Windows.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::streamsize;
using std::numeric_limits;


UserSystem userSystem;
void errorMessage(string error) {
	cout << "Error: " << error << endl;
}
void registerStep() {
	system("cls");
	string username, password;
	while (true) {
		cout << "Please input your username." << endl;
		cin.ignore();
		getline(cin, username);
		if (!userSystem.checkUser(username)) break;
		errorMessage("User already exists!");
	}
	cout << "Please input your password." << endl;
	cin.ignore();
	getline(cin, password);
	userSystem.userRegister(username, password);
	userSystem.setCurrentUser(username);
	cout << "Registration successful!" << endl;
	Sleep(500);
}

void login() {
	cout << "Welcome! Login with your username and password, or register a new account." << endl 
		<< "1. Login" << endl 
		<< "2. Register" << endl;
	while (true) {
		int userInput = -1;
		string username, password;
		cin >> userInput;
		if (userInput == 1) {
			system("cls");
			cout << "Please input your username." << endl;
			cin >> username;
			if (!userSystem.checkUser(username)) {
				cout << "User does not exist. Proceeding to register step..." << endl;
				Sleep(1000);
				registerStep();
			}
			else {
				while (true) {
					cout << "Please input your password." << endl;
					cin >> password;
					if (userSystem.checkPassword(username, password)) {
						userSystem.setCurrentUser(username);
						cout << "Login successful!" << endl;
						Sleep(500);
						break;
					}
					else {
						errorMessage("Wrong password...");
						continue;
					}

				}
			}
			break;
		}
		else if (userInput == 2) {
			registerStep();
			break;
		}
		else {
			errorMessage("Invalid input!");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
	}
}

void deposit() {
	cout << "Enter an amount" << endl;
	int amount = 0;
	cin >> amount;
	while (cin.fail() || amount < 1) {
		if (cin.fail()) errorMessage("Invalid input!");
		else errorMessage("Amount must be bigger than 0!");
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> amount;
	}
	userSystem.deposit(amount);
	cout << "Deposit successful!" << endl;
}

void withdraw() {
	cout << "Enter an amount" << endl;
	int amount = 0;
	cin >> amount;
	while (cin.fail() || userSystem.checkBalance() < amount) {
		if (cin.fail()) errorMessage("Invalid input!");
		else {
			system("cls");
			errorMessage("Amount must be less than available balance!");
			cout << "Current Balance : " << userSystem.checkBalance() << endl;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> amount;
	}
	userSystem.withdraw(amount);
	cout << "Withdraw successful!" << endl;
}

void transactStep() {
	while (true) {
		system("cls");
		int userInput;
		cout << "Choose a transaction:" << endl
			<< "1. Check balance" << endl
			<< "2. Deposit" << endl
			<< "3. Withdraw" << endl
			<< "4. Exit" << endl;
		cin >> userInput;
		switch (userInput) {
		case 1:
			system("cls");
			cout << "Your current balance is:" << endl
				<< userSystem.checkBalance() << endl;
			system("pause");
			continue;
		case 2:
			system("cls");
			deposit();
			system("pause");
			continue;
		case 3:
			system("cls");
			withdraw();
			system("pause");
			continue;
		case 4:
			system("cls");
			cout << "Thank you!" << endl;
			break;
		default:
			system("cls");
			errorMessage("Invalid input!");
			system("pause");
			continue;
		}
		break;

	}
}


int main() {
	login();
	transactStep();
}