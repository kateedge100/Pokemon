#ifndef GLOBALS_H
#define GLOBALS_H

#define MAX_MENU_ELEMENTS 6

#include <SD.h>
#include <TFT.h>
#include <SPI.h>
#include <Esplora.h>

int cursorRow = 0;
int yAxis = 0;    // read the Y axis
const char SD_card = 8;


byte numberOfPokemon  = 0;
byte selectedPokemon  = 0;



enum TypeID { POISON, NORMAL, GRASS, FIRE, ELECTRIC, GROUND, ROCK, ICE, FIGHTING, PSYCHIC, BUG, DRAGON, GHOST, WATER };

  

typedef struct menu_t 
{
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
menu_t challengeResponseMenu = {};
menu_t playerMenu = {};
menu_t pokemonInfoMenu = {};
menu_t nameMenu = {};
menu_t starterPokemonMenu = {};
menu_t myPokemonMenu = {};
menu_t pickPokemonForBattleMenu = {};
menu_t movesMenu = {};



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
  char * name;
  TypeID type;
  int health;
  int EV;
  int xp;
  moves_t *moves[4];
  byte moveUsed[8];
  bool active;
};

pokemon currentPokemon[] = {};
//pokemon starterPokemon[] = {};

pokemon starterPokemon[] = 
{
  {
    "Charmander",                         // Name
    FIRE,                                 // Type
    90,                                    // Health
    0,                                    // EV
    0,                                    // XP
    {nullptr, nullptr, nullptr, nullptr}, // Move id's
    {0, 0, 0, 0, 0, 0, 0, 0},             // Used moves
    false                                     // Active
  },
  {
    "Squirtle",                           // Name
    WATER,                                // Type
    0,                                    // Health
    0,                                    // EV
    0,                                    // XP
    {nullptr, nullptr, nullptr, nullptr}, // Move id's
    {0, 0, 0, 0, 0, 0, 0, 0},             // Used moves
    false                                     // Active
  },
  {
    "Bulbasaur",                          // Name
    GRASS,                                // Type
    0,                                    // Health
    0,                                    // EV
    0,                                    // XP
    {nullptr, nullptr, nullptr, nullptr}, // Move id's
    {0, 0, 0, 0, 0, 0, 0, 0},             // Used moves
    false                                     // Active
  },
  
};

void selectStarterPokemon();
void viewMyPokemon();




void initialMenuFunctionDecider();


/////////////////////////////////////////////////////////////////////////////// pokedex prototypes
String loadPokemon(int _pokemonNum);
PImage getBackImage(int _pokemonNum);
PImage getFrontImage(int _pokemonNum);
String getType_str(String &_PokemonData);
TypeID getType(String &_PokemonData);
String getHP_str(String &_PokemonData);
int getHP(String &_PokemonData);
String getAttack_str(String &_PokemonData);
int getAttack(String &_PokemonData);
String getDefence_str(String &_PokemonData);
int getDefence(String &_PokemonData);
String getSpecialAttack_str(String &_PokemonData);
int getSpecialAttack(String &_PokemonData);
String getSpecialDefence_str(String &_PokemonData);
int getSpecialDefence(String &_PokemonData);
String getSpeed_str(String &_PokemonData);
int getSpeed(String &_PokemonData);
String getName(String &_PokemonData);
pokemon getPokemon(String &_PokemonData);
stats_t getStats_t(String &_PokemonData);

/////////////////////////////////////////////////////////////////////////////// GUI prototypes

void clearScreen();
void buildInitialMenu();
void buildMainMenu();
void buildBattleMenu();
void buildChallengeResponseMenu();
void buildPickPokemonForBattleMenu();
void buildMovesMenu();
void buildPlayerMenu();
void buildPokemonInfoMenu();
void buildNameMenu();
void buildStarterPokemonMenu();
void buildMyPokemonMenu();
void viewMyPokemon();
void selectStarterPokemon();
void renderMenu(menu_t *menu);
void switchRow(menu_t *menu);


#endif

