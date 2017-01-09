#ifndef GLOBALS_H
#define GLOBALS_H

#define MAX_MENU_ELEMENTS 6

int cursorRow = 0;
int yAxis = 0;    // read the Y axis

int rightButton = Esplora.readButton(SWITCH_RIGHT);

int numberOfPokemon = 0;

enum TypeID {FIRE, WATER, GRASS, ELECTRIC};

  

typedef struct menu_t {
  // A set of strings which forms the options of a menu. How many strings is dependent on MAX_MENU_ELEMENTS
  char* element[MAX_MENU_ELEMENTS];
  // The number of elements in a menu. Being a Byte, the max is 255.
  byte elements;
  // A set of pointers from this menu to its next menus, i.e. which menu to go to when a selection is made in this one
  // In the event that there is no next menu, set this to nullptr
  menu_t* next[MAX_MENU_ELEMENTS];
  // A pointer to the previous menu, i.e. how the user got here. Used to return to a previous menu with the "back" option
  // If there is no previous menu or the user should not be able to go back, set to nullptr
  menu_t* prev;
  // A function pointer, which function should be called when an option is selected in this menu
  // If this menu is used purely to get to other menus, set to nullptr
  void (*func)();
  // A pointer to an alternative view for this menu, such as viewing the stats of a move in the moveMenu
  // Can be used as a second function pointer if required.
  void (*altView)();
} menu_t;

menu_t *currentMenu;
menu_t initialMenu = {};
menu_t mainMenu = {};
menu_t battleMenu = {};
menu_t playerMenu = {};
menu_t battlePlayerMenu = {};
menu_t pokemonMenu = {};
menu_t nameMenu = {};
menu_t starterPokemonMenu = {};
menu_t battleScreen = {};
menu_t myPokemonMenu = {};


struct  moves_t {
  byte id;
  char name[14];
  byte power;
  byte acc;
  byte lvl;
};

struct stats_t
{
  byte HP;
  byte Att;
  byte Def;
  byte Speed;
};

struct pokemon
{
  char name[14];
  TypeID type;
  int health;
  int EV;
  int xp;
  moves_t *moves[4];
  byte moveUsed[8];
};

void selectPokemon();
void viewMyPokemon();






void initialMenuFunctionDecider();

#endif
