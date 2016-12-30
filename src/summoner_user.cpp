#include "../include/summoner_user.h"

Summoner::User::User() {}

Summoner::User::User(std::string u): Username(u) {} 

Summoner::User::User(std::string username, std::string& password): Username(username)
{
  Authenticate(password);
}

Summoner::User::~User() {}

bool Summoner::User::Authenticate(std::string& password)
{
  if (this->Username == "default" && password == "default"){
    this->Authenticated = true;
    return true;
  } else {
    this->Authenticated = false;
    return false;
  }
}