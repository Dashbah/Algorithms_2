//
// Created by Dashbah on 26.02.2023.
//
#include <iostream>
#include <vector>

struct Room {
    int a;
    int b;
};

int compute(const std::vector<Room> &rooms) {
    std::vector<int> dp(rooms.size());
    dp[0] = rooms[0].a;
    dp[1] = std::min(std::min(rooms[0].a + rooms[1].a, rooms[0].a + rooms[0].b),
                     rooms[0].b + rooms[1].a);
    for (size_t i = 2; i < rooms.size(); ++i) {
        int val = rooms[i - 1].b;
        int min = dp[i - 2] + val;
        for (size_t j = i - 1; j >= 2; --j) {
            val += rooms[j - 1].b;
            int temp = dp[j - 2] + val;
            if (temp < min) {
                min = temp;
            }
        }
        val += rooms[0].b;
        if (val < min) {
            min = val;
        }
        min += rooms[i].a;
        dp[i] = std::min(std::min(dp[i - 1] + rooms[i - 1].b, dp[i - 1] + rooms[i].a), min);
    }
    return dp.back();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<Room> rooms(n, Room());
    for (auto &room : rooms) {
        std::cin >> room.a;
    }
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> rooms[i].b;
    }

    if (n == 0) {
        std::cout << 0;
        return 0;
    }
    if (n == 1) {
        std::cout << rooms[0].a;
        return 0;
    }

    std::cout << compute(rooms) << std::endl;

    return 0;
}
