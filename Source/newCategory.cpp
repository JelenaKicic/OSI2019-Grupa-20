#include "../Include/newCategory.h"
#include <iostream>
#include <fstream>
#include <vector>
int new_category()
{
    std::string input, temp, choice;
    char c;
    int i = 0, j = 0;
    std::ifstream file("./Database/categories.txt");
    std::cout << "Unesite naziv kategorije koju zelite dodati: ";
    getline(std::cin, input);
    while (input[j])
    {
        if ((input[j] >= 'a' && input[j] <= 'z') || (input[j] >= 'A' && input[j] <= 'Z') || (input[j] == ' '))
            j++;
        else
        {
            std::cout << "Unijeli ste broj!" << std::endl;
            return 1;
        }
    }
    c = input[i];
    input[i] = toupper(c);
    while (input[i + 1])
    {
        c = input[i + 1];
        input[i + 1] = tolower(c);
        i++;
    }
    while (getline(file, temp))
    {
        if (input.compare(temp) == 0)
        {
            std::cout << "Unesena kategorija vec postoji!\n";
            return 1;
        }
    }
    file.close();
    std::ofstream file2("./Database/categories.txt", std::ios_base::app);
    std::cout << "Nova kategorija unesena\n";
    do
    {
        std::cout << "Sacuvajte izmjene? DA/NE >>> ";
        std::cin >> choice;
        if (choice == "DA")
        {
            std::cout << "Sacuvano" << std::endl;
            file2 << "\n"
                  << input;
            return 0;
        }
        else if (choice == "NE")
        {
            std::cout << "Nije sacuvano" << std::endl;
            return 1;
        }
    } while (choice != "DA" && choice != "NE");
    return 0;
}


void categoryErase()
{
	std::string category;
	std::vector<std::string> categories;


	std::string line;
	int p = 0;
	std::string j;

	std::cout << "Izaberite jednu od ponudjenih kategorija: " << std::endl;
	std::ifstream infile1("./Database/categories.txt");

	while (std::getline(infile1, line))
	{
		if (line.size() > 0)
		{
			std::cout << p + 1 << ". " << line << std::endl;
			categories.push_back(line);
			p++;
		}
	}

	infile1.close();
	do
	{
		std::cout << "Unesite redni broj zeljene kategorije: " << std::endl;
		std::cin >> j;
	} while (stringToInt(j) > p || stringToInt(j) < 0);

	int categoryIndex = stringToInt(j) - 1;
    std::cout <<"aaaaaaaaaa"<< categoryIndex << std::endl;

    std::ofstream fileOut1("./Database/categories.txt");
    fileOut1 << "" ;

    std::ofstream fileOut("./Database/categories.txt", std::ios::app);
	for (int i = 0; i < p; i++)
	{
		if (i != categoryIndex)
		{
			fileOut << categories[i] << std::endl;

		}

	}

}