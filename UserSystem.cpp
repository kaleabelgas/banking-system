#include "UserSystem.h"

void UserSystem::userRegister(string username, string password) {
	users.insert(pair<string, string>(username, password));
	accounts.insert({username, 0});
}

bool UserSystem::checkUser(string username) {

	return users.contains(username);
}

bool UserSystem::checkPassword(string username, string password) {
	return password == users.at(username);
}

void UserSystem::setCurrentUser(string username) {
	currentUser = username;
}

int UserSystem::checkBalance() {
	return accounts.at(currentUser);
}

void UserSystem::withdraw(int amount) {
	accounts.at(currentUser) = accounts.at(currentUser) - amount;
}


void UserSystem::deposit(int amount) {
	accounts.at(currentUser) = accounts.at(currentUser) + amount;

}
