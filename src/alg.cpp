// Copyright 2022 NNTU-CS
#include "../include/tree.h"

#include <algorithm>

PMTree::PMTree(const std::vector<char>& symbols)
{
    root = new Node();
    sizeAlphabet = symbols.size();

    buildTree(root, symbols);
}

void PMTree::buildTree(Node* current,
                       std::vector<char> symbols)
{
    if (symbols.empty())
    {
        return;
    }

    for (size_t i = 0; i < symbols.size(); i++)
    {
        Node* child = new Node(symbols[i]);
        current->children.push_back(child);

        std::vector<char> rest = symbols;
        rest.erase(rest.begin() + i);

        buildTree(child, rest);
    }
}

void PMTree::clear(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    for (Node* child : node->children)
    {
        clear(child);
    }

    delete node;
}

PMTree::~PMTree()
{
    clear(root);
}

Node* PMTree::getRoot()
{
    return root;
}

int PMTree::getSize() const
{
    return sizeAlphabet;
}
