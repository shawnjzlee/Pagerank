#include <iostream>
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

#include "adjacencylist.h"

using namespace std;
using namespace std::chrono;

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
        
        // cout << source << " " << neighbor << endl;
        
        pagerank.create_list(source, neighbor);
    }
}

int main(int argc, char *argv[]) {
    string dataset = argv[1];
    
    AdjacencyList pagerank;
    
    parse_data(pagerank, dataset);
}

