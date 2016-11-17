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

void rank_distribution(AdjacencyList& graph) {
    double difference = 1.0, max_difference = 1.0;
    int iteration = 0;
    while (max_difference > 0.01) {
        for (int i = 0; i < graph.incoming_edges.size(); i++) {
            double temp = graph.vertex_rank.at(i);
            double new_rank = 0.0;
            graph.set_vertex_rank(i, 
                [&](void)->double {
                    for(int j = 0; j < graph.incoming_edges[i].size(); j++) {
                        new_rank += (double)graph.vertex_rank.at(graph.incoming_edges[i].at(j));
                    }
                    new_rank = (0.15 + (0.85 * new_rank)) / graph.outgoing_edges[i].size();
                    return new_rank;
                }
            );
            difference = abs(double(temp - new_rank));
            // cout << "Difference: " << difference << " ";
            if (difference < max_difference) {
                max_difference = difference;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    string dataset = argv[1];
    AdjacencyList graph (dataset);
    
    rank_distribution(graph);
    graph.print_vertex_ranks();
}

