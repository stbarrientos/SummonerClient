#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstring>
#include <string>
#include "../include/summoner_settings.h"
#include "../include/summoner_user.h"

void Summoner::Settings::SaveSettings(Summoner::User& user)
{
	using namespace std;
	ofstream file;
	SettingsFileHeader header;
	char garbage[18] = "abcdefghijklmno";
	header.UsernameLength = user.GetUsername().size();
	header.PasswordLength = user.GetPassword().size();
	strncpy(header.Garbage, garbage, sizeof(header.Garbage));
	file.open(Summoner::Settings::FilePath, ios::binary);
	if (!file) return;
	file.write((char*) &header, sizeof(header));
	file.write(user.GetUsername().c_str(), header.UsernameLength);
	file.write(user.GetPassword().c_str(), header.PasswordLength);
	file.close();
}

void Summoner::Settings::LoadSettings(Summoner::User& user)
{
	using namespace std;
	ifstream file;
	long size;
	char* buffer;
	SettingsFileHeader header;

	file.open(Summoner::Settings::FilePath, ios::binary);
	if (!file) return;
	file.seekg(0, ios::end);
	size = file.tellg();
	file.seekg(0, ios::beg);

	buffer = new char[size];

	file.read((char*) &header, sizeof(header));
	file.seekg(header.DataOffset);
	file.read(buffer, size - sizeof(header)); 
	file.close();

	string username;
	string password;
	ReadStringFromBuffer(username, buffer, header.UsernameLength);
	ReadStringFromBuffer(password, buffer, header.PasswordLength, header.UsernameLength);
	user.SetUsername(username);
	user.SetPassword(password);
}

void Summoner::Settings::ReadStringFromBuffer(std::string& out_string, char* buffer, int string_target_length, int offset)
{
	for (int i = 0; i < string_target_length; i++)
	{
		out_string += buffer[i + offset];
	}
}

