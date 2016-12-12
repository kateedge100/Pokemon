// include the library code:
#include <SPI.h>
#include <TFT.h>
#include <Esplora.h>

#include "statsSystem.h"
#include "GUI.h"

void setup()
{
 
 // moveManager();
  initialiseTypes();
  
  
  //setting up menus and setting defaults

  
 
  buildInitialMenu()
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
  initialMenu.func = &initialMenuFunctionDecider;
}



}

void loop() 
{
}
