#include "fillcells.h"
#include <iostream>
#include <catch2/catch_all.hpp>


TEST_CASE("Initalization Test 1 - num_cells = 100, target_alive_fraction = 0.25", "[initial_cells]"){
    Cells test_arr = initial_cells(100, 0.25);

    double distribution_counter = 0;
    for (int i = 1; i <= 100; i ++){
        distribution_counter += test_arr[i] - 0.25;
        REQUIRE(abs(distribution_counter) <= 1);
    }
}

TEST_CASE("Initalization Test 2 - num_cells = 80, target_alive_fraction = 1/3", "[initial_cells]"){
    Cells test_arr = initial_cells(100, 1.0/3.0);

    double distribution_counter = 0;
    for (int i = 1; i <= 80; i ++){
        distribution_counter += test_arr[i] - 1.0/3.0;
        REQUIRE(abs(distribution_counter) <= 1);
    }
}


TEST_CASE("Initalization Test 3 - num_cells = 95, target_alive_fraction = 0.1", "[initial_cells]"){
    Cells test_arr = initial_cells(100, 0.1);

    double distribution_counter = 0;
    for (int i = 1; i <= 95; i ++){
        distribution_counter += test_arr[i] - 0.1;
        REQUIRE(abs(distribution_counter) <= 1);
    }
}

TEST_CASE("Initalization Test 4 - num_cells = 42, target_alive_fraction = 13/49", "[initial_cells]"){
    Cells test_arr = initial_cells(42, 13.0/49.0);

    double distribution_counter = 0;
    for (int i = 1; i <= 42; i ++){
        distribution_counter += test_arr[i] - 13.0/49.0;
        REQUIRE(abs(distribution_counter) <= 1);
    }
}

TEST_CASE("Initalization Test 5 - num_cells = 12, target_alive_fraction = 0.6", "[initial_cells]"){
    Cells test_arr = initial_cells(12, 0.6);

    double distribution_counter = 0;
    for (int i = 1; i <= 12; i ++){
        distribution_counter += test_arr[i] - 0.6;
        REQUIRE(abs(distribution_counter) <= 1);
    }
}
