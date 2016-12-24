#ifndef _SUMMONER_SUMMONER_H_
#define _SUMMONER_SUMMONER_H_

#include "summoner_settings.h"
#include "summoner_user.h"
#include "summoner_workstation.h"
#include "connector.h"

namespace Summoner {

class Summoner {

public:

	// Constructors
	Summoner();
	~Summoner();

	// Getters and Setters
	char* GetSummonWorkstationDirectory() const { return this->SummonWorkstationDirectory; }

	// Summon Functions
	void SubmitSummonHelpRequest();
	void ListenForSummonHelpRequest();
	void AcceptSummonHelpRequest();
	void ViewAvailableSummonRequests();
	void UploadWorkstation();

	// User Functions
	User GetCurrentUser();
	bool AuthenticateUser();
	void SaveCurrentUserSettings();
	void LoadCurrentUserSettings();

	// Workstation Functions
	void CreateWorkstation();
	void UpdateWorkstationSettings();

private:

	// Authentication
	bool AttemptAuthentication();

	// Member Vars
	char* SummonWorkstationDirectory;
	User CurrentUser;

};
}

#endif
