#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../algorithms.h"
#include "../graph.h"

TEST_CASE("Sanity check") {
    int x = 1;
    int y = 2;
    REQUIRE(x + y == 3);
}

// Graph Creation Tests

// BFS Traversal Tests

// Kosaraju's Algorithm Tests

// Betweeness-Centrality Tests