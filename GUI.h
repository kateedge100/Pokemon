#ifndef GUI_H
#define GUI_H

#include "Globals.h"

void clearScreen()
{
  
  EsploraTFT.background(1,1,1);
}

void buildInitialMenu()
{
  // The elements of this menu are manually set
  initialMenu.element[0] = (char*)"Battle        ";
  initialMenu.element[1] = (char*)"Select pokemon";
  initialMenu.element[2] = (char*)"Load Game     ";
  initialMenu.element[3] = (char*)"Save Game     ";
  initialMenu.elements = 4;
  initialMenu.next[0] = nullptr;
  initialMenu.next[1] = &pokemonMenu;
  initialMenu.next[2] = nullptr;
  initialMenu.next[3] = nullptr;
  //initialMenu.func = &initialMenuFunctionDecider;
}

#endif
