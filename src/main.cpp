#include <iostream>
#include <curl/curl.h>
#include "../include/summoner_cli.h"

#define START_SUMMONER Summoner::CLI cli(argc, argv);

const char DEFAULT_SERVER_ADDRESS[] = "162.243.86.112/json"; 

int main(int argc, const char * argv[])
{
	
	Connector c;
	char credentials[] = "summoner:summoner";
	std::string buffer;
	c.GetFromServer(buffer, DEFAULT_SERVER_ADDRESS, credentials);
	json response = buffer;
	std::cout << response << std::endl;

	// START_SUMMONER

	return 0;
}
