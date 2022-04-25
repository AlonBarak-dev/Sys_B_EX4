#pragma once
#include <string>
#include <vector>
#include <unordered_map>
//#include "Player.hpp"


namespace coup{

    class Game{

        private:
            std::vector<std::string> players_names;   // list of all active players names
            //std::unordered_map<std::string, coup::Player> players_map;      // pairs of names and player objects e.g (Alon, Captain)
            std::string player_turn;    // the name of the player that this is his turn to play
            bool active;    // tells if the game is still active


        public:

            Game(){}    // constructor
            ~Game(){}   // destructor

            std::string turn();     // return the player turn
            std::vector<std::string> players(); // list of players
            std::string winner();   // tells the winner if exist
            //void new_player(coup::Player* p1, std::string name);   // adds a new player to the game




    };

}