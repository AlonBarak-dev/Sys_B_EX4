#pragma once
#include "Player.hpp"
#include "Assassin.hpp"
#include "Game.hpp"
#include <iostream>


namespace coup{

    class Duke : public Player{

        private:

        public:

            Duke(coup::Game& g, const std::string& name) : Player(&g,name, "Duke"){}
            ~Duke(){}
            void block(coup::Assassin& p1);
            void tax();

    };



}

