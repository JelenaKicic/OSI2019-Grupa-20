#include "../Include/event.h"
#include <iostream>
#include <fstream>

//pomocna funkcija za ispitivanje izbranog kriterijuma i citanje odgovarajucih dogadjaja
void checkOverviewCriteria(int overviewCriteria, Event **events)
{
    std::ifstream file("./Database/events.txt");
    int number_of_events = 0;
    int i = 0;
    std::string line, name, description, city, address, type, dayStr, monthStr, yearStr, hoursStr, minutesStr, input, comments;
    int day, month, year, hours, minutes;

    number_of_events = Event::getNumberOfEvents(file);
             
    events = new Event *[number_of_events];
    for (int i = 0; i < number_of_events; i++)
    {
        events[i] = new Event;
    }

    while (getline(file, line))
    {
        std::stringstream lineStream(line);

        std::getline(lineStream, name, '|');
        events[i]->setName(name);

        std::getline(lineStream, description, '|');
        events[i]->setDescription(description);

        std::getline(lineStream, city, '|');
        std::getline(lineStream, address, '|');
        events[i]->setLocation(city, address);

        std::getline(lineStream, type, '|');
        events[i]->setType(type);

        std::getline(lineStream, hoursStr, ':');
        std::getline(lineStream, minutesStr, '|');
        events[i]->setTime(std::stoi(hoursStr), std::stoi(minutesStr));

        std::getline(lineStream, dayStr, '.');
        std::getline(lineStream, monthStr, '.');
        std::getline(lineStream, yearStr, '|');
        events[i]->setDate(std::stoi(dayStr), std::stoi(monthStr), std::stoi(yearStr));

        std::getline(lineStream, comments, '|');
        std::stringstream commentsStream(comments);
        int number_of_comments = std::count(comments.begin(), comments.end(), ',') + 1;

        for (int j = 0; j < number_of_comments; j++)
        {
            std::string comment;
            std::getline(commentsStream, comment, ',');
            events[i]->setComment(comment);
        }
        i++;
    }
}

void sortEvents(int sortCriteria, int sortDirection, Event **events)
{
}

//prikaz dogadjaja po izabranom redu i kriterijumu
void geteventsByOrder(int overviewCriteria, int sortCriteria, int sortDirection)
{
    Event **events;

    checkOverviewCriteria(overviewCriteria, events);

    sortEvents(sortCriteria, sortDirection, events);
}

//izbor kriterijuma pretrage i nacina na koji ce dogadjaji biti sortirani
void eventOverviewCriteria()
{
    int overviewCriteria = 0, sortCriteria = 0, sortDirection = 0;
    std::cout << "Izaberite kritrijum pregleda dogadjaja:" << std::endl
              << "1. Pregled danasnjih dogadjaja" << std::endl
              << "2. Pregled svih buducih dogadjaja" << std::endl
              << "3. Pregled dogadjaja odredjene kategorije" << std::endl
              << "4. Pregled dogadjaja koji su prosli" << std::endl;

    do
    {
        std::cout << "Unesi broj:" << std::endl;
        std::cin >> overviewCriteria;
    } while (overviewCriteria < 1 || overviewCriteria > 4);

    std::cout << "Sortiraj dogadjaje po:" << std::endl
              << "1. Nazivu" << std::endl
              << "2. Lokaciji" << std::endl
              << "3. Vrsti dogadjaja (kategorija)" << std::endl
              << "4. Datumu i vremenu odrzavanja" << std::endl;

    do
    {
        std::cout << "Unesi broj:" << std::endl;
        std::cin >> sortCriteria;
    } while (sortCriteria < 1 || sortCriteria > 4);

    std::cout << "Sortiranje vrisiti po:" << std::endl
              << "1. Opadajucem" << std::endl
              << "2. Rastucem" << std::endl
              << "poretku." << std::endl;

    do
    {
        std::cout << "Unesi broj:" << std::endl;
        std::cin >> sortDirection;
    } while (sortDirection < 1 || sortDirection > 2);

    geteventsByOrder(overviewCriteria, sortCriteria, sortDirection);
}

Event::Event()
{
    setName("");
    setDescription("");
    setLocation("", "");
    setType("");
    setDate(1, 1, 2020);
    setTime(0, 0);
}

