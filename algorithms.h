#pragma once

#include <vector>
#include <stack>
#include "graph.h"

using namespace std;

vector<Graph::Node> BFSTraversal(Graph::Node start, map<Graph::Node, vector<Graph::Edge>> & adj_list, map<Graph::Node, bool> & visited);

vector<vector<Graph::Node>> BFSTraversal(Graph::Node start, Graph * graph);

vector<vector<Graph::Node>> kosaraju(Graph * graph);

map<Graph::Node, vector<Graph::Edge>> reverseAdjacencyList(map<Graph::Node, vector<Graph::Edge>> & adj_list);

void DFS(Graph::Node node, stack<Graph::Node> & s, map<Graph::Node, vector<Graph::Edge>> & adj_list, map<Graph::Node, bool> & visited, bool isFirst, vector<Graph::Node> & scc);

map<Graph::Node, float> betweennessCentrality(Graph * graph);

map<Graph::Node, vector<Graph::Node>> shortestPath(Graph::Node start, Graph * graph);
