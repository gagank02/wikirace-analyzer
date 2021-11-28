#pragma once

#include <map>
#include <vector>
#include <string>

using namespace std;

class Graph {
    public:
        struct Node {
            string data_;
            bool operator<(const Node &) const;
        };

        struct Edge {
            Node start_;
            Node end_;
        };


        Graph(string filepath);

        void createAdjacencyList(string filepath);

        map<Node, vector<Edge>> getMap();

    private:
        map<Node, vector<Edge>> adjacency_list_;

        void addNode(Node node);
        
        void addEdge(Node start, Node end);
};