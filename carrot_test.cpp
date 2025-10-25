#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/carrot.hpp"

TEST_CASE( "it returns a v as its when it is a seedling" ) {
    Carrot carrot;
    REQUIRE( carrot.symbol() == "v" );
}

TEST_CASE( "it returns a V when the carrot is half-grown" ) {
    Carrot carrot;
    carrot.end_day();
    REQUIRE( carrot.symbol() == "V" );
}

TEST_CASE( "it returns a W when the carrot is fully grown" ) {
    Carrot carrot;
    carrot.end_day();
    carrot.end_day();
    REQUIRE( carrot.symbol() == "W" );
}

TEST_CASE( "it is not mature on day zero" ) {
    Carrot carrot;
    REQUIRE( carrot.is_mature() == false );
}

TEST_CASE( "it is not empty" ) {
    Carrot carrot;
    REQUIRE( carrot.is_empty() == false );
}

TEST_CASE( "it is mature after one day" ) {
    Carrot carrot;
    carrot.end_day();
    REQUIRE( carrot.is_mature() == true );
}