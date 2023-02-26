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
        dp[i] = std::min(std::min(dp[i - 1] + rooms[i - 1].b, dp[i - 1] + rooms[i].a),
                         dp[i - 2] + rooms[i - 1].b + rooms[i].a);
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
