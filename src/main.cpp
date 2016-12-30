#include <iostream>
#include <curl/curl.h>
#include "../include/summoner_cli.h"

#define START_SUMMONER Summoner::CLI cli(argc, argv)

const char DEFAULT_SERVER_ADDRESS[] = "162.243.86.112/json"; 

int main(int argc, const char * argv[])
{
	
	/*
	Connector c;
	char credentials[] = "summoner:summoner";
	nlohmann::json response;
	c.GetJsonFromServer(response, DEFAULT_SERVER_ADDRESS, credentials);
	std::cout << response.dump() << std::endl;
	return 0;
	*/

	START_SUMMONER;

	return 0;
}
