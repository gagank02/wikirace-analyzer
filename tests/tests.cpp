#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../algorithms.h"
#include "../graph.h"

#include <sstream>
#include <cassert>
#include <stdexcept>

typedef string Node;

using namespace std;

TEST_CASE("Edge") {
    Graph::Edge edge1;
    edge1.start_ = "1";
    edge1.end_ = "2";
    Graph::Edge edge2;
    edge2.start_ = "1";
    edge2.end_ = "2";

    REQUIRE(edge1 == edge2);
}

// Graph Creation Tests
TEST_CASE("Graph properly created", "[graph]") {
    Graph * g = new Graph("./tests/test_graph_data.txt");
    stringstream ss;
    g->printGraph(ss);

    REQUIRE(ss.str() == "0: 2 3\n1: 0\n2: 1\n3: 4\n4: \n");
}

TEST_CASE("Invalid file should throw error", "[graph]") {
    REQUIRE_THROWS(new Graph("./tests/test_malformed_data.txt"));
}

// BFS Traversal Tests
TEST_CASE("BFS proper traversal on connected graph", "[bfs]") {
    Graph * g = new Graph("./tests/test_data_small_connected.txt");
    vector<vector<Graph::Node>> expected{{"0", "2", "4", "3", "1"}};

    REQUIRE(expected == BFSTraversal("0", g));
}

TEST_CASE("BFS proper traversal on disconnected graph", "[bfs]") {
    Graph * g = new Graph("./tests/test_data_small_disconnected.txt");
    vector<vector<Graph::Node>> expected{{"0", "2", "4", "3", "1"}, {"5", "6"}};

    REQUIRE(expected == BFSTraversal("0", g));
}

TEST_CASE("BFS proper traversal on a graph with a single node", "[bfs]") {
    Graph * g = new Graph("./tests/test_data_single.txt");
    vector<vector<Graph::Node>> expected{{"1"}};

    REQUIRE(expected == BFSTraversal("1", g));
}

// Kosaraju's Algorithm Tests
TEST_CASE("Kosaraju's on connected graph", "[kosaraju]") {
    Graph * g = new Graph("./tests/test_data_small_connected.txt");
    vector<vector<Graph::Node>> expected{{"0"}, {"1", "2", "3"}, {"4"}};

    REQUIRE(expected == kosaraju(g));
}

TEST_CASE("Kosaraju's on disconnected graph", "[kosaraju]") {
    Graph * g = new Graph("./tests/test_data_small_disconnected.txt");
    vector<vector<Graph::Node>> expected{{"5"}, {"6"}, {"0"}, {"1", "2", "3"}, {"4"}};

    REQUIRE(expected == kosaraju(g));
}

TEST_CASE("Kosaraju's on a graph with a single node", "[kosaraju]") {
    Graph * g = new Graph("./tests/test_data_single.txt");
    vector<vector<Graph::Node>> expected{{"1"}};

    REQUIRE(expected == kosaraju(g));
}

// Betweeness-Centrality Tests
TEST_CASE("Betweenness Centrality on connected graph", "[betweenness]") {
    Graph * g = new Graph("./tests/test_data_small_connected_betweenness.txt");
    // map<Graph::Node, float> expected;

     map<Graph::Node, float> between = betweennessCentrality(g);
     for (auto it = between.begin(); it != between.end(); ++it) {
        cout << "Value of " << it->first << ": " << it->second << endl;
    }
}
