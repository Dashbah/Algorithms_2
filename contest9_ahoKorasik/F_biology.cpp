//
// Created by Dashbah on 07.04.2023.
//
#include <cstring>
#include <vector>
#include <iostream>
#include <queue>

const int kN = static_cast<int>(1e6) + 1;
const int kAlphabet = 26;

int getNum(char c) {
    return int(c) - int('a');
}

struct Node {
    int length = 0, link = -1, term_link = -1, go[kAlphabet];
    bool is_terminal = false;
    int pch = -1, parent = -1;

    Node(int len = 0, int ch = -1, int par = -1) : length(len), pch(ch), parent(par) {
        memset(go, -1, sizeof(go));
    }
};

std::vector<Node> states(kN);
int total = 0, cur = 0, depth[kN], in[kN], out[kN];
std::vector<int> word_start[kN];

void addString(const std::string &tmp) {
    int cur_node = 0;
    for (size_t i = 0; i < tmp.size(); i++) {
        if (states[cur_node].go[(getNum(tmp[i]))] == -1) {
            states[cur_node].go[(getNum(tmp[i]))] = ++total;
            states[total] = Node(states[cur_node].length + 1, getNum(tmp[i]), cur_node);
        }
        cur_node = states[cur_node].go[(getNum(tmp[i]))];
    }
    states[cur_node].is_terminal = true;
}

void dfs(int now) {
    in[now] = ++cur;
    for (int i = 0; i < static_cast<int>(word_start[now].size()); ++i) {
        depth[word_start[now][i]] = depth[now] + 1;
        dfs(word_start[now][i]);
    }
    out[now] = ++cur;
}

bool isParent(int u, int v) {
    return (in[u] <= in[v]) && (out[v] <= out[u]);
}

int getAns(int u, int v) {
    return isParent(v, u) ? depth[u] - depth[v] : -1;
}

int go(int v, int c);

int link(int v) {
    if (states[v].link == -1) {
        if (states[v].length == 0 || states[v].length == 1) {
            states[v].link = 0;
        } else {
            states[v].link = go(link(states[v].parent), states[v].pch);
        }
    }
    return states[v].link;
}

int go(int v, int c) {
    if (states[v].go[c] == -1) {
        if (v == 0) {
            states[v].go[c] = 0;
        } else {
            states[v].go[c] = go(link(v), c);
        }
    }
    return states[v].go[c];
}

void bfs(int v) {
    std::queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (auto child : states[current].go) {
            if (child != -1) {
                q.push(child);
            }
        }
        int lin = link(current);
        states[current].term_link = states[lin].term_link;
        if (states[lin].is_terminal) {
            states[current].term_link = lin;
        }

        for (int k = 0; k < kAlphabet; ++k) {
            go(current, k);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string tmp;
        std::cin >> tmp;
        addString(tmp);
    }
    bfs(0);
    std::string tmp;
    std::cin >> tmp;
    n = tmp.size();
    bool terminal_position[kN];
    memset(terminal_position, false, sizeof(terminal_position));
    int lin, cur = 0;
    for (int i = 0; i < n; ++i) {
        lin = cur = states[cur].go[(getNum(tmp[i]))];
        if (!states[lin].is_terminal) {
            lin = states[lin].term_link;
        }
        while (lin != 0 && lin != -1) {
            terminal_position[i - states[lin].length + 1] = true;
            word_start[i + 1].push_back(i - states[lin].length + 1);
            lin = states[lin].term_link;
        }
    }

    for (int i = n; i >= 0; --i) {
        if (!terminal_position[i]) {
            dfs(i);
        }
    }

    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        std::cout << getAns(u - 1, v) << std::endl;
    }
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int sum = 0, t, a, b, c, d, e, l, r;
        std::cin >> t >> a >> b >> c >> d >> e >> l >> r;
        for (int j = 0; j < t; ++j) {
            int ans = getAns(std::min(l % n, r % n), std::max(l % n, r % n) + 1);
            if (ans != -1) {
                sum = (sum + ans) % e;
            }
            l = (a * l + b) % e, r = (c * r + d + ans) % e;
        }
        std::cout << sum << std::endl;
    }
    return 0;
}