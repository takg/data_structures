#include <iostream>
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
#include "Vector.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

template <typename T>
void testList(T& list) {
    for (int loop = 10 ; loop > 0 ; --loop) {
        list.push_back(loop);
    }
    std::cout << "push_back ::";
    list.print();

    for (int loop = 20 ; loop > 10 ; --loop) {
        list.push_front(loop);
    }
    std::cout << "push_front ::";
    list.print();

    std::cout << "pop_back ::";
    for (int loop = 0 ; loop < 10 ; ++loop) {
        std::cout<< list.pop_back() << " ";
    }
    std::cout << std::endl;

    std::cout << "pop_front ::";
    for (int loop = 0 ; loop < 10 ; ++loop) {
        std::cout<< list.pop_front() << " ";
    }
    std::cout << std::endl;

    std::cout << "push_back ::";
    for (int loop = 10 ; loop > 0 ; --loop) {
    list.push_back(loop);
    }
    list.print();
    std::cout << "List size ::" << list.size();
    list.clear();
    list.print();
}

template <typename T>
void testVector(Vector<T>& vec) {
    const int size = 20;
    for (int loop = 0 ; loop < size ; ++ loop ) {
        vec.push_back(loop);
    }

    std::cout << "Vector contents::";
    for (int loop = 0 ; loop < size ; ++ loop ) {
        std::cout << vec[loop] << " ";
    }
    std::cout << std::endl;

    return;
}

template <typename T>
void testStack(Stack<T>& stack) {
    for (int loop = 0; loop < 10; ++loop) {
        stack.push(loop);
    }
    std::cout << "Stack::pop()" ;
    for (int loop = 0; loop < 10; ++loop) {
        std::cout << stack.pop() << " ";
    }
    std::cout<<endl;
}

template <typename T>
void testQueue(Queue<T>& queue) {
    for (int loop = 0; loop < 10; ++loop) {
        queue.push_back(loop);
    }
    std::cout << "Queue::pop_front()" ;
    for (int loop = 0; loop < 10; ++loop) {
        std::cout << queue.pop_front() << " ";
    }
    std::cout<<endl;
}
int main()
{
    cout << "Single Linked List!" << endl;
    SingleLinkedList<int> slist;
    testList(slist);

    cout << endl << "Double Linked List!" << endl;
    DoubleLinkedList<int> dlist;
    testList(dlist);

    cout << endl << "Vector!" << endl;
    Vector<int> vec;
    testVector(vec);

    cout << endl << "Stack!" << endl;
    Stack<int> stack;
    testStack(stack);

    cout << endl << "Queue!" << endl;
    Queue<int> queue;
    testQueue(queue);
    return 0;
}
