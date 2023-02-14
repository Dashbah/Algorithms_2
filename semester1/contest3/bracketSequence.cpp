#include <iostream>
#include <stack>
//
// Created by Dashbah on 04.10.2022.
//
int main() {
    char bracket;
    std::stack<char> stack;
    while (std::cin >> bracket) {
        if (bracket == '(' || bracket == '{' || bracket == '[') {
            stack.push(bracket);
        } else {
            switch (bracket) {
                case ')': {
                    if (stack.top() != '(') {
                        std::cout << "NO";
                        return 0;
                    } else {
                        stack.pop();
                    }
                    break;
                }
                case '}': {
                    if (stack.top() != '{') {
                        std::cout << "NO";
                        return 0;
                    } else {
                        stack.pop();
                    }
                    break;
                }
                case ']': {
                    if (stack.top() != '[') {
                        std::cout << "NO";
                        return 0;
                    } else {
                        stack.pop();
                    }
                    break;
                }
            }
            //            if (stack.top() == bracket) {
            //                stack.pop();
            //            } else {
            //                std::cout << "NO";
            //                return 0;
            //            }
        }
    }
    if (!stack.empty()) {
        std::cout << "NO";
    } else {
        std::cout << "YES";
    }
    return 0;
}