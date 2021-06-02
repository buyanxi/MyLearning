#include <iostream>
#include <vector>

typedef struct BinaryTree
{
    int         data;
    BinaryTree* leftChild;
    BinaryTree* rightChild;
    BinaryTree(const int& _data, BinaryTree* _leftChild = nullptr, BinaryTree* _rightChild = nullptr) :
               data(_data), leftChild(_leftChild), rightChild(_rightChild) {}
};

void PreorderTraversal(BinaryTree* root)
{
    std::vector<BinaryTree*> vecNode;
    while(root || !vecNode.empty()) {
        if (root) {
            std::cout << root->data << " ";

            vecNode.push_back(root);
            root = root->leftChild;
        }
        else {
            root = *(vecNode.end() - 1);
            vecNode.erase(vecNode.end() - 1);
            root = root->rightChild;
        }
    }

    std::cout << std::endl;
}

void InorderTraversal(BinaryTree* root)
{
    std::vector<BinaryTree*> vecNode;
    while(root || !vecNode.empty()) {
        if (root) {
            vecNode.push_back(root);
            root = root->leftChild;
        }
        else {
            root = *(vecNode.end() - 1);
            vecNode.erase(vecNode.end() - 1);

            std::cout << root->data << " ";
            root = root->rightChild;
        }
    }

    std::cout << std::endl;
}

void PostorderTraversal(BinaryTree* root)
{
    std::vector<BinaryTree*> vecNode;
    BinaryTree* lastvist = root;
    while(root || !vecNode.empty()) {
        if (root) {
            vecNode.push_back(root);
            root = root->leftChild;
        }
        else {
            root = *(vecNode.end() - 1);
            if (!root->rightChild || root->rightChild == lastvist) {
                vecNode.erase(vecNode.end() - 1);

                std::cout << root->data << " ";
                lastvist = root;
                root = nullptr;
            }
            else {
                root = root->rightChild;
            }
        }
    }

    std::cout << std::endl;
}

int main()
{
    //create binary tree
    BinaryTree* A = new BinaryTree(4);
    BinaryTree* B = new BinaryTree(2);
    BinaryTree* C = new BinaryTree(8);
    BinaryTree* D = new BinaryTree(1);
    BinaryTree* E = new BinaryTree(3);
    BinaryTree* F = new BinaryTree(6);
    BinaryTree* G = new BinaryTree(7);
    BinaryTree* H = new BinaryTree(5);

    A->leftChild = B;
    A->rightChild = G;
    B->leftChild = D;
    B->rightChild = E;
    G->leftChild = F;
    G->rightChild = C;
    F->leftChild = H;

    PreorderTraversal(A);

    InorderTraversal(A);

    PostorderTraversal(A);

    return 0;
}
