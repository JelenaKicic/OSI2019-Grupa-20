#pragma once

#include "./login.h"
#include "./newCategory.h"
#include "./event.h"
#include "./quiz.h"
#include <iostream>
#include <vector>

typedef void (*Menu_Processing_Function_Pointer)(void);

struct Menu_Option
{
  std::string choice;
  std::string selection_text;
  Menu_Processing_Function_Pointer p_procesing_function;

  bool operator==(const Menu_Option &other) const;
};

void clearInputBuffer();
void processMenu(const std::vector <Menu_Option> &);
std::string intToString(int);

// Functions for parsing main menu
void mainMenuParseLogin();
void mainMenuParseClientSection();

// Functions for parsing admin menu
void adminMenuParseAddCategory();
void adminMenuParseAddEvent();

// Functions for parsking client menu
void clientMenuParseQuiz();

// Functions mutal for both admin and client menus
void menuParseEventOverview();

// Menus
const std::vector <Menu_Option> main_menu = 
    {
      {"1", "Prijava na sistem",  mainMenuParseLogin},
      {"2", "Korisnicki dio", mainMenuParseClientSection},
    };

const std::vector <Menu_Option> admin_menu =
    {
      {"1", "Dodavanje kategorije", adminMenuParseAddCategory},
      {"2", "Dodavanje dogadjaja", adminMenuParseAddEvent},
      {"3", "Pregeld dogadjaja", menuParseEventOverview},
    };

const std::vector <Menu_Option> client_menu =
    {
      {"1", "Pregled dogadjaja", menuParseEventOverview},
      {"2", "Kviz", clientMenuParseQuiz},
    };