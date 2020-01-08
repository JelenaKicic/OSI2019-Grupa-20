#include "../Include/event.h"
#include <iostream>
#include <fstream>

//pomocna funkcija za ispitivanje izbranog kriterijuma i citanje odgovarajucih dogadjaja
void checkOverviewCriteria(int overviewCriteria, std::vector<Event> &events, std::vector<Event> &eventsByCriteria)
{
    std::string category;
    std::vector<std::string> categories;
 
    if (overviewCriteria == 3)
    {
        std::string line;
        int p = 0, j;
 
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
        } while (j > p || j < 0);
 
        category = categories[j-1];
    }
 
    // std::cout << "category: " << category << std::endl;


    std::ifstream file("./Database/events.txt");

    int i = 0;

    std::string line, name, description, city, address, type, dayStr, monthStr, yearStr, hoursStr, minutesStr, input, comments;
    int day, month, year, hours, minutes;



    while (getline(file, line))
    {
        Event event;
            std::stringstream lineStream(line);

            std::getline(lineStream, name, '|');
            event.setName(name);

        std::getline(lineStream, description, '|');
        event.setDescription(description);

        std::getline(lineStream, city, '|');
        std::getline(lineStream, address, '|');
        event.setLocation(city, address);

        std::getline(lineStream, type, '|');
        event.setType(type);

        std::getline(lineStream, hoursStr, ':');
        std::getline(lineStream, minutesStr, '|');
        event.setTime(std::stoi(hoursStr), std::stoi(minutesStr));

        std::getline(lineStream, dayStr, '.');
        std::getline(lineStream, monthStr, '.');
        std::getline(lineStream, yearStr, '|');
        event.setDateRead(std::stoi(dayStr), std::stoi(monthStr), std::stoi(yearStr));

        std::getline(lineStream, comments, '|');
        std::stringstream commentsStream(comments);
        int number_of_comments = std::count(comments.begin(), comments.end(), ',') + 1;

        for (int j = 0; j < number_of_comments; j++)
        {
            std::string comment;
            std::getline(commentsStream, comment, ',');
            event.setComment(comment);
        }
        events.push_back(event);

        if (overviewCriteria == 1)
        {
            time_t now = time(0);
            tm *ltm = localtime(&now);
            if (event.getDay() == ltm->tm_mday && event.getMonth() == 1 + ltm->tm_mon && event.getYear() == 1900 + ltm->tm_year)
            {
                eventsByCriteria.push_back(event);
            }
        }
        if (overviewCriteria == 2)
        {
            time_t now = time(0);
            tm *ltm = localtime(&now);
            if (event.getYear() < 1900 + ltm->tm_year)
            {
                eventsByCriteria.push_back(event);
            }
            else if (event.getYear() == 1900 + ltm->tm_year && event.getMonth() > 1 + ltm->tm_mon)
            {
                eventsByCriteria.push_back(event);
            }
            else if (event.getYear() == 1900 + ltm->tm_year && event.getMonth() == 1 + ltm->tm_mon && event.getDay() > ltm->tm_mday)
            {
                eventsByCriteria.push_back(event);
            }
            else if (event.getYear() == 1900 + ltm->tm_year && event.getMonth() == 1 + ltm->tm_mon && event.getDay() == ltm->tm_mday && event.getHours() > 1 + ltm->tm_hour)
            {
                eventsByCriteria.push_back(event);
            }
            else if (event.getYear() == 1900 + ltm->tm_year && event.getMonth() == 1 + ltm->tm_mon && event.getDay() == ltm->tm_mday && event.getHours() == 1 + ltm->tm_hour && event.getMinutes() > 1 + ltm->tm_min)
            {
                eventsByCriteria.push_back(event);
            }
        }
        if (overviewCriteria == 3)
        {

            if (event.getType() == category)
            {
                eventsByCriteria.push_back(event);
            }
        }
        if (overviewCriteria == 4)
        {
            time_t now = time(0);
            tm *ltm = localtime(&now);

            if (event.getYear() < 1900 + ltm->tm_year)
            {
                eventsByCriteria.push_back(event);
            }
            else if (event.getYear() == 1900 + ltm->tm_year && event.getMonth() < 1 + ltm->tm_mon)
            {
                eventsByCriteria.push_back(event);
            }
            else if (event.getYear() == 1900 + ltm->tm_year && event.getMonth() == 1 + ltm->tm_mon && event.getDay() < ltm->tm_mday)
            {
                eventsByCriteria.push_back(event);
            }
            else if (event.getYear() == 1900 + ltm->tm_year && event.getMonth() == 1 + ltm->tm_mon && event.getDay() == ltm->tm_mday && event.getHours() < 1 + ltm->tm_hour)
            {
                eventsByCriteria.push_back(event);
            }
            else if (event.getYear() == 1900 + ltm->tm_year && event.getMonth() == 1 + ltm->tm_mon && event.getDay() == ltm->tm_mday && event.getHours() == 1 + ltm->tm_hour && event.getMinutes() < 1 + ltm->tm_min)
            {
                eventsByCriteria.push_back(event);
            }
        }
        if (overviewCriteria == 5)
        {
            eventsByCriteria.push_back(event);
        }
    }

}

