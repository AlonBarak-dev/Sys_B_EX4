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
            bool started;


        public:

            Game(){
                this->turn_idx = 0;
                this->active = false;
                this->started = false;
            }    // constructor

            ~Game(){}   // destructor

            std::string turn();     // return the player turn
            void increament_turn();
            std::vector<std::string> players(); // list of players
            std::string winner();   // tells the winner if exist
            void new_player(const std::string &name);   // adds a new player to the game
            void remove_player(const std::string &name);    // removes a player after a coup
            void back_2_life(const std::string &name, int index);       // bring players back to the game
            bool in_game(const std::string &player_name);   // checks if a player is in the game
            int get_turn_idx() const;
            bool is_active() const;
            void start_game();
            bool is_on() const;


    };

}