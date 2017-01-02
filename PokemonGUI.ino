#include <TFT.h>
#include <SPI.h>
#include <Esplora.h>
#include "GUI.h"
#include "Globals.h"



void setup() {

  Serial.begin(9600);
  
  EsploraTFT.begin(); 
   
  EsploraTFT.background(0,0,0);  // clear the screen with black

  // writes starting menu to screen
   buildInitialMenu();
   buildMainMenu();

   currentMenu = &initialMenu;

   // build current menu which is initial menu to start with
   renderMenu(currentMenu);


}

void loop() {

  int button = Esplora.readButton(SWITCH_RIGHT);

  if(button == LOW && cursorRow == 60 )
  {
    
    clearScreen();

    EsploraTFT.stroke(255,255,255);
    EsploraTFT.setTextSize(2);
    EsploraTFT.text("Loading",25,0);
   
  }
  
  


 switchRow(currentMenu);
 

 
  

}
