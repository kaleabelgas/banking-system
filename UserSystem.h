#pragma once
#include <string>
#include <iostream>
#include <map>
using std::map;
using std::string;
using std::pair;
class UserSystem {
private:
	map<string, string> users{ {"kale", "pass"} };
	map<string, float> accounts{ {"kale", 100} };
	string currentUser = "";
public:
	void serialize();
	void deserialize();
	void userRegister(string username, string password);
	bool checkUser(string username);
	bool checkPassword(string username, string password);
	void setCurrentUser(string username);
	void withdraw(int amount);
	int checkBalance();
	void deposit(int amount);
};

