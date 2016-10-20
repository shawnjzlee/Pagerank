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
    // cout << "Source: " << source << "\t Neighbor: " 
    //      << neighbor << "\t IE.size(): " << incoming_edges.size() << endl;
    if(incoming_edges.empty()) {
        if (source == neighbor) return;
        else if(source < neighbor) {
            incoming_edges.resize(neighbor + 1, vector<int>());
            vertex_rank.resize(neighbor + 1, 1.0);
        }
        else {
            incoming_edges.resize(source, vector<int>());
            vertex_rank.resize(source, 1.0);
        }
    } 
    else if (incoming_edges.size() <= source || incoming_edges.size() <= neighbor) {
        if (source == neighbor) return;
        else if (source < neighbor) {
            incoming_edges.resize(neighbor + 1, vector<int>());
            vertex_rank.resize(neighbor + 1, 1.0);
        }
        else {
            incoming_edges.resize(source + 1, vector<int>());
            vertex_rank.resize(source + 1, 1.0);
        }
    }
    
    incoming_edges.at(source).push_back(neighbor);
}

void AdjacencyList::print_list() {
    for(int i = 0; i < incoming_edges.size(); i++) {
        for(int j = 0; j < incoming_edges[i].size(); j++) {
                cout << incoming_edges[i].at(j) << " ";
        }
        if(!incoming_edges[i].empty())
            cout << endl;
    }
}