#include "outputcells.h"
#include <fstream>
#include <iostream>
#include <catch2/catch_all.hpp>

TEST_CASE("Ouput Test 1 - 10 cells, all alive, step 1", "[output_cells]"){
    Cells test_arr = {alive,alive,alive,alive,alive,alive,alive,alive,alive,alive};

    std::ofstream out("output_test_1.txt");
    output_cells(out, 1, test_arr);
    out.close();

    std::ifstream in_test("output_test_1.txt");
    std::ifstream in_true("output_true_1.txt");

    std::string s_test;
    std::getline(in_test, s_test);

    std::string s_true;
    std::getline(in_true, s_true);
    
    REQUIRE(s_test == s_true);
}