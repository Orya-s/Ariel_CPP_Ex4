#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <string>
#include <set>
#include <iostream>
#include <sstream>

namespace pandemic {

    class Player
    {
        protected:
            Board& board;
            City location; 
            std::set<City> cards; 
            int min_to_dis = 5;

        public:
            Player(Board& b, City c) : board(b), location(c) {}
            ~Player() {}

            virtual Player& drive(City neighbor) ;
            virtual Player& fly_direct(City city) ;
            virtual Player& fly_charter(City city) ;
            virtual Player& fly_shuttle(City city) ;
            virtual Player& build() ;
            virtual Player& discover_cure(Color color) ;
            virtual Player& treat(City city) ;
            virtual std::string role() ;
            virtual Player& take_card(City city) ;
            virtual void remove_cards();
            virtual void enter_city(City city);
    };
}
