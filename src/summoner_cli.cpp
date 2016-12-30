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
  string username;
  string password;
  User* user = new User();
  do {
    cout << "Username: " << flush;
    cin >> username;
    user->SetUsername(username);
    cout << "Password: " << flush;
    cin >> password;
    user->Authenticate(password);
    if (!user->IsAuthenticated()) cout << "Invalid Username Or Password" << endl;
  } while (!user->IsAuthenticated());
  CurrentUser = user;
  cout << "Welcome " << CurrentUser->GetUsername() << endl << endl;
  DisplayMainMenu();
}

// Menu Init Functions
void Summoner::CLI::InitMainMenuOptions()
{
  MainMenuOptions[0] = new MenuOption(1, "Account", &Summoner::CLI::DisplayAccountMenu, this);
  MainMenuOptions[1] = new MenuOption(2, "Settings");
  MainMenuOptions[2] = new MenuOption(3, "Summon Help");
  MainMenuOptions[2] = new MenuOption(3, "List Summon Requests");
}

void Summoner::CLI::InitAccountMenuOptions()
{
  AccountMenuOptions[0] = new MenuOption(1, "Log Out");
  AccountMenuOptions[1] = new MenuOption(2, "Change Password");
  AccountMenuOptions[1] = new MenuOption(2, "Back To Main Menu", &Summoner::CLI::DisplayMainMenu, this);

}

void Summoner::CLI::InitSettingsMenuOptions()
{

}

// Menu Display Functions
void Summoner::CLI::DisplayMenu(Summoner::MenuOption** options, int options_count)
{
  using namespace std;
  string input;
  bool valid_input = false;
  Summoner::MenuOption* selected_option;
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
  DisplayMenu(MainMenuOptions, MainMenuOptionsLength);
  return true;
}

bool Summoner::CLI::DisplayAccountMenu()
{
  InitAccountMenuOptions();
  DisplayMenu(AccountMenuOptions, AccountMenuOptionsLength);
  return true;
}

// Menu Memory Cleanup
void Summoner::CLI::DeleteMenu(MenuOption** options, int options_count)
{
  for (int i = 0; i < options_count; i++){
    if (options[i]) delete options[i];
  }
}


