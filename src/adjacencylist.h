#ifndef ADJACENCY_H
#define ADJACENCY_H

#include <map>
#include <tuple>
#include <vector>
#include <functional>

#include "thread_data.h"
using namespace std;

class AdjacencyList : public ThreadData {
    public:
        AdjacencyList();
        ~AdjacencyList();
        
        void thread_data_init(int, bool);
        short get_thread_id() const;
        void set_thread_id(int);
        
        void set_vertex_rank(int, function<double ()> const&);
        
        void create_list(int, int);
        
        void print_list();
        void print_one_list(int);
        void print_vertex_ranks();
    
    // temporary
    // private:
        vector <vector<int>> incoming_edges;
        vector <vector<int>> outgoing_edges;
        vector <double> vertex_rank;
        
        char buff[100];
};

#endif /* adjacencylist.h */