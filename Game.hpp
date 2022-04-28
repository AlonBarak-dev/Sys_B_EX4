#pragma once
#include <string>
#include <vector>
#include <unordered_map>
//#include "Player.hpp"


namespace coup{

    class Game{

        private:
            std::vector<std::string> players_names;   // list of all active players names
            int turn_idx;
            bool active;    // tells if the game is still active


        public:

            Game(){
                this->turn_idx = 0;
                this->active = true;
            }    // constructor

            ~Game(){}   // destructor

            std::string turn();     // return the player turn
            void increament_turn();
            std::vector<std::string> players(); // list of players
            std::string winner();   // tells the winner if exist
            void new_player(const std::string &name);   // adds a new player to the game
            void remove_player(const std::string &name);    // removes a player after a coup




    };

}