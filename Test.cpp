#include "doctest.h"
#include "Game.hpp"
#include "Player.hpp"
#include "Ambassador.hpp"
#include "Assassin.hpp"
#include "Captain.hpp"
#include "Duke.hpp"
#include "Contessa.hpp"
#include <iostream>
#include <vector>


using namespace std;
using namespace coup;

TEST_CASE("INCOME & COINS"){        // 15 tests

    // create a game 
    Game g1{};
    // add players to the game
    Duke duke{g1,"Alon"};
    Assassin assassin{g1, "Barak"};
    Ambassador ambassador{g1, "Ambassosh"};
    Captain captain{g1, "Capitano"};
    Contessa contessa{g1, "Conti"};

    // call income on Alon - Duke
    CHECK(duke.coins() == 0);   // at start, all players have 0 coins
    CHECK_NOTHROW(duke.income());  // duke turn
    CHECK(duke.coins() == 1);   // income add 1 coin to the player

    CHECK_NOTHROW(assassin.income());   // assassin turn
    CHECK_NOTHROW(ambassador.income()); // ambassador turn
    CHECK_THROWS(duke.income());    // not duke's turn -- captain turn
    CHECK_NOTHROW(captain.income());    // captain turn
    CHECK_NOTHROW(contessa.income());   // contessa turn

    // check all coins updated to 1 after income action
    CHECK(assassin.coins() == 1);
    CHECK(ambassador.coins() == 1);
    CHECK(captain.coins() == 1);
    CHECK(contessa.coins() == 1);

    // check duke income is still 1
    CHECK(duke.coins() == 1);

    CHECK_NOTHROW(duke.income());   // duke turn
    CHECK(duke.coins() == 2);   // should update to 2 

}


TEST_CASE("FOREIGN AID"){   // 14 tests

    // create a game 
    Game g1{};
    // add players to the game
    Duke duke{g1,"Alon"};
    Assassin assassin{g1, "Barak"};
    Ambassador ambassador{g1, "Ambassosh"};
    Captain captain{g1, "Capitano"};
    Contessa contessa{g1, "Conti"};

    CHECK_NOTHROW(duke.foreign_aid());  // duke turn
    CHECK(duke.coins() == 2);   // foreign aid adds 2 coins to a player

    CHECK_NOTHROW(assassin.foreign_aid());  // assassin turn
    CHECK(assassin.coins() == 2);   // foreign aid adds 2 coins to a player

    CHECK_NOTHROW(ambassador.foreign_aid());  // ambassador turn
    CHECK(ambassador.coins() == 2);   // foreign aid adds 2 coins to a player

    CHECK_NOTHROW(captain.foreign_aid());  // captain turn
    CHECK(captain.coins() == 2);   // foreign aid adds 2 coins to a player

    CHECK_NOTHROW(contessa.foreign_aid());  // contessa turn
    CHECK(contessa.coins() == 2);   // foreign aid adds 2 coins to a player

    CHECK_THROWS(assassin.foreign_aid());   // duke turn, not assassin
    CHECK_THROWS(ambassador.foreign_aid()); // duke turn, not ambassador
    CHECK_THROWS(captain.foreign_aid());    // duke turn, not captain
    CHECK_THROWS(contessa.foreign_aid());   // duke turn, not contessa

}


TEST_CASE("COUP & WINNER & PLAYERS"){

    // create a game 
    Game g1{};
    // add players to the game
    Duke duke{g1,"Alon"};
    Assassin assassin{g1, "Barak"};
    Ambassador ambassador{g1, "Ambassosh"};
    Captain captain{g1, "Capitano"};
    Contessa contessa{g1, "Conti"};

    // play until duke & assassin has atleast 7 coins
    for (size_t i = 0; i < 4; i++)
    {
        duke.foreign_aid();
        assassin.foreign_aid();
        ambassador.income();
        captain.income();
        contessa.income();
    }
    // now duke & assassin have 8 coins and the rest have 4
    
    CHECK_NOTHROW(duke.coup(contessa));     // duke coup contessa out of the game

    vector<std::string> players_left = g1.players();

    CHECK(players_left.size() == 4);    // only 4 players are left in the game

    // check that contessa is out
    for (string name : players_left)
    {
        CHECK(name != "Conti");        
    }

    CHECK(duke.coins() == 1);   // coup action cost duke 7 coins

    // assassin coup ambassador out of the game
    CHECK_NOTHROW(assassin.coup(ambassador));
    players_left = g1.players();
    CHECK(players_left.size() == 3);    // only 3 players are left in the game

    // check that ambassador is out
    for (string name : players_left)
    {
        CHECK(name != "Ambassosh");        
    }

    CHECK(assassin.coins() == 1);   // coup action cost assassin 3 coins

    // play until captain have atleast 7 coins
    captain.foreign_aid();
    duke.foreign_aid();
    assassin.foreign_aid();
    captain.foreign_aid();
    duke.foreign_aid();
    assassin.foreign_aid();
    // now captain have 8 coins and assassin have 9 coins and the rest have 5

    CHECK_NOTHROW(captain.coup(duke));     // captain coup duke out of the game
    players_left = g1.players();
    CHECK(players_left.size() == 2);    // only 2 players are left in the game

    // check that duke is out
    for (string name : players_left)
    {
        CHECK(name != "Alon");        
    }

    CHECK(captain.coins() == 1);   // coup action cost captain 7 coins
    
    // play until assassin have 10 coins
    assassin.foreign_aid();
    captain.income();
    assassin.foreign_aid();
    captain.income();
    assassin.income();
    captain.income();
    // now assassin have 10 coins and captain have 4
    
    CHECK_THROWS(assassin.income()); // assassin have 10 coins, must coup
    CHECK_THROWS(assassin.foreign_aid()); // assassin have 10 coins, must coup

    CHECK_NOTHROW(assassin.coup(captain));  // assassin coup captain out of the game, assassin won
    players_left = g1.players();
    CHECK(players_left.size() == 1);    // only 3 players are left in the game

    // check that ambassador is out
    for (string name : players_left)
    {
        CHECK(name != "Capitano");        
    }
    CHECK(assassin.coins() == 3);       // coup cost assassin 7 coins, ot 3


    CHECK_NOTHROW(g1.winner());
    CHECK(g1.winner() == "Barak");
    

}