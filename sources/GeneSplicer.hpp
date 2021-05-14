#pragma once
#include "Player.hpp"

namespace pandemic {

    class GeneSplicer : public Player
    {  // can discover a cure with any 5 cards , doesn't have to be the same color
     
        public:
            GeneSplicer(Board& b, City c) : Player::Player(b, c) {}
            GeneSplicer &discover_cure(Color);
            std::string role();

    };
}

