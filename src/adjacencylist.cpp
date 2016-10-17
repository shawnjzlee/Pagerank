#include <iostream>

#include "adjacencylist.h"
//#include "global.h"

using namespace std;

AdjacencyList::AdjacencyList() { }

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

void AdjacencyList::create_list() {
}