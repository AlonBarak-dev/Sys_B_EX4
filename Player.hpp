#pragma once
#include <string>
#include "Game.hpp"

namespace coup{

    class Player{

        private:

            int coins_counter;  // amount of coins
            std::string _name;       // player name
            coup::Game game;
            bool _can_be_blocked;    // if the player played a move that can be blocked
            bool _has_to_coup;       // if the player have 10 coins
            std::string _role;   
            std::string _last_play;

        public:
            // ctor
            Player(coup::Game &g, const std::string &name, const std::string &role){
                this->coins_counter = 0;
                this->_name = name;
                this->game = g;
                this->_role = role;
                this->game.new_player(this->_name, this->_role);

                this->_can_be_blocked = false;
                this->_has_to_coup = false;
            }

            Player(){   // empty constructor
                this->coins_counter = 0;
                this->_can_be_blocked = false;
                this->_has_to_coup = false;

            }

            ~Player(){}     // destructor

            void income();
            void foreign_aid();
            virtual void coup(coup::Player p1);
            int coins() const;
            std::string role();
            bool is_turn();
            bool can_be_blocked();
            bool has_to_coup();
            std::string get_name();
    };
    
}

