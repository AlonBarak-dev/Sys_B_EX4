#include "Ambassador.hpp"
#include <string>
#include <vector>

using namespace std;
using namespace coup;

namespace coup{

    void Ambassador::block(Player &p1){
        // this method allows the Ambassador to block the captain from stealing money

        //check that the players are active
        if (!this->is_active() || !p1.is_active())
        {
            throw runtime_error("The players aren't active");
        }

        // check that the players are from the same game
        if (this->get_game() != p1.get_game())
        {
            throw runtime_error("Players must be from the same game");
        }

        if (!this->game->is_active())
        {
            throw runtime_error("Game isn't active");
        }

        // check that the player is a Captain 
        if (p1.role() != "Captain")
        {
            throw runtime_error("Can only Block Captains");
        }

        // check the Captain last move
        if (!p1.can_be_blocked() || p1.get_last_play() != "steal")
        {
            throw runtime_error("Ambassador can only block stealing actions");
        }

        // block the Captain
        p1.block_steal();
        
    }

    void Ambassador::transfer(Player &p1, Player &p2){
        // this method allows the Ambassador to transfer 1 coin from 
        // one player to another w/o being blocked

        // check if the players are active
        if (!this->is_active() || !p1.is_active() || !p2.is_active())
        {
            throw runtime_error("The players aren't active");
        }

        // check if the players play in the same game
        if (this->get_game() != p1.get_game() || this->get_game() != p2.get_game() || p1.get_game() != p2.get_game())
        {
            throw runtime_error("Players must be from the same game");
        }

        // check that p1 has atleast 1 coin
        if (p1.coins() < 1)
        {
            throw runtime_error("PLayer 1 must have atleast 1 coin to his name");
        }

        if (!this->game->is_on())
        {
            this->game->start_game();
        }

        // transfer 1 coin from p1 to p2
        p1.set_coins(p1.coins() - 1);
        p2.set_coins(p2.coins() + 1);

        // update Ambassador last play and move the turn to the next player
        this->_last_play = "transfer";
        this->get_game()->increament_turn();
        
    }

}