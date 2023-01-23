#include "UserSystem.h"

void UserSystem::userRegister(string username, string password) {
	users.insert(std::pair<string, string>(username, password));
}

bool UserSystem::checkUser(string username) {

	return users.contains(username);
}

bool UserSystem::checkPassword(string username, string password)
{
	return password == users.at(username);
}