#include "Game.hpp"
#include <string>
#include <vector>


using namespace std;
using namespace coup;

namespace coup{

    vector<string> Game::players(){
        vector<string> vec;
        return vec;
    }
    string Game::turn(){
        string str = "hi";
        return str;
    }
    string Game::winner(){
        string str = "hi";
        return str;
    }

    void Game::new_player(const std::string &name, const std::string &player_role){}   // adds a new player to the game
    void Game::remove_player(const std::string &name, const std::string &player_role){}    // removes a player after a coup

}