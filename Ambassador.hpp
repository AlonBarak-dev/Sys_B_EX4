#pragma once 
#include "Player.hpp"
#include "Game.hpp"
#include <string>

namespace coup{

    class Ambassador : public Player{

        private:

        public:
            Ambassador(Game &g, const std::string &name){
                Player(g,name);
            }
            ~Ambassador(){}
            void transfer(Player p1, Player p2);
            void block(Player p1);


    };



}
