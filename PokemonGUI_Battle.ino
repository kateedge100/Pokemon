
#include "Globals.h"
#include "GUI.h"
//#include "statsSystem.h"
//PImage img;

void setup() 
{
  Serial.begin(9600);
  SPI.begin();
  EsploraTFT.begin(); 

  EsploraTFT.background(0,0,0);  // clear the screen with black

 buildInitialMenu();
 buildMainMenu();
 buildBattleMenu();
 buildChallengeResponseMenu();
 buildPickPokemonForBattleMenu();
 buildMovesMenu();
 buildPlayerMenu();
 buildPokemonInfoMenu();
 buildNameMenu();
 buildStarterPokemonMenu();
 buildMyPokemonMenu();


  // writes starting menu to screen
  //currentMenu = &initialMenu;

  //renderMenu(currentMenu);

  // Rewrites menu1 struct as initial menu
  buildMenu(0);

  // build current menu which is initial menu to start with
  renderMenu1(menu1);

  if (!SD.begin(SD_card)) 
  {
    Serial.println("Failed");
    return;
  }
  Serial.println("Succeded");
}

void loop() 
{
  while(currentMenu == &myPokemonMenu)
  {
    if(numberOfPokemon != 0)
    {
      viewMyPokemon();
      renderMenu(currentMenu);
    }
  }
   
  int rightButton = Esplora.readButton(SWITCH_RIGHT);
  int downButton = Esplora.readButton(SWITCH_DOWN);

  // if right button is pressed and the row leads to a new menu the new menu is rendered
  if(rightButton == LOW && currentMenu->next[(cursorRow/30)] != nullptr )
  { 
    clearScreen();

    // if on select pokemon page select pokemon based on choice
    if(currentMenu == &starterPokemonMenu)
    {
      selectStarterPokemon();
    }   

    else if(currentMenu == &pickPokemonForBattleMenu)
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
