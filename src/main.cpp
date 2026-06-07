// Copyright 2022 NNTU-CS
#include "../include/tree.h"

#include <iostream>

int main()
{
    std::vector<char> in =
    {
        '1',
        '2',
        '3'
    };

    PMTree tree(in);

    auto perms = getAllPerms(tree);

    std::cout << "All permutations:\n";

    for (auto& p : perms)
    {
        for (char c : p)
        {
            std::cout << c;
        }

        std::cout << std::endl;
    }

    auto p1 = getPerm1(tree, 1);

    std::cout << "\nPerm1:\n";

    for (char c : p1)
    {
        std::cout << c;
    }

    std::cout << std::endl;

    auto p2 = getPerm2(tree, 2);

    std::cout << "\nPerm2:\n";

    for (char c : p2)
    {
        std::cout << c;
    }

    std::cout << std::endl;

    return 0;
}
