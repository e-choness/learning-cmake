#include "Ancestor.hpp"
#include <iostream>

Ancestor::Ancestor() {
    root = buildTree();
}

Node* Ancestor::findLowestCommon(Node *root, Node *p, Node *q) {
    while(root!= nullptr){
        if(root->value < p->value && root->value < q->value){
            root = root->right;
        }else if(root->value > p->value && root->value > q->value){
            root = root->left;
        }else{
            return root;
        }
    }
    return nullptr;
}

Ancestor::~Ancestor() {
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;
}

Node *Ancestor::buildTree() {
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);

    return root;
}

void Ancestor::show() {
    Node* lowestCommon = findLowestCommon(root, root->left, root->right);
    if(lowestCommon) std::cout << "The lowest common ancestor is: " << lowestCommon->value << "\n";
    else std::cout << "The lowest common ancestor not found.\n";
}

