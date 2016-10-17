#ifndef THREAD_DATA_H
#define THREAD_DATA_H

using namespace std;

class ThreadData {
    public:
        virtual void thread_data_init(int, bool) = 0;
        virtual short get_thread_id() const = 0;
        virtual void set_thread_id(int) = 0;
        
    protected:
        short thread_id;
        int num_threads;
        
        bool is_shared;
        bool can_share;
        
    private:
};

#endif /* thread_data.h */