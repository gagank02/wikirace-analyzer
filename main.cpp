#include "graph.h"
#include "algorithms.h"
#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
    // Graph * g = new Graph("./data/test_bfs_small_data.txt");
    Graph * g = new Graph("./data/test_betweenness_data.txt");
    // cout << "Adj list size: " << g->getAdjacencyList().size() << endl;
    //vector<vector<Graph::Node>> bfs = BFSTraversal("0", g);
    //cout << "bfs size: " << bfs.size() << endl;
    

    // for (size_t i = 0; i < bfs.size(); i++) {
    //     for (size_t j = 0; j < bfs[i].size(); j++) {
    //         cout << bfs[i][j] << endl;
    //     }
    //     //cout << "Component done" << endl;
    // }

    

    //vector<vector<Graph::Node>> kosa = kosaraju(g);
    /*
    for (vector<Graph::Node> nodes : kosa) {
        for (size_t i = 0; i < nodes.size(); i++) {
            cout << nodes[i] << " ";
        }
        cout << endl;
    }
    */

    
    //map<Graph::Node, vector<Graph::Node>> paths = shortestPath("6", g);
    // for (auto it = paths.begin(); it != paths.end(); ++it) {
    //     cout << it->first << endl;
    //     for (unsigned i = 0; i < it->second.size(); i++) {
    //         cout << it->second[i] << endl;
    //     }
    //     cout << "End Path" << endl;
    // }

    map<Graph::Node, float> between = betweennessCentrality(g);
    for (auto it = between.begin(); it != between.end(); ++it) {
        cout << "Value of " << it->first << ": " << it->second << endl;
    }

    
    //map<Graph::Node, float> between = betweennessCentrality(g);

    return 0;
}