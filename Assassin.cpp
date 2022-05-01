#include "Assassin.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;
using namespace coup;

namespace coup{
    void Assassin::coup(Player& p1){
        // this method allows the assassin to coup players at cost of 3 coins
        // can be blocked by the Contessa

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

        if (!this->is_turn())
        {
            throw runtime_error("Not his turn to play!");
        }
        
        // check if the player have atleast 3 coins
        if (this->coins_counter < 3)
        {
            throw runtime_error("Need atleast 3 coins to preform Coup as Assassin");
        }
        
        
        // can be blocked by the Contessa
        this->_can_be_blocked = true;

        // update the player last action 
        this->_last_play = "coup";

        // remove 3 coins from the player amount
        this->set_coins(this->coins_counter - 3);

        // save the player until next round in case of being blocked by Contessa
        this->couped = p1.get_name();
        for (size_t i = 0; i < this->game->players().size(); i++)
        {
            if (this->game->players().at(i) == p1.get_name())
            {
                this->couped_idx = (int)i;
                break;
            }
        }
        

        // remove the player p1 from the game
        this->game->remove_player(p1.get_name());

        // move turn
        this->game->increament_turn();
    }

}