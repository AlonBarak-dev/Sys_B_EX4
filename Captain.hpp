#pragma once
#include "Player.hpp"
#include "Game.hpp"
#include <string>

namespace coup{

    class Captain : public Player{
        private:

        public:
            Captain(Game g, std::string name){
                Player(g, name);
            }
            ~Captain(){}
            void block(Player p1);
            void steal(Player p1);
    };

}