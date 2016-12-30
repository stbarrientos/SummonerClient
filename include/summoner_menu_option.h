#ifndef _SUMMONER_MENU_OPTION_H_
#define _SUMMONER_MENU_OPTION_H_

#include <string>

namespace Summoner {

class CLI;

class MenuOption {

public:

  MenuOption();
  MenuOption(int, std::string);
  MenuOption(int, std::string, bool (Summoner::CLI::*)(), Summoner::CLI*);
  ~MenuOption();

  int GetID() const { return ID; }
  std::string GetText() const { return Text; }
  void SetCallFunction(bool (Summoner::CLI::*)(), Summoner::CLI*);
  bool ExecuteCallFunction();
  void Print();

private:

  int ID;
  std::string Text;
  bool (Summoner::CLI::*CallFunction)() = nullptr;
  CLI* CallObject = nullptr;

};

}

#endif