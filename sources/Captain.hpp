#pragma once
#include "Player.hpp"
#include "Game.hpp"
#include <string>

namespace coup{

    class Captain : public Player{
        private:

        public:
            Captain(Game& g, const std::string &name) : Player(&g, name, "Captain"){}
            ~Captain(){}
            void block(Player &p1);
            void steal(Player &p1);
    };

}