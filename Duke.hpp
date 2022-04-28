#pragma once
#include "Player.hpp"
#include "Game.hpp"


namespace coup{

    class Duke : public Player{

        private:

        public:

            Duke(coup::Game& g, const std::string& name){
                Player(g,name, "Duke");
            }
            ~Duke(){}
            void block(Player p1);
            void tax();

    };



}

