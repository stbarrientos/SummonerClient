#ifndef _SUMMONER_CONNECTOR_H_
#define _SUMMONER_CONNECTOR_H_

#include <iostream>
#include <curl/curl.h>
#include "../include/json.hpp"

using json = nlohmann::json;

class Connector {

public:

	Connector();
	~Connector();

	void GetJsonFromServer(json&, const char*, char*);
	void PostToServer(CURLcode*,char*, char*, char*);

private:
	
	void GetFromServer(std::string&, const char*, char*);
  static size_t GetRequestCallback(void *contents, size_t size, size_t nmemb, void *userp);

};

#endif
