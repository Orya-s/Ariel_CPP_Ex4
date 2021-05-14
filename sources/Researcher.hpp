#pragma once
#include "Player.hpp"

namespace pandemic {

    class Researcher : public Player
    {  // can discover a cure from every city , doesn't need to ba in a research station
     
        public:
            Researcher(Board& b, City c) : Player::Player(b, c) {}
            Researcher &discover_cure(Color);
            std::string role();

    };
}

