#include "graph.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

Graph::Graph(string filepath) {
    createAdjacencyList(filepath);
}

void Graph::createAdjacencyList(string filepath) {
    ifstream infile(filepath);

    if (!infile) {
        cout << "Error during parsing" << endl;
    }

    string line;
    string delimiter = ",";
    while (getline(infile, line)) {
        size_t pos = line.find(delimiter);
        string key = line.substr(0, line.find(delimiter));
        string value = line.substr(line.find(delimiter) + 1, line.length());

        // cout << "key: " << key << endl;
        // cout << "value: " << value << endl;


        // Node keyNode;
        // keyNode.data_ = key;
        // Node valueNode;
        // valueNode.data_ = value;
        
        addNode(key);
        addNode(value);
        addEdge(key, value);
    }
}

void Graph::addNode(Node node) {
    adjacency_list_.insert({node, vector<Edge>(0)});

    // cout << "Adding node: " << node << endl;
    // cout << "# keys: " << adjacency_list_.size() << endl;
}

void Graph::addEdge(Node start, Node end) {
    // cout << "Edge start: " << start << endl;
    // cout << "Edge end: " << end << endl;
    vector<Edge> & edges = adjacency_list_.at(start);
    for (Edge edge : edges) {
        if (edge.end_ == end) {
            return;
        }
    }

    Edge edge;
    edge.start_ = start;
    edge.end_ = end;
    edges.push_back(edge);
}

map<Graph::Node, vector<Graph::Edge>> & Graph::getAdjacencyList() {
    return adjacency_list_;
}

// bool Graph::Node::operator<(const Node & other) const {
//     return data_ < other.data_;
// }

// bool Graph::Node::operator!=(const Node & other) const {
//     return data_ != other.data_;
// }
