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

void rank_distribution(AdjacencyList pagerank) {
    double difference = 1.0, max_difference = 1.0;
    while (max_difference > 0.0001) {
        for (int i = 0; i < pagerank.incoming_edges.size(); i++) {
            double temp = pagerank.vertex_rank.at(i);
            double new_rank = 0.0;
            pagerank.set_vertex_rank(i, 
                [&](void)->double {
                    for(int j = 0; j < pagerank.incoming_edges[i].size(); j++) {
                        new_rank += (double)pagerank.vertex_rank.at(pagerank.incoming_edges[i].at(j));
                    }
                    new_rank = 0.15 + (0.85 * (new_rank / pagerank.outgoing_edges[i].size()));
                    // cout << new_rank << " ";
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

void parse_data(AdjacencyList pagerank, string dataset) {
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
        
        pagerank.create_list(source, neighbor);
    }
    
    rank_distribution(pagerank);
    // pagerank.print_list();
    // cout << pagerank.incoming_edges.size() << endl;
    pagerank.print_one_list(0);
    pagerank.print_one_list(1);
    pagerank.print_one_list(2);
    pagerank.print_one_list(3);
    pagerank.print_one_list(4);
    pagerank.print_one_list(5);
    pagerank.print_one_list(6);
    pagerank.print_one_list(7);
    pagerank.print_one_list(8);
    pagerank.print_one_list(9);
    pagerank.print_one_list(10);
    pagerank.print_vertex_ranks();
}

int main(int argc, char *argv[]) {
    string dataset = argv[1];
    
    AdjacencyList pagerank;
    
    parse_data(pagerank, dataset);
}

