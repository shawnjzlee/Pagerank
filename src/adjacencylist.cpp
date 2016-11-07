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

void AdjacencyList::set_vertex_rank(int index, function<double ()> const &calculate_rank) {
    vertex_rank.at(index) = calculate_rank();
}

void AdjacencyList::insert_edge(int source, int destination) {
    if(source == destination) return;
    
    auto temp = (source < destination ? destination : source);
    if(incoming_edges.empty()) {
        incoming_edges.resize(temp + 1, vector<int>());
        outgoing_edges.resize(temp + 1, vector<int>());
        vertex_rank.resize(temp + 1, 1.0);
    } 
    else if (incoming_edges.size() <= source || incoming_edges.size() <= destination) {
        incoming_edges.resize(temp + 1, vector<int>());
        outgoing_edges.resize(temp + 1, vector<int>());
        vertex_rank.resize(temp + 1, 1.0);
    }
    
    incoming_edges.at(destination).push_back(source);
    outgoing_edges.at(source).push_back(destination);
}

// static reference function, reference to ostream
void AdjacencyList::print_list() {
    //reference to ostream
    for(int i = 0; i < incoming_edges.size(); i++) {
        if(!incoming_edges[i].empty()) {
            cout << "Vertex: " << i << "\t";
            for(int j = 0; j < incoming_edges[i].size(); j++) {
                    cout << incoming_edges[i].at(j) << " ";
            }
            cout << endl;
        }
    }
}

void AdjacencyList::print_one_list(int index) {
    for(int i = 0; i < incoming_edges[index].size(); i++)
        cout << incoming_edges[index].at(i) << " ";
    cout << endl;
}

void AdjacencyList::print_vertex_ranks() {
    for(int i = 0; i < vertex_rank.size(); i++)
        cout << i << "\t" << vertex_rank.at(i) << endl;
    cout << endl;
}