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
            bool operator== (const Edge& other) const {
                return start_ == other.start_ && end_ == other.end_;
            }
        };

        Graph(string filepath);

        // Need to add destructor and/or big 3

        void printGraph(std::ostream& output);

        void createAdjacencyList(string filepath);

        map<Node, vector<Edge>> & getAdjacencyList();

    private:
        map<Node, vector<Edge>> adjacency_list_;

        void addNode(Node node);
        
        void addEdge(Node start, Node end);
};