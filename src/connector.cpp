#include <curl/curl.h>
#include <string>
#include <iostream>
#include "../include/connector.h"
#include "../include/json.hpp"

using json = nlohmann::json;

Connector::Connector() {}

Connector::~Connector() {}


void Connector::GetJsonFromServer(json& response, const char* url, char* userpswd)
{
	std::string buffer;
	GetFromServer(buffer, url, userpswd);
	response = json::parse(buffer);
	std::cout << "Done" << std::endl;
}

void Connector::GetFromServer(std::string & buffer, const char* url, char* userpswd)
{
	CURL* curl = curl_easy_init();
	CURLcode res;
	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_HTTPAUTH, (long) CURLAUTH_BASIC);
	curl_easy_setopt(curl, CURLOPT_USERPWD, userpswd);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Connector::GetRequestCallback); 
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
	res = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
}

size_t Connector::GetRequestCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	((std::string*) userp)->append((char*) contents, size * nmemb);
	return size * nmemb;
}

