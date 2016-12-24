#include <curl/curl.h>
#include "../include/connector.h"
#include "../include/json.hpp"

using json = nlohmann::json;

Connector::Connector()
{
	mCurlHandle = curl_easy_init();
}

Connector::~Connector(){}


json Connector::GetJsonFromServer(const char* url, char* userpswd)
{
	CURLcode res;
	GetFromServer(&res, url, userpswd);
	json response = json::parse((char*) &res);
	return response;
}

void Connector::GetFromServer(CURLcode* p_response, const char* url, char* userpswd)
{
	if(!mCurlHandle) return;
	curl_easy_setopt(mCurlHandle, CURLOPT_URL, url);
	curl_easy_setopt(mCurlHandle, CURLOPT_HTTPAUTH, (long) CURLAUTH_BASIC);
	curl_easy_setopt(mCurlHandle, CURLOPT_USERPWD, userpswd);
	*p_response = curl_easy_perform(mCurlHandle);
}

