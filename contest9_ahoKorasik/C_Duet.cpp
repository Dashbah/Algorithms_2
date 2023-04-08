#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

int64_t alfabet = 0;

struct Node {
    bool terminal_ = false;
    std::unordered_map<char, Node *> next_node_;
    Node *parent_ = nullptr;
    char parent_char_;
    Node *suff_link_ = nullptr;
    std::unordered_map<char, Node *> go;
    int64_t length = 0;
    int64_t max_go = 1e9;
};

void addString(Node *node, const std::string &str) {
    for (const auto &symbol : str) {
        if (node->next_node_.find(symbol) == node->next_node_.end()) {
            node->next_node_[symbol] = new struct Node;
            node->next_node_[symbol]->length = node->length + 1;
            node->next_node_[symbol]->parent_ = node;
        }
        node = node->next_node_[symbol];
        node->parent_char_ = symbol;
    }
    node->terminal_ = true;
}

Node *go(Node *v, char c, Node *root);

Node *link(Node *v, Node *root) {
    if (!v->suff_link_) {
        if (v == root || v->parent_ == root) {
            v->suff_link_ = root;
        } else {
            v->suff_link_ = go(link(v->parent_, root), v->parent_char_, root);
        }
    }
    return v->suff_link_;
}

Node *go(Node *v, char c, Node *root) {
    if (!v->go[c]) {
        if (v->next_node_[c]) {
            v->go[c] = v->next_node_[c];
        } else if (v == root) {
            v->go[c] = root;
        } else {
            v->go[c] = go(link(v, root), c, root);
        }
    }
    return v->go[c];
}

void bfs(Node *root) {
    std::queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *current_node = q.front();
        q.pop();
        for (const auto &[key, value] : current_node->next_node_) {
            if (value != nullptr) {
                q.push(value);
            }
        }
        link(current_node, root);
        for (int i = 0; i < alfabet; ++i) {
            // go(current_node, 'a'+i, root);
            current_node->max_go =
                    std::min(current_node->max_go, go(current_node, 'a' + i, root)->length);
        }
    }
}

int main() {
    Node root;
    std::string str;
    int64_t n, k;
    std::cin >> n >> alfabet >> k;
    std::cin >> str;
    addString(&root, str);
    bfs(&root);
    auto v = &root;
    int64_t answer = 1;
    for (int64_t i = 0; i < static_cast<int64_t>(str.length()) - 1; ++i) {
        v = go(v, str[i], &root);
        answer =
                std::max(answer, std::max((v->length - v->max_go), static_cast<int64_t>(0)) * k + n);
    }
    std::cout << answer;
    return 0;
}