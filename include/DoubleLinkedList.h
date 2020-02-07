#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

template <typename U>
class DNode {
public:
    U data;
    DNode* next;
    DNode* prev;
    DNode(const U& _data):data(_data), next(nullptr), prev(nullptr) {}
};


template <typename T>
class DoubleLinkedList
{
    typedef DNode<T>* NodePtr;
    public:
        DoubleLinkedList():head(nullptr), tail(nullptr) {}

        ~DoubleLinkedList() {
            clear();
        }

        T pop_back() {
            T data;
            data = tail->data;
            NodePtr ptr = tail;

            if (head == tail) {
                head = tail = nullptr;
            }
            else {
                tail = tail->prev;
                tail->next = nullptr;
            }
            delete ptr;
            return data;
        }

        T pop_front() {
            T data;
            data = head->data;
            NodePtr ptr = head;

            if (head == tail) {
                head = tail = nullptr;
            }
            else {
                head = head->next;
                head->prev = nullptr;
            }
            delete ptr;
            return data;
        }
        void push_back(const T& data) {
            NodePtr ptr = new DNode<T>(data);
            if (head == nullptr) {
                head = tail = ptr;
            }
            else {
                tail->next = ptr;
                ptr->prev = tail;
                tail = tail->next;
            }
        }

        void push_front(const T& data) {
            NodePtr ptr = new DNode<T>(data);
            if (head == nullptr) {
                head = tail = ptr;
            }
            else {
                ptr->next = head;
                head->prev = ptr;
                head = ptr;
            }
        }

        void print(const std::string delimiter=" ", const std::string line_delimiter="\n") const {
            for (NodePtr ptr = head ; ptr != nullptr ; ptr = ptr->next) {
                std::cout << ptr->data << delimiter;
            }

            std::cout << line_delimiter;
        }

       int size() const {
            int count = 0;
            for (NodePtr ptr = head ; ptr != nullptr ; ptr = ptr->next, ++count) {}

            return count;
        }

        void clear() {
            NodePtr ptr1 = nullptr;
            for (NodePtr ptr = head; ptr != nullptr; ptr= ptr->next ) {
                ptr1 = ptr;
                ptr = ptr->next;
                delete ptr1;
            }
            head = tail = nullptr;
        }

    protected:

    private:
        NodePtr head;
        NodePtr tail;
};

#endif // DOUBLELINKEDLIST_H
