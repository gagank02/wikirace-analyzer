#pragma once

#include <map>
#include <vector>
#include <string>

using namespace std;

class Graph {
    public:
        typedef string Node;

        struct Edge {
            Node start_;
            Node end_;
        };

        Graph(string filepath);

        void createAdjacencyList(string filepath);

        map<Node, vector<Edge>> & getAdjacencyList();

    private:
        map<Node, vector<Edge>> adjacency_list_;

        void addNode(Node node);
        
        void addEdge(Node start, Node end);
};