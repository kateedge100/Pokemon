#ifndef GUI_H
#define GUI_H

#include "Globals.h"
//#include "statsSystem.h"
#include "pokedex.h"

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


// Add code so that there is a waiting screen and only proceeds when network establisted, also display opponents name
void buildBattleMenu()
{
  // The elements of this menu are manually set
  battleMenu.element[0] = (char*)"Solo        ";
  battleMenu.element[1] = (char*)"Battle \n  Player";
  battleMenu.elements = 2;
  battleMenu.next[0] = nullptr;
  battleMenu.next[1] = &challengeResponseMenu;
  battleMenu.prev = &mainMenu;
}

void buildChallengeResponseMenu()
{
  challengeResponseMenu.element[0] = (char*)"Accept        ";
  challengeResponseMenu.element[1] = (char*)"Reject        ";
  challengeResponseMenu.elements = 2;
  challengeResponseMenu.next[0] = &pickPokemonForBattleMenu;
  challengeResponseMenu.next[1] = nullptr;
  challengeResponseMenu.prev = &battleMenu;
  //challengeResponseMenu.func = &acceptReject;
}

void buildPickPokemonForBattleMenu()
{
  /*for(int i = 0; i < 1; ++i)
  {

  // FIND A WAY TO CONVERT STRING TO CHAR*
    char * tmp =  (char *) String(starterPokemon[0].health).c_str();
    
    pickPokemonForBattleMenu.element[0] =tmp;
   // pickPokemonForBattleMenu.element[0] = 
    pickPokemonForBattleMenu.elements++;
    pickPokemonForBattleMenu.next[0] = nullptr;
  //}
  pickPokemonForBattleMenu.prev = &battleMenu; 

  {*/
// FIND A WAY TO CONVERT STRING TO CHAR*
    //char * tmp =  (char *) String(currentPokemon[0].name).c_str();
    
    //pickPokemonForBattleMenu.element[0] =tmp;
 
  pickPokemonForBattleMenu.element[0] = (char*)"Select\n  Pokemon\n  For Battle ";
  pickPokemonForBattleMenu.elements=1;
  pickPokemonForBattleMenu.next[0] = &movesMenu;

  int pokemonRow = 30;
  
  /*for(int i = 0; i < (sizeof(currentPokemon)/sizeof(pokemon))+1; ++i)
  {
    //char* tmp = currentPokemon[i].name;
   
       EsploraTFT.stroke(255,255,255);
       EsploraTFT.text((char*) currentPokemon[i].name,25,pokemonRow);
     

       pokemonRow+=30;
    
    
 
  }*/
  
  pickPokemonForBattleMenu.prev = &battleMenu;
  

  
}

void buildMovesMenu()
{
  movesMenu.element[0] = (char*)"Pick Move";
  movesMenu.next[0]=nullptr;
  movesMenu.elements=1;

  for(int i=0; i<4; i++)
  {
    movesMenu.element[i+1] = currentPokemon[selectedPokemon].moves[i]->name;
    movesMenu.elements++;
    movesMenu.next[i+1] = &pickPokemonForBattleMenu;
   
  }

  movesMenu.prev = &battleMenu;
  //challengeResponseMenu.func = &acceptReject;
}


void buildPlayerMenu()
{
  // The elements of this menu are manually set
  playerMenu.element[0] = (char*)"Pokemon ";
  playerMenu.element[1] = (char*)"Player Info";
  playerMenu.elements = 2;
  playerMenu.next[0] = &pokemonInfoMenu;
  playerMenu.next[1] = nullptr;
  playerMenu.prev = &mainMenu;
}

void buildPokemonInfoMenu()
{
  // The elements of this menu are manually set
  pokemonInfoMenu.element[0] = (char*)"View Pokemon        ";
 pokemonInfoMenu.element[1] = (char*)"Select Team";
 pokemonInfoMenu.elements = 2;
 pokemonInfoMenu.next[0] = &myPokemonMenu;
 pokemonInfoMenu.next[1] = nullptr;
  pokemonInfoMenu.prev = &playerMenu;
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
  starterPokemonMenu.element[0] = (char*)"Choose \n  Pokemon  ";
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
  myPokemonMenu.element[0] = (char*)"My Pokemon  ";
  myPokemonMenu.elements = 1;
  myPokemonMenu.next[0] = nullptr;
  myPokemonMenu.prev = &pokemonInfoMenu;
  
}

// Creates an element for each Pokemon and assigns the corresponding Pokemon's name to each one, problems printing out from myPokemon rather then starterPokemon
void viewMyPokemon()
{
  int pokemonRow = 30;
  //clearScreen();
  
  EsploraTFT.stroke(255,255,255);
  for(int i = 0; i < (sizeof(currentPokemon)/sizeof(pokemon))+1; ++i)
  {
    EsploraTFT.text((char*) currentPokemon[i].name,25,pokemonRow);
    pokemonRow+=30;
  }  

  delay(750);

  clearScreen();
  
  currentMenu = &pokemonInfoMenu;
 

} 

//// Function to select which pokemon the user will use in the battle
//void selectStarterPokemon()
//{
//  
//  // Determine which pokemon is selected and set it as the current
//  int selectedStarterPokemon = (cursorRow/30)-1;
//
//  clearScreen();
//  
//  EsploraTFT.stroke(255,255,255);
//  EsploraTFT.text((char*) starterPokemon[selectedStarterPokemon].name,0,30);
//  EsploraTFT.text("now selected",0,50);
//
//  currentPokemon[0]=starterPokemon[selectedStarterPokemon];
//
//  // Test the myPokemon[0] is correct
//  //EsploraTFT.text(currentPokemon[0].name,0,80);
//
//  numberOfPokemon = 1;
//  
//  delay(750);
//
//  clearScreen();
//  
//  currentMenu = &mainMenu;
//}

// Function to select which pokemon the user will use in the battle
void selectStarterPokemon()
{
  // Determine which pokemon is selected and set it as the current
  int selectedStarterPokemon = (cursorRow/30)-1;

  clearScreen();
  
//  EsploraTFT.stroke(255,255,255);
  EsploraTFT.text((char*) starterPokemon[selectedStarterPokemon].name,0,30);
  EsploraTFT.text("now selected",0,50);
//  PImage img = getFrontImage(1);
//  EsploraTFT.image(img, 0, 45);
  currentPokemon[0]=starterPokemon[selectedStarterPokemon];

  // Test the myPokemon[0] is correct
  //EsploraTFT.text(currentPokemon[0].name,0,80);

  numberOfPokemon = 1;

  
  delay(750);

  clearScreen();
  
  currentMenu = &mainMenu;
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

  //PImage myPokemonImg = loadFrontImage(4);

  
  
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


#endif
