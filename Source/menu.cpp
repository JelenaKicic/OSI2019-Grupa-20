#include "../Include/menu.h"

// Generate menu and parse input based on passed argument
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
    clearInputBuffer();
    
    if(!std::getline(std::cin, choice))
    {
        processMenu(menu_option);
    }

    for (int i = 0; i < menu_length; ++i)
    {
        clearInputBuffer();
        if (choice == menu_option[i].choice)
        {
            invalid_choice = 1;
            Menu_Processing_Function_Pointer p_function = menu_option[i].p_procesing_function;
            (p_function)();
            break;
        }
        else if (choice == "0")
        {
            std::exit(0);
        }
        else if (!invalid_choice && i == menu_length - 1)
        {
            processMenu(menu_option);
        }
    }
}

// Clears input buffer to avoid selection errors
void clearInputBuffer()
{
    std::cin.clear();
    fflush(stdin);
}


// Operator overload for comparing two menus
bool Menu_Option::operator==(const Menu_Option &other) const
{
    return ((this->choice == other.choice) && 
            (this->selection_text == other.selection_text) && 
            (this->p_procesing_function == other.p_procesing_function));
}

// Convert integer to string
// Used for parsing input
std::string intToString(int n)
{
    std::stringstream stream;
    stream << n;

    return stream.str();
}

/* Functions for parsing main menu */

// Function for parsing main menu
void parseMainMenu()
{
    processMenu(main_menu);
}

// Parses login menu
void mainMenuParseLogin()
{
    if (!login())
    {
        std::cout << "\n\nDashboard" << std::endl;
        processMenu(admin_menu);
    }
    else
    {
        std::cout << "\n" << std::endl;
        processMenu(main_menu);
    }
}

// Parse client area option from the main menu
void mainMenuParseClientSection()
{
    std::cout << "\nAdventursit" << std::endl;
    processMenu(client_menu);
}

/* Functions for parsing admin menu */

// Parse add category option from admin menu
void adminMenuParseAddCategory()
{
    new_category();
    processMenu(admin_menu);
}

// Parse add event option from the admin menu
void adminMenuParseAddEvent()
{
    addEvent();
    processMenu(admin_menu);
}

// Pare even overview option form the admin menu
void adminMenuParseEventOverview()
{
    eventOverviewCriteria();
    std::cout << "\n";
    processMenu(admin_menu);
}

/* Functions for parsing client menu */

// Function for parsing client menu
void parseClientMenu()
{
    processMenu(client_menu);
}

// Parse quiz option from the client menu
void clientMenuParseQuiz()
{
    startQuiz();
    processMenu(client_menu);
}

// Parse event overview option from the client menu
void clientMenuParseEventOverview()
{
    eventOverviewCriteria();
    std::cout << "\n";
    processMenu(client_menu);
}
