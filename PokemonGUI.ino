
#include <TFT.h>
#include <Esplora.h>
#include "GUI.h"



void setup() {
  // put your setup code here, to run once:
  clearScreen();

  // writes starting menu to screen
  buildInitialMenu();

  // draws selection arrow
  Esplora.write("<-");

}

void loop() {
  // put your main code here, to run repeatedly:

}
