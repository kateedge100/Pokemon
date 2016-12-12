#ifndef GUI_H
#define GUI_H

// The maximum amount of options in any given menu, not including "back". Increasing will allow more moves, Pokemon etc.
#define MAX_MENU_ELEMENTS 6

enum TypeID {FIRE, WATER, GRASS, ELECTRIC};

// A menu structure, used to allow simple switching between menus
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

//Each pokemon move/attack has an ID, Name, Power, Accuracy, and the levle in which the pokemon access the move
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


  void buildInitialMenu();


int myAddress = 1;
int opponentAddress = 2;
int damageTaken = -1;
int damageDone = -1;

bool fighting = false;
bool challenging = false;
bool challenged = false;
bool enemyAttacked = false;

// Which row is currently the focus. The top row is considered 0 while bottom is considered 1.
byte rowSelected   = 0;
// Which page of a menu is to be shown. Should never exceed MAX_MENU_ELEMENTS/2 (+1 if a menu has a "back" option). In this case, 1 is the first page, 2 the second and so on
byte page          = 1;

// Define the identifiers for each menu
menu_t *currentMenu;
menu_t initialMenu = {};
menu_t challengeResponseMenu = {};
menu_t mainMenu = {};
menu_t statsMenu = {};
menu_t attacksMenu = {};
menu_t pokemonMenu = {};
menu_t replaceMoveMenu = {};

void buildReplaceMoveMenu(const char* moveName);
bool replaceMoves();
void replaceMove();
void clearText();
void initialiseTypes();
int calcDamage(moves_t* attack, pokemon _myPokemon, pokemon _enemyPokemon);
void swapAddresses();
void battleStarted();
void renderText(const char *, const char *);
void handleDamage(int _dmgDone, int _dmgTaken);
void finishMatch();
bool isConnectionActive();

void challengeOpponent();
void saving();
void loading();
void acceptReject();
void renderStats(byte);
void renderStatsSelection();
void renderStatsCurrent();
void renderAttackStats();
void selectPokemon();
void attack();
void initialMenuFunctionDecider();
#endif

