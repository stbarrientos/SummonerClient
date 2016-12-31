#ifndef _SUMMONER_SUMMONER_H_
#define _SUMMONER_SUMMONER_H_

#define SCLI_MENU_OPTION Summoner::MenuOption<bool (Summoner::CLI::*)(), Summoner::CLI*>

#include <string>
#include "summoner_settings.h"
#include "summoner_user.h"
#include "summoner_workstation.h"
#include "connector.h"
#include "summoner_menu_option.h"

namespace Summoner {

class CLI {

public:

	// Constructors
	CLI();
	CLI(int, const char**);
	~CLI();

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

	// CLI Functions
	void InterpretArgs(int, const char**);
	void BeginLogin();
	bool Logout();
	bool DisplayMainMenu();
	bool DisplayAccountMenu();
	bool DisplaySettingsMenu();


private:

	// Member Vars
	char* SummonWorkstationDirectory;
	User* CurrentUser;

	// Menu
	static const int MainMenuOptionsLength = 3;
	static const int AccountMenuOptionsLength = 2;
	static const int SettingsMenuOptionsLength = 2;
	SCLI_MENU_OPTION* MainMenuOptions[MainMenuOptionsLength];
	SCLI_MENU_OPTION* AccountMenuOptions[AccountMenuOptionsLength];
	SCLI_MENU_OPTION* SettingsMenuOptions[SettingsMenuOptionsLength];
	void InitMainMenuOptions();
	void InitAccountMenuOptions();
	void InitSettingsMenuOptions();
	void DisplayMenu(SCLI_MENU_OPTION**, int);
	void DeleteMenu(SCLI_MENU_OPTION**, int);

};
}

#endif
