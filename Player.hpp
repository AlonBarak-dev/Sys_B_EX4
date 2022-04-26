#pragma once
#include <string>
#include "Game.hpp"

namespace coup{

    class Player{

        private:

            int coins_counter;  // amount of coins
            std::string name;       // player name
            coup::Game game;

        public:

            Player(coup::Game &g, const std::string &name){   // constructor
                this->coins_counter = 0;
                this->name = name;
                this->game = g;
                //this->game.new_player(this, this->name);    // adds a new player to the game
            }

            Player(){   // empty constructor
                this->coins_counter = 0;
            }

            ~Player(){}     // destructor

            void income();
            void foreign_aid();
            virtual void coup(coup::Player p1);
            int coins();
            std::string role();
    };
    
}

