#pragma once

#include "../Include/login.h"
#include "../Include/newCategory.h"
#include "../Include/event.h"
#include "../Include/quiz.h"
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
void processMenu(const std::vector<Menu_Option> &);
std::string intToString(int);

// Functions for parsing main menu
void parseMainMenu();
void mainMenuParseLogin();
void mainMenuParseClientSection();

// Functions for parsing admin menu
void adminMenuParseAddCategory();
void adminMenuParseDeleteCategory();
void adminMenuParseAddEvent();
void adminMenuParseEventOverview();

// Functions for parsing client menu
void parseClientMenu();
void clientMenuParseQuiz();
void clientMenuParseEventOverview();

// Menus
const std::vector<Menu_Option> main_menu =
    {
        {"1", "Prijava na sistem", mainMenuParseLogin},
        {"2", "Korisnicki dio", mainMenuParseClientSection},
};

const std::vector<Menu_Option> admin_menu =
    {
        {"1", "Dodavanje kategorije", adminMenuParseAddCategory},
        {"2", "Brisanje kategorije", adminMenuParseDeleteCategory},
        {"3", "Dodavanje dogadjaja", adminMenuParseAddEvent},
        {"4", "Pregled dogadjaja", adminMenuParseEventOverview},
        {"5", "Nazad", parseMainMenu},
};

const std::vector<Menu_Option> client_menu =
    {
        {"1", "Pregled dogadjaja", clientMenuParseEventOverview},
        {"2", "Kviz", clientMenuParseQuiz},
        {"3", "Nazad", parseMainMenu},
};