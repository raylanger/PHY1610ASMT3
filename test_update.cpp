#include "updatecells.h"
#include <catch2/catch_all.hpp>

TEST_CASE("Update Test 1 - All cells alive remains all alive", "[update_all_cells]"){
    //Create initial cells
    Cells init_arr = {alive,alive,alive,alive,alive,alive,alive,alive,alive,alive,alive};

    //Use update_cells to generate next iteration
    Cells fin_arr = update_all_cells(init_arr);

    //All cells should be alive in this case
    for (bool b : fin_arr) REQUIRE(b);
}

TEST_CASE("Update Test 2 - All cells dead remains all dead", "[update_all_cells]"){
    //Create initial cells
    Cells init_arr = {dead,dead,dead,dead,dead,dead,dead,dead,dead,dead};
    
    //Use update_cells to generate next iteration
    Cells fin_arr = update_all_cells(init_arr);

    //All cells should be dead in this case
    for (bool b : fin_arr) REQUIRE(~b);
}

TEST_CASE("Update Test 3 - Single alive cell dies", "[update_all_cells]"){
    //Create initial cells
    Cells init_arr = {alive,dead,dead,dead,dead,dead,dead,dead,dead,dead};
    
    //Use update_cells to generate next iteration
    Cells fin_arr = update_all_cells(init_arr);

    //All cells should be dead in this case
    for (bool b : fin_arr) REQUIRE(~b);
}

TEST_CASE("Update Test 4 - alternating alive/dead becomes all alive - test periodic BCs", "[update_all_cells]"){
    //Create initial cells
    Cells init_arr = {dead,alive,dead,alive,dead,alive,dead,alive,dead,alive,dead,alive};
    
    //Use update_cells to generate next iteration
    Cells fin_arr = update_all_cells(init_arr);

    //All cells should be alive in this case
    for (bool b : fin_arr) REQUIRE(b);
}