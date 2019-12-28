#include "../Include/menu.h"

void processMenu(const std::vector <Menu_Option> &menu_option)
{
    int menu_length;
    int invalid_choice = 0;

    menu_length = menu_option.size();

    for (int i = 0; i < menu_length; ++i)
    {
        std::cout << menu_option[i].choice << ". " << menu_option[i].selection_text << std::endl;
    }
    std::cout << "0. Izlaz" << std::endl;

    std::string choice;
    
    if(!std::getline(std::cin, choice))
    {
        processMenu(menu_option);
    }

    for (int i = 0; i < menu_length && choice != "0"; ++i)
    {
        if (choice == menu_option[i].choice)
        {
            invalid_choice = 1;
            Menu_Processing_Function_Pointer p_function = menu_option[i].p_procesing_function;
            std::cin.clear();
            fflush(stdin);
            (p_function)();
            break;
        }
        else if (!invalid_choice && i == menu_length - 1)
        {
            std::cin.clear();
            fflush(stdin);
            processMenu(menu_option);
        }
    }
}

// Functions for parsing main menu
void mainMenuParseLogin()
{
    if (!login())
    {
        std::cout << "\n\nDashboard" << std::endl;
    }
    else
    {
        std::cout << "\n" << std::endl;
        processMenu(main_menu);
    }
}

void mainMenuParseUserSection()
{
    std::cout << "\nAdventursit" << std::endl;
}