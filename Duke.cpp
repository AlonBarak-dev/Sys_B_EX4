#include "Duke.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;
using namespace coup;

namespace coup{

    void Duke::block(Player& p1){
        // this method allows the Duke to block a foreign_aid actions of differernt players

        //check that the players are active
        if (!this->is_active() || !p1.is_active())
        {
            throw runtime_error("The players aren't active");
        }

        // check if both players play in the same game
        if (this->get_game() != p1.get_game())
        {
            throw runtime_error("Players must be from the same game");
        }

        if (p1.can_be_blocked() && p1.get_last_play() == "foreign aid")
        {
            // can be blocked
            p1.blocked();
            p1.set_coins(p1.coins() - 2);   // p1 returns the money back

        }
        else{
            throw runtime_error("Cannot be Blocked!");
        }
    }

    void Duke::tax(){

        // check if the player is active
        if (!this->active)
        {
            throw runtime_error("The player isn't active");
        }

        // this method allows the Dukw to tax 3 coins, cannot be blocked
        if (!this->is_turn())
        {
            throw runtime_error("Not his turn to play!");
        }

        // update that the Duke cannot be blocked
        this->_can_be_blocked = false;

        // add 3 coins to the Duke
        this->set_coins(this->coins() + 3);

        // update the Duke last move to "tax"
        this->_last_play = "tax";

        // move the turn to the next player
        this->game->increament_turn();
        
    }

}