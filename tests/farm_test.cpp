#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/player.hpp"
#include "../src/farm.hpp"
#include "../src/carrot.hpp"

TEST_CASE( "it can be initialized with a single plot" ) {
    Player player;
    Farm farm(1, 1, &player);
    REQUIRE( farm.number_of_rows() == 1 );
    REQUIRE( farm.number_of_columns() == 1 );
}

TEST_CASE( "it can be initialized as a 1x2 farm" ) {
    Player player;
    Farm farm(1, 2, &player);
    REQUIRE( farm.number_of_rows() == 1 );
    REQUIRE( farm.number_of_columns() == 2 );
}

TEST_CASE( "it can be initialized as a 2x1 farm" ) {
    Player player;
    Farm farm(2, 1, &player);
    REQUIRE( farm.number_of_rows() == 2 );
    REQUIRE( farm.number_of_columns() == 1 );
}

TEST_CASE( "it returns the symbol for a single soil plot" ) {
    Player player;
    Farm farm(1, 1, &player);
    REQUIRE( farm.get_symbol(0, 0) == "@" );
}

TEST_CASE( "it returns the symbols for a 1x2 farm" ) {
    Player player;
    Farm farm(1, 2, &player);
    REQUIRE( farm.get_symbol(0, 0) == "@" );
    REQUIRE( farm.get_symbol(0, 1) == "." );
}

TEST_CASE( "it returns the symbols for a 2x1 farm" ) {
    Player player;
    Farm farm(2, 1, &player);
    REQUIRE( farm.get_symbol(0, 0) == "@" );
    REQUIRE( farm.get_symbol(1, 0) == "." );
}

TEST_CASE( "it allows us to plant a carrot" ) {
    Player player;
    Farm farm(1, 2, &player);
    Carrot carrot;
    farm.plant(0, 1, &carrot);
    REQUIRE( farm.get_symbol(0, 1) == "v" );
}

TEST_CASE( "it starts on day 1" ) {
    Player player;
    Farm farm(1, 1, &player);
    REQUIRE( farm.get_current_day() == 1 );
}

TEST_CASE( "it increments day when ending day" ) {
    Player player;
    Farm farm(1, 1, &player);
    farm.end_day();
    REQUIRE( farm.get_current_day() == 2 );
}

TEST_CASE( "it increments day multiple times" ) {
    Player player;
    Farm farm(1, 1, &player);
    farm.end_day();
    farm.end_day();
    farm.end_day();
    REQUIRE( farm.get_current_day() == 4 );
}

TEST_CASE( "it reports that empty soil can be planted" ) {
    Player player;
    Farm farm(1, 2, &player);
    REQUIRE( farm.can_plant(0, 1) == true );
}

TEST_CASE( "it reports that occupied soil cannot be planted" ) {
    Player player;
    Farm farm(1, 2, &player);
    Carrot *carrot = new Carrot();
    farm.plant(0, 1, carrot);
    REQUIRE( farm.can_plant(0, 1) == false );
}

TEST_CASE( "it prevents planting on occupied plots" ) {
    Player player;
    Farm farm(1, 2, &player);
    Carrot *carrot1 = new Carrot();
    Carrot *carrot2 = new Carrot();
    farm.plant(0, 1, carrot1);
    farm.plant(0, 1, carrot2);
    REQUIRE( farm.get_symbol(0, 1) == "v" );
    delete carrot2;  // Clean up since it wasn't planted
}

TEST_CASE( "it reports that empty soil cannot be harvested" ) {
    Player player;
    Farm farm(1, 2, &player);
    REQUIRE( farm.can_harvest(0, 1) == false );
}

TEST_CASE( "it reports that immature plants cannot be harvested" ) {
    Player player;
    Farm farm(1, 2, &player);
    Carrot *carrot = new Carrot();
    farm.plant(0, 1, carrot);
    REQUIRE( farm.can_harvest(0, 1) == false );
}

TEST_CASE( "it reports that mature plants can be harvested" ) {
    Player player;
    Farm farm(1, 2, &player);
    Carrot *carrot = new Carrot();
    farm.plant(0, 1, carrot);
    farm.end_day();
    REQUIRE( farm.can_harvest(0, 1) == true );
}

TEST_CASE( "it allows harvesting of mature plants" ) {
    Player player;
    Farm farm(1, 2, &player);
    Carrot *carrot = new Carrot();
    farm.plant(0, 1, carrot);
    farm.end_day();
    farm.harvest(0, 1);
    REQUIRE( farm.get_symbol(0, 1) == "." );
}

TEST_CASE( "it prevents harvesting empty plots" ) {
    Player player;
    Farm farm(1, 2, &player);
    farm.harvest(0, 1);
    REQUIRE( farm.get_symbol(0, 1) == "." );
}