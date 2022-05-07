#pragma once
#include "Player.hpp"
#include "Assassin.hpp"
#include "Game.hpp"
#include <iostream>


namespace coup{

    class Duke : public Player{

        private:

        public:

            Duke(Game& g, const std::string& name) : Player(&g,name, "Duke"){}
            ~Duke(){}
            void block(Player& p1);
            void tax();

    };



}

