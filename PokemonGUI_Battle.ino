#include <TFT.h>
#include <SPI.h>
#include <Esplora.h>
#include "GUI.h"
#include "Globals.h"



void setup() {

  //Serial.begin(9600);
  
  EsploraTFT.begin(); 
   
  EsploraTFT.background(0,0,0);  // clear the screen with black

  // writes starting menu to screen
   buildInitialMenu();
   buildMainMenu();
   buildBattleMenu();
   buildPlayerMenu();
   buildPokemonMenu();
   buildNameMenu();
   buildStarterPokemonMenu();
   buildMyPokemonMenu();
   

   currentMenu = &initialMenu;

   // build current menu which is initial menu to start with
   renderMenu(currentMenu);


}

void loop() {


  int rightButton = Esplora.readButton(SWITCH_RIGHT);
  int downButton = Esplora.readButton(SWITCH_DOWN);

  // if right button is pressed and the row leads to a new menu the new menu is rendered
  if(rightButton == LOW && currentMenu->next[(cursorRow/30)]!=nullptr )
  {
    
    clearScreen();

    // if on select pokemon page select pokemon based on choice
    if(currentMenu==&starterPokemonMenu)
    {
      selectPokemon();
    }

    else if(currentMenu==&myPokemonMenu)
    {
      viewMyPokemon();
    }
    
    else
    {
      currentMenu=currentMenu->next[(cursorRow/30)];
      
    }

    renderMenu(currentMenu);

    
   
  }
  

  // if down button is pressed and there is a previuos page it will go back
  if(downButton == LOW && currentMenu->prev!=nullptr )
  {
    
    clearScreen();

    currentMenu=currentMenu->prev;
    renderMenu(currentMenu);
   
  }
  
  


 switchRow(currentMenu);
 

 
  

}
