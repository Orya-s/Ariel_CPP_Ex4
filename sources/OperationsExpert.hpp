#pragma once
#include "Player.hpp"

namespace pandemic {

    class OperationsExpert : public Player
    {  // can build in every city he's in , no need for the city's card
     
        public:
            OperationsExpert(Board& b, City c) : Player::Player(b, c) {}
            OperationsExpert &build();
            std::string role();

    };
}

