#pragma once
#include <string>
#include "Game.hpp"

namespace coup{

    class Player{

        protected:

            int coins_counter;  // amount of coins
            std::string _name;       // player name
            coup::Game *game;
            bool _can_be_blocked;    // if the player played a move that can be blocked
            bool _has_to_coup;       // if the player have 10 coins
            std::string _role;   
            std::string _last_play;
            std::string couped;
            int couped_idx;
            bool active;
            coup::Player *looted_from{};
            int amount;

        public:
            // ctor
            Player(coup::Game* g, const std::string &name, const std::string &role){
                this->coins_counter = 0;
                this->_name = name;
                this->game = g;
                this->_role = role;
                this->game->new_player(this->_name);

                this->_can_be_blocked = false;
                this->_has_to_coup = false;
                this->active = true;
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
            std::string get_last_play();
            void blocked();
            void set_coins(int amount);
            void blocked_by_contessa(const std::string name, int index);
            std::string get_couped_name();
            int get_couped_idx();
            coup::Game* get_game();
            void deactivate();
            bool is_active();
            void block_steal();
    };
    
}

