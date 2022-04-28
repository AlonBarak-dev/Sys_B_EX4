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

        if (!(p1.role() == "Assassin"))
        {
            throw runtime_error("Contessa can only block Assassin");
        }
        else if(!p1.can_be_blocked() || !(p1.get_last_play() == "coup")){
            throw runtime_error("Assassin didn't preform coup, therefore cannot be blocked");
        }

        // block the assassin action
        p1.blocked_by_contessa(p1.get_couped_name(), p1.get_couped_idx());;
        
        
    }

}