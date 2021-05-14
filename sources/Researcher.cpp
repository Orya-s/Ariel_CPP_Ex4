#include "Researcher.hpp"
#include <algorithm>

using namespace std;

namespace pandemic {

    Researcher &Researcher::discover_cure(Color color) 
    {
        if (board.is_cured(color))
        {
            return *this;
        }
        int counter = 0;
        for (const auto& it : cards) 
        {
            if (board.cities.at(it).color == color)
            {
                counter++;
            }
        }
        if (counter >= min_to_dis)
        {
            board.add_cure(color);

            //removing 5 cards
            counter = 0;
            for (auto i = cards.begin(); i != cards.end() && counter < min_to_dis; ++i)
            {   
                if (board.cities.at(*i).color == color)
                {
                    cards.erase(i++);
                    counter++;
                }
            }
        }
        else
        {
            throw invalid_argument("Illegal action: you don't have enough cards to discover a cure");
        }
        
        return *this;
    }

    string Researcher::role() 
    {
        return "Researcher";
    }
}
