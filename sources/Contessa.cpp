#include "Contessa.hpp"
#include "Assassin.hpp"
#include <string>
#include <vector>


using namespace std;
using namespace coup;

namespace coup{

    void Contessa::block(Player& p1){
        // this method allows Contessa to block the assassin 
        // action and bring the couped player back to life

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

        if (!this->game->is_active())
        {
            throw runtime_error("Game isn't active");
        }

        if (!(p1.role() == "Assassin"))
        {
            throw runtime_error("Contessa can only block Assassin");
        }
        if(!p1.can_be_blocked() || !(p1.get_last_play() == "coup3")){
            throw runtime_error("Assassin didn't preform coup at cost 3, therefore cannot be blocked");
        }

        // block the assassin action
        p1.blocked_by_contessa(p1.get_couped_name(), p1.get_couped_idx());
        
        
    }

}