#ifndef _SUMMONER_USER_H_
#define _SUMMONER_USER_H_

#include <string>

namespace Summoner {

class User {

public:

	User();
	User(char*, char*);
	~User();

	std::string GetUsername() const { return Username; }
	std::string GetPassword() const { return EncryptedPassword; }

	void SetUsername(std::string u) { Username = u; }
	void SetPassword(std::string p);

private:

	void SetPasswordFromUnencryptedString();

	std::string Username;
	std::string EncryptedPassword;


};

}

#endif
