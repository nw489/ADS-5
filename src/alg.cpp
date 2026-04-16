// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

std::string infx2pstfx(std::string infix) {
    TStack<char> stack(100);
    std::string postfix = "";
    
    for (char c : infix) {
        if (c >= '0' && c <= '9') {
            postfix += c;
            postfix += ' ';
        }
        else if (c == '(') {
            stack.Push(c);
        }
        else if (c == ')') {
            while (!stack.IsEmpty() && stack.Top() != '(') {
                postfix += stack.Pop();
                postfix += ' ';
            }
            if (!stack.IsEmpty()) {
                stack.Pop();
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!stack.IsEmpty() && stack.Top() != '(' && 
                   getPriority(stack.Top()) >= getPriority(c)) {
                postfix += stack.Pop();
                postfix += ' ';
            }
            stack.Push(c);
        }
    }
    
    while (!stack.IsEmpty()) {
        postfix += stack.Pop();
        postfix += ' ';
    }
    
    if (!postfix.empty() && postfix.back() == ' ') {
        postfix.pop_back();
    }
    
    return postfix;
}
int eval(std::string postfix) {
    TStack<int> stack(100);
    std::string num = "";
    
    for (char c : postfix) {
        if (c >= '0' && c <= '9') {
            num += c;
        }
        else if (c == ' ') {
            if (!num.empty()) {
                stack.Push(std::stoi(num));
                num = "";
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = stack.Pop();
            int a = stack.Pop();
            int result;
            
            switch (c) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default: result = 0;
            }
            
            stack.Push(result);
        }
    }
    
    return stack.Pop();
}
