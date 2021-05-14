#pragma once
#include "Player.hpp"

namespace pandemic {

    class Dispatcher : public Player
    {  // when in a city with a research station - can take a flight to any other destination,
       // no card neccesary
        
        public:
            Dispatcher(Board& b, City c) : Player::Player(b, c) {}
            Dispatcher &fly_direct(City city);
            std::string role();

    };
}

