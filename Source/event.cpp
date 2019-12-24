#include "../Include/event.h"

//pomocna funkcija za ispitivanje izbranog kriterijuma i citanje odgovarajucih dogadjaja
void checkOverviewCriteria(int overviewCriteria, Event **events)
{
}

//prikaz dogadjaja po izabranom redu i kriterijumu
void geteventsByOrder(int overviewCriteria, int sortCriteria, int sortDirection)
{
    Event **events;

    checkOverviewCriteria(overviewCriteria, events);
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
