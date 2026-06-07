// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

struct PMNode
{
    char value;
    std::vector<PMNode*> children;

    PMNode(char v = 0)
    {
        value = v;
    }
};

class PMTree
{
public:
    PMNode* root;
    int alphabetSize;

    PMTree(const std::vector<char>& symbols);
    ~PMTree();

private:
    void buildTree(PMNode* node, std::vector<char> symbols);
    void clear(PMNode* node);
};

std::vector<std::vector<char>> getAllPerms(PMTree& tree);

std::vector<char> getPerm1(PMTree& tree, int num);

std::vector<char> getPerm2(PMTree& tree, int num);

#endif  // INCLUDE_TREE_H_
