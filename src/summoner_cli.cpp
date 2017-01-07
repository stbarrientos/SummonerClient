#include <iostream>
#include "../include/summoner_cli.h"

Summoner::CLI::CLI() 
{
  BeginLogin();
}

Summoner::CLI::CLI(int argc, const char* argv[])
{
  this->InterpretArgs(argc, argv);
}

Summoner::CLI::~CLI()
{
  if (CurrentUser)
    delete CurrentUser;
  DeleteMenu(MainMenuOptions, MainMenuOptionsLength);
  DeleteMenu(AccountMenuOptions, AccountMenuOptionsLength);
  DeleteMenu(SettingsMenuOptions, SettingsMenuOptionsLength);
}

void Summoner::CLI::InterpretArgs(int argc, const char* argv[])
{
  if (argc > 1){

  } else {
    BeginLogin();
  }
}

void Summoner::CLI::BeginLogin()
{
  using namespace std;
  User* user = new User();
  if (Settings::LoadSettings(user)){
    DisplayUserLoginMenu(user, LoginMode::PasswordOnly);
  } else {
    DisplayUserLoginMenu(user, LoginMode::FullLogin);
  }
  CurrentUser = user;
  cout << "Welcome " << CurrentUser->GetUsername() << endl << endl;
  DisplayMainMenu();
}

void Summoner::CLI::DisplayUserLoginMenu(User* user, LoginMode mode)
{
  using namespace std;
  string username;
  string password;
  do {
    if (mode == LoginMode::FullLogin){
      cout << "Username: " << flush;
      cin >> username;
      user->SetUsername(username);
    }
    cout << "Password: " << flush;
    cin >> password;
    user->Authenticate(password);
    if (!user->IsAuthenticated()) cout << "Invalid Username Or Password" << endl;
  } while (!user->IsAuthenticated());
}

// Menu Init Functions
void Summoner::CLI::InitMainMenuOptions()
{
  MainMenuOptions[0] = new SCLI_MENU_OPTION(1, "Account", &Summoner::CLI::DisplayAccountMenu, this);
  MainMenuOptions[1] = new SCLI_MENU_OPTION(2, "Settings", &Summoner::CLI::DisplaySettingsMenu, this);
  MainMenuOptions[2] = new SCLI_MENU_OPTION(3, "Summon Help");
  MainMenuOptions[3] = new SCLI_MENU_OPTION(4, "List Summon Requests");
  MainMenuOptions[4] = new SCLI_MENU_OPTION(5, "Quit", &Summoner::CLI::UserQuit, this);
}

void Summoner::CLI::InitAccountMenuOptions()
{
  AccountMenuOptions[0] = new SCLI_MENU_OPTION(1, "Log Out");
  AccountMenuOptions[1] = new SCLI_MENU_OPTION(2, "Change Password");
  AccountMenuOptions[2] = new SCLI_MENU_OPTION(3, "Back To Main Menu", &Summoner::CLI::DisplayMainMenu, this);

}

void Summoner::CLI::InitSettingsMenuOptions()
{
  SettingsMenuOptions[0] = new SCLI_MENU_OPTION(1, "Save Current Settings", &Summoner::CLI::SaveUserSettings, this);
  SettingsMenuOptions[1] = new SCLI_MENU_OPTION(2, "Load Last Saved Settings");
  SettingsMenuOptions[2] = new SCLI_MENU_OPTION(3, "Back To Main Menu", &Summoner::CLI::DisplayMainMenu, this);
}

// Menu Display Functions
void Summoner::CLI::DisplayMenu(SCLI_MENU_OPTION** options, int options_count)
{
  using namespace std;
  string input;
  bool valid_input = false;
  SCLI_MENU_OPTION* selected_option;
  do {
    for (int i = 0; i < options_count; i++){
      options[i]->Print();
    }
    cout << "> " << flush;
    cin >> input;
    for (int i = 0; i < options_count; i++){
      if (atoi(input.c_str()) == options[i]->GetID()){
        selected_option = options[i];
        valid_input = true;
        break;
      }
    }
    if (!valid_input) cout << "Invalid Input" << endl;
  } while (!valid_input);
  selected_option->ExecuteCallFunction();
}

bool Summoner::CLI::DisplayMainMenu()
{
  InitMainMenuOptions();
  do {
    DisplayMenu(MainMenuOptions, MainMenuOptionsLength);
  } while (!Quit);
  return true;
}

bool Summoner::CLI::DisplayAccountMenu()
{
  InitAccountMenuOptions();
  DisplayMenu(AccountMenuOptions, AccountMenuOptionsLength);
  return true;
}

bool Summoner::CLI::DisplaySettingsMenu()
{
  InitSettingsMenuOptions();
  DisplayMenu(SettingsMenuOptions, SettingsMenuOptionsLength);
  return true;
}

// Menu Memory Cleanup
void Summoner::CLI::DeleteMenu(SCLI_MENU_OPTION** options, int options_count)
{
  for (int i = 0; i < options_count; i++){
    if (options[i]) delete options[i];
  }
}

// Settings Functions
bool Summoner::CLI::SaveUserSettings()
{
  if (CurrentUser)
    return Summoner::Settings::SaveSettings(CurrentUser);
  return false;
}

bool Summoner::CLI::LoadUserSettings()
{
  if (CurrentUser)
    return Summoner::Settings::LoadSettings(CurrentUser);
  return false;
}

bool Summoner::CLI::UserQuit()
{
  if (!Quit)
    Quit = true;
  return Quit;
}



