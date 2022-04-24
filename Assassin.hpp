#pragma once
#include <string>
#include "Player.hpp"
#include "Game.hpp"

namespace coup{

    class Assassin : public Player{

        private:

        public:
            Assassin(Game g, std::string name){
                Player(g,name);
            }
            ~Assassin(){}
            void coup(Player p1);


    };


}