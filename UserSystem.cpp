#include "UserSystem.h"

void UserSystem::serialize(){
	userDB = users;
	accountDB = accounts;
	ofstream userout("userDB.json");
	userout << std::setw(4) << userDB << std::endl;
	ofstream accout("accountDB.json");
	accout << std::setw(4) << accountDB << std::endl;
}

void UserSystem::deserialize(){
	ifstream userin("userDB.json");
	userin >> userDB;
	users = userDB.get<map<string, string>>();
	ifstream accin("accountDB.json");
	accin >> accountDB;
	accounts = accountDB.get<map<string, int>>();
}

void UserSystem::userRegister(string username, string password) {
	users.insert(pair<string, string>(username, password));
	accounts.insert({username, 0});
	serialize();
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
	serialize();
}

void UserSystem::deposit(int amount) {
	accounts.at(currentUser) = accounts.at(currentUser) + amount;
	serialize();
}