//leksikografsko poredjenje naziva dva dogadjaja
int compareName(Event &event1, Event &event2)
{
    return event1.getName().compare(event2.getName());
}

//leksikografsko poredjenje tipova (kategorija) dva dogadjaja
int compareType(Event &event1, Event &event2)
{
    return event1.getType().compare(event2.getType());
}

//poredjenje datuma i vremena dva dogadjaja
int compareTime(Event &event1, Event &event2)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
 
    if (event1.getYear() < event2.getYear())
        return -1;
 
    else if (event1.getYear() == event2.getYear() && event1.getMonth() < event2.getMonth())
        return -1;
 
    else if (event1.getYear() == event2.getYear() && event1.getMonth() == event2.getMonth() && event1.getDay() < event2.getDay())
        return -1;
 
    else if (event1.getYear() == event2.getYear() && event1.getMonth() == event2.getMonth() && event1.getDay() == event2.getDay() && event1.getHours() < event2.getHours())
        return -1;
 
    else if (event1.getYear() == event2.getYear() && event1.getMonth() == event2.getMonth() && event1.getDay() == event2.getDay() && event1.getHours() < event2.getHours() && event1.getMinutes() < event2.getMinutes())
        return -1;
 
    else if (event1.getYear() == event2.getYear() && event1.getMonth() == event2.getMonth() && event1.getDay() == event2.getDay() && event1.getHours() < event2.getHours() && event1.getMinutes() == event2.getMinutes())
        return 0;
 
    else
        return 1;
}

//sortiranje inplementirano pomocu shell sort algoritma
void sort(std::vector<Event> &events, int (*cmp)(Event &, Event &))
{
    int i, j, h, n;
    n = events.size();
 
    for (h = n / 2; h > 0; h /= 2)
    {
        for (i = h; i < n; i++)
        {
            Event &x = events[i];
            for (j = i; j >= h && (*cmp)(x, events[j - h]) < 0; j -= h)
                events[j] = events[j - h];
            events[j] = x;
        }
    }
}
 
//odredjivanje atributa po kojem ce se dogadjaji ispisivati
void sortEvents(int sortCriteria, std::vector<Event> &events)
{
    if (sortCriteria == 1)
        sort(events, compareName);
 
    if (sortCriteria == 2)
        sort(events, compareType);
 
    if (sortCriteria == 3)
        sort(events, compareTime);
}
 
 
//prikaz dogadjaja po izabranom redu i kriterijumu
void geteventsByOrder(int overviewCriteria, int sortCriteria)
{
    std::vector<Event> allEvents, eventsByCriteria;
 
    int numAllEvenets;
 
    checkOverviewCriteria(overviewCriteria, allEvents, eventsByCriteria);
    sortEvents(sortCriteria, eventsByCriteria);
 
    for (int i = 0; i < eventsByCriteria.size(); i++)
    {
        std::cout << i + 1 << ".";
        eventsByCriteria[i].printEventLine();
    }
 
    int eventNumber;
    std::cout << "Za pregled jednog dogadjaja unesite broj dogadjaja" << std::endl;
    do
    {
        std::cin >> eventNumber;
    } while (eventNumber <= 0 || eventNumber > eventsByCriteria.size());
 
    //ovdje umjesto jednog dogadjaja pozovi samo to za brisanje
	printEvent(allEvents, eventsByCriteria, eventNumber-1);
	
 
}

