#include "updatecells.h"
#include <catch2/catch_all.hpp>

TEST_CASE("Update Test 1 - All cells alive remains all alive", "[update_all_cells]"){
    Cells init_arr = {alive,alive,alive,alive,alive,alive,alive,alive,alive,alive,alive};
    Cells fin_arr = update_all_cells(init_arr);

    for (bool b : fin_arr) REQUIRE(b);
}

TEST_CASE("Update Test 2 - All cells dead remains all dead", "[update_all_cells]"){
    Cells init_arr = {dead,dead,dead,dead,dead,dead,dead,dead,dead,dead};
    Cells fin_arr = update_all_cells(init_arr);

    for (bool b : fin_arr) REQUIRE(~b);
}

TEST_CASE("Update Test 3 - Single alive cell dies", "[update_all_cells]"){
    Cells init_arr = {dead,dead,dead,dead,alive,dead,dead,dead,dead,dead};
    Cells fin_arr = update_all_cells(init_arr);

    for (bool b : fin_arr) REQUIRE(~b);
}

TEST_CASE("Update Test 4 - alternating alive/dead becomes all alive", "[update_all_cells]"){
    Cells init_arr = {dead,alive,dead,alive,dead,alive,dead,alive,dead,alive,dead,alive};
    Cells fin_arr = update_all_cells(init_arr);

    for (bool b : fin_arr) REQUIRE(b);
}