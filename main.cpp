#include "graph.h"
#include "algorithms.h"
#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
    // Graph * g = new Graph("./data/test_bfs_small_data.txt");

    // cout << "Adj list size: " << g->getAdjacencyList().size() << endl;
    // vector<Graph::Node> bfs = BFSTraversal("0", g);
    // cout << "bfs size: " << bfs.size() << endl;
    

    // for (size_t i = 0; i < bfs.size(); i++) {
    //     cout << bfs[i] << endl;
    // }

    Graph * g = new Graph("./data/parsed_test.txt");

    vector<vector<Graph::Node>> kosa = kosaraju(g);

    for (vector<Graph::Node> nodes : kosa) {
        for (size_t i = 0; i < nodes.size(); i++) {
            cout << nodes[i] << " ";
        }
        cout << endl;
    }

    return 0;
}