Event::Event(std::string name, std::string description, std::string city, std::string address, std::string type, int day, int month, int year, int hours, int minutes)
{
    setName(name);
    setDescription(description);
    setLocation(city, address);
    setType(type);
    setDate(day, month, year);
    setTime(hours, minutes);
}

void Event::setName(std::string name)
{
    this->name = name;
}

void Event::setDescription(std::string description)
{
    this->description = description;
}

void Event::setType(std::string type)
{
    this->type = type;
}

void Event::setLocation(std::string city, std::string address)
{
    this->location.setCity(city);
    this->location.setAddress(address);
}

void Event::setTime(int hours, int minutes)
{
    this->time.setHours(hours);
    this->time.setMinutes(minutes);
}

void Event::setDate(int day, int month, int year)
{
    this->date.setDate(day, month, year);
}

void addEvent() //dodavanje dogadjaja
{
	std::string line, name, description, adress, line1;
	Date* date = new Date;
	Time* time = new Time;
	Location* location = new Location;
	std::string* arrayCities = new std::string[55];
	std::string* array = new std::string[3];
	std::string* arrayCategories = new std::string[15];
	static int i, p;
	int k, j, day, month, year, m, n;
	std::cout << "Naziv dogadjaja: " << std::endl;
	std::getline(std::cin, name);
	array[0] = name;
	std::cout << "Opis dogadjaja: " << std::endl;
	std::getline(std::cin, description);
	array[1] = description;
	std::cout << "Izabrati jedan od sledecih ponudjenih gradova: " << std::endl;

	std::ifstream infile("cities.txt");
	while (std::getline(infile, line))
	{

		std::cout << i + 1 << line << std::endl;
		arrayCities[i] = line;
		i++;
	}
	do {
		std::cout << "Unesite redni broj zeljenog grada: " << std::endl;
		std::cin >> k;
	} while (k > i || k < 0);
	location->setCity(arrayCities[k - 1]);

	infile.close();

	std::cout << "Unesite adresu: " << std::endl;
	std::cin >> adress;
	location->setAddress(adress);

	std::cout << "Izaberite jednu od ponudjenih kategorija: " << std::endl;
	std::ifstream infile1("categories.txt");
	while (std::getline(infile1, line1))
	{
		if (line1.size() > 0)
		{
			std::cout << p + 1 << line1 << std::endl;
			arrayCategories[p] = line1;
			p++;
		}
	}
	infile1.close();
	do {
		std::cout << "Unesite redni broj zeljene kategorije: " << std::endl;
		std::cin >> j;
	} while (j > p || j < 0);
	array[2] = arrayCategories[j];
	do {
		std::cout << "Unesite datum,dan mjesec godina: " << std::endl;
		std::cin >> day >> month >> year;
	} while (!date->setDate(day, month, year));
	do
	{
		std::cout << "Unesite vrijeme, sate i minute:" << std::endl;
		std::cin >> m >> n;
	} while (!(time->setHours(m) && time->setMinutes(n)));




	Event newEvent = Event(array[0], array[1], location->getCity(), location->getAddress(), array[2], date->getDay(), date->getMonth(), date->getYear(), time->getHours(), time->getHours());

	delete time;
	delete date;
	delete location;
	delete[] array;
	delete[] arrayCategories;
	delete[] arrayCities;

	newEvent.writeInFile(newEvent);



}
int Event::writeInFile(Event& newEvent) //upis dogadjaja na kraj fajla
{
	std::ofstream fileOut("events.txt", std::ios::app);
	fileOut << newEvent.name << "|" << newEvent.description << "|" << newEvent.location.getCity() << "|" << newEvent.location.getAddress() << "|" << newEvent.type << "|" << newEvent.time.getHours() << ":" << newEvent.time.getMinutes() << "|" << newEvent.date.getDay() << "." << newEvent.date.getMonth() << "." << newEvent.date.getYear() << "." << "|" << std::endl;
	fileOut.close();
	return 1;
}

void Event::setComment(const std::string &comment)
{
    this->comments.push_back(comment);
}

int Event::getNumberOfEvents(std::ifstream &file)
{
    int number_of_events = 0;

    number_of_events = (std::count(std::istreambuf_iterator<char>(file), 
                        std::istreambuf_iterator<char>(), '\n')) + 1;
    file.seekg(0, std::ios::beg);

    return number_of_events;
}