#ifndef GUI_H
#define GUI_H

#include "Globals.h"
#include "statsSystem.h"


void clearScreen()
{
  
  EsploraTFT.background(0,0,0);
}

void buildInitialMenu()
{
  // The elements of this menu are manually set
  initialMenu.element[0] = (char*)"Resume        ";
  initialMenu.element[1] = (char*)"New Game      ";
  initialMenu.elements = 2;
  initialMenu.next[0] = &mainMenu;
  initialMenu.next[1] = &nameMenu;
  initialMenu.prev = nullptr;
  //initialMenu.func = &initialMenuFunctionDecider;
}

void buildMainMenu()
{
  // The elements of this menu are manually set
  mainMenu.element[0] = (char*)"Battle        ";
  mainMenu.element[1] = (char*)"Player";
  mainMenu.element[2] = (char*)"Pokedex     ";
  mainMenu.elements = 3;
  mainMenu.next[0] = &battleMenu;
  mainMenu.next[1] = &playerMenu;
  mainMenu.next[2] = nullptr;
  mainMenu.prev = &initialMenu;
}

void buildBattleMenu()
{
  // The elements of this menu are manually set
  battleMenu.element[0] = (char*)"Solo        ";
  battleMenu.element[1] = (char*)"Battle \n  Player";
  battleMenu.elements = 2;
  battleMenu.next[0] = nullptr;
  battleMenu.next[1] = nullptr;
  battleMenu.prev = &mainMenu;
}

void buildPlayerMenu()
{
  // The elements of this menu are manually set
  playerMenu.element[0] = (char*)"Pokemon        ";
  playerMenu.element[1] = (char*)"Player Info";
  playerMenu.elements = 2;
  playerMenu.next[0] = &pokemonMenu;
  playerMenu.next[1] = nullptr;
  playerMenu.prev = &mainMenu;
}

void buildPokemonMenu()
{
  // The elements of this menu are manually set
  pokemonMenu.element[0] = (char*)"View Pokemon        ";
  pokemonMenu.element[1] = (char*)"Select Team";
  pokemonMenu.elements = 2;
  pokemonMenu.next[0] = &myPokemonMenu;
  pokemonMenu.next[1] = nullptr;
  pokemonMenu.prev = &playerMenu;
}

void buildNameMenu()
{
  // The elements of this menu are manually set
  nameMenu.element[0] = (char*)"Enter Name  ";
  nameMenu.elements = 1;
  nameMenu.next[0] = &starterPokemonMenu;
  nameMenu.prev = &initialMenu;
}

void buildStarterPokemonMenu()
{
  // The elements of this menu are manually set
  starterPokemonMenu.element[0] = (char*)"Choose \nStarter Pokemon  ";
  starterPokemonMenu.element[1] = (char*)"Charmander  ";
  starterPokemonMenu.element[2] = (char*)"Squirtle  ";
  starterPokemonMenu.element[3] = (char*)"Bulbasaur  ";
  starterPokemonMenu.elements = 4;
  starterPokemonMenu.next[0] = nullptr;
  starterPokemonMenu.next[1] = &mainMenu;
  starterPokemonMenu.next[2] = &mainMenu;
  starterPokemonMenu.next[3] = &mainMenu;
  starterPokemonMenu.prev = &nameMenu;
}

void buildMyPokemonMenu()
{
  myPokemonMenu.prev=&pokemonMenu;
}

void viewMyPokemon()
{
  int row = 0;
  for(int i=0;i<numberOfPokemon; i++)
  {
    EsploraTFT.stroke(255,255,255);
    EsploraTFT.text(myPokemon[i].name,25,row);
    row+=30;
  }
}


void renderMenu(menu_t *menu)
{ 
  int row = 0;

  EsploraTFT.stroke(255,255,255);
  EsploraTFT.setTextSize(2);

  for(int i = 0; i < menu->elements; i++)
  {
    
      // draw i element of the menu
    EsploraTFT.text(menu->element[i],25,row);

    // draws next element on next row
    row+=30;
  }
}

void switchRow(menu_t *menu)
{
   // save the height of the screen
  int myHeight = EsploraTFT.height();

  // map the paddle's location to the joystick's position 
 
  yAxis = map(Esplora.readJoystickY(), -512, 512, 0, myHeight);

  // use joystick position to move cursor up and down menu
 if( yAxis>120 && menu->elements>3 )
 {
  cursorRow=90;
 }
 // if there are less then 2 rows the cursor wont go past row 2
 else if(yAxis>=100 && yAxis<120 && menu->elements>2)
 {
  cursorRow=60;
 }
 else if(yAxis>=80 && yAxis<100 && menu->elements>1)
 {
  cursorRow=30;
 }
 else if(yAxis>=64 && yAxis<80)
 {
  cursorRow=0;
 }

 //initial position 64

  // draws cursor
 EsploraTFT.stroke(255,255,255);
 EsploraTFT.text("->",0,cursorRow);

 EsploraTFT.stroke(0,0,0);
 EsploraTFT.text("->",0,cursorRow);
  
}

// Function to select which pokemon the user will use in the battle
void selectPokemon()
{
  int currentPokemon = 0;
  // Determine which pokemon is selected and set it as the current
  currentPokemon = (cursorRow/30)-1;

  clearScreen();
  
  EsploraTFT.stroke(255,255,255);
  EsploraTFT.text(starterPokemon[currentPokemon].name,0,30);
  EsploraTFT.text("now selected",0,50);

  myPokemon[0]=starterPokemon[currentPokemon];

  numberOfPokemon = 1;
  
  delay(750);

  clearScreen();
  
  currentMenu = &mainMenu;
}


#endif
