#pragma once
#include "Player.hpp"

namespace pandemic {

    class Virologist : public Player
    {  // can treat any city if trows it's card - even when not there
     
        public:
            Virologist(Board& b, City c) : Player::Player(b, c) {}
            Virologist &treat(City city);
            std::string role();

    };
}
