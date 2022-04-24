#pragma once
#include "Player.hpp"
#include "Game.hpp"


namespace coup{

    class Duke : public Player{

        private:

        public:

            Duke(coup::Game g, std::string name){
                Player(g,name);
            }
            ~Duke(){}
            void block(Player p1);
            void tax();

    };



}

