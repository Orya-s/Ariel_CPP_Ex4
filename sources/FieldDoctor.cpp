#include "FieldDoctor.hpp"
#include <algorithm>

using namespace std;

namespace pandemic {

    FieldDoctor &FieldDoctor::treat(City city) 
    {
        if (board[city] == 0)  // no disease cubes
        {
            throw invalid_argument("Illegal action: Your location doesn't have any disease cubes");
        }

        vector<City> n = board.cities.at(location).neighbors;
        if (city != location && (count(n.begin(), n.end(), city) == 0))
        {
            throw invalid_argument("Illegal action: This city is not your location or a neighbor city");
        }
        
        Color col = board.cities.at(city).color;
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

    string FieldDoctor::role() 
    {
        return "FieldDoctor";
    }

}
