#ifndef ADJACENCY_H
#define ADJACENCY_H

#include <map>
#include <tuple>
#include <vector>

#include "thread_data.h"
using namespace std;

class AdjacencyList : public ThreadData {
    public:
        AdjacencyList();
        ~AdjacencyList();
        
        void thread_data_init(int, bool);
        short get_thread_id() const;
        void set_thread_id(int);
        
        void create_vertex();
        void create_list();
        
    private:
        map <int, vector<int>> incoming_edges;    // map of edge list <vertex id, incoming vertices>
        vector <double> vertex_rank;            // vector stores vertex rank
        
        char buff[100];
};

#endif /* adjacencylist.h */