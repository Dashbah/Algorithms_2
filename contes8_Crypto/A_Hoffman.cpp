// Refactored by Jane Smith
// Date: February 1, 2022

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <map>

struct Node {
    char sym;
    int freq;
    Node* left;
    Node* right;
};

struct Compare {
    bool operator()(const Node* lhs, const Node* rhs) {
        return lhs->freq > rhs->freq;
    }
};

void encode(Node* root, std::string code, std::unordered_map<char, std::string>& huffman_code) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffman_code[root->sym] = code;
        return;
    }

    encode(root->left, code + "0", huffman_code);
    encode(root->right, code + "1", huffman_code);
}

void clean(Node* root) {
    if (!root) return;

    clean(root->left);
    clean(root->right);

    delete root;
}

void build_huffman_tree(const std::string& line, std::unordered_map<char, std::string>& huffman_code) {
    std::unordered_map<char, int> frequency_map;

    for (const char& sym : line) {
        frequency_map[sym]++;
    }

    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;

    for (const auto& p : frequency_map) {
        Node* n = new Node{.sym = p.first, .freq = p.second};
        pq.push(n);
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        int left_freq = left->freq;
        pq.pop();

        Node* right = pq.top();
        int right_freq = right->freq;
        pq.pop();

        Node* parent = new Node{.sym = '$', .freq = right_freq + left_freq};
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    encode(pq.top(), "", huffman_code);
    clean(pq.top());
}

int main() {
    std::string input_string;
    std::cin >> input_string;

    std::unordered_map<char, std::string> huffman_code;
    build_huffman_tree(input_string, huffman_code);

    int num_symbols = static_cast<int>(huffman_code.size());
    size_t encoded_len = 0;
    std::string encoded_string;

    for (size_t i = 0; i < input_string.size(); ++i) {
        encoded_len += huffman_code[input_string[i]].size();
        encoded_string += huffman_code[input_string[i]];
    }

    std::map<char, std::string> sorted_huffman_code;

    std::cout << num_symbols << " " << encoded_len << "\n";

    for (const auto& sym : huffman_code) {
        sorted_huffman_code[sym.first] = sym.second;
    }

    for (const auto& sym : sorted_huffman_code) {
        std::cout << sym.first << ": " << sym.second << "\n";
    }

    std::cout << encoded_string << "\n\n";

    return 0;
}