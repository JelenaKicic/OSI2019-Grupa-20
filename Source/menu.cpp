#include "../Include/menu.h"

void processMenu(const std::vector <Menu_Option> &menu_option)
{
    int menu_length;

    menu_length = menu_option.size();

    for (int i = 0; i < menu_length; ++i)
    {
        std::cout << menu_option[i].choice << ". " << menu_option[i].p_selection_text << std::endl;
    }
    std::cout << "0. Izlaz" << std::endl;

    char choice;
    std::cin >> choice;
    for (int i = 0; i < menu_length; ++i)
    {
        if (choice == menu_option[i].choice)
        {
            Menu_Processing_Function_Pointer p_function = menu_option[i].p_procesing_function;
            std::cin.clear();
            fflush(stdin);
            (p_function)();
            break;
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