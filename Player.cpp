#include "Player.hpp"
#include <vector>
#include <string>

using namespace std;
using namespace coup;

namespace coup{

    void Player::income(){
        // this method adds 1 coin to the player and cannot be blocked

        if (!this->is_turn())
        {
            throw runtime_error("Not his turn to play!");
        }

        if (this->has_to_coup())
        {
            throw runtime_error("This Player must Coup");
        }
        

        // a full round passed, player cannot be blocked anymore
        if (this->can_be_blocked())
        {
            this->_can_be_blocked = false;  
        }
        
        // add 1 coin to the player
        this->coins_counter++;

        // write the player last play
        this->_last_play = "income";

    }

    int Player::coins() const{
        // return the amount of coins the player have at the moment
        return this->coins_counter;
    }

    void Player::foreign_aid(){
        // this method adds 2 coins to the player and can be blocked
        if (!this->is_turn())
        {
            throw runtime_error("Not his turn to play!");
        }

        if (this->has_to_coup())
        {
            throw runtime_error("This Player must Coup");
        }

        this->_can_be_blocked = true;   // the player can be blocked for a full round
        
        // add 2 coins to the player 
        this->coins_counter += 2;

        // write the player last play
        this->_last_play = "foreign aid";
        
    }


    string Player::role(){
        // return the player role, e.g "Duke"
        return this->_role;
    }

    bool Player::is_turn(){
        // checks if the turn at the moment belongs to the player
        return this->game.turn() == this->_name;
    }

    bool Player::has_to_coup(){
        // check if the next play must be coup
        return this->coins() >= 10;
    }

    bool Player::can_be_blocked(){
        // checks if the player can be blocked base on his last action
        return this->_can_be_blocked;
    }

    string Player::get_name(){
        return this->_name;
    }

    void Player::coup(Player p1){
        // this method allows a player to remove other players from the game
        // this method cannot be blocked, but cost 7 coins
        
        if (!this->is_turn())
        {
            throw runtime_error("Not his turn to play!");
        }
        
        // check if the player have atleast 7 coins
        if (this->coins_counter < 7)
        {
            throw runtime_error("Need atleast 7 coins to preform Coup");
        }
        
        
        // full round passed, no longer can be blocked
        this->_can_be_blocked = false;

        // update the player last action 
        this->_last_play = "coup";

        // remove 7 coins from the player amount
        this->coins_counter -=7;

        // remove the player p1 from the game
        this->game.remove_player(p1.get_name(), p1.role());

    }

}