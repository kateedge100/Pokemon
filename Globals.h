#ifndef GLOBALS_H
#define GLOBALS_H

#define MAX_MENU_ELEMENTS 6

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

menu_t initialMenu = {};
menu_t pokemonMenu = {};

void initialMenuFunctionDecider();

#endif
