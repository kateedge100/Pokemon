#ifndef GUI_H
#define GUI_H

#include "Globals.h"


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
  initialMenu.next[1] = nullptr;
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
 else if(yAxis>80 && yAxis<100 && menu->elements>1)
 {
  cursorRow=30;
 }
 else if(yAxis>=64)
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