//izbor kriterijuma pretrage i nacina na koji ce dogadjaji biti sortirani
void eventOverviewCriteria()
{
    int overviewCriteria = 0, sortCriteria = 0;

    std::cout << "Sortiraj dogadjaje po:" << std::endl
              << "1. Nazivu" << std::endl
              << "2. Vrsti dogadjaja (kategorija)" << std::endl
              << "3. Datumu i vremenu odrzavanja" << std::endl
              << std::endl;

    do
    {
        std::cout << "Unesi broj:" << std::endl;
        std::cin >> sortCriteria;
        std::cout << std::endl;
    } while (sortCriteria < 1 || sortCriteria > 3);

    std::cout << "Izaberite kritrijum pregleda dogadjaja:" << std::endl
              << "1. Pregled danasnjih dogadjaja" << std::endl
              << "2. Pregled svih buducih dogadjaja" << std::endl
              << "3. Pregled dogadjaja odredjene kategorije" << std::endl
              << "4. Pregled dogadjaja koji su prosli" << std::endl
              << "5. Pregled svih dogadjaja" << std::endl
              << std::endl;

    do
    {
        std::cout << "Unesi broj:" << std::endl;
        std::cin >> overviewCriteria;
        std::cout << std::endl;
    } while (overviewCriteria < 1 || overviewCriteria > 5);

    geteventsByOrder(overviewCriteria, sortCriteria);
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

void Event::setDateRead(int day, int month, int year)
{
    this->date.setDateRead(day, month, year);
}

int search(std::vector<Event>& first, std::vector<Event>& second, int index) //trazi element iz second u first vraca indeks nadjenog 
{
	while (index >= second.size());
	{
		std::string tmp = second[index].getName();
		for (int i = 0; i < first.size(); i++)
		{
			if (tmp == first[i].getName())
				return i;

		}
	}
	return -1;
}

void deleteEvent(std::vector<Event> &allEvents, std::vector<Event>& eventsByCriteria, int index)
{
	std::ofstream file("./Database/events.txt");
	int i;
	
	if (index < 0 || index >= eventsByCriteria.size())
		std::cout << "Brisanje nije moguce." << std::endl;
	else
	{
		int indexAllEvents = search(allEvents, eventsByCriteria, index);
		if (indexAllEvents != -1)
		{
			eventsByCriteria.erase(eventsByCriteria.begin() + index);
			allEvents.erase(allEvents.begin() + indexAllEvents);

			file.open("./Database/events.txt",std::ifstream::out | std::ifstream::trunc);  // brise sadrzaj fajla da ne dodje do ponavljanja

			for (i = 0; i < allEvents.size(); i++)
			{
				allEvents[i].writeInFile(allEvents[i]); // upisuje na kraj fajla

			}
			file.close();
			

		}


	}
}
int stringToInt(std::string s) 
{
    std::stringstream geek(s);
    int x = 0;
    geek >> x;
    return x;
}

void printEvent(std::vector<Event>& allEvents, std::vector<Event>& eventsByCriteria, int index)
{
	if (index < 0 || index >= eventsByCriteria.size())
		std::cout << "Prikazivanje dogadjaja nije moguce." << std::endl;
	else
	{
		int indexAllEvents = search(allEvents, eventsByCriteria, index);
		if (indexAllEvents != -1)
		{
			std::cout << std::endl;
			std::cout << "  Naziv:      " << allEvents[indexAllEvents].getName() << std::endl;
			std::cout << "  Opis:       " << allEvents[indexAllEvents].getDescription() << std::endl;  
			std::cout << "  Grad:       " << allEvents[indexAllEvents].getCity() << std::endl;
			std::cout << "  Adresa:     " << allEvents[indexAllEvents].getAddress() << std::endl; 
			std::cout << "  Tip:        " << allEvents[indexAllEvents].getType() << std::endl;
			std::cout << "  Dan:        " << allEvents[indexAllEvents].getDay() << std::endl;
			std::cout << "  Mjesec:     " << allEvents[indexAllEvents].getMonth() << std::endl;
			std::cout << "  Godina:     " << allEvents[indexAllEvents].getYear() << std::endl;
			std::cout << "  Sat:        " << allEvents[indexAllEvents].getHours() << std::endl;
			std::cout << "  Minut:      " << allEvents[indexAllEvents].getMinutes() << std::endl;
			std::cout << "  Komentari:  " << std::endl;
			for (int i = 0; i < eventsByCriteria[indexAllEvents].comments.size(); i++)
			{
				std::cout <<"             "<< eventsByCriteria[indexAllEvents].comments[i] << std::endl;
			}
			
			//komentari ispis
		}
	}
	if (isAdministrator == true)
	{
		int select;
		std::cout << std::endl << std::endl << "Administratorske opcije sa dogadjajem:" << std::endl
			<< "1. Dodavanje dogadjaja" << std::endl
			<< "2. Izmjena dogadjaja" << std::endl
			<< "3. Brisanje dogadjaja" << std::endl
			<< std::endl;

		do
		{
			std::cout << "Unesi broj:" << std::endl;
			std::cin >> select ;
			std::cout << std::endl;
		} while (select < 1 || select > 3);

		if (select == 1)
        {
            std::cin.clear();
            fflush(stdin);
            addEvent();
        }
		
		//	if (select == 2)  poziv izmjene dogadjaja
			
		if (select == 3) deleteEvent(allEvents, eventsByCriteria, index);
	}
}

void addEvent() //dodavanje dogadjaja
{
    std::string line, name, description, adress, line1;
    Date* date = new Date;
    Time* time = new Time;

    Location* location = new Location;
    std::string* arrayCities = new std::string[55];
    std::string* array = new std::string[3];
    std::string* arrayCategories = new std::string[200];
    std::string date1, day, month, year, minutes, hours, time1, k, j, c = ":", s, point = ".", r, q, t;
    int i, p, w,v;

    std::cout << "Naziv dogadjaja: " << std::endl;
    std::getline(std::cin, name);

    array[0] = name;
    std::cout << "Opis dogadjaja: " << std::endl;
    std::getline(std::cin, description);

    array[1] = description;
    std::cout << "Izabrati jedan od sledecih ponudjenih gradova: " << std::endl;

    std::ifstream infile("./Database/cities.txt");
    i = 0;
    while (std::getline(infile, line))
    {

        std::cout << i + 1 << ". " << line << std::endl;
        arrayCities[i] = line;
        i++;
    }

    do
    {
        std::cout << "Unesite redni broj zeljenog grada: " << std::endl;
        std::cin >> k;
    } while (stringToInt(k) > i || stringToInt(k) < 0 );
    location->setCity(arrayCities[stringToInt(k) - 1]);

    infile.close();

    std::cin.clear();
    fflush(stdin);
    std::cout << "Unesite adresu: " << std::endl;
    std::getline(std::cin, adress);
    location->setAddress(adress);

    std::cout << "Izaberite jednu od ponudjenih kategorija: " << std::endl;

    p = 0;
    std::ifstream infile1("./Database/categories.txt");
    while (std::getline(infile1, line1))
    {
        if (line1.size() > 0)
        {
            std::cout << p + 1 << ". " << line1 << std::endl;
            arrayCategories[p] = line1;
            p++;
        }
    }

    infile1.close();
    do
    {
        std::cout << "Unesite redni broj zeljene kategorije: " << std::endl;
        std::cin >> j;
    } while (stringToInt(j) > p || stringToInt(j) < 0);
    array[2] = arrayCategories[stringToInt(j) - 1];
    do
    {
        v = 0;
        day.clear(); month.clear(); year.clear(); r.clear(); q.clear(); t.clear();
        std::cin.clear();
        fflush(stdin);
        std::cout << "Unesite datum (xx.xx.xxxx.): " << std::endl;
        std::getline(std::cin, date1);
        day.push_back(date1[0]);
        if (isdigit(day.back()))
            v++;
        day.push_back(date1[1]);
        if (isdigit(day.back()))
            v++;
        month.push_back(date1[3]);
        if (isdigit(month.back()))
            v++;
        month.push_back(date1[4]);
        if (isdigit(month.back()))
            v++;
        year.push_back(date1[6]);
        year.push_back(date1[7]);
        year.push_back(date1[8]);
        year.push_back(date1[9]);
        r.push_back(date1[2]);
        q.push_back(date1[5]);
        t.push_back(date1[10]);


    } while ((date1.length() != 11) || v!=4 || (!date->setDate(stringToInt(day), stringToInt(month), stringToInt(year)) || r.compare(point) || q.compare(point) || t.compare(point)));
    do
    {
        w=0;
        hours.clear(); minutes.clear(); s.clear();
        std::cin.clear();
        fflush(stdin);
        std::cout << "Unesite vrijeme(xx:xx):" << std::endl;
        std::getline(std::cin, time1);
        hours.push_back(time1[0]);
        if (isdigit(hours.back()))
            w++;
        hours.push_back(time1[1]);
        if (isdigit(hours.back()))
            w++;
        minutes.push_back(time1[3]);
        if (isdigit(minutes.back()))
            w++;
        minutes.push_back(time1[4]);
        if (isdigit(minutes.back()))
            w++;
        s.push_back(time1[2]);
    } while (time1.length() != 5 || w!=4 || s.compare(c) || !(time->setHours(stringToInt(hours) || time->setMinutes(stringToInt(minutes)))));
    
    Event newEvent = Event(array[0], array[1], location->getCity(), location->getAddress(), array[2], date->getDay(), date->getMonth(), date->getYear(), time->getHours(), time->getMinutes());

    delete time;
    delete date;
    delete location;
    delete[] array;
    delete[] arrayCategories;
    delete[] arrayCities;

    newEvent.writeInFile(newEvent);
}

int Event::writeInFile(Event &newEvent) //upis dogadjaja na kraj fajla
{
    std::ofstream fileOut("./Database/events.txt", std::ios::app);
    fileOut << newEvent.name << "|" << newEvent.description << "|" << newEvent.location.getCity() << "|" << newEvent.location.getAddress() << "|" << newEvent.type << "|" << newEvent.time.getHours() << ":" << newEvent.time.getMinutes() << "|" << newEvent.date.getDay() << "." << newEvent.date.getMonth() << "." << newEvent.date.getYear() << "."
            << "| |"<< std::endl;
    fileOut.close();
    return 1;
}

void Event::setComment(const std::string &comment)
{
    this->comments.push_back(comment);
}

int Event::getNumberOfEvents(std::ifstream &file)
{
    int numAllEvenets = 0;

    numAllEvenets = (std::count(std::istreambuf_iterator<char>(file),
                                std::istreambuf_iterator<char>(), '\n')) +
                    1;
    file.seekg(0, std::ios::beg);

    return numAllEvenets;
}

std::string Event::getName()
{
    return name;
}

std::string Event::getDescription()
{
    return description;
}

std::string Event::getType()
{
    return type;
}

std::string Event::getCity()
{
    return this->location.getCity();
}

std::string Event::getAddress()
{
    return this->location.getAddress();
}

int Event::getHours()
{
    return this->time.getHours();
}

int Event::getMinutes()
{
    return this->time.getMinutes();
}

int Event::getDay()
{
    return this->date.getDay();
}

int Event::getMonth()
{
    return this->date.getMonth();
}

int Event::getYear()
{
    return this->date.getYear();
}

void Event::printEventLine()
{
    std::cout << this->getName() << " " << this->time << " " << this->date << " " << this->getType() << std::endl;
}

