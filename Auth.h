#pragma once
#include <string>
#include <iostream>
#include <map>
using std::map;
using std::string;
class Users
{
private:
	map<string, string> users;
public:
	void userRegister(string username, string password);
	bool checkUser(string username);
	bool checkPassword(string username, string password);
};

