// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int getPriority(char op) {
    switch (op) {
        case '(': return 0;
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        default: return -1;
    }
}

std::string infx2pstfx(const std::string& inf) {
    TStack<char, 100> stack;
    std::string result;
    for (size_t i = 0; i < inf.length(); i++) {
        char c = inf[i];
        if (isdigit(c)) {
            while (i < inf.length() && isdigit(inf[i])) {
                result += inf[i];
                i++;
            }
            result += ' ';
            i--;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.get() != '(') {
                result += stack.pop();
                result += ' ';
            }
            if (!stack.isEmpty() && stack.get() == '(') {
                stack.pop();
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!stack.isEmpty() && getPriority(stack.get()) >= getPriority(c)) {
                result += stack.pop();
                result += ' ';
            }
            stack.push(c);
        }
    }
    while (!stack.isEmpty()) {
        result += stack.pop();
        result += ' ';
    }
    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }
    return result;
}
int eval(const std::string& pref) {
  TStack<int, 100> stack;
    for (size_t i = 0; i < post.length(); i++) {
        char c = post[i];
        if (isdigit(c)) {
            int number = 0;
            while (i < post.length() && isdigit(post[i])) {
                number = number * 10 + (post[i] - '0');
                i++;
            }
            stack.push(number);
            i--;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = stack.pop();
            int a = stack.pop();
            int res;
            if (c == '+') {
                res = a + b;
            } else if (c == '-') {
                res = a - b;
            } else if (c == '*') {
                res = a * b;
            } else {
                res = a / b;
            }
            stack.push(res);
        }
    }
    return stack.pop();
}
