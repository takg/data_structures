#ifndef QUEUE_H
#define QUEUE_H

#include "SingleLinkedList.h"

template <typename T>
class Queue
{
    public:
        Queue() {}
        ~Queue() {}
        void push_back(const T& data) {
            list.push_back(data);
        }
        T pop_front() {
            return list.pop_front();
        }
        int size() const {
            return list.size();
        }

    protected:

    private:
        SingleLinkedList<T> list;
};

#endif // QUEUE_H
