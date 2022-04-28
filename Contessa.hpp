#pragma once 
#include "Player.hpp"
#include "Game.hpp"
#include <string>

namespace coup{

    class Contessa : public Player{
        private:

        public:
            Contessa(Game& g, const std::string &name){
                Player(g,name, "Contessa");
            }
            ~Contessa(){}
            void block(Player p1);

    };


}