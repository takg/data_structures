#ifndef STACK_H
#define STACK_H

#include "SingleLinkedList.h"

template <typename T>
class Stack
{
    public:
        Stack() {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
        ~Stack() {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
        void push(const T& data) {
            //std::cout << __PRETTY_FUNCTION__ << std::endl;
            list.push_front(data);
            return;
        }
        T pop() {
            //std::cout << __PRETTY_FUNCTION__ << std::endl;
            return list.pop_front();
        }
        int size() const {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            return list.size();
        }
    private:
        SingleLinkedList<T> list;
};

#endif // STACK_H
