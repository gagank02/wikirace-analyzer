#include "graph.h"
#include "algorithms.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char** argv) {
    // string filepath = argv[1];
    // string starting_node = argv[2]; // needed for BFS Traversal

    // Graph * g = new Graph(filepath);
    // cout << "Graph (Start Node: Adjacent Nodes):" << endl;
    // g->printGraph(cout);


    // // BFS Traversal
    // cout << endl;
    // cout << "BFS Traversal:" << endl;
    // vector<vector<Graph::Node>> bfs = BFSTraversal(starting_node, g);    
    // for (size_t i = 0; i < bfs.size(); i++) {
    //     cout << "Component " << i + 1 << ": ";
    //     for (size_t j = 0; j < bfs[i].size(); j++) {
    //         cout << bfs[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // // Kosaraju's Algorithm
    // cout << endl;
    // cout << "Kosaraju's Algorithm:" << endl;
    // vector<vector<Graph::Node>> kosa = kosaraju(g);
    // for (vector<Graph::Node> nodes : kosa) {
    //     for (size_t i = 0; i < nodes.size(); i++) {
    //         cout << nodes[i] << " ";
    //     }
    //     cout << endl;
    // }

    // // Betweenness Centrality
    // cout << endl;
    // cout << "Betweenness Centrality: " << endl;
    // map<Graph::Node, float> between = betweennessCentrality(g);
    // for (auto it = between.begin(); it != between.end(); ++it) {
    //     cout << "Value of " << it->first << ": " << it->second << endl;
    // }

    Graph *h = new Graph("./data/parsed.txt");
    map<Graph::Node, float> answer = betweennessCentrality(h);
    //vector<vector<Graph::Node>> bfs = BFSTraversal("10th_century", h); 
    // vector<vector<Graph::Node>> kosa = kosaraju(h);
    std::ofstream outfile("./betweenness_output.txt");
    if (outfile.is_open())
    {
        for(auto& scores : answer) {
            outfile << scores.first << ": " << scores.second <<'\n';
        }
        // for (size_t i = 0; i < bfs.size(); i++) {
        //     outfile << "Strongly Conn " << i + 1 << ": \n";
        //     for (size_t j = 0; j < bfs[i].size(); j++) {
        //         outfile << bfs[i][j] << "\n";
        //     }
        //     outfile << endl;
        // }
        
        // for (size_t i = 0; i < kosa.size(); i++) {
        //     outfile << "Strongly Connected Component " << i + 1 << ": \n";
        //     for (size_t j = 0; j < kosa[i].size(); j++) {
        //         outfile << kosa[i][j] << "\n";
        //     }
        //     outfile << endl;
        // }
        outfile.flush();
        outfile.close();
    }
    else
    {
        std::cerr << "didn't write" << std::endl;
    }
    
    return 0;
}