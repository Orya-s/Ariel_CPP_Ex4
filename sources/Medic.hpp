#pragma once
#ifndef MEDIC
#define MEDIC
#include "Player.hpp"

namespace pandemic {

    class Medic : public Player
    {  // when treating a pandemic removes all cubes , not just one 
     
        public:
            using Player::Player;
            Medic &treat(City city);
            std::string role();
            void enter_city(City city);

    };
}
#endif // !MEDIC
