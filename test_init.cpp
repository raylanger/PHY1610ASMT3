#include "fillcells.h"
#include <iostream>
#include <fstream>
#include <catch2/catch_all.hpp>


TEST_CASE("Initalization Test 1 - num_cells = 100, target_alive_fraction = 0.25", "[initial_cells]"){
    Cells test_arr = initial_cells(100, 0.25);

    double distribution_counter = 0;
    for (int i = 1; i <= 100; i ++){
        distribution_counter += test_arr[i] - 0.25;
        REQUIRE(abs(distribution_counter) <= 1);
    }
}
