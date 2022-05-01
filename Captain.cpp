#include "Captain.hpp"
#include <string>
#include <vector>

using namespace std;
using namespace coup;

namespace coup{
    void Captain::block(Player &p1){
        // this method allows the Captain to block the captain from stealing money

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

        // check that the player is a Captain 
        if (p1.role() != "Captain")
        {
            throw runtime_error("Can only Block Captains");
        }

        // check the Captain last move
        if (!p1.can_be_blocked() || p1.get_last_play() != "steal")
        {
            throw runtime_error("Captain can only block stealing actions");
        }

        // block the Captain
        p1.block_steal();
    }

    void Captain::steal(Player &p1){
        // this method allows the Captain to steal 2 coins from another player
        // can be blocked by amassador/captain

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

        // transfer 1 coins from p1 to the captain
        if (p1.coins() == 1)
        {
            this->set_coins(this->coins() + 1);
            p1.set_coins(0);
            this->amount = 1;
        }
        // transfer 2 coins from p1 to the captain
        else if(p1.coins() >= 2){
            this->set_coins(this->coins() + 2);
            p1.set_coins(p1.coins() - 2);    
            this->amount = 2;        
        }
        else{
            this->amount = 0;
        }

        // rememeber p1 for a full round
        this->looted_from = &p1;

        // update last play and able blocks from other players
        this->_last_play = "steal";
        this->_can_be_blocked = true;

        // move the turn to the next
        this->get_game()->increament_turn();
    }
}