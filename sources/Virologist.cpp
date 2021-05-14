#include "Virologist.hpp"
#include <algorithm>

using namespace std;

namespace pandemic {

    Virologist &Virologist::treat(City city) 
    {
        if (board[city] == 0)  // no disease cubes
        {
            throw invalid_argument("Illegal action: Your location doesn't have any disease cubes");
        }
        Color col = board.cities.at(city).color;

        if (city != location)
        {
            if (count(cards.begin(), cards.end(), city) != 0)
            {
                cards.erase(city);
            }
            else
            {
                throw invalid_argument("Illegal action: This is not your location and you don't have this city's card");
            }
        }    
        if (board.is_cured(col))
        {
            board[city] = 0;
        }
        else
        {
            board[city]--;
        }     
        
        return *this;
    }

    string Virologist::role() 
    {
        return "Virologist";
    }

}
