#include "Duke.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;
using namespace coup;

namespace coup{

    void Duke::block(Assassin& p1){
        // this method allows the Duke to block a foreign_aid actions of differernt players

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