#include "updatecells.h"
#include <catch2/catch_all.hpp>

TEST_CASE("Update Test 1 - All cells alive remains all alive", "[update_all_cells]"){
    Cells init_arr = {alive,alive,alive,alive,alive,alive,alive,alive,alive,alive,alive};
    Cells fin_arr = update_all_cells(init_arr);

    for (bool b : fin_arr) REQUIRE(b);
}
