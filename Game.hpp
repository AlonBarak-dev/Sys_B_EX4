#pragma once
#include <string>
#include <vector>
#include <unordered_map>
//#include "Player.hpp"


namespace coup{

    class Game{

        private:
            std::vector<std::string> players_names;   // list of all active players names
            unsigned int turn_idx;
            std::unordered_map<std::string, std::string> players_map;      // pairs of names and players rolee e.g (Alon, Captain)
            bool active;    // tells if the game is still active


        public:

            Game(){}    // constructor
            ~Game(){}   // destructor

            std::string turn();     // return the player turn
            std::vector<std::string> players(); // list of players
            std::string winner();   // tells the winner if exist
            void new_player(const std::string &name, const std::string &player_role);   // adds a new player to the game
            void remove_player(const std::string &name, const std::string &player_role);    // removes a player after a coup




    };

}