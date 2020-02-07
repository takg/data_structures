#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector
{
    public:
        Vector():array(nullptr), _size(0),capacity(10) {
            resize();
        }

        void push_back(const T& data) {
            if (_size < capacity-1) {
                array[_size] = data;
                ++_size;
            }
            else {
                resize();
                push_back(data);
            }
            return;
        }

        T& operator[](int index) {
            return array[index];
        }

        const T& operator[](int index) const {
            return array[index];
        }

        void clear() {
            delete array;
            array = nullptr;
        }

        int size() const{
            return _size;
        }

        ~Vector() {
            clear();
        }

    private:
        void resize() {
            std::cout << "Vector::resize(" << capacity << ", " << 2*capacity << ")\n" ;
            T* ptr = new T[2*capacity];

            std::copy(array, array+_size, ptr);
            delete[] array;
            array = ptr;
            capacity = 2*capacity;
        }
        T* array;
        int _size;
        int capacity;
};

#endif // VECTOR_H
