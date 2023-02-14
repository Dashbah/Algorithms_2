//
// Created by Dashbah on 18.10.2022.
//
// OK

#include <iostream>
#include <vector>
#include <algorithm>

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    if (b % a == 0) {
        return a;
    }
    if (a > b) {
        return gcd(a % b, b);
    }
    return gcd(a, b % a);
}

std::vector<int> primeDivisors(int num) {
    std::vector<int> answer;
    int d = 2;
    while (d * d <= num) {
        if (num % d == 0) {
            answer.emplace_back(d);
            num /= d;
        } else {
            d += 1;
        }
    }
    if (num > 1) {
        answer.emplace_back(num);
    }
    return answer;
}

int maxPrimeDivisor(int num) {
    int max = 1;
    for (auto item : primeDivisors(num)) {
        if (item > max) {
            max = item;
        }
    }
    return max;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    int nod = gcd(a, b);
    a /= nod;
    b /= nod;
    int a_result = maxPrimeDivisor(a);
    int b_result = maxPrimeDivisor(b);
    int result = (a_result > b_result) ? a_result : b_result;
    std::cout << result * nod;
}