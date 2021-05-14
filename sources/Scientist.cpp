#include "Scientist.hpp"
#include <algorithm>

using namespace std;

namespace pandemic {

    Scientist &Scientist::discover_cure(Color color) 
    {
        if (board.is_cured(color))
        {
            return *this;
        }
        
        if (board.cities.at(location).has_station())
        {
            int counter = 0;
            for (auto i = cards.begin(); i != cards.end(); ++i)
            {
                if (board.cities.at(*i).color == color)
                {
                    counter++;
                }
            }
            if (counter >= min_cards)
            {
                board.add_cure(color);

                //removing min_cards 
                counter = min_cards;

                for (auto i = cards.begin(); i != cards.end() && counter > 0; ++i)
                {
                    if (board.cities.at(*i).color == color)
                    {
                        cards.erase(i++);
                        counter--;
                        if (cards.empty())
                        {
                            return *this;
                        } 
                    }
                }
            }
            else
            {
                throw invalid_argument("Illegal action: you don't have enough cards to discover a cure");
            }
        }
        else
        {
            throw invalid_argument("Illegal action: Your location doesn't have a research station");
        }

        return *this;
    }

    string Scientist::role() 
    {
        return "Scientist";
    }
}
