#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T>
class TStack {
private:
    T* data;
    int max_size;
    int top_idx;

public:
    TStack(int size) : max_size(size), top_idx(-1) {
        data = new T[max_size];
    }
    
    ~TStack() {
        delete[] data;
    }
    
    bool IsEmpty() const {
        return top_idx == -1;
    }
    
    bool IsFull() const {
        return top_idx == max_size - 1;
    }
    
    void Push(const T& value) {
        if (!IsFull()) {
            data[++top_idx] = value;
        }
    }
    
    T Pop() {
        if (!IsEmpty()) {
            return data[top_idx--];
        }
        return T();
    }
    
    T Top() const {
        if (!IsEmpty()) {
            return data[top_idx];
        }
        return T();
    }
    
    int Size() const {
        return top_idx + 1;
    }
    
    void Clear() {
        top_idx = -1;
    }
};

#endif  // INCLUDE_TSTACK_H_
