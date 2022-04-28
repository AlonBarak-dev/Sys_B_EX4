#include "Game.hpp"
#include <string>
#include <vector>
#include <iostream>


using namespace std;
using namespace coup;

namespace coup{

    vector<string> Game::players(){
        // return a list of all active players
        return this->players_names;
    }

    string Game::turn(){
        // return the player's name 
        return this->players_names.at((size_t)this->turn_idx);
    }

    void Game::increament_turn(){
        // this method moves the turn to the next player
        this->turn_idx++;
        if (this->turn_idx == this->players_names.size())
        {
            this->turn_idx = 0;
        }
    }

    string Game::winner(){
        // this method return the winner name if exist
        // throws error if not

        if (this->players_names.size() != 1)
        {
            // throw
            throw runtime_error("No winner yet");
        }
        else{
            // return the last player on the list
            this->active = false;
            return this->players_names.at(0);
        }
        
    }

    void Game::new_player(const std::string &name){
        // adds a new player to the game
        this->players_names.push_back(name);
    }   



    void Game::remove_player(const std::string &name){
        // removes a player after a coup
        for (int i = 0; i < this->players_names.size(); i++)
        {
            if (this->players_names.at((size_t)i) == name)
            {
                this->players_names.erase(this->players_names.begin()+i);
                return;
            }
            
        }
    }

    void Game::back_2_life(const string &name, int index){
        // this method brings back players that couped and saved
        this->players_names.insert(this->players_names.begin()+index, name);

    }

}