#include "Player.hpp"
#include <vector>
#include <string>
#include <iostream>
constexpr auto MAX_COINS = 10;
constexpr auto COUP_COST =  7;
using namespace std;
using namespace coup;

namespace coup{

    void Player::income(){
        // this method adds 1 coin to the player and cannot be blocked
        

        if (!this->game->is_active())
        {
            throw runtime_error("Game isn't active");
        }
        

        if (!this->is_turn())
        {
            throw runtime_error("Not his turn to play!");
        }

        if (this->has_to_coup())
        {
            throw runtime_error("This Player must Coup");
        }

        // check if the player is active
        if (!this->is_active())
        {
            throw runtime_error("The player isn't active");
        }
        
        if (!this->game->is_on())
        {
            this->game->start_game();
        }
        
        // a full round passed, player cannot be blocked anymore
        if (this->can_be_blocked())
        {
            this->_can_be_blocked = false;  
        }
        
        // add 1 coin to the player
        this->set_coins(this->coins_counter + 1);

        // write the player last play
        this->_last_play = "income";

        // move turn
        this->game->increament_turn();


    }

    int Player::coins() const{
        // return the amount of coins the player have at the moment
        return this->coins_counter;
    }

    void Player::foreign_aid(){
        // this method adds 2 coins to the player and can be blocked

        if (!this->game->is_active())
        {
            throw runtime_error("Game isn't active");
        }

        if (!this->is_turn())
        {
            throw runtime_error("Not his turn to play!");
        }

        if (this->has_to_coup())
        {
            throw runtime_error("This Player must Coup");
        }

        // check if the player is active
        if (!this->is_active())
        {
            throw runtime_error("The player isn't active");
        }

        if (!this->game->is_on())
        {
            this->game->start_game();
        }

        this->_can_be_blocked = true;   // the player can be blocked for a full round
        
        // add 2 coins to the player 
        this->set_coins(this->coins_counter + 2);

        // write the player last play
        this->_last_play = "foreign aid";

        // move turn
        this->game->increament_turn();
        
    }


    string Player::role(){
        // return the player role, e.g "Duke"
        return this->_role;
    }

    bool Player::is_turn(){
        // checks if the turn at the moment belongs to the player
        return this->game->turn() == this->_name;
    }

    bool Player::has_to_coup() const{
        // check if the next play must be coup
        return this->coins() >= MAX_COINS;
    }

    bool Player::can_be_blocked() const{
        // checks if the player can be blocked base on his last action
        return this->_can_be_blocked;
    }

    string Player::get_name() const{
        return this->_name;
    }

    void Player::coup(Player &p1){
        // this method allows a player to remove other players from the game
        // this method cannot be blocked, but cost 7 coins

        if (!this->game->is_active())
        {
            throw runtime_error("Game isn't active");
        }
        
        // check if the player is active
        if (!this->is_active() || !p1.is_active())
        {
            throw runtime_error("The player isn't active");
        }

        if (!this->is_turn())
        {
            throw runtime_error("Not his turn to play!");
        }
        
        // check if the player have atleast 7 coins
        if (this->coins_counter < COUP_COST)
        {
            throw runtime_error("Need atleast 7 coins to preform Coup");
        }
        

        // check if both players play in the same game
        if (this->get_game() != p1.get_game())
        {
            throw runtime_error("Players must be from the same game");
        }
        
        
        // full round passed, no longer can be blocked
        this->_can_be_blocked = false;

        // update the player last action 
        this->_last_play = "coup";

        // remove 7 coins from the player amount
        this->set_coins(this->coins_counter - COUP_COST);

        // move turn
        this->game->increament_turn();

        // remove the player p1 from the game
        this->game->remove_player(p1.get_name());

        p1.deactivate();

    }

    string Player::get_last_play() const{
        // return the player's last move
        return this->_last_play;
    }

    void Player::blocked(){
        // in case the player gets blocked, update his status
        this->_can_be_blocked = false;
    }

    void Player::set_coins(int amount){
        // set the coins amount to a new amount
        this->coins_counter = amount;
    }

    void Player::blocked_by_contessa(const std::string &name, int index){
        this->game->back_2_life(this->couped, this->couped_idx);
        this->_can_be_blocked = false;
        if (this->game->get_turn_idx() >= index)
        {
            this->game->increament_turn();
        }
        
    }
    
    std::string Player::get_couped_name() const{
        return this->couped;

    }
    
    int Player::get_couped_idx() const{
        return this->couped_idx;
    }

    coup::Game* Player::get_game() const{
        return this->game;
    }

    void Player::deactivate(){
        this->active = false;
    }

    void Player::activate(){
        this->active = true;
    }

    bool Player::is_active() const{
        return this->game->in_game(this->_name);
    }

    void Player::block_steal(){
        // this method allows Captain/Ambassador to block the Captain from stealing

        // check if the players are still active
        if (!this->is_active() || !this->looted_from->is_active())
        {
            throw runtime_error("The player isn't active");
        }

        // return the money from captain to the victim
        this->set_coins(this->coins() - this->amount);
        this->looted_from->set_coins(this->looted_from->coins() + amount);

        // cannot be blocked on stealing again
        this->_can_be_blocked = false;
    }

}