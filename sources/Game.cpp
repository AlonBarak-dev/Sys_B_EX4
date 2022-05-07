#include "Game.hpp"
#include <string>
#include <vector>
#include <iostream>

constexpr auto MAX_PLAYERS = 6;
constexpr auto MIN_PLAYERS = 2;

using namespace std;
using namespace coup;

namespace coup{

    vector<string> Game::players(){
        // return a list of all active players
        return this->players_names;
    }

    string Game::turn(){
        // return the player's name 
        if (this->turn_idx >= this->players().size())
        {
            this->turn_idx = 0;
        }
        
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

        if (this->players_names.size() != 1 || !this->started)
        {
            // throw
            throw runtime_error("No winner yet");
        }
        
        // return the last player on the list
        this->active = false;
        return this->players_names.at(0);
        
        
    }

    void Game::new_player(const std::string &name){
        // adds a new player to the game
        this->players_names.push_back(name);
        if (this->players_names.size() >= MIN_PLAYERS)
        {
            this->active = true;
        }
        if (this->players_names.size() > MAX_PLAYERS)
        {
            throw runtime_error("2-6 Players only!");
        }
        if (this->started)
        {
            throw runtime_error("Game already started!");
        }
        
        
        
    }   

    bool Game::is_active() const{
        return this->active;
    }

    void Game::remove_player(const std::string &name){
        // removes a player after a coup
        for (size_t i = 0; i < this->players_names.size(); i++)
        {
            if (this->players_names.at(i) == name)
            {
                this->players_names.erase(this->players_names.begin()+(int)i);
                if(i < turn_idx){
                    this->turn_idx--;
                    if (this->turn_idx == -1)
                    {
                        this->turn_idx = 0;
                    }
                }
                return;
            }
        }
    }

    void Game::back_2_life(const string &name, int index){
        // this method brings back players that couped and saved
        this->players_names.insert(this->players_names.begin()+index, name);

    }

    bool Game::in_game(const string &player_name){
        for (size_t i = 0; i < this->players_names.size(); i++)
        {
            if (this->players_names.at(i) == player_name)
            {
                return true;
            }
        }
        return false;
        
    }

    int Game::get_turn_idx() const{
        return this->turn_idx;
    }

    bool Game::is_on() const{
        return this->started;
    }

    void Game::start_game(){
        this->started = true;
    }

}