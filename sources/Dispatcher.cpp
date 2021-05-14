#include "Dispatcher.hpp"
#include <algorithm>

using namespace std;

namespace pandemic {

    Dispatcher &Dispatcher::fly_direct(City city) 
    {
        if (city == location)
        {
            throw invalid_argument("Illegal action: you can't fly to your location");
        }
        if (board.cities.at(location).has_station())
        {
            location = city;
        }
        else
        {
            if (count(cards.begin(), cards.end(), city) != 0)
            {
                location = city;
                cards.erase(city);
            }
            else
            {
                throw invalid_argument("Illegal action: you are not in a research station and don't have this city's card");
            }
        }
        return *this;
    }

    string Dispatcher::role() 
    {
        return "Dispatcher";
    }
}
