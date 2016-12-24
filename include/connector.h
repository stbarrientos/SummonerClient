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

	json GetJsonFromServer(const char*, char*);
	void PostToServer(CURLcode*,char*, char*, char*);

private:
	
	void GetFromServer(CURLcode*, const char*, char*);
	CURL* mCurlHandle;

};

#endif
