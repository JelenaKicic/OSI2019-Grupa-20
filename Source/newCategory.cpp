#include "newCategory.h"
#include <iostream>
#include <fstream>

int new_category()
{
    std::string unesen, temp, izbor;
    std::ifstream file ("./Database/categories.txt");
    std::cout << "Unesite naziv kategorije koju zelite dodati: ";
    std::cin >> unesen;
    while (getline(file, temp))
    {
        if (unesen.compare(temp) == 0)
        {
            std::cout << "Unesena kategorija vec postoji!\n";
            return 2;
        }
    }
    file.close();
    std::ofstream file2 ("./Database/categories.txt", std::ios_base::app);
    std::cout << "Nova kategorija unesena\n";
    do {
            std::cout << "Sacuvajte izmjene? DA/NE >>> ";
            std::cin >> izbor;
            if ( izbor == "DA")
            {
                std::cout << "Sacuvano" << std::endl;
                file2 << unesen ;
                return 1;
            }
            else if ( izbor == "NE")
                {
                    std::cout << "Nije sacuvano" << std::endl;
                    return 2;
                }
    }
    while (izbor != "DA" && izbor != "NE");

}