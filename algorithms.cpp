#include "algorithms.h"
#include <map>
#include <queue>

using namespace std;

void bfs_traversal(Graph::Node start, map<Graph::Node, vector<Graph::Edge>> & adj_list, map<Graph::Node, bool> & visited, vector<Graph::Node> &result) {

    queue<Graph::Node> q;
    q.push(start);
    visited.at(start) = true;
    
    while (!q.empty()) {
        Graph::Node curr = q.front();
        q.pop();
        result.push_back(curr);
        for (size_t i = 0; i < adj_list.at(curr).size(); i++) {
            if (!visited.at(adj_list.at(curr)[i].end_)) {
                q.push(adj_list.at(curr)[i].end_);
                visited.at(adj_list.at(curr)[i].end_) = true;
            }
        }
    }
}

vector<Graph::Node> bfs_traversal(Graph::Node start, Graph * graph) {
    map<Graph::Node, bool> visited;
    map<Graph::Node, vector<Graph::Edge>> adj_list = graph->getAdjacencyList();
    for (auto it = adj_list.begin(); it != adj_list.end(); ++it) {
        visited.insert({it->first, false});
    }

    vector<Graph::Node> result;
    bfs_traversal(start, adj_list, visited, result);

    for (auto it = visited.begin(); it != visited.end(); ++it) {
        if (!(it->second)) {
            bfs_traversal(it->first, adj_list, visited, result);
        }
    }
    
    return result;
 }
