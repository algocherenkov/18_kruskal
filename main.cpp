#include "kruskal.h"
#include <string>
#include <ctime>
#include <chrono>
#include <random>
#include <iterator>
#include <map>

#define BOOST_TEST_MODULE test_main

#include <boost/test/included/unit_test.hpp>

using namespace boost::unit_test;
BOOST_AUTO_TEST_SUITE(test_suite_main)

/*graph for test purposes was taken from lecture*/

BOOST_AUTO_TEST_CASE(Demukron_sort_and_Tarian_sort_test)
{
    std::vector<std::vector<std::pair<int, int>>> testGraph;
    std::vector<std::pair<int, int>> temp;
    temp.emplace_back(1, 7);
    temp.emplace_back(3, 5);
    testGraph.push_back(temp);
    temp.clear();

    temp.emplace_back(0, 7);
    temp.emplace_back(2, 8);
    temp.emplace_back(3, 9);
    temp.emplace_back(4, 7);
    testGraph.push_back(temp);
    temp.clear();

    temp.emplace_back(1, 8);
    temp.emplace_back(4, 5);
    testGraph.push_back(temp);
    temp.clear();

    temp.emplace_back(0, 5);
    temp.emplace_back(1, 9);
    temp.emplace_back(4, 15);
    temp.emplace_back(5, 6);
    testGraph.push_back(temp);
    temp.clear();

    temp.emplace_back(1, 7);
    temp.emplace_back(2, 5);
    temp.emplace_back(3, 15);
    temp.emplace_back(5, 8);
    temp.emplace_back(6, 9);
    testGraph.push_back(temp);
    temp.clear();

    temp.emplace_back(3, 6);
    temp.emplace_back(4, 8);
    temp.emplace_back(6, 11);
    testGraph.push_back(temp);
    temp.clear();

    temp.emplace_back(5, 11);
    temp.emplace_back(4, 9);
    testGraph.push_back(temp);
    temp.clear();

    auto result = graphs::kruskalSkeleton(testGraph);

    BOOST_CHECK_MESSAGE(result.size() == 6, "wrong result size");
    BOOST_CHECK_MESSAGE(result[0].w == 5, "wrong edge's weight");
    BOOST_CHECK_MESSAGE(result[1].w == 5, "wrong edge's weight");
    BOOST_CHECK_MESSAGE(result[2].w == 6, "wrong edge's weight");
    BOOST_CHECK_MESSAGE(result[3].w == 7, "wrong edge's weight");
    BOOST_CHECK_MESSAGE(result[4].w == 7, "wrong edge's weight");
    BOOST_CHECK_MESSAGE(result[5].w == 9, "wrong edge's weight");

}
BOOST_AUTO_TEST_SUITE_END()
