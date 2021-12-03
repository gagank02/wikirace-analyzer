#pragma once

#include <vector>
#include "graph.h"

using namespace std;

void bfs_traversal(Graph::Node start, map<Graph::Node, vector<Graph::Edge>> & adj_list, map<Graph::Node, bool> & visited, vector<Graph::Node> &result);
vector<Graph::Node> bfs_traversal(Graph::Node start, Graph * graph);

