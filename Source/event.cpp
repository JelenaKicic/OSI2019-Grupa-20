#include "../Include/event.h"

//pomocna funkcija za ispitivanje izbranog kriterijuma i citanje odgovarajucih dogadjaja
int checkOverviewCriteria(int overviewCriteria, Event **events, Event **eventsByCriteria)
{
    std::ifstream file("../Database/events.txt");

    int numberOfEvents = 0;
    int i = 0;

    std::string line, name, description, city, address, type, dayStr, monthStr, yearStr, hoursStr, minutesStr, input, comments;
    int day, month, year, hours, minutes;

    numberOfEvents = Event::getNumberOfEvents(file);

    events = new Event *[numberOfEvents];
    for (int i = 0; i < numberOfEvents; i++)
    {
        events[i] = new Event;
    }

    int k = 0;

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

        if (overviewCriteria == 1)
        {
            time_t now = time(0);
            tm *ltm = localtime(&now);
            if (events[i]->getDay() == ltm->tm_mday && events[i]->getMonth() == 1 + ltm->tm_mon && events[i]->getYear() == 1900 + ltm->tm_year)
            {
                eventsByCriteria[k++] = events[i];
            }
        }
        if (overviewCriteria == 2)
        {
            // struct tm *tm = localtime(0);
            // tm->tm_mday += 1;
            // time_t next = mktime(tm);
            // if (events[i]->getDay() == next.tm_mday && events[i]->getMonth() == 1 + next->tm_mon && events[i]->getYear() == 1900 + next->tm_year)
            // {
            //     eventsByCriteria[k++] = events[i];
            // }
        }
        if (overviewCriteria == 3)
        {
            if (events[i]->getType().compare("Koncert") == 0)
            {
                eventsByCriteria[k++] = events[i];
            }
        }
        if (overviewCriteria == 4)
        {
            time_t now = time(0);
            tm *ltm = localtime(&now);

            if (events[i]->getYear() < 1900 + ltm->tm_year)
                eventsByCriteria[k++] = events[i];

            else if (events[i]->getYear() == 1900 + ltm->tm_year && events[i]->getMonth() < 1 + ltm->tm_mon)
                eventsByCriteria[k++] = events[i];

            else if (events[i]->getYear() == 1900 + ltm->tm_year && events[i]->getMonth() == 1 + ltm->tm_mon && events[i]->getDay() < ltm->tm_mday)
                eventsByCriteria[k++] = events[i];

            else if (events[i]->getYear() == 1900 + ltm->tm_year && events[i]->getMonth() == 1 + ltm->tm_mon && events[i]->getDay() == ltm->tm_mday && events[i]->getHours() < 1 + ltm->tm_hour)
                eventsByCriteria[k++] = events[i];

            else if (events[i]->getYear() == 1900 + ltm->tm_year && events[i]->getMonth() == 1 + ltm->tm_mon && events[i]->getDay() == ltm->tm_mday && events[i]->getHours() == 1 + ltm->tm_hour && events[i]->getMinutes() < 1 + ltm->tm_min)
                eventsByCriteria[k++] = events[i];
        }
        if (overviewCriteria == 5)
            eventsByCriteria[k++] = events[i];
    }

    return k;
}

int compareName(Event *event1, Event *event2)
{
    return event1->getName().compare(event2->getName());
}

int compareType(Event *event1, Event *event2)
{
    return event1->getType().compare(event2->getType());
}

int compareTime(Event *event1, Event *event2)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    if (event1->getYear() < event2->getYear())
        return -1;

    else if (event1->getYear() == event2->getYear() && event1->getMonth() < event2->getMonth())
        return -1;

    else if (event1->getYear() == event2->getYear() && event1->getMonth() == event2->getMonth() && event1->getDay() < event2->getDay())
        return -1;

    else if (event1->getYear() == event2->getYear() && event1->getMonth() == event2->getMonth() && event1->getDay() == event2->getDay() && event1->getHours() < event2->getHours())
        return -1;

    else if (event1->getYear() == event2->getYear() && event1->getMonth() == event2->getMonth() && event1->getDay() == event2->getDay() && event1->getHours() < event2->getHours() && event1->getMinutes() < event2->getMinutes())
        return -1;

    else if (event1->getYear() == event2->getYear() && event1->getMonth() == event2->getMonth() && event1->getDay() == event2->getDay() && event1->getHours() < event2->getHours() && event1->getMinutes() == event2->getMinutes())
        return 0;

    else
        return 1;
}

void sort(Event **events, int n, int (*cmp)(Event *, Event *))
{
    int i, j, h;
    for (h = n / 2; h > 0; h /= 2)
    {
        for (i = h; i < n; i++)
        {
            Event *x = events[i];
            for (j = i; j >= h && (*cmp)(x, events[j - h]) < 0; j -= h)
                events[j] = events[j - h];
            events[j] = x;
        }
    }
}

void sortEvents(int sortCriteria, Event **events, int num)
{
    if (sortCriteria == 1)
        sort(events, num, compareName);

    if (sortCriteria == 2)
        sort(events, num, compareType);

    if (sortCriteria == 3)
        sort(events, num, compareTime);
}

//prikaz dogadjaja po izabranom redu i kriterijumu
void geteventsByOrder(int overviewCriteria, int sortCriteria)
{
    Event **allEvents, **eventsByCriteria;

    int n = checkOverviewCriteria(overviewCriteria, allEvents, eventsByCriteria);

    sortEvents(sortCriteria, eventsByCriteria, n);

    for (int i = 0; i < n; i++)
        eventsByCriteria[i]->printEvent();
}

//izbor kriterijuma pretrage i nacina na koji ce dogadjaji biti sortirani
void eventOverviewCriteria()
{
    int overviewCriteria = 0, sortCriteria = 0;
    std::cout << "Izaberite kritrijum pregleda dogadjaja:" << std::endl
              << "1. Pregled danasnjih dogadjaja" << std::endl
              << "2. Pregled svih buducih dogadjaja" << std::endl
              << "3. Pregled dogadjaja odredjene kategorije" << std::endl
              << "4. Pregled dogadjaja koji su prosli"
              << "5. Pregled svih dogadjaja" << std::endl;

    do
    {
        std::cout << "Unesi broj:" << std::endl;
        std::cin >> overviewCriteria;
    } while (overviewCriteria < 1 || overviewCriteria > 5);

    std::cout << "Sortiraj dogadjaje po:" << std::endl
              << "1. Nazivu" << std::endl
              << "2. Vrsti dogadjaja (kategorija)" << std::endl
              << "3. Datumu i vremenu odrzavanja" << std::endl;

    do
    {
        std::cout << "Unesi broj:" << std::endl;
        std::cin >> sortCriteria;
    } while (sortCriteria < 1 || sortCriteria > 3);

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

void Event::setComment(const std::string &comment)
{
    this->comments.push_back(comment);
}

int Event::getNumberOfEvents(std::ifstream &file)
{
    int numberOfEvents = 0;

    numberOfEvents = (std::count(std::istreambuf_iterator<char>(file),
                                 std::istreambuf_iterator<char>(), '\n')) +
                     1;
    file.seekg(0, std::ios::beg);

    return numberOfEvents;
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

void Event::printEvent()
{
    std::cout << this->getName() << " " << this->time << " " << this->date << " " << std::endl;
}