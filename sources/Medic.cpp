#include "Medic.hpp"

using namespace std;

namespace pandemic {

    Medic &Medic::treat(City city) 
    {
        if (board[city] == 0)  // no disease cubes
        {
            throw invalid_argument("Illegal action: Your location doesn't have any disease cubes");
        }        
        board[city] = 0;
        return *this;
    }

    string Medic::role() 
    {
        return "Medic";
    }

    void Medic::enter_city(City city)
    {
        Color c = board.cities.at(city).color;
        if (board.is_cured(c))
        {
            board[city] = 0;
        }
    }
}
