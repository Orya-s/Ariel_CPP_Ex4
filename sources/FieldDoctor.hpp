#pragma once
#include "Player.hpp"

namespace pandemic {

    class FieldDoctor : public Player
    {  // can treat a neighbor city , without throwing the city's card
     
        public:
            FieldDoctor(Board& b, City c) : Player::Player(b, c) {}
            FieldDoctor &treat(City city);
            std::string role();

    };
}

