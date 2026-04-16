#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

#include <stdexcept>

template <typename T>
class TStack {
private:
    T* arr;
    int top_index;
    int capacity;

public:
    TStack(int size) : top_index(-1), capacity(size) {
        if (size <= 0) {
            throw std::invalid_argument("Size must be positive");
        }
        arr = new T[capacity];
    }
    ~TStack() {
        delete[] arr;
    }
    
    TStack(const TStack& other) : top_index(other.top_index), capacity(other.capacity) {
        arr = new T[capacity];
        for (int i = 0; i <= top_index; i++) {
            arr[i] = other.arr[i];
        }
    }
    
    TStack& operator=(const TStack& other) {
        if (this != &other) {
            delete[] arr;
            capacity = other.capacity;
            top_index = other.top_index;
            arr = new T[capacity];
            for (int i = 0; i <= top_index; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    bool IsEmpty() const {
        return top_index == -1;
    }
    bool IsFull() const {
        return top_index == capacity - 1;
    }
    void Push(const T& value) {
        if (IsFull()) {
            throw std::overflow_error("Stack is full");
        }
        arr[++top_index] = value;
    }
    
    T Pop() {
        if (IsEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return arr[top_index--];
    }
    
        if (IsEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return arr[top_index];
    }
    
    int Size() const {
        return top_index + 1;
    }
    
    void Clear() {
        top_index = -1;
    }
};

#endif  // INCLUDE_TSTACK_H_
