#include <iostream>
#include "AVLTree.h"
#include "SwapableAVL.h"
#include <functional>
int main()
{
    std::cout << "Start" << std::endl;
    SwapableAVL tree;
    // for(int i = 0; i<100; i++)
    // {
    //     std::string str = std::string("#") + std::to_string(i);
    //     tree.insert(i, str);
    // }
    // for(int i = 99; i >= 10; i--)
    // {
    //     tree.remove(i);
    // }
    // std::cout << "Swapping" << std::endl;
    // tree.swapValuesOfMinMaxKeys();
    tree.insert(1, "#1");
    tree.insert(2, "#2");
    tree.insert(3, "#3");
    tree.insert(4, "#4");
    tree.insert(4, "#4");
    std::cout << "postfix" << std::endl;
    tree.postfix_foreach([](const int key, std::string& val)
    {
        std::cout << key << " : " << val << std::endl;
    });
    std::cout << "infix" << std::endl;
    tree.infix_foreach([](const int key, std::string& val)
    {
        std::cout << key << " : " << val << std::endl;
    });
    std::cout << "prefix" << std::endl;
    tree.prefix_foreach([](const int key, std::string& val)
    {
        std::cout << key << " : " << val << std::endl;
    });
    // AvlIterator it = tree.GetRoot();
}