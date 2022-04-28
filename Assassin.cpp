#include "Assassin.hpp"
#include <string>
#include <vector>

using namespace std;
using namespace coup;

namespace coup{
    void Assassin::coup(Player p1){
        // this method allows the assassin to coup players at cost of 3 coins
        // can be blocked by the Contessa

        if (!this->is_turn())
        {
            throw runtime_error("Not his turn to play!");
        }
        
        // check if the player have atleast 7 coins
        if (this->coins_counter < 3)
        {
            throw runtime_error("Need atleast 3 coins to preform Coup as Assassin");
        }
        
        
        // full round passed, no longer can be blocked
        this->_can_be_blocked = false;

        // update the player last action 
        this->_last_play = "coup";

        // remove 7 coins from the player amount
        this->set_coins(this->coins_counter - 3);

        // remove the player p1 from the game
        this->game->remove_player(p1.get_name());

        // save the player until next round in case of being blocked by Contessa
        this->couped = p1;

        // move turn
        this->game->increament_turn();
    }

    void Assassin::blocked(){
        // bring the couped player back to the game
        this->game->new_player(this->couped.get_name());
    }
}