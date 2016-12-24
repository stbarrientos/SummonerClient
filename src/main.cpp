#include <iostream>
#include <curl/curl.h>
#include "../include/summoner.h"

const char DEFAULT_SERVER_ADDRESS[] = "162.243.86.112/json"; 

int main()
{
	/*
	Summoner::User user;
	Summoner::Settings::SaveSettings(user);
	Summoner::Settings::LoadSettings(user);
	std::cout << "User: " << user.GetUsername() << std::endl;
	std::cout << "Password: " << user.GetPassword() << std::endl;
	*/
	
	Connector c;
	char credentials[] = "summoner:summoner";
	nlohmann::json j = c.GetJsonFromServer(DEFAULT_SERVER_ADDRESS, credentials);
	std::cout << j.dump() << std::endl;
	return 0;
}
