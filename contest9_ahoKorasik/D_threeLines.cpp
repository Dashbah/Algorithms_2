//
// Created by Dashbah on 07.04.2023.
//
#include <iostream>
#include <vector>

int n;
int alphabet = 26;

int getNum1(char symbol) {
    return int(symbol) - int('a');
}

struct Node {
    std::vector<Node *> next;
    int i = 1e9, j = -1, length = 0;
    bool chosen = false, is_terminal = false;
    int child = 0;

    Node(int64_t len = 0) {
        next.assign(alphabet, nullptr);
    }
};

std::vector<Node *> good;

class Bor {
public:
    Bor() {
        root = new Node(0);
        root->chosen = true;
        root->i = 1;
        root->j = n + 1;
    }

    void addString(const std::string &str, int word, int index_recovery) {
        Node *cont = root;
        for (int i = 0; i < static_cast<int>(str.size()); ++i) {
            if (!cont->next[getNum1(str[i])]) {
                cont->next[getNum1(str[i])] = new Node(getNum1(i + 1));
                cont->child += 1;
            }
            cont->next[getNum1(str[i])]->length = cont->length + 1;
            cont = cont->next[getNum1((str[i]))];
            if (word == 1) {
                cont->i = std::min(1 + index_recovery, cont->i);
                if (cont->j > 0 && cont->i != 1e9 && !cont->chosen &&
                    (cont->is_terminal || cont->child >= 1)) {
                    good.push_back(cont);
                    cont->chosen = true;
                }
            } else {
                cont->j = std::max(1 + index_recovery, cont->j);
                if (cont->j > 0 && cont->i != 1e9 && !cont->chosen &&
                    (cont->is_terminal || cont->child >= 1)) {
                    good.push_back(cont);
                    cont->chosen = true;
                }
            }
        }
        cont->is_terminal = true;
    }
    Node *root;
};

std::vector<std::vector<int>> fun(const std::string &str1, const std::string &str2) {
    std::vector<std::vector<int>> d(n + 1, std::vector<int>(n + 1));
    std::vector<std::vector<int>> p(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        int k = i, j = 1;
        for (int t = 0; t <= 1; ++t) {
            while (k <= n && j <= n) {
                int k1 = k, j1 = j, size = 0;
                while (str1[k1 - 1] == str2[j1 - 1]) {
                    if (k1 == n + 1 || j1 == n + 1) {
                        break;
                    }
                    ++k1, ++j1, ++size;
                }
                do {
                    d[k][j] = size;
                    ++k, ++j, --size;
                } while (size > 0);
            }
            k = 1, j = i;
        }
    }
    std::vector<std::vector<int>> ans(n + 1, std::vector<int>(n + 2));

    for (int j = n; j >= 1; --j) {
        int k1 = 1, k;
        for (int i = 1; i <= n; ++i) {
            if (k1 + d[k1][j] > i) {
                k = k1;
                p[i][j] = i - k + 1;
            } else {
                k = 0;
                for (int t = k1; t <= i; ++t) {
                    if (t + d[t][j] > i) {
                        k = t;
                        break;
                    }
                }
                k1 = k;
                p[i][j] = i - k + 1;
                if (k == 0) {
                    p[i][j] = 0;
                }
            }
            ans[i][j] = std::max(std::max(ans[i - 1][j], ans[i][j + 1]), p[i][j]);
        }
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::string a, b, c;
    std::cin >> n;
    std::cin >> a >> b >> c;
    Bor bor = Bor();
    good.push_back(bor.root);
    std::string str1 = a, str2 = b;
    int index = 0;
    for (int i = n - 1; i >= 0; --i) {
        bor.addString(str1, 1, index);
        bor.addString(str2, 2, index);
        str1.erase(str1.begin());
        str2.erase(str2.begin());
        ++index;
    }

    std::vector<std::vector<int>> matrix1 = fun(b, c), matrix2 = fun(c, a);
    int answer = 0;

    for (auto it : good) {
        for (int k = 0; k <= n; ++k) {
            answer = std::max(
                it->length + matrix1[it->j - 1][k + 1] + matrix2[k][it->i + it->length], answer);
        }
    }

    std::cout << answer;
    return 0;
}