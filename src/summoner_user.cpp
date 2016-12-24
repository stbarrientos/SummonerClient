#include "../include/summoner_user.h"

Summoner::User::User(): User((char*) "default", (char*) "default") {}

Summoner::User::User(char* username, char* password): Username(username) {}

Summoner::User::~User() {}

void Summoner::User::SetPassword(std::string p) {}
