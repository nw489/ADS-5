// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_


template<typename T, int size>
class TStack {
 private:
  static constexpr int kStackSize = size;
  T data[kStackSize];
  int topIndex;

 public:
  TStack() : topIndex(0) {}

  bool isEmpty() const {
    return topIndex == 0;
  }

  bool isFull() const {
    return topIndex >= kStackSize;
  }

  void push(const T& value) {
    if (!isFull()) {
      data[topIndex++] = value;
    }
  }

  T pop() {
    if (!isEmpty()) {
      return data[--topIndex];
    }
    throw std::runtime_error("Stack is empty");
  }

  const T& peek() const {
    if (!isEmpty()) {
      return data[topIndex - 1];
    }
    throw std::runtime_error("Stack is empty");
  }
};

#endif  // INCLUDE_TSTACK_H_
