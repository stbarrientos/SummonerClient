#ifndef _SUMMONER_USER_H_
#define _SUMMONER_USER_H_

#include <string>

namespace Summoner {

class User {

public:

	User();
	User(std::string);
	User(std::string, std::string&);
	~User();

	std::string GetUsername() const { return Username; }
	bool IsAuthenticated() { return Authenticated; }
	void SetAuthentication(bool a) { Authenticated = a; }
	void SetUsername(std::string u) { Username = u; }

	bool Authenticate(std::string&);

private:

	bool Authenticated;
	std::string Username;


};

}

#endif
