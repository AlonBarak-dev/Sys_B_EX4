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

TEST_CASE("INCOME"){        // 15 tests

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
