// Copyright 2022 NNTU-CS
#include <algorithm>
#include <cstdint>
#include <vector>

#include "../include/tree.h"

PMTree::PMTree(const std::vector<char>& symbols) {
    root = new Node();
    sizeAlphabet = static_cast<int>(symbols.size());

    buildTree(root, symbols);
}

void PMTree::buildTree(Node* current, std::vector<char> symbols) {
    if (symbols.empty()) {
        return;
    }

    for (size_t i = 0; i < symbols.size(); i++) {
        Node* child = new Node(symbols[i]);
        current->children.push_back(child);

        std::vector<char> rest = symbols;
        rest.erase(rest.begin() + i);

        buildTree(child, rest);
    }
}

void PMTree::clear(Node* node) {
    if (node == nullptr) {
        return;
    }

    for (Node* child : node->children) {
        clear(child);
    }

    delete node;
}

PMTree::~PMTree() {
    clear(root);
}

Node* PMTree::getRoot() {
    return root;
}

int PMTree::getSize() const {
    return sizeAlphabet;
}

static void dfsAll(Node* node,
                   std::vector<char>& path,
                   std::vector<std::vector<char>>& result,
                   int depth) {
    if (node->value != '\0') {
        path.push_back(node->value);
    }

    if (static_cast<int>(path.size()) == depth) {
        result.push_back(path);
    } else {
        for (Node* child : node->children) {
            dfsAll(child, path, result, depth);
        }
    }

    if (node->value != '\0') {
        path.pop_back();
    }
}

std::vector<std::vector<char>> getAllPerms(PMTree& tree) {
    std::vector<std::vector<char>> result;
    std::vector<char> path;

    dfsAll(tree.getRoot(), path, result, tree.getSize());

    return result;
}

std::vector<char> getPerm1(PMTree& tree, int num) {
    std::vector<std::vector<char>> perms = getAllPerms(tree);

    if (num < 1 || num > static_cast<int>(perms.size())) {
        return {};
    }

    return perms[num - 1];
}

static int64_t factorial(int n) {
    int64_t result = 1;

    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}

std::vector<char> getPerm2(PMTree& tree, int num) {
    int n = tree.getSize();

    int64_t total = factorial(n);

    if (num < 1 || num > total) {
        return {};
    }

    std::vector<char> result;
    Node* current = tree.getRoot();

    int index = num - 1;

    for (int level = 0; level < n; level++) {
        int64_t block = factorial(n - level - 1);

        int childIndex = static_cast<int>(index / block);

        index %= static_cast<int>(block);

        current = current->children[childIndex];

        result.push_back(current->value);
    }

    return result;
}
