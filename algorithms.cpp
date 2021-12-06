#include "algorithms.h"
#include <map>
#include <queue>

#include <iostream>

using namespace std;

void BFSTraversal(Graph::Node start, map<Graph::Node, vector<Graph::Edge>> & adj_list, map<Graph::Node, bool> & visited, vector<Graph::Node> &result) {
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

vector<Graph::Node> BFSTraversal(Graph::Node start, Graph * graph) {
    map<Graph::Node, bool> visited;
    map<Graph::Node, vector<Graph::Edge>> adj_list = graph->getAdjacencyList();
    for (auto it = adj_list.begin(); it != adj_list.end(); ++it) {
        visited.insert({it->first, false});
    }

    vector<Graph::Node> result;
    BFSTraversal(start, adj_list, visited, result);

    for (auto it = visited.begin(); it != visited.end(); ++it) {
        if (!(it->second)) {
            BFSTraversal(it->first, adj_list, visited, result);
        }
    }
    
    return result;
 }

 vector<vector<Graph::Node>> kosaraju(Graph * graph) {
    // setup
    vector<vector<Graph::Node>> result;
    stack<Graph::Node> s;

    map<Graph::Node, bool> visited;
    map<Graph::Node, vector<Graph::Edge>> adj_list = graph->getAdjacencyList();
    for (auto it = adj_list.begin(); it != adj_list.end(); ++it) {
        visited.insert({it->first, false});
    }

    map<Graph::Node, bool> reverse_visited;
    map<Graph::Node, vector<Graph::Edge>> reverse_adj_list = reverseAdjacencyList(adj_list);
    for (auto it = reverse_adj_list.begin(); it != reverse_adj_list.end(); ++it) {
        reverse_visited.insert({it->first, false});
    }

    // Start of Kosaraju's algorithm
    for (auto it = visited.begin(); it != visited.end(); ++it) {
        if (!it->second) {
            vector<Graph::Node> placeholder;
            DFS(it->first, s, adj_list, visited, true, placeholder);
        }
    }

    while (!s.empty()) {
        Graph::Node currNode = s.top();
        s.pop();

        if (!reverse_visited.at(currNode)) {
            vector<Graph::Node> scc;
            DFS(currNode, s, reverse_adj_list, reverse_visited, false, scc);
            result.push_back(scc);
        }
    }

    return result;
 }

map<Graph::Node, vector<Graph::Edge>> reverseAdjacencyList(map<Graph::Node, vector<Graph::Edge>> & adj_list) {
    map<Graph::Node, vector<Graph::Edge>> reversed;

    for (auto it = adj_list.begin(); it != adj_list.end(); ++it) {
        for (Graph::Edge edge : it->second) {
            Graph::Node start = edge.start_;
            Graph::Node end = edge.end_;
            if (!(reversed.count(end))) { // key doesnt exists
                reversed.insert({end, vector<Graph::Edge>(0)});
            }
            Graph::Edge e;
            e.start_ = end;
            e.end_ = start;
            reversed.at(end).push_back(e);
        }
    }

    return reversed;
}

void DFS(Graph::Node node, stack<Graph::Node> & s, map<Graph::Node, vector<Graph::Edge>> & adj_list, map<Graph::Node, bool> & visited, bool isFirst, vector<Graph::Node> & scc) {
    visited.at(node) = true;

    if (!isFirst) {
        scc.push_back(node);
    }

    vector<Graph::Edge> edges = adj_list.at(node);
    for (size_t i = 0; i < edges.size(); i++) {
        Graph::Node currNeigbor = edges[i].end_;
        if (!visited.at(currNeigbor)) {
            DFS(currNeigbor, s, adj_list, visited, isFirst, scc);
        }
    }
    
    if (isFirst) {
        s.push(node);
    }
}
