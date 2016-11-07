#include <iostream>
#include <ios>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>

#include <thread>
#include <chrono>
#include <cstdio>
#include <functional>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include <cmath>

#include "adjacencylist.h"

using namespace std;
using namespace std::chrono;

void rank_distribution(AdjacencyList& pagerank) {
    double difference = 1.0, max_difference = 1.0;
    int iteration = 0;
    while (max_difference > 0.01) {
        for (int i = 0; i < pagerank.incoming_edges.size(); i++) {
            double temp = pagerank.vertex_rank.at(i);
            double new_rank = 0.0;
            pagerank.set_vertex_rank(i, 
                [&](void)->double {
                    for(int j = 0; j < pagerank.incoming_edges[i].size(); j++) {
                        new_rank += (double)pagerank.vertex_rank.at(pagerank.incoming_edges[i].at(j));
                    }
                    new_rank = (0.15 + (0.85 * new_rank)) / pagerank.outgoing_edges[i].size();
                    cout << new_rank << " ";
                    return new_rank;
                }
            );
            difference = abs(double(temp - new_rank));
            // cout << "Difference: " << difference << " ";
            if (difference < max_difference) {
                max_difference = difference;
            }
        }
        cout << "Iteration " << iteration++ << " completed" << endl;
    }
}

void parse_data(AdjacencyList &pagerank, string dataset) {
    ifstream instream;
    instream.open(dataset.c_str());
    if(!instream.is_open()) {
        throw std::runtime_error(string("Could not open file ") + dataset);
    }
    
    string line;
    int source, neighbor;
    while(getline(instream, line)) {
        if(line.at(0) == '#') continue; 
        stringstream ss(line);
        ss >> source >> neighbor;
        
        pagerank.insert_edge(source, neighbor);
    }
    
}

int main(int argc, char *argv[]) {
    string dataset = argv[1];
    AdjacencyList pagerank;
    
    parse_data(pagerank, dataset);
    rank_distribution(pagerank);
    pagerank.print_vertex_ranks();
}

