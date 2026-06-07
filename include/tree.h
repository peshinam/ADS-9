// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

struct Node
{
    char value;
    std::vector<Node*> children;

    Node(char v = '\0')
    {
        value = v;
    }
};

class PMTree
{
private:
    Node* root;
    int sizeAlphabet;

    void buildTree(Node* current,
                   std::vector<char> symbols);

public:
    PMTree(const std::vector<char>& symbols);

    ~PMTree();

    void clear(Node* node);

    Node* getRoot();

    int getSize() const;
};

std::vector<std::vector<char>> getAllPerms(PMTree& tree);

std::vector<char> getPerm1(PMTree& tree, int num);

std::vector<char> getPerm2(PMTree& tree, int num);

#endif  // INCLUDE_TREE_H_
