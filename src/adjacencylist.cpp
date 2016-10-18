#include <iostream>

#include "adjacencylist.h"
//#include "global.h"

using namespace std;

AdjacencyList::AdjacencyList() {  }

AdjacencyList::~AdjacencyList() { }

void AdjacencyList::thread_data_init(int _num_threads, bool _can_share) {
    num_threads = _num_threads;
    can_share = _can_share;
}

short AdjacencyList::get_thread_id() const {
    return thread_id;
}

void AdjacencyList::set_thread_id(int thread_id) {
    this->thread_id = thread_id;
}

void AdjacencyList::create_vertex() {
    
}

void AdjacencyList::create_list(int source, int neighbor) {
    if (incoming_edges.empty()) {
        vertex_rank.push_back(1.0);
        incoming_edges.push_back(vector<int>());
        cout << "size: " << incoming_edges.size() << "; source: " << source << endl;
    }
    else if (incoming_edges.size() == source) {
        vertex_rank.push_back(1.0);
        incoming_edges.push_back(vector<int>());
        cout << "size: " << incoming_edges.size() << "; source: " << source << endl;
    }
    
    incoming_edges.at(source).push_back(neighbor);
}

void AdjacencyList::print_list() {
    for(int i = 0; i < incoming_edges.size(); i++) {
        for(int j = 0; j < incoming_edges[i].size(); j++)
            cout << incoming_edges[i].at(j) << " ";
        cout << endl;
    }
}