// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include <stdexcept>
#include "tstack.h"

bool isOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/';
}

int getPrecedence(char op) {
  switch (op) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    default:
      return 0;
  }
}

std::string infx2pstfx(const std::string& inf) {
  TStack<char, 100> stack;
  std::string result;

  for (size_t i = 0; i < inf.length(); ++i) {
    char c = inf[i];

    if (c == ' ') {
      continue;
    }

    if (std::isdigit(c)) {
      while (i < inf.length() && std::isdigit(inf[i])) {
        result += inf[i];
        ++i;
      }
      result += ' ';
      --i;
    } else if (c == '(') {
      stack.push(c);
    } else if (c == ')') {
      while (!stack.isEmpty() && stack.peek() != '(') {
        result += stack.pop();
        result += ' ';
      }
      if (!stack.isEmpty()) {
        stack.pop();
      }
    } else if (isOperator(c)) {
      while (!stack.isEmpty() &&
             stack.peek() != '(' &&
             getPrecedence(stack.peek()) >= getPrecedence(c)) {
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

int eval(const std::string& post) {
  TStack<int, 100> stack;

  std::string currentNumber;
  for (size_t i = 0; i <= post.length(); ++i) {
    char c = (i < post.length()) ? post[i] : ' ';

    if (std::isdigit(c)) {
      currentNumber += c;
    } else if (c == ' ' && !currentNumber.empty()) {
      stack.push(std::stoi(currentNumber));
      currentNumber.clear();
    } else if (isOperator(c)) {
      if (stack.isEmpty()) {
        throw std::runtime_error("Invalid postfix expression");
      }
      int b = stack.pop();
      if (stack.isEmpty()) {
        throw std::runtime_error("Invalid postfix expression");
      }
      int a = stack.pop();

      int result;
      switch (c) {
        case '+':
          result = a + b;
          break;
        case '-':
          result = a - b;
          break;
        case '*':
          result = a * b;
          break;
        case '/':
          if (b == 0) {
            throw std::runtime_error("Division by zero");
          }
          result = a / b;
          break;
        default:
          throw std::runtime_error("Unknown operator");
      }

      stack.push(result);
    }
  }

  if (stack.isEmpty()) {
    throw std::runtime_error("Empty expression");
  }

  int finalResult = stack.pop();
  if (!stack.isEmpty()) {
    throw std::runtime_error("Invalid postfix expression");
  }

  return finalResult;
}
