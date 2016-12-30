#include <iostream>
#include "../include/summoner_menu_option.h"

Summoner::MenuOption::MenuOption() {}

Summoner::MenuOption::MenuOption(int id, std::string t): MenuOption(id, t, nullptr, nullptr) {}

Summoner::MenuOption::MenuOption(int id, std::string t, bool (Summoner::CLI::*pf)(), Summoner::CLI* o): ID(id), Text(t), CallFunction(pf), CallObject(o) {}

Summoner::MenuOption::~MenuOption() {}

void Summoner::MenuOption::SetCallFunction(bool (Summoner::CLI::*function)(), Summoner::CLI* o)
{
  CallFunction = function;
  CallObject = o;
}

void Summoner::MenuOption::Print()
{
  std::cout << ID << ") " << Text << std::endl;
}

bool Summoner::MenuOption::ExecuteCallFunction()
{
  if (CallFunction && CallObject) {
    return (CallObject->*CallFunction)();
  } else {
    return false;
  }
}