//
// Created by Dashbah on 07.04.2023.
//
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

int64_t alfabet = 2;

struct Node {
    bool terminal_ = false;
    std::unordered_map<char, Node *> next_node_;
    Node *parent_ = nullptr;
    char parent_char_;
    Node *suff_link_ = nullptr;
    std::unordered_map<char, Node *> go;
    Node *term = nullptr;
    int used = 0;
};

void addString(Node *node, const std::string &str) {
    for (const auto &symbol : str) {
        if (node->next_node_.find(symbol) == node->next_node_.end()) {
            node->next_node_[symbol] = new struct Node;
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

Node *termLink(Node *node, Node *root) {
    if (node->term == nullptr) {
        if (!node->terminal_ && node->parent_ != nullptr) {
            node->term = termLink(link(node, root), root);
        } else {
            node->term = node;
        }
    }
    return node->term;
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
        link(current_node, root);
        termLink(current_node, root);
        for (int i = 0; i < alfabet; ++i) {
            go(current_node, '0' + i, root);
        }
        for (const auto &[key, value] : current_node->next_node_) {
            if (value != nullptr) {
                q.push(value);
            }
        }
    }
}

void dfs(Node *node) {
    node->used = 1;
    for (const auto &[key, value] : node->go) {
        if (value != nullptr && value->used == 0 && !value->terminal_ && !value->term->terminal_) {
            dfs(value);
        }
        if (value->used == 1) {
            std::cout << "TAK";
            exit(0);
        }
    }
    node->used = 2;
}

int main() {
    Node root;
    int n;
    std::string str;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> str;
        addString(&root, str);
    }
    bfs(&root);
    dfs(&root);

    std::cout << "NIE";
    return 0;
}
