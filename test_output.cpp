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

TEST_CASE("Ouput Test 2 - 10 cells, all dead, step 10", "[output_cells]"){
    Cells test_arr = {dead,dead,dead,dead,dead,dead,dead,dead,dead,dead};

    std::ofstream out("output_test_2.txt");
    output_cells(out, 10, test_arr);
    out.close();

    std::ifstream in_test("output_test_2.txt");
    std::ifstream in_true("output_true_2.txt");

    std::string s_test;
    std::getline(in_test, s_test);

    std::string s_true;
    std::getline(in_true, s_true);
    
    REQUIRE(s_test == s_true);
}

TEST_CASE("Ouput Test 3 - 15 cells, alternating dead/alive, step 100", "[output_cells]"){
    Cells test_arr = {dead,alive,dead,alive,dead,alive,dead,alive,dead,alive,dead,alive,dead,alive,dead};

    std::ofstream out("output_test_3.txt");
    output_cells(out, 100, test_arr);
    out.close();

    std::ifstream in_test("output_test_3.txt");
    std::ifstream in_true("output_true_3.txt");

    std::string s_test;
    std::getline(in_test, s_test);

    std::string s_true;
    std::getline(in_true, s_true);
    
    REQUIRE(s_test == s_true);
}

TEST_CASE("Ouput Test 4 - 1 cells, dead, step 1", "[output_cells]"){
    Cells test_arr = {dead};

    std::ofstream out("output_test_4.txt");
    output_cells(out, 1, test_arr);
    out.close();

    std::ifstream in_test("output_test_4.txt");
    std::ifstream in_true("output_true_4.txt");

    std::string s_test;
    std::getline(in_test, s_test);

    std::string s_true;
    std::getline(in_true, s_true);
    
    REQUIRE(s_test == s_true);
}

TEST_CASE("Ouput Test 5 - 20 cells, no special configuration, step 1", "[output_cells]"){
    Cells test_arr = {dead,dead,alive,dead,alive,alive,alive,dead,dead,alive,dead,dead,dead,dead,alive,alive,dead,alive,alive,dead};

    std::ofstream out("output_test_5.txt");
    output_cells(out, 1, test_arr);
    out.close();

    std::ifstream in_test("output_test_5.txt");
    std::ifstream in_true("output_true_5.txt");

    std::string s_test;
    std::getline(in_test, s_test);

    std::string s_true;
    std::getline(in_true, s_true);
    
    REQUIRE(s_test == s_true);
}