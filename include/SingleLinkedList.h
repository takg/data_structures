#ifndef SINGELLINKEDLIST_H
#define SINGELLINKEDLIST_H

using namespace std;

template <typename U>
class Node {
    public:
    Node<U>* next;
    U data;

    Node() : next(nullptr) {}
    Node(const U& _data) : next(nullptr), data(_data) {}
};


template <typename T>
class SingleLinkedList
{
    typedef Node<T>* NodePtr;
    NodePtr head;
    NodePtr tail;

    public:
        SingleLinkedList():head(nullptr), tail(nullptr) {}

        void push_back(const T& data) {
            NodePtr ptr = new Node<T>(data);
            if (head == nullptr) {
                head = tail = ptr;
            }
            else {
                tail->next = ptr;
                tail = ptr;
            }
        }

        T pop_back() {
            T data = tail->data;
            NodePtr ptr1 = tail;

            if (tail == head) {
                head = tail = nullptr;
            }
            else {
                // todo: implement ++ptr
                // todo: implement another ptr to hold the prev of tail
                NodePtr ptr = head;
                while (ptr->next != tail) {
                    ptr = ptr->next;
                }
                tail = ptr;
                tail->next = nullptr;
            }

            delete ptr1;
            return data;
        }

        void push_front(const T& data) {
            NodePtr ptr = new Node<T> (data);
            if (tail == nullptr) {
                tail = head = ptr;
            }
            else {
                ptr->next = head;
                head = ptr;
            }
        }

        T pop_front() {
            NodePtr ptr = head;
            T data = ptr->data;

            if (tail == head) {
                tail = head = nullptr;
            }
            else {
                head = head->next;
            }
            delete ptr;
            return data;
        }

        int size() const {
            int count = 0;
            for (NodePtr ptr = head ; ptr != nullptr ; ptr = ptr->next, ++count) {}

            return count;
        }

        void print(const std::string delimiter=" ", const std::string line_delimiter="\n") const {
            for (NodePtr ptr = head ; ptr != nullptr ; ptr = ptr->next) {
                std::cout << ptr->data << delimiter;
            }

            std::cout << line_delimiter;
        }

        void clear() {
            NodePtr ptr = head ;
            while (ptr != nullptr) {
                NodePtr ptr1 = ptr;
                ptr = ptr->next;
                delete ptr1;
            }
            head = tail = nullptr;
        }
        ~SingleLinkedList() {
            clear();
        }

    protected:

    private:
        int count;
};

#endif // SINGELLINKEDLIST_H
