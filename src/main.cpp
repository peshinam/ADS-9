// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>

#include "../include/tree.h"

int main() {
    std::vector<char> in = {'1', '2', '3'};

    PMTree tree(in);

    std::vector<std::vector<char>> perms = getAllPerms(tree);

    std::cout << "All permutations:\n";

    for (const auto& p : perms) {
        for (char c : p) {
            std::cout << c;
        }

        std::cout << '\n';
    }

    std::vector<char> p1 = getPerm1(tree, 1);

    std::cout << "\nPerm1:\n";

    for (char c : p1) {
        std::cout << c;
    }

    std::cout << '\n';

    std::vector<char> p2 = getPerm2(tree, 2);

    std::cout << "\nPerm2:\n";

    for (char c : p2) {
        std::cout << c;
    }

    std::cout << '\n';

    return 0;
}
