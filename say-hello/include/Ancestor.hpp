#pragma once

struct Node{
    int value;
    Node* left;
    Node* right;
    explicit Node(int v) : value(v), left(nullptr), right(nullptr){}
};

class Ancestor {
public:
    Ancestor();
    ~Ancestor();
    void show();
private:
    static Node* buildTree();
    static Node* findLowestCommon(Node* root, Node* p, Node* q);
    Node* root;
};