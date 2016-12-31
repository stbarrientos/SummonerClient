#ifndef _SUMMONER_MENU_OPTION_H_
#define _SUMMONER_MENU_OPTION_H_

#include <iostream>
#include <string>

namespace Summoner {

class CLI;

// Takes a member function and instance
template <typename F, typename O>
class MenuOption {

public:

  MenuOption();
  MenuOption(int, std::string);
  MenuOption(int, std::string, F, O);
  ~MenuOption();

  int GetID() const { return ID; }
  std::string GetText() const { return Text; }
  void SetCallFunction(F, O);
  bool ExecuteCallFunction();
  void Print();

private:

  int ID;
  std::string Text;
  F CallFunction = nullptr;
  O CallObject = nullptr;

};

}

template <typename F, typename O>
Summoner::MenuOption<F, O>::MenuOption() {}

template <typename F, typename O>
Summoner::MenuOption<F, O>::MenuOption(int id, std::string t): MenuOption(id, t, nullptr, nullptr) {}

template <typename F, typename O>
Summoner::MenuOption<F, O>::MenuOption(int id, std::string t, F pf, O o): ID(id), Text(t), CallFunction(pf), CallObject(o) {}

template <typename F, typename O>
Summoner::MenuOption<F, O>::~MenuOption() {}

template <typename F, typename O>
void Summoner::MenuOption<F, O>::SetCallFunction(F function, O o)
{
  CallFunction = function;
  CallObject = o;
}

template <typename F, typename O>
void Summoner::MenuOption<F, O>::Print()
{
  std::cout << ID << ") " << Text << std::endl;
}

template <typename F, typename O>
bool Summoner::MenuOption<F, O>::ExecuteCallFunction()
{
  if (CallFunction && CallObject) {
    return (CallObject->*CallFunction)();
  } else {
    return false;
  }
}

#endif