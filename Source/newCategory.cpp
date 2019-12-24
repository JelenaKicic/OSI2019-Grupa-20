#include "newCategory.h"
#include <iostream>
#include <fstream>

int new_category()
{
    std::string unesen, temp, izbor;
	char c;
	int i = 0, j = 0;
    std::ifstream file ("./Database/categories.txt");
    std::cout << "Unesite naziv kategorije koju zelite dodati: ";
	std::cin >> unesen;
	while (unesen[j])
	{
		if ((unesen[j] >= 'a' && unesen[j] <= 'z') || (unesen[j] >= 'A' && unesen[j] <= 'Z'))
			j++;
		else
		{
			cout << "Unijeli ste broj!" << endl;
			return 1;
		}
	}
	c = unesen[i];
	unesen[i] = toupper(c);
	while (unesen[i + 1])
	{
		c = unesen[i + 1];
		unesen[i + 1] = tolower(c);
		i++;
	}
    while (getline(file, temp))
    {
        if (unesen.compare(temp) == 0)
        {
            std::cout << "Unesena kategorija vec postoji!\n";
            return 1;
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
                file2 << "\n" << unesen ;
                return 0;
            }
            else if ( izbor == "NE")
                {
                    std::cout << "Nije sacuvano" << std::endl;
                    return 1;
                }
    }
    while (izbor != "DA" && izbor != "NE");

}