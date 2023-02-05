#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "nlohmann/json.hpp"
using std::map;
using std::string;
using std::pair;
using std::ofstream;
using std::ifstream;
using json = nlohmann::json;
class UserSystem {
private:
	map<string, string> users;
	map<string, int> accounts;
	string currentUser = "";
	json userDB;
	json accountDB;
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

