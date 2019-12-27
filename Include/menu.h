#pragma once

#include "../Include/login.h"
#include <iostream>
#include <vector>

typedef void (*Menu_Processing_Function_Pointer)(void);

struct Menu_Option
{
  char choice;
  char const * p_selection_text;
  Menu_Processing_Function_Pointer p_procesing_function;
};

void processMenu(const std::vector <Menu_Option> &);

// Functions for parsing main menu
void mainMenuParseLogin();
void mainMenuParseUserSection();

// Menus
const std::vector <Menu_Option> main_menu = 
    {
      {'1', "Prijava na sistem",  mainMenuParseLogin},
      {'2', "Korisnicki dio", mainMenuParseUserSection},
    };