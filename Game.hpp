#pragma once
#include <string>
#include <vector>



namespace coup{

    class Game{

        private:
            std::vector<std::string> players_list;   // list of all active players names
            std::string player_turn;
            bool active;    // tells if the game is still active


        public:

            Game(){}
            ~Game(){}

            std::string turn();
            std::vector<std::string> players();
            std::string winner();





    };

}