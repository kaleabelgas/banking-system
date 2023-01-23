#include "Auth.h"

void Users::userRegister(string username, string password) {
	users.insert(std::pair<string, string>(username, password));
}

bool Users::checkUser(string username) {

	return users.contains(username);
}

bool Users::checkPassword(string username, string password)
{
	return password == users.at(username);
}